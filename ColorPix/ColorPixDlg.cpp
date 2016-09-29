
// ColorPixDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ColorPix.h"
#include "ColorPixDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CColorPixDlg �Ի���



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


// CColorPixDlg ��Ϣ�������

BOOL CColorPixDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	this->SetTimer(1, 50, NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CColorPixDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CColorPixDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CColorPixDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	if (1 == nIDEvent){
		// ������
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
		str.Format("����A����ȷ��ѡ����ɫ  R:%d G:%d B:%d ", red, green, blue);
		SetDlgItemText(IDC_STATIC, str);
	}

	CDialogEx::OnTimer(nIDEvent);
}


LRESULT CColorPixDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO:  �ڴ����ר�ô����/����û���
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
	// TODO:  �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYUP)
	{
		if (pMsg->wParam == 65)
		{
			// todo: ����
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


HBRUSH CColorPixDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
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
// 		pDC->SetTextColor(color);//�޸��������ɫ
// 		pDC->SetBkMode(TRANSPARENT);//������ı������͸����
// 
// 		HWND ctrl = NULL;
// 		GetDlgItem(IDC_STATIC, &ctrl);
// 		CString str;
// 		str.Format("����A����ȷ��ѡ����ɫ  R:%d G:%d B:%d ", red, green, blue);
// 		SetDlgItemText(IDC_STATIC, str);
	}

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}
