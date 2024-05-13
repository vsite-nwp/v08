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
	DDX_Control(pDX, IDC_EDIT2, edit2);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
	ON_EN_UPDATE(IDC_EDIT2, &MainDlg::OnEnUpdateEdit2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	edit2.LimitText(4);

	// Structure for column information.
	struct columnInfo {
		int mask;
		int cx;
		LPSTR pszText;
	};

	// Write column information.
	std::vector<columnInfo> columns = {
		{LVCF_WIDTH | LVCF_TEXT, 200, _T("Title")},
		{LVCF_WIDTH | LVCF_TEXT, 50, _T("Year")}
	};

	// Insert columns.
	LVCOLUMN lvColumn;
	int index = 0;
	for (columnInfo i : columns) {
		lvColumn.mask = i.mask;
		lvColumn.cx = i.cx;
		lvColumn.pszText = i.pszText;

		list.InsertColumn(index, &lvColumn);
		++index;
	}

	return TRUE;
}

void MainDlg::OnBnClickedButton1()
{
	CString title, year;
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);
	if (title.GetLength() != 0 && year.GetLength() != 0) {
		int index = list.GetItemCount();
		list.InsertItem(index, title);
		list.SetItemText(index, 1, year);
		SetDlgItemText(IDC_EDIT1, _T(""));
		SetDlgItemText(IDC_EDIT2, _T(""));
	}
	else {
		MessageBox(_T("You must enter title and year."), _T("Error"), MB_ICONEXCLAMATION);
	}
}

void MainDlg::OnBnClickedButton2()
{
	list.DeleteItem(list.GetNextItem(-1, LVNI_SELECTED));
}

bool is_number(const CString& text) {
	for (int i = 0; i < text.GetLength(); ++i) {
		if (!isdigit(text[i])) {
			return false;
		}
	}
	return true;
}

void MainDlg::OnEnUpdateEdit2()
{
	CString text;
	GetDlgItemText(IDC_EDIT2, text);

	if (!is_number(text)) {
		SetDlgItemText(IDC_EDIT2, _T(""));
	}
}
