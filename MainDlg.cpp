#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent /*=NULL*/) : CDialog(MainDlg::IDD, pParent)
, year(2020)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list);
	DDX_Text(pDX, IDC_EDIT1, title);
	DDV_MaxChars(pDX, title, 50);
	DDX_Text(pDX, IDC_EDIT2, year);
	DDV_MinMaxUInt(pDX, year, 1895, 2020);	
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::AddRow)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::DeleteRow)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	list.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 140);
	list.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 60);
	list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(0);
	return TRUE;
}

int MainDlg::checkInput(CString& title, CString& year)
{
	if (title == "" || year == "")
	{
		MessageBox(_T("Nemože!"), "Vojko kaže...", MB_OK | MB_ICONWARNING);
		return 1;
	}
	title.TrimLeft();
	year.TrimLeft(" +");
	if (title.IsEmpty())
	{
		MessageBox(_T("...the final frontier..."), "Space...", MB_OK | MB_ICONWARNING);
		return 2;
	}
	year.Format("%d", _ttoi(year));
	if (!UpdateData(true))
		return 3;
	return 0;
}


void MainDlg::AddRow()
{
	noOfRows = list.GetItemCount();
	CString title, year;
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);
	if (checkInput(title, year))
		return;
	list.InsertItem(noOfRows, title);
	list.SetItemText(noOfRows, 1, year);
	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
	GetDlgItem(IDC_EDIT1)->SetFocus();
	GetDlgItem(IDC_BUTTON2)->EnableWindow(1);
}


void MainDlg::DeleteRow()
{
	if (list.GetNextItem(-1, LVNI_SELECTED) != -1)
		list.DeleteItem((list.GetNextItem(-1, LVNI_SELECTED)));
	GetDlgItem(IDC_EDIT1)->SetFocus();
	if (noOfRows == 0)
		GetDlgItem(IDC_BUTTON2)->EnableWindow(0);
}
