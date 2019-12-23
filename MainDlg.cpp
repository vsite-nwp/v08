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
	DDX_Control(pDX, IDC_LIST1, listItem);
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

	listItem.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 150);
	listItem.InsertColumn(1, _T("Year"), LVCFMT_CENTER, 50);
	listItem.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{
	CString title, year;
	int i = listItem.GetItemCount();

	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);

	if (title != "" && year != "") {
		listItem.InsertItem(i, title);
		listItem.SetItemText(i, 1, year);
		SetDlgItemTextA(IDC_EDIT1, "");
		SetDlgItemTextA(IDC_EDIT2, "");
	}
	else
		MessageBox("Polje je prazno", "Pozor", MB_OK);

}


void MainDlg::OnBnClickedButton2()
{
	int index = listItem.GetNextItem(-1, LVNI_SELECTED);
	if (index != -1) {
		listItem.DeleteItem(index);
	}
}
