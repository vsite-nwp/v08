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
	DDX_Control(pDX, IDC_LIST1, List);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &MainDlg::OnNMClickList1)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);

	List.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 200);
	List.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 50);
	List.SetExtendedStyle(List.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	
	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{
	CString title, year;
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);
	List.InsertItem(0, title);
	List.SetItemText(0, 1, year);
};


void MainDlg::OnBnClickedButton2()
{
	int selected = List.GetNextItem(-1, LVNI_SELECTED);

	List.DeleteItem(selected);
}

