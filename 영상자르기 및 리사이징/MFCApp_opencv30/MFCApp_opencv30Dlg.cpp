
// MFCApp_opencv30Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MFCApp_opencv30.h"
#include "MFCApp_opencv30Dlg.h"
#include "afxdialogex.h"
#include <time.h>

#define PI 3.14159

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")



// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApp_opencv30Dlg 대화 상자


CMFCApp_opencv30Dlg::CMFCApp_opencv30Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApp_opencv30Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApp_opencv30Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DP_0, m_picture0);
	DDX_Control(pDX, IDC_DP_1, m_picture1);
}

BEGIN_MESSAGE_MAP(CMFCApp_opencv30Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApp_opencv30Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApp_opencv30Dlg::OnBnClickedButton1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFCApp_opencv30Dlg 메시지 처리기

BOOL CMFCApp_opencv30Dlg::OnInitDialog()
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

	// ------------------------------------------------
	// 공유메모리 Mapping
	// ------------------------------------------------


	//SetTimer(1,200,NULL);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApp_opencv30Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApp_opencv30Dlg::OnPaint()
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
HCURSOR CMFCApp_opencv30Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApp_opencv30Dlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CMFCApp_opencv30Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.




	
	


	CDialogEx::OnTimer(nIDEvent);
}


void CMFCApp_opencv30Dlg::OnBnClickedButton1()
{

	// image 를 color로 가져와서 픽셀 get/set

	//w = 0.0010554321;
	w = 0.0012379;
	printf("%lf\n", w);
	cut_image();



}




void	CMFCApp_opencv30Dlg::cut_image()
{
	// 샘플 이미지들 가져오기
	char  filename[300];
	//Mat img;



	// 파일 열기
	char szFilter[] = "All Files(*.*)|*.*|";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, (CString)szFilter);
	CString str_path_and_name;

	// dlg.m_ofn.lpstrInitialDir = FILE_PATH;

	if (IDOK == dlg.DoModal())
	{
		memset(filename, 0, 300);
		str_path_and_name = dlg.GetPathName();
		wsprintfA(filename, "%S", (LPCTSTR)str_path_and_name);

		// 원본 이미지
		IplImage* iplimg;
		iplimg = cvLoadImage(filename, CV_LOAD_IMAGE_UNCHANGED);



		// 원본이미지
		int cutted_width_low = 704;
		int cutted_width_high = 704 + 2696;

		int cutted_height_low = 1036;
		int cutted_height_high = 1036 + 696;



		IplImage* cutted_img;
		cutted_img =
			cvCreateImage(cvSize(CUTTED_IMG_WIDTH, CUTTED_IMG_HEIGHT), IPL_DEPTH_8U, 3);

		cvSetZero(cutted_img);

		//// 원본 이미지 출력
		//CWnd* pWnd = GetDlgItem(IDC_DP_0);
		//CClientDC	dc(pWnd);
		//RECT		rect;
		//pWnd->GetClientRect(&rect);
		//CvvImage	cvv_image;
		//cvv_image.CopyOf(iplimg, -1);
		//cvv_image.DrawToHDC(dc.m_hDC, &rect);


		int cnt = 0;
		clock_t startTime, endTime;
		startTime = clock();

		//영상 자르기
// #pragma omp parallel for
		for (int i = X_START_PIXEL; i < X_END_PIXEL; i++)
			for (int j = Y_START_PIXEL; j < Y_END_PIXEL; j++)
			{
				{
					int B = 0, G = 0, R = 0;
					GetColor(iplimg, i, j, &B, &G, &R);
					SetColor(cutted_img, i - X_START_PIXEL, j - Y_START_PIXEL, B, G, R);
				}
			}



		//cvShowImage("영역 자른 영상", cutted_img);

		cvSaveImage("테스트.png", cutted_img);
		//cvSaveImage("D:\\AVM\\image\\샘플이미지만들기용_영상\\광각렌즈_영상잘라내기(바다)\\cutted_image.png", cutted_img);
		//cvSaveImage("D:\\AVM\\image\\샘플이미지만들기용_영상\\어안렌즈_영상잘라내기(랜드)\\cutted_image.png", cutted_img);
		//cvSaveImage("D:\\AVM\\image\\샘플이미지만들기용_영상\\어안렌즈_영상잘라내기(바다)\\cutted_image.png", cutted_img);
		//리사이징
		//cvResize(cutted_img, iplimg, CV_INTER_LINEAR);


		//endTime = clock();
		//printf("%f\n", (endTime - startTime) / (float)1000.0f);

		//CWnd* pWnd2 = GetDlgItem(IDC_DP_2);
		//CClientDC	dc2(pWnd2);
		//RECT		rect2;
		//pWnd2->GetClientRect(&rect2);
		//CvvImage	cvv_image2;
		//cvv_image2.CopyOf(iplimg, -2);
		//cvv_image2.DrawToHDC(dc2.m_hDC, &rect2);

		// cvSaveImage("D:\\AVM\\image\\샘플이미지만들기용_영상\\어안렌즈_영상잘라내기(랜드)\\resized_image.png", iplimg);
	}


	//GET만 할 시
	//openMP 사용 안할시 : 0.466초
	//openMP 사용 시	 : 0.176

	//GET/SET 할 시
	//openMP 사용 안할시 : 0.85초
	//openMP 사용 할시	:  0.328초
}


void	CMFCApp_opencv30Dlg::cover_black(IplImage* src, int i, int j)
{
	int B, G, R;
	GetColor(src, i, j, &B, &G, &R);
	if ((B == 0) && (G == 0) && (R == 0))
	{
		GetColor(src, i-1, j-1, &B, &G, &R);
		int B1 = B;
		int G1 = G;
		int R1 = R;
		//GetColor(src, i+1, j+1, &B, &G, &R);
		//int B2 = B;
		//int G2 = G;
		//int R2 = R;
		//GetColor(src, i, j-1, &B, &G, &R);
		//int B3 = B;
		//int G3 = G;
		//int R3 = R;
		//GetColor(src, i, j+1, &B, &G, &R);
		//int B4 = B;
		//int G4 = G;
		//int R4 = R;

		//B = (B1 + B2) / 2;
		//G = (G1 + G2) / 2;
		//R = (R1 + R2) / 2;

		SetColor(src, i, j, B, G, R);
	}
}
/*
if ((B == 0) && (G == 0) && (R == 0))
{
	GetColor(src, i - 1, j, &B, &G, &R);
	if (B != 0)
	{
		SetColor(src, i, j, B, G, R);
		return;
	}
	GetColor(src, i + 1, j, &B, &G, &R);
	if (B != 0)
	{
		SetColor(src, i, j, B, G, R);
		return;
	}
	GetColor(src, i, j - 1, &B, &G, &R);
	if (B != 0)
	{
		SetColor(src, i, j, B, G, R);
		return;
	}
	GetColor(src, i, j + 1, &B, &G, &R);
	if (B != 0)
	{
		SetColor(src, i, j, B, G, R);
		return;
	}
	*/







void CMFCApp_opencv30Dlg::GetColor(IplImage* src, int i, int j, int *blue, int *green, int *red)
{
	if (i<0 || j<0)	return;
	if (i> src->width - 1)	return;
	if (j> src->height - 1) return;

	*blue = src->imageData[i * src->nChannels + j*src->widthStep + 0];
	*green = src->imageData[i * src->nChannels + j*src->widthStep + 1];
	*red = src->imageData[i * src->nChannels + j*src->widthStep + 2];

	return;
}

void CMFCApp_opencv30Dlg::SetColor(IplImage* src, int i, int j, int blue, int green, int red)
{
	if (i<0 || j<0)	return;
	if (i> src->width - 1)	return;
	if (j> src->height - 1) return;

	src->imageData[i * src->nChannels + j*src->widthStep + 0] = (uchar)blue;
	src->imageData[i * src->nChannels + j*src->widthStep + 1] = (uchar)green;
	src->imageData[i * src->nChannels + j*src->widthStep + 2] = (uchar)red;

	return;
}





void CMFCApp_opencv30Dlg::CreateBitmapInfo(int w, int h, int bpp)
{
	if (m_pBitmapInfo != NULL)
	{
		delete[]m_pBitmapInfo;
		m_pBitmapInfo = NULL;
	}

	if (bpp == 8)
		m_pBitmapInfo = (BITMAPINFO *) new BYTE[sizeof(BITMAPINFO) + 255 * sizeof(RGBQUAD)];
	else // 24 or 32bit
		m_pBitmapInfo = (BITMAPINFO *) new BYTE[sizeof(BITMAPINFO)];

	m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_pBitmapInfo->bmiHeader.biPlanes = 1;
	m_pBitmapInfo->bmiHeader.biBitCount = bpp;
	m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;
	m_pBitmapInfo->bmiHeader.biSizeImage = 0;
	m_pBitmapInfo->bmiHeader.biXPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biYPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biClrUsed = 0;
	m_pBitmapInfo->bmiHeader.biClrImportant = 0;

	if (bpp == 8)
	{
		for (int i = 0; i < 256; i++)
		{
			m_pBitmapInfo->bmiColors[i].rgbBlue = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbGreen = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbRed = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbReserved = 0;
		}
	}

	m_pBitmapInfo->bmiHeader.biWidth = w;
	m_pBitmapInfo->bmiHeader.biHeight = -h;
}

void CMFCApp_opencv30Dlg::DrawImage()
{
	//CClientDC dc(GetDlgItem(IDC_DP_0));

	//CRect rect;
	//GetDlgItem(IDC_DP_0)->GetClientRect(&rect);

	//SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);
	//StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, img.cols, img.rows, img.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
}


