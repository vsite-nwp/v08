#pragma once

#include "resource.h"	

class MainDlg : public CDialog
{
public:
	MainDlg(CWnd* pParent = NULL);	// standard constructor
	enum { IDD = IDD_V8_DIALOG };

protected:
	void DoDataExchange(CDataExchange* pDX) override;
	HICON m_hIcon;
	BOOL OnInitDialog() override;
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl movie_list;
	CButton add_btn;
	CButton delete_btn;
	CEdit title_edit;
	CEdit year_edit;
	afx_msg void AddButtonClicked();
	afx_msg void DeleteButtonClicked();
};
