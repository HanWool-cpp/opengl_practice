
// OPENGL_TEST.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// COPENGL_TESTApp:
// �� Ŭ������ ������ ���ؼ��� OPENGL_TEST.cpp�� �����Ͻʽÿ�.
//

class COPENGL_TESTApp : public CWinApp
{
public:
	COPENGL_TESTApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern COPENGL_TESTApp theApp;