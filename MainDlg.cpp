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
	DDX_Control(pDX, IDC_LIST1, movies);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::AddRow)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::DeleteRow)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	movies.InsertColumn(0, "Title", LVCFMT_LEFT,140);
	movies.InsertColumn(1, "Year", LVCFMT_CENTER, 50);
	movies.SetExtendedStyle(movies.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	return TRUE;
}



void MainDlg::AddRow()
{
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	int index = movies.InsertItem(movies.GetItemCount(), text);
	GetDlgItemText(IDC_EDIT2, text);
	movies.SetItemText(index, 1, text);
}


void MainDlg::DeleteRow()
{
	int red = movies.GetNextItem(-1, LVNI_SELECTED);
	if(red != -1)
		movies.DeleteItem(red);
}
