
// SampleDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CSampleDlg dialog
class CSampleDlg : public CDialogEx
{
// Construction
public:
	CSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SAMPLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnCbnSelchangeCombo1();
	CString m_number;
	afx_msg void OnBnClickedButton1();
	CString m_strName;
	CString m_hobbies;
	CString m_language;
	CString m_search;
	int m_male;
	int m_female;
	CComboBox m_combobox;
	
	CListCtrl m_lstIDC_LIST1Control;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
};
