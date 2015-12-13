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
	DDX_Control(pDX, IDC_LIST1, listVar);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	listVar.InsertColumn(0, _T("Title"), 0, 150);
	listVar.InsertColumn(1, _T("Year"), 0, 40);
	listVar.SetExtendedStyle(listVar.GetExtendedStyle()|LVS_EX_FULLROWSELECT);
	return TRUE;
}



void MainDlg::OnBnClickedAdd()
{
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	int line=listVar.InsertItem(listVar.GetItemCount(), text);

	GetDlgItemText(IDC_EDIT2, text);
	listVar.SetItemText(line, 1, text);

	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
}


void MainDlg::OnBnClickedDelete()
{
	listVar.DeleteItem(listVar.GetNextItem(-1,LVNI_SELECTED));
}
