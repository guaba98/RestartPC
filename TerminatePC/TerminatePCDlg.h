
// TerminatePCDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"


// CTerminatePCDlg 대화 상자
class CTerminatePCDlg : public CDialogEx
{
// 생성입니다.
public:
	CTerminatePCDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TERMINATEPC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
