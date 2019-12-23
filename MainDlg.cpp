#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent )
	: CDialog(MainDlg::IDD, pParent)
	, ime(_T("Ime"))
	, godina("")

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ime);
	DDX_Text(pDX, IDC_EDIT2, godina);
	
	DDX_Control(pDX, IDC_LIST1, makeList);

	
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

	makeList.InsertColumn(0, "Ime", 0, 120, 20);
	makeList.InsertColumn(1, "Godina", 0, 120, 20);
	makeList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	

	
	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{
	int countItems = makeList.GetItemCount();
	GetDlgItemText(IDC_EDIT1, ime);
	GetDlgItemText(IDC_EDIT2, godina);
	makeList.InsertItem(countItems, ime);
	makeList.SetItemText(countItems, 1, godina);
	/*odabrani red možete saznati pomoću 
	CListCtrl::GetNextItem koristeći LVNI_SELECTED
odabir cijelog reda se postiže ex-stilom LVS_EX_FULLROWSELECT 
(CListCtrl::SetExtendedStyle)*/
}


void MainDlg::OnBnClickedButton2()
{
	makeList.DeleteItem(makeList.GetNextItem(-1, makeList.SetExtendedStyle(LVS_EX_FULLROWSELECT)));
}








