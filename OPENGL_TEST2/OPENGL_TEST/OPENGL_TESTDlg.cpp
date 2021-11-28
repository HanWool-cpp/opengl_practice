
// OPENGL_TESTDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "OPENGL_TEST.h"
#include "OPENGL_TESTDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")    //semicolon�� ����

COPENGL_TESTDlg::COPENGL_TESTDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COPENGL_TESTDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COPENGL_TESTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEST_P, m_test_p);
}

BEGIN_MESSAGE_MAP(COPENGL_TESTDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// COPENGL_TESTDlg �޽��� ó����

BOOL COPENGL_TESTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	//make OpenGL context 
	if (!GetRenderingContext())
	{
		AfxMessageBox(CString("OpenGL error occur : initialization"));
		return -1;
	}

	Setting_Draw();

	//// ���μ��� �ҷ�����
	//STARTUPINFO si = { 0, };
	//PROCESS_INFORMATION pi;
	//si.cb = sizeof(si);

	//TCHAR command[] = _T("D:\\py_test\\examples\\get_image\\dist\\get_image.exe");
	//SetCurrentDirectory(_T("D:"));

	//CreateProcess(
	//	NULL, command, NULL, NULL,
	//	TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

	SetTimer(1, 1000, NULL);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}


void COPENGL_TESTDlg::Setting_Draw()
{
	// make shader program object 
	shaderProgram = create_program();
	
	float vertices[] = {
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};


	// make VAO, VBO object
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind VAO
	glBindVertexArray(VAO);
	// bind VBO and allocate data on GPU
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//  configure vertex attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	//glEnableVertexAttribArray(1);
	// release binding of VAO, VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);	
}



// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void COPENGL_TESTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR COPENGL_TESTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COPENGL_TESTDlg::OnDestroy()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	if (FALSE == ::wglDeleteContext(m_hRC))
	{
		printf("%S\n", CString("wglDeleteContext failed"));
	}

	CDialogEx::OnDestroy();
}


void COPENGL_TESTDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	if (nIDEvent == 1)
	{		

		//for (int i = 0; i < 44; i++)
		//{
		//	{
		//		// float greenValue = sin(timeValue) / 2.0f + 0.5f;
		//		int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
		//		object_color_R = 0;		 object_color_G = 1.0;		 object_color_B = 0;
		//		glUniform4f(vertexColorLocation, object_color_R, object_color_G, object_color_B, 1.0f);

		//		// transform
		//		float radian = Return_Y(0,-180, 43, 180, i);


		//		glm::mat4 trans = glm::mat4(1.0f);
		//		trans = glm::translate(trans, glm::vec3(0.3f, 0.0f, 0.0f));
		//		trans = glm::rotate(trans, glm::radians(radian), glm::vec3(0.0, 0.0, 1.0));
		//		trans = glm::scale(trans, glm::vec3(0.1, 0.1, 0.1));

		//		unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
		//		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

		//		glBindVertexArray(VAO);
		//		glDrawArrays(GL_TRIANGLES, 0, 3);
		//	}
		//}
		static int flag = 0;
		if (flag == 0)
		{
			flag = 1;
			glClearColor((float)25 / 255, (float)45 / 255, (float)47 / 255, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// draw triangle
			glUseProgram(shaderProgram);

			// update the uniform color
			static float object_color_R = 0;
			static float object_color_G = 0;
			static float object_color_B = 0;

			for (int i = 0; i < 44; i++)
			{
				// float greenValue = sin(timeValue) / 2.0f + 0.5f;
				int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
				object_color_R = 0;		 object_color_G += 0.025;	 object_color_B = 0;
				glUniform4f(vertexColorLocation, object_color_R, object_color_G, object_color_B, 1.0f);

				object_color_G += 0.025;

				// transform
				float radian = Return_Y(0, 360, 44, 0, i);
				printf("radian : %f, x��ǥ :%f, y��ǥ : %f\n", radian, 0.5f*cos(radian), 0.5f*sin(radian));
				glm::mat4 trans = glm::mat4(1.0f);
				trans = glm::translate(trans, glm::vec3(0.7f*cos(radian*PI / 180), 0.7f*sin(radian*PI / 180), 0.0f));
				trans = glm::rotate(trans, glm::radians(radian - 90.0f), glm::vec3(0.0, 0.0, 1.0));
				trans = glm::scale(trans, glm::vec3(0.05, 0.05, 0.05));

				unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
				glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

				glBindVertexArray(VAO);
				glDrawArrays(GL_TRIANGLES, 0, 3);
			}
			// screen update (if double buffer)
			SwapBuffers(m_pDC->GetSafeHdc());
		}
		{
			//// float greenValue = sin(timeValue) / 2.0f + 0.5f;
			//int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
			//object_color_R = 0;		 object_color_G = 1.0;		 object_color_B = 0;
			//glUniform4f(vertexColorLocation, object_color_R, object_color_G, object_color_B, 1.0f);

			//// transform
			//glm::mat4 trans = glm::mat4(1.0f);
			//trans = glm::translate(trans, glm::vec3(-0.3f, 0.0f, 0.0f));
			//trans = glm::rotate(trans, glm::radians(180.0f), glm::vec3(0.0, 0.0, 1.0));
			//trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));

			//unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
			//glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

			//glBindVertexArray(VAO);
			//glDrawArrays(GL_TRIANGLES, 0, 3);
		}

		

	}
	
	CDialogEx::OnTimer(nIDEvent);
}

BOOL COPENGL_TESTDlg::GetRenderingContext()
{
	// draw on picture control
	CWnd* pImage = GetDlgItem(IDC_TEST_P);
	CRect rc;
	pImage->GetWindowRect(rc);
	m_pDC = pImage->GetDC();
	
	if (NULL == m_pDC)
	{
		AfxMessageBox(CString("Unable to get a DC"));
		return FALSE;
	}
	
	if (!GetOldStyleRenderingContext())
	{
		return TRUE;
	}
	
	//Get access to modern OpenGL functionality from this old style context.
	glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit())
	{
		AfxMessageBox(CString("GLEW could not be initialized!"));
		return FALSE;
	}

	//Get a new style pixel format
	if (!SetupPixelFormat())
	{
		return FALSE;
	}

	//���� http://gamedev.stackexchange.com/a/30443
	GLint attribs[] =
	{
		//OpenGL 3.3 ���
		WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
		WGL_CONTEXT_MINOR_VERSION_ARB, 3,
		// Uncomment this for forward compatibility mode
		//WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
		// Uncomment this for Compatibility profile
		//WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB,
		// We are using Core profile here
		WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
		0
	};


	HGLRC CompHRC = wglCreateContextAttribsARB(m_pDC->GetSafeHdc(), 0, attribs);
	if (CompHRC && wglMakeCurrent(m_pDC->GetSafeHdc(), CompHRC))
		m_hRC = CompHRC;

	return TRUE;
}


GLuint COPENGL_TESTDlg::create_program() {
	
	// GLSL
	const GLchar* vertexShaderSource =
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		//"layout (location = 1) in vec3 aColor;"
		"uniform mat4 transform;\n"
		//"out vec3 ourColor;"

		"void main()\n"
		"{\n"
		"	gl_Position = transform * vec4(aPos, 1.0);\n"
		//"ourColor = aColor;"
		
		"}\n\0";
	
	const GLchar* fragmentShaderSource =
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		// "in vec3 ourColor;"
		"uniform vec4 ourColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = ourColor;\n"
		"}\n\0";
	
	// make and compile vertex shader object 
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLint success;
	GLchar infoLog[512];

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		printf("%S\n", CString("ERROR: vertex shader comile fail ") + CString(infoLog) + CString("\n"));
	}

	// make and compile fragment shader object 
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		printf("%S\n", CString("ERROR: fragment shader compile fail ") + CString(infoLog) + CString("\n"));
	}

	// make shader program object and attach shader object
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	
	
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);

		printf("%S\n", CString("ERROR: shader program link fail ") + CString(infoLog) + CString("\n"));
	}

	return shaderProgram;
}

BOOL COPENGL_TESTDlg::GetOldStyleRenderingContext()
{
	//A generic pixel format descriptor. This will be replaced with a more
	//specific and modern one later, so don't worry about it too much.
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW |            // support window
		PFD_SUPPORT_OPENGL |            // support OpenGL
		PFD_DOUBLEBUFFER,               // double buffered
		PFD_TYPE_RGBA,                  // RGBA type
		32,                             // 32-bit color depth
		0, 0, 0, 0, 0, 0,               // color bits ignored
		0,                              // no alpha buffer
		0,                              // shift bit ignored
		0,                              // no accumulation buffer
		0, 0, 0, 0,                     // accum bits ignored
		24,                        // 24-bit z-buffer
		0,                              // no stencil buffer
		0,                              // no auxiliary buffer
		PFD_MAIN_PLANE,                 // main layer
		0,                              // reserved
		0, 0, 0                         // layer masks ignored
	};

	// Get the id number for the best match supported by the hardware device context
	// to what is described in pfd
	int pixelFormat = ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd);

	//If there's no match, report an error
	if (0 == pixelFormat)
	{
		AfxMessageBox(CString("ChoosePixelFormat failed"));
		return FALSE;
	}

	//If there is an acceptable match, set it as the current 
	if (FALSE == SetPixelFormat(m_pDC->GetSafeHdc(), pixelFormat, &pfd))
	{
		AfxMessageBox(CString("SetPixelFormat failed"));
		return FALSE;
	}

	//Create a context with this pixel format
	if (0 == (m_hRC = wglCreateContext(m_pDC->GetSafeHdc())))
	{
		AfxMessageBox(CString("wglCreateContext failed"));
		return FALSE;
	}

	//Make it current. 
	if (FALSE == wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC))
	{
		AfxMessageBox(CString("wglMakeCurrent failed"));
		return FALSE;
	}
	return TRUE;
}

BOOL COPENGL_TESTDlg::SetupPixelFormat()
{
	//This is a modern pixel format attribute list.
	//It has an extensible structure. Just add in more argument pairs 
	//befroe the null to request more features.
	const int attribList[] =
	{
		WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
		WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
		WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
		WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
		WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
		WGL_COLOR_BITS_ARB, 32,
		WGL_DEPTH_BITS_ARB, 24,
		WGL_STENCIL_BITS_ARB, 8,
		0, 0  //End
	};


	unsigned int numFormats;
	int pixelFormat;
	PIXELFORMATDESCRIPTOR pfd;

	//Select a pixel format number
	wglChoosePixelFormatARB(m_pDC->GetSafeHdc(), attribList, NULL, 1, &pixelFormat, &numFormats);

	//Optional: Get the pixel format's description. We must provide a 
	//description to SetPixelFormat(), but its contents mean little.
	//According to MSDN: 
	//  The system's metafile component uses this structure to record the logical
	//  pixel format specification. The structure has no other effect upon the
	//  behavior of the SetPixelFormat function.
	DescribePixelFormat(m_pDC->GetSafeHdc(), pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

	//// Set it as the current 
	//if (FALSE == SetPixelFormat(m_pDC->GetSafeHdc(), pixelFormat, &pfd))
	//{
	//	AfxMessageBox(CString("SelectPixelFormat failed"));
	//	return FALSE;
	//}

	return TRUE;
}

void COPENGL_TESTDlg::OnClose()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	AfxGetMainWnd()->PostMessageW(WM_CLOSE);
	CDialogEx::OnClose();
}

float COPENGL_TESTDlg::Return_Y(float x1, float y1, float x2, float y2, float input)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	float output;

	output = ((y2 - y1)*(input - x1)) / (x2 - x1) + y1;
	return output;
}
