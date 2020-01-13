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
	DDX_Control(pDX, IDC_LIST1, list);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog) 
ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAdd)
ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	list.InsertColumn(0, "Title", LVCFMT_LEFT, 150);
	list.InsertColumn(1, "Year", LVCFMT_CENTER, 150);
	list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	return TRUE;
}


void MainDlg::OnAdd() {
	CString title, year;
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);
	int inputIndex = list.GetItemCount();

	if (title != "" && year != "") {
		list.InsertItem(inputIndex, title);
		list.SetItemText(inputIndex, 1, year);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
		GetDlgItem(IDC_BUTTON2)->EnableWindow(1);
	}
}


void MainDlg::OnDelete() {
	list.DeleteItem(list.GetNextItem(-1, LVNI_SELECTED));
	if (!list.GetItemCount()) {
		GetDlgItem(IDC_BUTTON2)->EnableWindow(0);
	}
}

