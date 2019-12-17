#pragma once

#include "StdAfx.h"
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
private:

	afx_msg void OnAddButton();
	afx_msg void OnDeleteButton();
	CListCtrl mListControl;
};
