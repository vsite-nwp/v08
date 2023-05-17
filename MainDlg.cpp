#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"
#include <string>

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
	DDX_Control(pDX, IDC_LIST1, itemList);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, MainDlg::OnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, MainDlg::OnRemove)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	itemList.InsertColumn(0, "Title", LVCFMT_LEFT, 150);
	itemList.InsertColumn(1, "Year", LVCFMT_LEFT, 40);
	itemList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	return TRUE;
}

void MainDlg::OnAdd() {
	CString title;
	CString year;
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);
	itemList.InsertItem(itemList.GetItemCount(), title);
	itemList.SetItemText(itemList.GetItemCount() - 1, 1, year);
}

void MainDlg::OnRemove()
{
	if (itemList.GetSelectedCount() > 0) {
		itemList.DeleteItem(itemList.GetNextItem(-1, LVNI_SELECTED));
	}
}

