20200809 fisheye distoring 제거 시험로직 


		//Mat m_image = imread("image.png");
		IplImage *img = cvLoadImage("RE055750.jpg", 1);

		CWnd* Wnd_DP_01 = GetDlgItem(IDC_DP_0);
		CClientDC dc_01(Wnd_DP_01);
		RECT rect_DP_01;
		Wnd_DP_01->GetClientRect(&rect_DP_01);
		CvvImage image_DP_01;
		image_DP_01.CopyOf(img);
		image_DP_01.DrawToHDC(dc_01.m_hDC, &rect_DP_01);