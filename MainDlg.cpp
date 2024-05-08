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

	list.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 120);
	list.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 10);
	list.SetExtendedStyle(list.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	
	return TRUE;
}

void MainDlg::OnAdd()
{
	CString title, year;
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);
	int year1 = _ttoi(year);

	int index = list.GetItemCount();
	list.InsertItem(index, title);
	list.SetItemText(index, 1, year);
}

void MainDlg::OnDelete()
{
	int index = list.GetNextItem(-1, LVNI_SELECTED);
	if (index != -1)
		list.DeleteItem(index);
}



