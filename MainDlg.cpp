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
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Movies);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	Movies.InsertColumn(0, "Title", LVCFMT_LEFT, 156, -1);
	Movies.InsertColumn(1, "Year", LVCFMT_RIGHT, 100, -1);
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	Movies.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}



void MainDlg::OnAdd()
{
	CString editValue;
	const int count = Movies.GetItemCount();

	GetDlgItemText(IDC_EDIT1, editValue);
	Movies.InsertItem(count, editValue);

	GetDlgItemText(IDC_EDIT2, editValue);
	Movies.SetItemText(count, 1, editValue);

}


void MainDlg::OnDelete()
{
	if (Movies.GetSelectedCount() > 0)
		Movies.DeleteItem(Movies.GetNextItem(-1, LVNI_SELECTED));
}
