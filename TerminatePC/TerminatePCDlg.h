
// TerminatePCDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CTerminatePCDlg ��ȭ ����
class CTerminatePCDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CTerminatePCDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TERMINATEPC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	BOOL CheckPing();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnPingTest();
	CListCtrl m_ListLog;
	CFont m_ListCtrlfont;
	void AddtoSystemLogList(CString strData, int nLogName);
	void WriteSystemAlarmLogtoLogList(CString strData, int nLogName /*0: SystemLog, 1: AlarmLog*/);
};
