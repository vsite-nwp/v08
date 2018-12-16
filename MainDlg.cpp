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
	DDX_Control(pDX, IDC_LIST1, list1);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	list1.InsertColumn(0,_T("Title"),LVCFMT_LEFT, 150);
	list1.InsertColumn(1,_T("Year"),LVCFMT_CENTER, 50);

	list1.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	return TRUE;
}


void MainDlg::OnBnClickedButton1()
{
	CString movie, year;

	GetDlgItemText(IDC_EDIT1, movie);
	GetDlgItemText(IDC_EDIT2, year);

	if (movie != "" && year != "") {
		list1.InsertItem(0, movie);
		list1.SetItemText(0, 1, year);
	}else
		MessageBox("Nisu popunjena sva polja!","Upozorenje",MB_OK);

}

void MainDlg::OnBnClickedButton2()
{
		list1.DeleteItem(list1.GetNextItem(-1, LVNI_SELECTED));
	
}
