
// TerminatePC.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTerminatePCApp:
// �� Ŭ������ ������ ���ؼ��� TerminatePC.cpp�� �����Ͻʽÿ�.
//

class CTerminatePCApp : public CWinApp
{
public:
	CTerminatePCApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CTerminatePCApp theApp;