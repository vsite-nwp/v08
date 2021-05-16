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
	, titleEdit(_T(""))
	, yearEdit(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, movieList);
	DDX_Text(pDX, IDC_EDIT1, titleEdit);
	DDV_MaxChars(pDX, titleEdit, 255);
	DDX_Text(pDX, IDC_EDIT2, yearEdit);
	DDV_MinMaxInt(pDX, yearEdit, 1900, 2021);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAddClickedButton)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDeleteClickedButton)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	movieList.InsertColumn(0, "Title", LVCFMT_LEFT, 100);
	movieList.InsertColumn(1, "Year", LVCFMT_LEFT, 100);
	movieList.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	return TRUE;
}



void MainDlg::OnAddClickedButton()
{
	UpdateData();
	CString t=(CString)(std::to_wstring(yearEdit).c_str());

	if(yearEdit > 1900 && yearEdit < 2021){

		movieList.InsertItem(0, titleEdit);
		movieList.SetItemText(0, 1, t);

		yearEdit = 0;
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
	}
}


void MainDlg::OnDeleteClickedButton()
{
	movieList.DeleteItem(movieList.GetNextItem(-1, LVNI_SELECTED));
}
