#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"
#include "cstring"

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
	DDX_Control(pDX, IDC_LIST1, Control);
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
	Control.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	Control.InsertColumn(0,"Title", LVCFMT_LEFT,120,20);
	Control.InsertColumn(1, "Year", LVCFMT_CENTER, 50, 20);

	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{
	CString title;
	CString year;
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);
	int counter = Control.GetItemCount();
	Control.InsertItem(counter, title);
	Control.SetItemText(counter, 1, year);
}


void MainDlg::OnBnClickedButton2()
{
	int item = Control.GetNextItem(-1, LVNI_SELECTED);
	if(item != -1)
	Control.DeleteItem(item);
}
