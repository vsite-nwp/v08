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
	DDX_Control(pDX, IDC_LIST1, listCtrl);
}

void MainDlg::OnAdd() {
	CString fieldValue;
	// add row and set movie title
	GetDlgItemText(IDC_EDIT1, fieldValue);
	listCtrl.InsertItem(listSize, fieldValue);

	// add column and add year
	GetDlgItemText(IDC_EDIT2, fieldValue);
	listCtrl.SetItemText(listSize, 1, fieldValue);

	// reset fields
	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
	++listSize;
}

void MainDlg::OnDelete() {
	if (listSize > 0) {
		// decrese size counter only if delete was successful
		if(listCtrl.DeleteItem(listCtrl.GetNextItem(-1, LVNI_SELECTED)) != 0)
			--listSize;
		return;
	}
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, MainDlg::OnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, MainDlg::OnDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	listCtrl.InsertColumn(0, "Title", LVCFMT_RIGHT, 100, -1);
	listCtrl.InsertColumn(1, "Year", LVCFMT_RIGHT, 100, -1);
	listCtrl.SetExtendedStyle(GetExStyle() | LVS_EX_FULLROWSELECT);
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	return TRUE;
}

