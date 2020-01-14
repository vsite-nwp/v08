#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent)
	: CDialog(MainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListBox);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnClickedButton2)


END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	ListBox.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 90);
	ListBox.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 45);
	ListBox.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	GotoDlgCtrl(GetDlgItem(IDC_EDIT1));
	return FALSE;


}

void MainDlg::OnClickedButton1() 
{
	CString mName, mYear;
	GetDlgItemText(IDC_EDIT1, mName);
	GetDlgItemText(IDC_EDIT2, mYear);
	
	if (!mName.IsEmpty() && !mYear.IsEmpty()) {
		int mCount = ListBox.GetItemCount();
		ListBox.InsertItem(mCount, mName);
		ListBox.SetItemText(mCount, 1, mYear);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
		GotoDlgCtrl(GetDlgItem(IDC_EDIT1));
	}
	
}
void MainDlg::OnClickedButton2() 
{
	if (ListBox.GetNextItem(-1, LVNI_SELECTED) != -1)
		ListBox.DeleteItem(ListBox.GetNextItem(-1, LVNI_SELECTED));
}
void MainDlg::OnOk()
{
	OnClickedButton1();
}

