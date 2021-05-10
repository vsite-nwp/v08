#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"
#include <cctype>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MainDlg::IDD, pParent) {
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX) {
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, cListCtrl);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::onAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::onDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog() {
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	cListCtrl.InsertColumn(0, "Title", LVCFMT_LEFT, 200);
	cListCtrl.InsertColumn(1, "Year", LVCFMT_LEFT, 200);

	cListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	return TRUE;
}
void MainDlg::onAdd() {
	CString title;
	CString year;

	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);

	if (title.IsEmpty())
		return;
	if (year.IsEmpty())
		return;
	cListCtrl.InsertItem(0, title);
	cListCtrl.SetItemText(0, 1, year);

	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
}


void MainDlg::onDelete()
{
	cListCtrl.DeleteItem(cListCtrl.GetNextItem(-1, LVNI_SELECTED));
}