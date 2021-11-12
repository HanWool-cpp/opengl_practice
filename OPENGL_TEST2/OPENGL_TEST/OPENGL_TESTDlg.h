
// OPENGL_TESTDlg.h : ��� ����
//

#pragma once
// #include <glad/glad.h> 
// #include <GLFW/glfw3.h>
#include "stdio.h"
#include "afxwin.h"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "./include/GL/glew.h"
#include "./include/GL/wglew.h"

#include <iostream>

//����� ���̺귯���� �������ݴϴ�.
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "./lib/glew32.lib")

// COPENGL_TESTDlg ��ȭ ����
class COPENGL_TESTDlg : public CDialogEx
{
// �����Դϴ�.
public:
	COPENGL_TESTDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_OPENGL_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

	

// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void Setting_Draw();


	CStatic m_test_p;
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

// opengl
protected:
	virtual BOOL GetOldStyleRenderingContext(void);
	virtual BOOL SetupPixelFormat(void);

private:
	//OpenGL Setup
	BOOL GetRenderingContext();
	//Rendering Context and Device Context Pointers
	HGLRC     m_hRC;
	CDC*      m_pDC;
	
	GLuint create_program();

	GLuint shaderProgram;

public:
	afx_msg void OnClose();






	unsigned int VAO, VBO, EBO;
};