
// MFCApp_opencv30Dlg.h : ��� ����
//

#pragma once

#include "CvvImage.h"
#include "afxwin.h"
#if defined(_MSC_VER) && _MSC_VER >= 1400
#pragma warning(disable: 4995)
#pragma warning (disable:4996)
#endif


#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#pragma comment(lib, "opencv_calib3d2410d")
#pragma comment(lib, "opencv_contrib2410d")
#pragma comment(lib, "opencv_core2410d")
#pragma comment(lib, "opencv_features2d2410d")
#pragma comment(lib, "opencv_flann2410d")
#pragma comment(lib, "opencv_gpu2410d")
#pragma comment(lib, "opencv_highgui2410d")
#pragma comment(lib, "opencv_imgproc2410d")
#pragma comment(lib, "opencv_legacy2410d")
#pragma comment(lib, "opencv_ml2410d")
#pragma comment(lib, "opencv_nonfree2410d")
#pragma comment(lib, "opencv_objdetect2410d")
#pragma comment(lib, "opencv_photo2410d")
#pragma comment(lib, "opencv_stitching2410d")
#pragma comment(lib, "opencv_superres2410d")
#pragma comment(lib, "opencv_ts2410d")
#pragma comment(lib, "opencv_video2410d")
#pragma comment(lib, "opencv_videostab2410d")


using namespace cv;
using namespace std;


#define PP_IMG_WIDTH		(double)(10.88)
#define PP_IMG_HEIGHT		(double)(8.06)

#define PIXEL_PER_CM		(double)37.79490359346857

#define CUTTED_IMG_WIDTH	(int)(PIXEL_PER_CM * PP_IMG_WIDTH) 
#define CUTTED_IMG_HEIGHT	(int)(PIXEL_PER_CM * PP_IMG_HEIGHT) 

#define X_START_PIXEL		0
#define X_END_PIXEL			(X_START_PIXEL + CUTTED_IMG_WIDTH)

#define Y_START_PIXEL		0
#define Y_END_PIXEL			(Y_START_PIXEL + CUTTED_IMG_HEIGHT)

// #define FILE_PATH			L"D:\\������Ʈ\\9. �Ҳɰ���\\template_img\\";

// CMFCApp_opencv30Dlg ��ȭ ����
class CMFCApp_opencv30Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMFCApp_opencv30Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MFCAPP_OPENCV30_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();


	vector<vector<Point3f>> object_points;
	vector<vector<Point2f>> imagePoints;
	vector<Point2f> pointBuf;
	BITMAPINFO *m_pBitmapInfo; // Bitmap ������ ��� �ִ� ����ü.
	void CreateBitmapInfo(int w, int h, int bpp); // Bitmap ������ �����ϴ� �Լ�.
	void DrawImage(); // �׸��� �۾��� �����ϴ� �Լ�.
	// color image���� pixel ���� color (r, g,b)�� �а�/����
	void	GetColor(IplImage* src, int i, int j, int *blue, int *green, int *red);
	void	SetColor(IplImage* src, int i, int j, int blue, int green, int red);
	void	cover_black(IplImage* src, int i, int j);
	void	cut_image();
public:

	CStatic m_picture0;
	CStatic m_picture1;

	double w;
	IplImage* iplimg;
	IplImage* color_iplimg;
	IplImage copy;
	Mat mat_iplimg;
	Mat mat_color_iplimg;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
