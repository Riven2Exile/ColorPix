
// ColorPixDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ColorPix.h"
#include "ColorPixDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CColorPixDlg 对话框



CColorPixDlg::CColorPixDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CColorPixDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CColorPixDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CColorPixDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDOK, &CColorPixDlg::OnBnClickedOk)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CColorPixDlg 消息处理程序

BOOL CColorPixDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	this->SetTimer(1, 50, NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CColorPixDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CColorPixDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CColorPixDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	if (1 == nIDEvent){
		// 画起来
		HWND HDesktop = ::GetDesktopWindow();
		HDC hdc_desktop = ::GetDC(HDesktop);
		POINT mouse_pos;
		::GetCursorPos(&mouse_pos);
		COLORREF color = ::GetPixel(hdc_desktop, mouse_pos.x, mouse_pos.y);
		int red = GetRValue(color);
		int green = GetGValue(color);
		int blue = GetBValue(color);

		HWND ctrl = NULL;
		GetDlgItem(IDC_STATIC, &ctrl);

		CString str;
		str.Format("按“A”键确定选中颜色  R:%d G:%d B:%d ", red, green, blue);
		SetDlgItemText(IDC_STATIC, str);
	}

	CDialogEx::OnTimer(nIDEvent);
}


LRESULT CColorPixDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO:  在此添加专用代码和/或调用基类
	if (message == WM_KEYUP)
	{
		if (wParam == 65 || wParam == 87)
		{
			
		}
	}

	return CDialogEx::WindowProc(message, wParam, lParam);
}


BOOL CColorPixDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYUP)
	{
		if (pMsg->wParam == 65)
		{
			// todo: 设置
			HWND HDesktop = ::GetDesktopWindow();
			HDC hdc_desktop = ::GetDC(HDesktop);
			POINT mouse_pos;
			::GetCursorPos(&mouse_pos);
			COLORREF color = ::GetPixel(hdc_desktop, mouse_pos.x, mouse_pos.y);
			int red = GetRValue(color);
			int green = GetGValue(color);
			int blue = GetBValue(color);

			CString str;
			str.Format("#%06x", color);
			SetDlgItemText(IDC_EDIT_COLOR, str);
			SetDlgItemInt(IDC_EDIT_R, red);
			SetDlgItemInt(IDC_EDIT_G, green);
			SetDlgItemInt(IDC_EDIT_B, blue);
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CColorPixDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


HBRUSH CColorPixDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_STATIC)
	{
// 		HWND HDesktop = ::GetDesktopWindow();
// 		HDC hdc_desktop = ::GetDC(HDesktop);
// 		POINT mouse_pos;
// 		::GetCursorPos(&mouse_pos);
// 		COLORREF color = ::GetPixel(hdc_desktop, mouse_pos.x, mouse_pos.y);
// 		int red = GetRValue(color);
// 		int green = GetGValue(color);
// 		int blue = GetBValue(color);
// 
// 		pDC->SetTextColor(color);//修改字体的颜色
// 		pDC->SetBkMode(TRANSPARENT);//把字体的背景变成透明的
// 
// 		HWND ctrl = NULL;
// 		GetDlgItem(IDC_STATIC, &ctrl);
// 		CString str;
// 		str.Format("按“A”键确定选中颜色  R:%d G:%d B:%d ", red, green, blue);
// 		SetDlgItemText(IDC_STATIC, str);
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
