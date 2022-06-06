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
	DDX_Control(pDX, IDC_LIST1, List);
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
	List.InsertColumn(0, _T("Name"), LVCFMT_CENTER, 90);
	List.InsertColumn(1, _T("Year"), LVCFMT_CENTER, 45);
	List.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString name, year;
	GetDlgItemText(IDC_EDIT1, name);
	GetDlgItemText(IDC_EDIT2, year);
	const int elementAtIndex = List.GetItemCount();
	if (!(name.IsEmpty() || year.IsEmpty())) {
		List.InsertItem(elementAtIndex, name);
		List.SetItemText(elementAtIndex, 1, year);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
	}
	else
		MessageBox("Wrong entry", "Warning:", MB_OK | MB_ICONWARNING);
}


void MainDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	const int item = List.GetNextItem(-1, LVNI_SELECTED);
	if (item != -1)
		List.DeleteItem(item);
}
