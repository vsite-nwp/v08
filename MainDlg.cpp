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
	DDX_Control(pDX, IDC_LIST1, ListKontrola);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAddClicked)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDeleteClicked)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	ListKontrola.InsertColumn(0, "Title", LVCFMT_CENTER, 120, -1);
	ListKontrola.InsertColumn(1, "Year", LVCFMT_CENTER, 50, -1);
	ListKontrola.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	return TRUE;
}




void MainDlg::OnAddClicked()
{
	// TODO: Add your control notification handler code here
	CString s1, s2;
	int cnt = ListKontrola.GetItemCount();
	GetDlgItemText(IDC_EDIT1, s1);
	GetDlgItemText(IDC_EDIT2, s2);
	ListKontrola.InsertItem(cnt, s1);
	ListKontrola.SetItemText(cnt, 1, s2);
}


void MainDlg::OnDeleteClicked()
{
	// TODO: Add your control notification handler code here
	int next = ListKontrola.GetNextItem(-1, LVNI_SELECTED);
	if (next)
		ListKontrola.DeleteItem(next);
}
