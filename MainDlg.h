#pragma once

#include "resource.h"	

class MainDlg : public CDialog
{
public:
	MainDlg(CWnd* pParent = NULL);	// standard constructor
	enum { IDD = IDD_V8_DIALOG };

protected:
	CListCtrl cList;
	void DoDataExchange(CDataExchange* pDX) override;
	HICON m_hIcon;
	BOOL OnInitDialog() override;
	afx_msg void addOnClick();
	afx_msg void deleteOnClick();
	DECLARE_MESSAGE_MAP()
};
