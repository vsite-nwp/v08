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
	//DDX_Control(pDX, IDC_LIST1, listCntrl);
	DDX_Control(pDX, IDC_LIST1, cList);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::addOnClick)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::deleteOnClick)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	cList.InsertColumn(0, "Title", LVCFMT_LEFT, 50);
	cList.InsertColumn(1, "Year", LVCFMT_LEFT, 50);
	cList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	return TRUE;
}



void MainDlg::addOnClick()
{
	CString title, year;

	GetDlgItemTextA(IDC_EDIT1, title);
	GetDlgItemTextA(IDC_EDIT2, year);
	if (title == "" && year == "")
		return;
	cList.InsertItem(0, title);
	cList.SetItemText(0, 1, year);
}


void MainDlg::deleteOnClick()
{
	cList.DeleteItem(cList.GetNextItem(-1, LVNI_SELECTED));
}



