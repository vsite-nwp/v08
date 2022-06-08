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
	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		
	list.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 170);
	list.InsertColumn(1, _T("Year"), LVCFMT_CENTER, 80);
	list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{
	CString title, year;
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);
	int index = list.GetItemCount();
	if (title.IsEmpty() || year.IsEmpty())
		MessageBox("Please enter a title and a year!", "Warning:", MB_OK | MB_ICONWARNING);
	else {
		list.InsertItem(index, title);
		list.SetItemText(index, 1, year);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
	}



}


void MainDlg::OnBnClickedButton2()
{
	
	int d = list.GetNextItem(-1, LVNI_SELECTED);
	if (d != -1)
		list.DeleteItem(d);
	else
		MessageBox("Please select a movie you want to delete!", "Warning:", MB_OK | MB_ICONWARNING);

}
