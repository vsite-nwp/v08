#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"
#include <string>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MainDlg::IDD, pParent)
	, TitleData(_T("Insert movie"))
	, YearData(1888)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, TitleData);
	DDX_Text(pDX, IDC_EDIT2, YearData);
	DDV_MinMaxInt(pDX, YearData, 1888, 2019);
	DDX_Control(pDX, IDC_LIST1, ListControl);
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
	ListControl.InsertColumn(0, "Name", LVCFMT_RIGHT, 100, 20);
	ListControl.InsertColumn(1, "Year", LVCFMT_LEFT, 100, 20);
	ListControl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
	return TRUE;
}



void MainDlg::OnBnClickedButton1()//add
{
	UpdateData(true);
	int index = ListControl.GetItemCount();
	ListControl.InsertItem(index, TitleData);
	ListControl.SetItemText(index,1, std::to_string(YearData).c_str());
	GetDlgItem(IDC_BUTTON2)->EnableWindow(true);

}


void MainDlg::OnBnClickedButton2()//delete
{

	ListControl.DeleteItem(ListControl.GetNextItem(-1,LVNI_SELECTED));
	GetDlgItem(IDC_BUTTON2)->EnableWindow(ListControl.GetItemCount());
}
