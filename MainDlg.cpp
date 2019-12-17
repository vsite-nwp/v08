#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"
#include <inttypes.h>

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
	DDX_Control(pDX, IDC_LIST1, mListControl);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAddButton)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDeleteButton)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	mListControl.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 100);
	mListControl.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 100);
	mListControl.SetExtendedStyle(mListControl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(0);
	return TRUE;
}

void MainDlg::OnAddButton()
{
	CString title, year;

	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);

	if (year != "" && title != "")
	{
		const int listSize = mListControl.GetItemCount();
		mListControl.InsertItem(listSize, title);
		mListControl.SetItemText(listSize, 1, year);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(1);
	}
	else
	{
		MessageBox(_T("Wrong input!!"), "Error", MB_OK | MB_ICONERROR);
	}
}

void MainDlg::OnDeleteButton()
{
	const int returnValue = mListControl.GetNextItem(-1, LVNI_SELECTED);
	mListControl.DeleteItem(returnValue);

	if (!mListControl.GetItemCount())
	{
		GetDlgItem(IDC_BUTTON2)->EnableWindow(0);
	}
	
}


