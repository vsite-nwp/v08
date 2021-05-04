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
	DDX_Control(pDX, IDC_BUTTON1, buttonAdd);
	DDX_Control(pDX, IDC_BUTTON2, buttonDelete);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_COMMAND(IDC_BUTTON1, Add)
	ON_COMMAND(IDC_BUTTON2, Del)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	list.InsertColumn(0, "Title");
	list.SetColumnWidth(0, 150);

	list.InsertColumn(1, "Year");
	list.SetColumnWidth(1, 40);

	return TRUE;
}

void MainDlg::Add() {
	TCHAR Title[512], Year[512];

	::GetDlgItemText(*this, IDC_EDIT1, Title, 512);
	::GetDlgItemText(*this, IDC_EDIT2, Year, 512);

	list.InsertItem(0, Title);
	list.SetItemText(0, 1, Year);

	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
}

void MainDlg::Del() {
	list.DeleteItem(list.GetNextItem(-1, LVNI_SELECTED));
}
