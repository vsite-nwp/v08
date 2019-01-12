#include "stdAfx.h"
#include "v8.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent )
	: CDialog(MainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	m_list.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 50);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}

void MainDlg::OnClickedButton1()
{
	CString movieName, movieYear;
	GetDlgItemText(IDC_EDIT1, movieName);
	GetDlgItemText(IDC_EDIT2, movieYear);
	
	if (!movieName.IsEmpty() && !movieYear.IsEmpty()) {
		int rowCount = m_list.GetItemCount();
		m_list.InsertItem(rowCount,movieName);
		m_list.SetItemText(rowCount, 1, movieYear);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
	}	
}



void MainDlg::OnClickedButton2()
{
	if (m_list.GetNextItem(-1, LVNI_SELECTED) != -1)
		m_list.DeleteItem(m_list.GetNextItem(-1, LVNI_SELECTED));
}
