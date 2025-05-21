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
	DDX_Control(pDX, IDC_LIST1, m_movieList);
	DDX_Control(pDX, IDC_EDIT1, m_titleInput);
	DDX_Control(pDX, IDC_EDIT2, m_yearInput);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAddClicked)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnRemoveClicked)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	m_movieList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_movieList.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 150);
	m_movieList.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 80);
	
	return TRUE;
}

void MainDlg::OnAddClicked()
{
	CString title, year;
	m_titleInput.GetWindowText(title);
	m_yearInput.GetWindowText(year);

	title.Trim();
	year.Trim();

	if (!title.IsEmpty() && !year.IsEmpty()) {
		int index = m_movieList.InsertItem(m_movieList.GetItemCount(), title);
		m_movieList.SetItemText(index, 1, year);
		m_titleInput.SetWindowText(_T(""));
		m_yearInput.SetWindowText(_T(""));
	}
}

void MainDlg::OnRemoveClicked()
{
	int selectedIndex = m_movieList.GetNextItem(-1, LVNI_SELECTED);
	if (selectedIndex != -1) {
		m_movieList.DeleteItem(selectedIndex);
	}
}
