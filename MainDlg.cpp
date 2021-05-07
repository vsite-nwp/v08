#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MainDlg::IDD, pParent), Title(_T("Title*")), Year("Year*")
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Title);
	DDX_Text(pDX, IDC_EDIT2, Year);
	DDX_Control(pDX, IDC_LIST1, makeList);
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
	makeList.InsertColumn(0, "Title", 0, 120, 20);
	makeList.InsertColumn(1, "Year", 0, 120, 20);
	makeList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}


void MainDlg::OnBnClickedButton1()
{
	UpdateData();
	int countItems = makeList.GetItemCount();
	makeList.InsertItem(countItems, Title);
	makeList.SetItemText(countItems, 1, Year);
}


void MainDlg::OnBnClickedButton2()
{
	if (makeList.GetNextItem(-1, LVNI_SELECTED) != -1)
		makeList.DeleteItem(makeList.GetNextItem(-1, (LVNI_SELECTED)));
}
