
// MFCApp_opencv30Dlg.cpp : ���� ����
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



// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	// �����Դϴ�.
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


// CMFCApp_opencv30Dlg ��ȭ ����


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


// CMFCApp_opencv30Dlg �޽��� ó����

BOOL CMFCApp_opencv30Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	// ------------------------------------------------
	// �����޸� Mapping
	// ------------------------------------------------


	//SetTimer(1,200,NULL);


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFCApp_opencv30Dlg::OnPaint()
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
HCURSOR CMFCApp_opencv30Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApp_opencv30Dlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnOK();
}


void CMFCApp_opencv30Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.




	
	


	CDialogEx::OnTimer(nIDEvent);
}


void CMFCApp_opencv30Dlg::OnBnClickedButton1()
{

	// image �� color�� �����ͼ� �ȼ� get/set

	//w = 0.0010554321;
	w = 0.0012379;
	printf("%lf\n", w);
	cut_image();



}




void	CMFCApp_opencv30Dlg::cut_image()
{
	// ���� �̹����� ��������
	char  filename[300];
	//Mat img;



	// ���� ����
	char szFilter[] = "All Files(*.*)|*.*|";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, (CString)szFilter);
	CString str_path_and_name;

	// dlg.m_ofn.lpstrInitialDir = FILE_PATH;

	if (IDOK == dlg.DoModal())
	{
		memset(filename, 0, 300);
		str_path_and_name = dlg.GetPathName();
		wsprintfA(filename, "%S", (LPCTSTR)str_path_and_name);

		// ���� �̹���
		IplImage* iplimg;
		iplimg = cvLoadImage(filename, CV_LOAD_IMAGE_UNCHANGED);



		// �����̹���
		int cutted_width_low = 704;
		int cutted_width_high = 704 + 2696;

		int cutted_height_low = 1036;
		int cutted_height_high = 1036 + 696;



		IplImage* cutted_img;
		cutted_img =
			cvCreateImage(cvSize(CUTTED_IMG_WIDTH, CUTTED_IMG_HEIGHT), IPL_DEPTH_8U, 3);

		cvSetZero(cutted_img);

		//// ���� �̹��� ���
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

		//���� �ڸ���
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



		//cvShowImage("���� �ڸ� ����", cutted_img);

		cvSaveImage("�׽�Ʈ.png", cutted_img);
		//cvSaveImage("D:\\AVM\\image\\�����̹���������_����\\��������_�����߶󳻱�(�ٴ�)\\cutted_image.png", cutted_img);
		//cvSaveImage("D:\\AVM\\image\\�����̹���������_����\\��ȷ���_�����߶󳻱�(����)\\cutted_image.png", cutted_img);
		//cvSaveImage("D:\\AVM\\image\\�����̹���������_����\\��ȷ���_�����߶󳻱�(�ٴ�)\\cutted_image.png", cutted_img);
		//������¡
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

		// cvSaveImage("D:\\AVM\\image\\�����̹���������_����\\��ȷ���_�����߶󳻱�(����)\\resized_image.png", iplimg);
	}


	//GET�� �� ��
	//openMP ��� ���ҽ� : 0.466��
	//openMP ��� ��	 : 0.176

	//GET/SET �� ��
	//openMP ��� ���ҽ� : 0.85��
	//openMP ��� �ҽ�	:  0.328��
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


