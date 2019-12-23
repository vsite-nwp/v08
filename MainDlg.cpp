#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"
#include <ctype.h>
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

void MainDlg::DoDataExchange(CDataExchange* pDDX)
{
	CDialog::DoDataExchange(pDDX);
	DDX_Control(pDDX, IDC_LIST1, items);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::add)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::add)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog(){
	CDialog::OnInitDialog();		
	SetIcon(m_hIcon, FALSE);		
	items.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 100);
	items.InsertColumn(1, _T("Year"), LVCFMT_LEFT,92);
	items.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	GotoDlgCtrl(GetDlgItem(IDC_EDIT1));
	return FALSE;
}

void MainDlg::add(){
	CString nm, yr;
	GetDlgItemText(IDC_EDIT1, nm);
	GetDlgItemText(IDC_EDIT2, yr);
	if (nm.IsEmpty() || yr.IsEmpty()){ return; };
		int num = items.GetItemCount();
		items.InsertItem(num, nm);
		items.SetItemText(num, 1, yr);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
		}
void MainDlg::del(){
	if (items.GetNextItem(-1, LVNI_SELECTED) != -1)
		items.DeleteItem(items.GetNextItem(-1, LVNI_SELECTED));
}
void MainDlg::OnOK(){
	add();
}