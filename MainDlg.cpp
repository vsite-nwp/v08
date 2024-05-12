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
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	list.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	// Structure for column information.
	struct columnInfo {
		int mask;
		int cx;
		LPSTR pszText;
	};

	// Write column information.
	std::vector<columnInfo> columns = {
		{LVCF_WIDTH | LVCF_TEXT, 200, "Title"},
		{LVCF_WIDTH | LVCF_TEXT, 50, "Year"}
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
	CString Title, Year;
	GetDlgItemText(IDC_EDIT1, Title);
	GetDlgItemText(IDC_EDIT2, Year);
	list.InsertItem(0, Title);
	list.SetItemText(0, 1, Year);
}


void MainDlg::OnBnClickedButton2()
{
	list.DeleteItem(list.GetNextItem(-1, LVNI_SELECTED));
}
