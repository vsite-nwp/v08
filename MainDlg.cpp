#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent /*=NULL*/) : CDialog(MainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list);
	DDX_Text(pDX, IDC_EDIT1, title);
	DDV_MaxChars(pDX, title, 50);
	DDX_Text(pDX, IDC_EDIT2, year);
	DDV_MaxChars(pDX, year, 4);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::AddRow)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::DeleteRow)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	list.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 140);
	list.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 60);
	list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(0);
	return TRUE;
}

void MainDlg::AddRow()
{
	UpdateData();
	noOfRows = list.GetItemCount();
	list.InsertItem(noOfRows, title);
	list.SetItemText(noOfRows, 1, year);
	SetDlgItemText(IDC_EDIT1, _T(""));
	SetDlgItemText(IDC_EDIT2, _T(""));
	GetDlgItem(IDC_EDIT1)->SetFocus();
	GetDlgItem(IDC_BUTTON2)->EnableWindow(1);
}

void MainDlg::DeleteRow()
{
	int sel = list.GetNextItem(-1, LVNI_SELECTED);
	if (sel != -1)
		list.DeleteItem(sel);
	noOfRows = list.GetItemCount();
	GetDlgItem(IDC_EDIT1)->SetFocus();
	if (noOfRows == 0)
		GetDlgItem(IDC_BUTTON2)->EnableWindow(0);
}
