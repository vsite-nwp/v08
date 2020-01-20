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
	DDX_Control(pDX, IDC_LIST1, data);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, onButtonClickAdd)
	ON_BN_CLICKED(IDC_BUTTON2, onButtonClickDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);		
	SetIcon(m_hIcon, FALSE);

	data.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	data.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 140, -1);
	data.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 100, -1);

	return TRUE;
}

void MainDlg::onButtonClickAdd()
{
	CString col1;
	CString col2;
	GetDlgItemText(IDC_EDIT1, col1);
	GetDlgItemText(IDC_EDIT2, col2);
	if (!col1.IsEmpty() || !col2.IsEmpty())
	{
		data.InsertItem(0, col1);
		data.SetItemText(0, 1, col2);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
	}
}

void MainDlg::onButtonClickDelete()
{
	int item = data.GetNextItem(-1, LVNI_SELECTED);
	if (item != -1)
		data.DeleteItem(item);
}