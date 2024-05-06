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
	DDX_Control(pDX, IDC_LIST1, Lista);
	DDX_Control(pDX, IDC_EDIT1, edit1);
	DDX_Control(pDX, IDC_EDIT2, edit2);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::Add)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::Delete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	Lista.InsertColumn(0, "Title", 0, 80, 1);
	Lista.InsertColumn(0, "Year", 0, 80, 1);
	Lista.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}



void MainDlg::Add()
{
	CString title;
	CString year;
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);
	int n = Lista.GetItemCount();
	Lista.InsertItem(n,title);
	Lista.SetItemText(n,1,year);
	// TODO: Add your control notification handler code here
}


void MainDlg::Delete()
{
	int n = Lista.GetNextItem(-1, LVNI_SELECTED);
	Lista.DeleteItem(n);	
		// TODO: Add your control notification handler code here
}
