#pragma once

#include "resource.h"	
#include "afxcmn.h"

class MainDlg : public CDialog
{
public:
	CListCtrl cList;
	MainDlg(CWnd* pParent = NULL);	// standard constructor
	enum { IDD = IDD_V8_DIALOG };
	afx_msg void addOnClick();
	afx_msg void deleteOnClick();
protected:
	void DoDataExchange(CDataExchange* pDX) override;
	HICON m_hIcon;
	BOOL OnInitDialog() override;
	DECLARE_MESSAGE_MAP();
};
