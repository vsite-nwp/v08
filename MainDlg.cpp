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
	, name(_T(""))
	, year(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT2, year);
	DDX_Control(pDX, IDC_LIST1, ListControl);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::Add)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::Delete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	ListControl.InsertColumn(0, "Title", 0, 130, 0);
	ListControl.InsertColumn(1, "Year", 0, 50, 0);
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	return TRUE;
}

void MainDlg::Add()
{
	GetDlgItemText(IDC_EDIT1, name);
	GetDlgItemText(IDC_EDIT2, year);
	int count = ListControl.GetItemCount();
	ListControl.InsertItem(count,name);
	ListControl.SetItemText(count, 1, year);
}


void MainDlg::Delete()
{
	int item = ListControl.GetNextItem(-1, ListControl.SetExtendedStyle(LVS_EX_FULLROWSELECT));
	ListControl.DeleteItem(item);
}
