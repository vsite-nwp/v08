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
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	m_listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_listCtrl.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 150);
	m_listCtrl.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 120);
	
	return TRUE;
}

void MainDlg::OnBnClickedAdd()
{
	CString title, year;
	m_edit1.GetWindowText(title);
	m_edit2.GetWindowText(year);

	if (!title.IsEmpty() && !year.IsEmpty()) {
		int index = m_listCtrl.InsertItem(m_listCtrl.GetItemCount(), title);
		m_listCtrl.SetItemText(index, 1, year);

		m_edit1.SetWindowText(_T(""));
		m_edit2.SetWindowText(_T(""));
	}
}

void MainDlg::OnBnClickedDelete()
{
	int selected = m_listCtrl.GetNextItem(-1, LVNI_SELECTED);
	if (selected != -1) {
		m_listCtrl.DeleteItem(selected);
	}
}
