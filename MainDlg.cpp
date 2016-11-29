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
	DDX_Control(pDX, IDC_LIST1, list_control);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::add_row)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::delete_row)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	list_control.InsertColumn(0, _T("Title"), 0, 100);
	list_control.InsertColumn(1, _T("Year"), 0, 50);
	list_control.SetExtendedStyle(list_control.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	
	return TRUE;
}

void MainDlg::add_row()
{
	// Add your control notification handler code here
	CString title;
	GetDlgItemText(IDC_EDIT1, title);
	
	int col_index = list_control.InsertItem(list_control.GetItemCount(), title);

	GetDlgItemText(IDC_EDIT2, title);
	list_control.SetItemText(col_index, 1, title);

	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
}

void MainDlg::delete_row() {
	list_control.DeleteItem(list_control.GetNextItem(-1, LVNI_SELECTED));
}