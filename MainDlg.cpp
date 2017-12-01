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
	DDX_Control(pDX, IDC_LIST1, movies);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &MainDlg::OnLvnItemchangedList1)
	ON_EN_CHANGE(IDC_EDIT1, &MainDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


void MainDlg::OnOK(void)
{
	CWnd* pWnd = GetFocus();
	if (GetDlgItem(IDOK) == pWnd)
	{
		CDialog::OnOK();
		return;
	}
	//Enter kliknut
	OnBnClickedButton1();
}




BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	movies.InsertColumn(0, "Naslov", LVCFMT_LEFT, 120);
	movies.InsertColumn(1, "Godina", LVCFMT_LEFT, 60);
	movies.SetExtendedStyle(movies.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{//add
	HWND hWnd;
	CString film, godina;
	GetDlgItemText(IDC_EDIT1, film);
	GetDlgItemText(IDC_EDIT2, godina);
	if (film != "" && godina != "") {
		int n = movies.InsertItem(IDC_LIST1, film);
		movies.SetItemText(n, 1, godina);
		GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
	}
	GetDlgItem(IDC_EDIT1, &hWnd);
	::PostMessage(GetSafeHwnd(), WM_NEXTDLGCTL, (WPARAM)hWnd, TRUE);
}

void MainDlg::OnBnClickedButton2()
{//delete

	int n = movies.GetNextItem(-1, LVNI_SELECTED);
	if(n != -1){ 
		movies.DeleteItem(n); 
	}
}


void MainDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	if (pNMLV->uNewState & LVIS_SELECTED)
	{
		GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	}
	else 
	{
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	}

	*pResult = 0;
}


void MainDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
