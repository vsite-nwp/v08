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
	DDX_Control(pDX, IDC_LIST1, Control1);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);        // Set small icon

	Control1.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	Control1.InsertColumn(0, "Title", LVA_ALIGNLEFT, 150);
	Control1.InsertColumn(1, "Year", LVA_ALIGNLEFT, 75);

	return TRUE;
}


void MainDlg::OnBnClickedButton1()
{
	CString title;
	GetDlgItemText(IDC_EDIT1, title);

	CString year;
	GetDlgItemText(IDC_EDIT2, year);

	int index = Control1.GetItemCount();

	Control1.InsertItem(index, title);
	Control1.SetItemText(index, 1, year);

}

void MainDlg::OnBnClickedButton2()
{
	Control1.DeleteItem(Control1.GetNextItem(-1, LVNI_SELECTED));
}
