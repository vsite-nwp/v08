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
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	m_listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_listCtrl.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 80);
	m_listCtrl.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 50);

	return TRUE;
}

void MainDlg::OnBnClickedButton1()
{
	CString strTitle, strYear;
	GetDlgItemText(IDC_EDIT1, strTitle);
	GetDlgItemText(IDC_EDIT2, strYear);

	// Dodavanje novog reda u list kontrolu
	int nItem = m_listCtrl.InsertItem(m_listCtrl.GetItemCount(), strTitle);
	m_listCtrl.SetItemText(nItem, 1, strYear);

	SetDlgItemText(IDC_EDIT1, _T(""));
	SetDlgItemText(IDC_EDIT2, _T(""));
}

void MainDlg::OnBnClickedButton2()
{
	int nItem = m_listCtrl.GetNextItem(-1, LVNI_SELECTED);

	if (nItem != -1)
	{
		m_listCtrl.DeleteItem(nItem);
	}
}
