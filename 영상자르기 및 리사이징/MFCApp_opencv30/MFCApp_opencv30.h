
// MFCApp_opencv30.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFCApp_opencv30App:
// �� Ŭ������ ������ ���ؼ��� MFCApp_opencv30.cpp�� �����Ͻʽÿ�.
//

class CMFCApp_opencv30App : public CWinApp
{
public:
	CMFCApp_opencv30App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFCApp_opencv30App theApp;