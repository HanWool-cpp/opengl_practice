
// OPENGL_TESTDlg.h : 헤더 파일
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

// createprocess
#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#include <ft2build.h>
#include FT_FREETYPE_H 




// opengl text 관련
#include <map>
#include <string>

//사용할 라이브러리를 지정해줍니다.
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "./lib/glew32.lib")

#pragma comment(lib, "./lib/freetyped.lib")

#define PI 3.1415926





// COPENGL_TESTDlg 대화 상자
class COPENGL_TESTDlg : public CDialogEx
{
// 생성입니다.
public:
	COPENGL_TESTDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_OPENGL_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

	

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
	GLuint create_program2();

	GLuint shaderProgram;
	GLuint shaderProgram2;

public:
	afx_msg void OnClose();



	// 1 : 삼각형 , 2 : 글자
	int object_mode;

	unsigned int VAO, VBO, EBO;
	unsigned int VAO2, VBO2;
	unsigned int texture[44];
	float Return_Y(float x1, float y1, float x2, float y2, float input);

	//// opengl text
	FT_Library ft;
	FT_Face face;
	void Setting_Opengl_Text();
	void RenderText(std::string text, float x, float y, float scale, glm::vec3 color);
};
