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
	DDX_Control(pDX, IDC_EDIT1, Edit1);
	DDX_Control(pDX, IDC_EDIT2, Edit2);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnADD)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	List.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 100);
	List.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 100);
	List.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	
	return TRUE;
}



void MainDlg::OnADD()
{
	// TODO: Add your control notification handler code here
	CString name, year;
	Edit1.GetWindowText(name);
	Edit2.GetWindowText(year);
	int n = List.GetItemCount();
	List.InsertItem(n, name);
	List.SetItemText(n, 1, year);
}


void MainDlg::OnDelete()
{
	
	
	// TODO: Add your control notification handler code here

	int nItem = List.GetNextItem(-1, LVNI_SELECTED);
	if (nItem != -1)
	{
		// Delete the selected item
		List.DeleteItem(nItem);
	}
	else
	{
		MessageBox(_T("Please select an item to delete"));
	}
}
