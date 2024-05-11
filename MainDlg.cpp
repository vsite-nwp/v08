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
	DDX_Control(pDX, IDC_LIST1, list);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	LVCOLUMN lvColumn1;
	lvColumn1.mask = LVCF_TEXT | LVCF_WIDTH;
	lvColumn1.cx = 200;
	lvColumn1.pszText = _T("Title");
	
	LVCOLUMN lvColumn2;
	lvColumn2.mask = LVCF_TEXT | LVCF_WIDTH;
	lvColumn2.cx = 50;
	lvColumn2.pszText = _T("Year");

	list.InsertColumn(0, &lvColumn1);
	list.InsertColumn(1, &lvColumn2);

	return TRUE;
}

