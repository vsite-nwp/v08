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
	DDX_Control(pDX, IDC_LIST1, title);
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
	title.InsertColumn(0, "Title", 0, 141, 0);
	title.InsertColumn(1, "Year", 0, 50, 0);
	title.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{
	CString str;	
	GetDlgItemText(IDC_EDIT1, str);
	title.InsertItem(0, str);
	GetDlgItemText(IDC_EDIT2, str);
	title.SetItemText(0, 1,str);
}



void MainDlg::OnBnClickedButton2()
{	
	title.DeleteItem(title.GetNextItem(-1, LVNI_SELECTED));
}
