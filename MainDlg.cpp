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
	DDX_Control(pDX, IDC_LIST1, movies);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	movies.InsertColumn(0, "Title", LVCFMT_LEFT, 150, -1);
	movies.InsertColumn(1, "Year", LVCFMT_RIGHT, 100, -1);
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);
	movies.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	return TRUE;
}

void MainDlg::OnAdd()
{
	CString name, year;

	int count = movies.GetItemCount();
	GetDlgItemText(IDC_EDIT1, name);
	GetDlgItemText(IDC_EDIT2, year);

	bool y_int = 0;
	for (int i = 0; i < year.GetLength(); ++i) {
		if (isdigit(year[i])) {
			y_int = 1;
			break;
		}
	}

	if (name.IsEmpty() || year.IsEmpty() || y_int == 0)
		MessageBox("Inccorect entry", "Warning:", MB_OK | MB_ICONWARNING);
	else
	{
		movies.InsertItem(count, name);
		movies.SetItemText(count, 1, year);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
	}
}

void MainDlg::OnDelete()
{
	if (movies.GetSelectedCount() > 0)
		movies.DeleteItem(movies.GetNextItem(-1, LVNI_SELECTED));
}
