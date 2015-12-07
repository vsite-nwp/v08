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
	DDX_Control(pDX, IDC_LIST1, movies_lista);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::Add)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::Delete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	movies_lista.InsertColumn(0,"Title",LVCFMT_LEFT,100);
	movies_lista.InsertColumn(1, "Year", LVCFMT_LEFT, 70);
	movies_lista.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	return TRUE;
}



void MainDlg::Add()
{
	CString s,s1;
	GetDlgItemText(IDC_EDIT1, s);
	GetDlgItemText(IDC_EDIT2, s1);
	movies_lista.InsertItem(0, s);
	movies_lista.SetItemText(0,1,s1);

	
}


void MainDlg::Delete()
{
	
	movies_lista.DeleteItem(movies_lista.GetNextItem(-1, LVNI_SELECTED));
	
}
