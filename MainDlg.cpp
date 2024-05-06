#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent /*=NULL*/) : CDialog(MainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::OnBnClickedButtonAdd()
{
	CString m_title, m_year;
	GetDlgItemText(IDC_EDIT1, m_title);
	GetDlgItemText(IDC_EDIT2, m_year);

	int index = m_list.GetItemCount();

	if (!m_title.IsEmpty() && !m_year.IsEmpty() && atoi(m_year))
	{
		m_list.InsertItem(index, m_title);
		m_list.SetItemText(index, 1, m_year);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
	}
	else
		MessageBox("Invalid input!", "Error!", MB_OK | MB_ICONERROR);
}

void MainDlg::OnBnClickedButtonDelete()
{
	int m_delete = m_list.GetNextItem(-1, LVNI_SELECTED);
	if (m_delete != -1)
		m_list.DeleteItem(m_delete);
	else
		MessageBox("No Movie Selected!", "Error!", MB_OK | MB_ICONERROR);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButtonDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_list.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 130);
	m_list.InsertColumn(1, _T("Year"), LVCFMT_CENTER, 61);

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	return TRUE;
}

