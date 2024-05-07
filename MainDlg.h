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
	afx_msg void addButton_Clicked();
	afx_msg void deleteButton_Clicked();
	afx_msg void clearAllButton_Clicked();
	CEdit titleEdit;
	CEdit yearEdit;
	CListCtrl movieDetail_list;
};
