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
	ON_BN_CLICKED(IDC_BUTTON1, AddItem)
	ON_BN_CLICKED(IDC_BUTTON2, DeleteItem)
END_MESSAGE_MAP()

void MainDlg::AddItem() {
	CString title;
	CString year;

	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);

	auto count = list_control.GetItemCount();

	if (title && atoi(year)) {
		list_control.InsertItem(count, title);
		list_control.SetItemText(count, 1, year);
	}
}

void MainDlg::DeleteItem() {
	auto index = list_control.GetNextItem(NULL, LVNI_SELECTED);
	if (index != NULL) {
		list_control.DeleteItem(index);
	}
}
BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	list_control.InsertColumn(0, "Title", LVCFMT_LEFT, 100);
	list_control.InsertColumn(1, "Year", LVCFMT_LEFT, 150);
	list_control.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	return TRUE;
}
