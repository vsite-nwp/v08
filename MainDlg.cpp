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
	DDX_Control(pDX, IDC_LIST1, m_moviesList);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAddClicked)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDeleteClicked)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	m_moviesList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_moviesList.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 140);
	m_moviesList.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 80);

	return TRUE;
}

void MainDlg::OnAddClicked()
{
	CString movieTitle = GetText(IDC_EDIT1);
	CString movieYear = GetText(IDC_EDIT2);

	if (!movieTitle.IsEmpty() && IsValidYear(movieYear)) {
		int pos = m_moviesList.GetItemCount();
		m_moviesList.InsertItem(pos, movieTitle);
		m_moviesList.SetItemText(pos, 1, movieYear);

		SetDlgItemText(IDC_EDIT1, _T(""));
		SetDlgItemText(IDC_EDIT2, _T(""));
	}
}

void MainDlg::OnDeleteClicked()
{
	int sel = m_moviesList.GetNextItem(-1, LVNI_SELECTED);
	if (sel >= 0) {
		m_moviesList.DeleteItem(sel);
	}
}

bool MainDlg::IsValidYear(const CString& year)
{
	if (year.IsEmpty()) return false;

	for (int i = 0; i < year.GetLength(); i++) {
		if (!isdigit(year[i])) return false;
	}
	return true;
}

CString MainDlg::GetText(int editId)
{
	CString text;
	GetDlgItemText(editId, text);
	return text;
}