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
	DDX_Control(pDX, IDC_LIST1, c_list);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	c_list.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 100);
	c_list.InsertColumn(1, _T("Year"), LVCFMT_CENTER, 100);
	c_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	return TRUE;
}

void MainDlg::OnBnClickedButton1() {
	CString mTitle, mYear;
	GetDlgItemText(IDC_EDIT1, mTitle);
	GetDlgItemText(IDC_EDIT2, mYear);

	if (!mTitle.IsEmpty() && !mYear.IsEmpty()) {
		int i = c_list.GetItemCount();
		c_list.InsertItem(i, mTitle);
		c_list.SetItemText(i, 1, mYear);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
	}
}

