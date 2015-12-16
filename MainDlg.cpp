#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MainDlg::IDD, pParent)
	, movies(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, film);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	film.InsertColumn(0,_T("Title"),LVCFMT_LEFT, 120);
	film.InsertColumn(1,_T("Year"), LVCFMT_LEFT, 100);
	film.SetExtendedStyle(LVS_EX_FULLROWSELECT  );
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	return TRUE;
}



void MainDlg::OnAdd()
{
	//  Add your control notification handler code here
	CString s1, s2; int number_item=film.GetItemCount();
	GetDlgItemText(IDC_EDIT1, s1);
	GetDlgItemText(IDC_EDIT2, s2);
	film.InsertItem(number_item, s1);
	film.SetItemText(number_item,1, s2);

}


void MainDlg::OnDelete()
{
	//  Add your control notification handler code here
	int number_item = film.GetNextItem(-1, LVNI_SELECTED);
	if (number_item > 0)
		film.DeleteItem(number_item);
	film.DeleteItem(film.GetNextItem(-1, LVNI_SELECTED));

}
