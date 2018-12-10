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
	DDX_Control(pDX, IDC_LIST1, lc);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAddButton)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDeleteButton)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	lc.InsertColumn(0,"Title",0,130);
	lc.InsertColumn(1, "Year", 0, 50);
	lc.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}

void MainDlg::OnAddButton()
{
	CString title,year;
	int i = lc.GetItemCount();

	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);
	if (year != "" && title != "") {
		lc.InsertItem(i, title);
		lc.SetItemText(i, 1, year);
	}
	else {
		MessageBox("Please enter both columns", "warning", MB_ICONWARNING);
	}
}


void MainDlg::OnDeleteButton()
{
	int i = lc.GetNextItem(-1, LVNI_SELECTED);
	if(i != -1){
		lc.DeleteItem(i);
	}
}
