
// TerminatePCDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "TerminatePC.h"
#include "TerminatePCDlg.h"
#include "afxdialogex.h"

#include <winsock2.h>
#include <iphlpapi.h>
#include <icmpapi.h>
#include <ws2tcpip.h>  // inet_pton 함수가 포함된 헤더
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static _TCHAR *_gszL1Label[2] = { _T("Date/Time"), _T("Detail System Log") };
static int _gnLColumnWidth[2] = { 150, 250 };

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTerminatePCDlg 대화 상자



CTerminatePCDlg::CTerminatePCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TERMINATEPC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTerminatePCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListLog);
}

BEGIN_MESSAGE_MAP(CTerminatePCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_PING_TEST, &CTerminatePCDlg::OnBnClickedBtnPingTest)
END_MESSAGE_MAP()


// CTerminatePCDlg 메시지 처리기

BOOL CTerminatePCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_ListCtrlfont.CreatePointFont(100, _T("맑은 고딕"));
	m_ListLog.SetFont(&m_ListCtrlfont);

	m_ListLog.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	for (int i = 0; i < 2; i++)
	{
		m_ListLog.InsertColumn(i, _gszL1Label[i], LVCFMT_CENTER, _gnLColumnWidth[i]);
	}




	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTerminatePCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTerminatePCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTerminatePCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CTerminatePCDlg::CheckPing()
{
	BOOL bChkInternet;
	int nMaxTime = 10;
	char* SendData = "Check TCP/IP";
	CString StrLog;

	HANDLE hIcmpFile;
	DWORD dwRetVal;
	LPVOID ReplyBuffer;
	DWORD ReplySize;
	struct sockaddr_in dest;
	PICMP_ECHO_REPLY pEchoReply;

	// ICMP 핸들 생성
	hIcmpFile = IcmpCreateFile();
	if (hIcmpFile == INVALID_HANDLE_VALUE)
	{
		AfxMessageBox(_T("IcmpCreateFile 실패"), MB_OK);
		return FALSE;
	}

	// IP 주소 변환 (inet_pton 사용)
	memset(&dest, 0, sizeof(dest));
	dest.sin_family = AF_INET;  // IPv4
	if (inet_pton(AF_INET, "192.168.1.201", &(dest.sin_addr)) != 1)
	{
		AfxMessageBox(_T("inet_pton 실패"), MB_OK);
		IcmpCloseHandle(hIcmpFile);
		return FALSE;
	}

	// ReplyBuffer 할당
	ReplySize = sizeof(ICMP_ECHO_REPLY) + sizeof(SendData);
	ReplyBuffer = (VOID*)malloc(ReplySize);
	if (ReplyBuffer == NULL)
	{
		AfxMessageBox(_T("메모리 할당 실패"), MB_OK);
		IcmpCloseHandle(hIcmpFile);
		return FALSE;
	}

	while (nMaxTime > 0)
	{
		// Ping 보내기
		bChkInternet = IcmpSendEcho(
			hIcmpFile,
			dest.sin_addr.s_addr,  // 변환된 IP 주소 사용
			SendData,
			(WORD)strlen(SendData),
			NULL,
			ReplyBuffer,
			ReplySize,
			1000);  // 타임아웃 1초

		pEchoReply = (PICMP_ECHO_REPLY)ReplyBuffer;

		if (bChkInternet)
		{
			// Ping 성공 시 결과 출력
			StrLog.Format(_T("바이트=%d 시간<%lums TTL=%d\n"),
				pEchoReply->DataSize,
				pEchoReply->RoundTripTime,
				pEchoReply->Options.Ttl);
		}
		else
		{
			// Ping 실패 시 오류 코드 출력
			DWORD dwError = GetLastError();  // 에러 코드 가져오기
			StrLog.Format(_T("Ping 실패: 오류 코드 %lu\n"), dwError);
		}

		AddtoSystemLogList(StrLog, false);

		Sleep(1000);  // 1초에 한 번씩 Ping 실행
		nMaxTime--;
	}

	// 핸들 및 메모리 해제
	free(ReplyBuffer);
	IcmpCloseHandle(hIcmpFile);

	return TRUE;
}


void CTerminatePCDlg::OnBnClickedBtnPingTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CheckPing();
}

void CTerminatePCDlg::AddtoSystemLogList(CString strData, int nLogName)
{
	WriteSystemAlarmLogtoLogList(strData, nLogName);
}

void CTerminatePCDlg::WriteSystemAlarmLogtoLogList(CString strData, int nLogName /*0: SystemLog, 1: AlarmLog*/)
{
	CString strTime, strWriteLog;
	CTime time = CTime::GetCurrentTime();
	strTime = time.Format(_T("[%Y/%m/%d] [%H:%M:%S]"));

	strWriteLog.Format(_T("%s	%s"), strTime, strData);

	if (strData == _T(""))
	{
		return;
	}


	if (nLogName == 0)
	{
		int nNum = m_ListLog.GetItemCount();
		CString strTemp;

		m_ListLog.InsertItem(nNum, NULL);
		m_ListLog.SetItemText(nNum, 0, strTime);

		strTemp.Format(_T("%s"), strData);
		m_ListLog.SetItemText(nNum, 1, strTemp);


		if (nNum == 1000) {
			m_ListLog.DeleteAllItems();
		}
	}
}