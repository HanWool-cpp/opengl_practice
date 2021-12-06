
// OPENGL_TESTDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "OPENGL_TEST.h"
#include "OPENGL_TESTDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")    //semicolon이 없음

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


// COPENGL_TESTDlg 메시지 처리기


struct Character {
	unsigned int TextureID; // ID handle of the glyph texture
	glm::ivec2   Size;      // Size of glyph
	glm::ivec2   Bearing;   // Offset from baseline to left/top of glyph
	unsigned int Advance;   // Horizontal offset to advance to next glyph
};

std::map<GLchar, Character> Characters;



BOOL COPENGL_TESTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	//make OpenGL context 
	if (!GetRenderingContext())
	{
		AfxMessageBox(CString("OpenGL error occur : initialization"));
		return -1;
	}

	object_mode = 1;

	/*glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);*/
	
	



	Setting_Draw();
	Setting_Opengl_Text();

	//// 프로세스 불러오기
	//STARTUPINFO si = { 0, };
	//PROCESS_INFORMATION pi;
	//si.cb = sizeof(si);

	//TCHAR command[] = _T("D:\\py_test\\examples\\get_image\\dist\\get_image.exe");
	//SetCurrentDirectory(_T("D:"));

	//CreateProcess(
	//	NULL, command, NULL, NULL,
	//	TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

	SetTimer(1, 1000, NULL);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}


void COPENGL_TESTDlg::Setting_Draw()
{
	// make shader program object 
	shaderProgram = create_program();
	




	/*float vertices[] = {
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f,
	};
*/
	float vertices[] = {
		-0.8f, 0.8f, 0.0f,
		0.8f, 0.8f, 0.0f,
		-0.6f, -0.1f, 0.0f,
		0.8f, 0.8f, 0.0f,
		-0.6f, -0.1f, 0.0f,
		0.6f, -0.1f, 0.0f,
		-0.4f, -0.1f, 0.0f,
		0.4f, -0.1f, 0.0f,
		-0.4f, -0.5f, 0.0f,
		0.4f, -0.1f, 0.0f,
		-0.4f, -0.5f, 0.0f,
		0.4f, -0.5f, 0.0f,
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





	//glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(430), 0.0f, static_cast<float>(430));
	//unsigned int transformLoc = glGetUniformLocation(shaderProgram, "projection");
	//glUseProgram(shaderProgram);
	//glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(projection));

	//glGenVertexArrays(1, &VAO);
	//glGenBuffers(1, &VBO);
	//glBindVertexArray(VAO);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);



}



// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void COPENGL_TESTDlg::OnPaint()
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
HCURSOR COPENGL_TESTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COPENGL_TESTDlg::OnDestroy()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	if (nIDEvent == 1)
	{		
		static int flag = 0;
		if (flag == 0)
		{
			flag = 1;
			 glClearColor((float)25 / 255, (float)45 / 255, (float)47 / 255, 1.0f);
			// glClearColor((float)0 / 255, (float)0 / 255, (float)0 / 255, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



			// draw triangle
			glUseProgram(shaderProgram);



			// RenderText("This is sample text", 0.1f, 0.1f, 1.0f, glm::vec3(1.0, 1.0f, 1.0f));
			// RenderText("(C) LearnOpenGL.com", 300.0f, 300.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));


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
				// printf("radian : %f, x좌표 :%f, y좌표 : %f\n", radian, 0.5f*cos(radian), 0.5f*sin(radian));
				glm::mat4 trans = glm::mat4(1.0f);
				trans = glm::translate(trans, glm::vec3(0.7f*cos(radian*PI / 180), 0.7f*sin(radian*PI / 180), 0.0f));
				trans = glm::rotate(trans, glm::radians(radian - 90.0f), glm::vec3(0.0, 0.0, 1.0));
				trans = glm::scale(trans, glm::vec3(0.05, 0.05, 0.05));

				unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
				glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

				glBindVertexArray(VAO);
				glDrawArrays(GL_TRIANGLES, 0, 12);
			}

			// screen update (if double buffer)
			SwapBuffers(m_pDC->GetSafeHdc());
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

	//참고 http://gamedev.stackexchange.com/a/30443
	GLint attribs[] =
	{
		//OpenGL 3.3 사용
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


	// opengl text
	// m_DefaultFlatTextID = GenerateBitmapListForFonts("Arial");

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


	// else if (object_mode == 2)
	//{
	//	// GLSL
	//	const GLchar* vertexShaderSource =
	//		"#version 330 core\n"
	//		"layout (location = 0) in vec4 vertex;\n"
	//		"out vec2 TexCoords;"
	//		"uniform mat4 projection;"
	//		"void main()\n"
	//		"{\n"
	//		"	gl_Position = projection * vec4(vertex.xy, 0.0, 1.0);\n"
	//		"	TexCoords = vertex.zw;"
	//		//"ourColor = aColor;"
	//		"}\n\0";

	//	const GLchar* fragmentShaderSource =
	//		"#version 330 core\n"
	//		"in vec2 TexCoords;"
	//		"out vec4 color;\n"
	//		// "in vec3 ourColor;"
	//		"uniform sampler2D text;\n"
	//		"uniform vec3 textColor;"
	//		"void main()\n"
	//		"{\n"
	//		"	vec4 sampled = vec4(1.0,1.0,1.0, texture(text, TexCoords).r);"
	//		"	color  = vec4(textColor, 1.0) * sampled;\n"
	//		"}\n\0";


	//	// make and compile vertex shader object 
	//	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	//	glCompileShader(vertexShader);

	//	GLint success;
	//	GLchar infoLog[512];

	//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	//	if (!success)
	//	{
	//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
	//		printf("%S\n", CString("ERROR: vertex shader comile fail ") + CString(infoLog) + CString("\n"));
	//	}

	//	// make and compile fragment shader object 
	//	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	//	glCompileShader(fragmentShader);

	//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	//	if (!success)
	//	{
	//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
	//		printf("%S\n", CString("ERROR: fragment shader compile fail ") + CString(infoLog) + CString("\n"));
	//	}

	//	// make shader program object and attach shader object
	//	GLuint shaderProgram = glCreateProgram();
	//	glAttachShader(shaderProgram, vertexShader);
	//	glAttachShader(shaderProgram, fragmentShader);

	//	glLinkProgram(shaderProgram);

	//	glDeleteShader(vertexShader);
	//	glDeleteShader(fragmentShader);


	//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	//	if (!success) {
	//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);

	//		printf("%S\n", CString("ERROR: shader program link fail ") + CString(infoLog) + CString("\n"));
	//	}
	//}
	//	return shaderProgram;
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	AfxGetMainWnd()->PostMessageW(WM_CLOSE);
	CDialogEx::OnClose();
}

float COPENGL_TESTDlg::Return_Y(float x1, float y1, float x2, float y2, float input)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	float output;

	output = ((y2 - y1)*(input - x1)) / (x2 - x1) + y1;
	return output;
}



void COPENGL_TESTDlg::Setting_Opengl_Text()
{
	// opengl text
	// freetype 정상 작동 체크
	if (FT_Init_FreeType(&ft))
	{
		std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
	}
	if (FT_New_Face(ft, "fonts/Arial.ttf", 0, &face))
	{
		std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
	}
	// freetype 가로세로 크기 결정
	FT_Set_Pixel_Sizes(face, 0, 48);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction

	for (unsigned char c = 0; c < 128; c++)
	{
		// load character glyph 
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
			continue;
		}
		// generate texture
		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			face->glyph->bitmap.width,
			face->glyph->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			face->glyph->bitmap.buffer
			);
		// set texture options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// now store character for later use
		Character character = {
			texture,
			glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
			glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
			face->glyph->advance.x
		};
		Characters.insert(std::pair<char, Character>(c, character));
	}
	glBindTexture(GL_TEXTURE_2D, 0);

	FT_Done_Face(face);
	FT_Done_FreeType(ft);
}


void COPENGL_TESTDlg::RenderText(std::string text, float x, float y, float scale, glm::vec3 color)
{
	// activate corresponding render state	
	glUseProgram(shaderProgram);
	glUniform3f(glGetUniformLocation(shaderProgram, "textColor"), color.x, color.y, color.z);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(VAO);

	// iterate through all characters
	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++)
	{
		Character ch = Characters[*c];

		float xpos = x + ch.Bearing.x * scale;
		float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

		float w = ch.Size.x * scale;
		float h = ch.Size.y * scale;
		// update VBO for each character
		float vertices[6][4] = {
			{ xpos, ypos + h, 0.0f, 0.0f },
			{ xpos, ypos, 0.0f, 1.0f },
			{ xpos + w, ypos, 1.0f, 1.0f },

			{ xpos, ypos + h, 0.0f, 0.0f },
			{ xpos + w, ypos, 1.0f, 1.0f },
			{ xpos + w, ypos + h, 1.0f, 0.0f }
		};
		// render glyph texture over quad
		glBindTexture(GL_TEXTURE_2D, ch.TextureID);
		// update content of VBO memory
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		// render quad
		glDrawArrays(GL_TRIANGLES, 0, 6);
		// now advance cursors for next glyph (note that advance is number of 1/64 pixels)
		x += (ch.Advance >> 6) * scale; // bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}