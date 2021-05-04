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
	DDX_Control(pDX, IDC_LIST1, movie_list);
	DDX_Control(pDX, IDC_BUTTON1, add_btn);
	DDX_Control(pDX, IDC_BUTTON2, delete_btn);
	DDX_Control(pDX, IDC_EDIT1, title_edit);
	DDX_Control(pDX, IDC_EDIT2, year_edit);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::AddButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::DeleteButtonClicked)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	if (movie_list.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 100) == -1) return FALSE;
	if (movie_list.InsertColumn(1, _T("Year"), LVCFMT_CENTER, 60) == -1) return FALSE;
	movie_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	return TRUE;
}



void MainDlg::AddButtonClicked()
{
	CString title_to_add;
	CString year_to_add;
	if (GetDlgItemText(IDC_EDIT1, title_to_add) != 0 && GetDlgItemText(IDC_EDIT2, year_to_add) != 0)
	{
		int list_size = movie_list.GetItemCount();
		movie_list.InsertItem(list_size, title_to_add);
		movie_list.SetItemText(list_size, 1, year_to_add);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
	}
	else 
	{
		MessageBox("Title or year cannot be empty", "Error inserting!", MB_OK); 
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
	}
}

//LVIS_SELECTED

void MainDlg::DeleteButtonClicked()
{
	int selected_row_index = movie_list.GetNextItem(-1, LVNI_SELECTED);
	if (selected_row_index != -1) 
	{
		movie_list.DeleteItem(selected_row_index);

		//TODO: Implement selecting row above the deleted row
		/*if (selected_row_index > 0)
		{
			movie_list.SetItemState(selected_row_index - 1, LVNI_SELECTED, 0);
		}*/
		return;
	}
	MessageBox("No row is selected!", "Error!", MB_OK);


}
