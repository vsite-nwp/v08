#pragma once

#include "resource.h"	

class MainDlg : public CDialog
{
public:
	MainDlg(CWnd* pParent = NULL);
	enum { IDD = IDD_V8_DIALOG };

protected:
	void DoDataExchange(CDataExchange* pDX) override;
	HICON m_hIcon;
	BOOL OnInitDialog() override;
	DECLARE_MESSAGE_MAP()

private:
	CListCtrl m_movieList;
	CEdit m_titleInput;
	CEdit m_yearInput;

	afx_msg void OnAddClicked();
	afx_msg void OnRemoveClicked();
};
