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
	DDX_Control(pDX, IDC_LIST1, Movies);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::Add_Btn)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::Delete_Btn)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	Movies.InsertColumn(0, "Title", LVCFMT_LEFT, 100);
	Movies.InsertColumn(1, "Year", LVCFMT_CENTER, 100);

	Movies.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	return TRUE;
}

void MainDlg::Add_Btn()
{
	CString Name, Year;
	const int Index = Movies.GetItemCount();

	GetDlgItemText(IDC_EDIT1, Name);
	GetDlgItemText(IDC_EDIT2, Year);

	if (Name.IsEmpty() || Year.IsEmpty()) // if name or year is not entered don't add it to the list
	{
		return;
	}

	Movies.InsertItem(Index, Name);
	Movies.SetItemText(Index, 1, Year);

	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
}

void MainDlg::Delete_Btn()
{
	Movies.DeleteItem(Movies.GetNextItem(-1, LVNI_SELECTED));
}