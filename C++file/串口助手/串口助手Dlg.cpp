// 串口助手Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "串口助手.h"
#include "串口助手Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_strRXData = _T("");
	m_strTXData = _T("");
	m_BaudRate = -1;
	m_Index = -1;
	m_Date_Select = -1;
	m_ParityCheck = -1;
	m_StopBit = -1;
	m_Timer = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_CHECK_HexSend, m_ctrlHexSend);
	DDX_Control(pDX, IDC_COMBO_ParityCheck, m_ParityCheck_M);
	DDX_Control(pDX, IDC_COMBO_StopBit, m_StopBit_M);
	DDX_Control(pDX, IDC_COMBO_Date_Select, m_Date_Select_M);
	DDX_Control(pDX, IDC_COMBO_BaudRate_Select, m_BaudRate_M);
	DDX_Control(pDX, IDC_COMBO_CommSelect, m_ComboBox);
	DDX_Control(pDX, IDC_MSCOMM1, m_ctrlComm);
	DDX_Text(pDX, IDC_EDIT_RXDATA, m_strRXData);
	DDX_Text(pDX, IDC_EDIT_TXDATA, m_strTXData);
	DDX_CBIndex(pDX, IDC_COMBO_BaudRate_Select, m_BaudRate);
	DDX_CBIndex(pDX, IDC_COMBO_CommSelect, m_Index);
	DDX_CBIndex(pDX, IDC_COMBO_Date_Select, m_Date_Select);
	DDX_CBIndex(pDX, IDC_COMBO_ParityCheck, m_ParityCheck);
	DDX_CBIndex(pDX, IDC_COMBO_StopBit, m_StopBit);
	DDX_Text(pDX, IDC_EDIT_Timer, m_Timer);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_MANUALSEND, OnButtonManualsend)
	ON_CBN_SELCHANGE(IDC_COMBO_CommSelect, OnSelchangeCOMBOCommSelect)
	ON_CBN_SELCHANGE(IDC_COMBO_BaudRate_Select, OnSelchangeCOMBOBaudRateSelect)
	ON_CBN_SELENDCANCEL(IDC_COMBO_Date_Select, OnSelendcancelCOMBODateSelect)
	ON_CBN_SELCHANGE(IDC_COMBO_StopBit, OnSelchangeCOMBOStopBit)
	ON_CBN_SELCHANGE(IDC_COMBO_ParityCheck, OnSelchangeCOMBOParityCheck)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON_AutoSend, OnBUTTONAutoSend)
	ON_BN_CLICKED(IDC_BUTTON_StopAutoSend, OnBUTTONStopAutoSend)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_CleanRXData, OnBUTTONCleanRXData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_ComboBox.SetCurSel(0);//打开软件时串口选择框默认显示COM1
	m_BaudRate_M.SetCurSel(0);//波特率9600
	m_Date_Select_M.SetCurSel(0);//数据位为8
	m_StopBit_M.SetCurSel(0);//停止位为1
	m_ParityCheck_M.SetCurSel(0);//奇偶校检为无校检N

	//下面if语句用于打开默认串口
	/**********************************************/
	if(m_ctrlComm.GetPortOpen())
	{
		m_ctrlComm.SetPortOpen(FALSE);//关闭窗口
	}
	m_ctrlComm.SetCommPort(1);//打开软件时默认使用COM1串口
	if(!m_ctrlComm.GetPortOpen())
	{
		m_ctrlComm.SetPortOpen(TRUE);//打开窗口
	}
	else
	{
		AfxMessageBox("cannot open serial port");
	}
	/***************************************************************/

	m_ctrlComm.SetSettings("9600,n,8,1");//
	m_ctrlComm.SetInputMode(1);//
	m_ctrlComm.SetRThreshold(1);//
	m_ctrlComm.SetInputLen(0);//设置当前接收数据长度为0
	m_ctrlComm.GetInput();//先预读缓冲区以清除残留数据*/
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(CMyDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CMyDlg)
	ON_EVENT(CMyDlg, IDC_MSCOMM1, 1 /* OnComm */, OnOnComm, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CMyDlg::OnOnComm() 
{
	// TODO: Add your control notification handler code here
	VARIANT variant_inp;//定义一个VARIANT类对象
	COleSafeArray safearray_inp;//定义一个COleSafeArray对象
	LONG len,k;
	BYTE rxdata[2048];//设置BYTE数组AN8—intterthat is not signed
	CString strtemp;
	if(m_ctrlComm.GetCommEvent() == 2)//事件值为2表示接受缓冲区内有数据
	{
		////以下可根据自己的通信协议加入处理代码
		variant_inp = m_ctrlComm.GetInput();//读缓冲区
		safearray_inp = variant_inp;//VARIANT型变量转换为ColeSafeArray型变量
		len = safearray_inp.GetOneDimSize();
		for(k = 0; k<len; k++)
		{
			safearray_inp.GetElement(&k, rxdata + k);//转换为BYTE型数组
		}
		for(k = 0; k<len; k++)//将数组转换为Cstring型变量
		{
			BYTE bt = *(char*)(rxdata+k);
			if(m_ctrlHexSend.GetCheck())//如果是HEX显示则转为16进制
				strtemp.Format("%02x",bt);//将16进制数送入临时变量strtemp存放
			else
				strtemp.Format("%c",bt);//将字符送入临时变量strtemp存放
				m_strRXData += "\n"+strtemp;//加入接受编辑框对应字符串
		}
		UpdateData(FALSE);//更新编辑框内容（主要是接受编辑框中的）
	}
}

void CMyDlg::OnButtonManualsend() 
{
	// TODO: Add your control notification handler code here
	if(!m_ctrlComm.GetPortOpen())
		AfxMessageBox("请打开串口");
	else
	{
		UpdateData(TRUE);
		if(m_ctrlHexSend.GetCheck())
		{
			CByteArray hexdate;
			int len = String2Hex(m_strTXData,hexdate);
			m_ctrlComm.SetOutput(COleVariant(hexdate));
		}
		else
			m_ctrlComm.SetOutput(COleVariant(m_strTXData));
	}
//	UpdateData(TRUE);
//	m_ctrlComm.SetOutput(COleVariant(m_strTXData));//发送数据
	
}

void CMyDlg::OnSelchangeCOMBOCommSelect() 
{
	// TODO: Add your control notification handler code here
	m_Index = ((CComboBox*)GetDlgItem(IDC_COMBO_CommSelect))->GetCurSel();//当前选择中的行
	((CComboBox*)GetDlgItem(IDC_COMBO_CommSelect))->SetCurSel(m_Index);//设置当前选中的行的内容为显示的内容
	if(m_ctrlComm.GetPortOpen())//当要改变时则要先关闭串口才可以用按键进行打开，所以先判断当前串口是否打开
	{
		m_ctrlComm.SetPortOpen(FALSE);
	}
	SetDlgItemText((IDC_BUTTON1),"打开串口");//将打开或关闭按钮改为“打开串口”显示状态
	
}

void CMyDlg::OnSelchangeCOMBOBaudRateSelect() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_BaudRate = ((CComboBox*)GetDlgItem(IDC_COMBO_BaudRate_Select))->GetCurSel();
	switch(m_BaudRate)
	{
	case 1:m_ctrlComm.SetSettings("14400,,,");
		break;
	case 2:m_ctrlComm.SetSettings("19200,,,");
		break;
	case 3:m_ctrlComm.SetSettings("38400,,,");
		break;
	case 4:m_ctrlComm.SetSettings("56000,,,");
		break;
	case 5:m_ctrlComm.SetSettings("57600,,,");
		break;
	case 6:m_ctrlComm.SetSettings("115200,,,");
		break;
	case 7:m_ctrlComm.SetSettings("128000,,,");
		break;
	case 8:m_ctrlComm.SetSettings("256000,,,");
		break;
	default:m_ctrlComm.SetSettings("9600,,,");
		break;
	}
	UpdateData(false);
	
}

void CMyDlg::OnSelendcancelCOMBODateSelect() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_Date_Select = ((CComboBox*)GetDlgItem(IDC_COMBO_Date_Select))->GetCurSel();
	switch(m_Date_Select)
	{
	case 1:m_ctrlComm.SetSettings(",,7,");
		break;
	case 2:m_ctrlComm.SetSettings(",,6,");
		break;
	case 3:m_ctrlComm.SetSettings(",,5,");
		break;
	case 4:m_ctrlComm.SetSettings(",,4,");
		break;
	default:m_ctrlComm.SetSettings(",,8,");
		break;
	}
	UpdateData(false);
}

void CMyDlg::OnSelchangeCOMBOStopBit() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_StopBit = ((CComboBox*)GetDlgItem(IDC_COMBO_StopBit))->GetCurSel();
	switch(m_StopBit)
	{
	case 1:m_ctrlComm.SetSettings(",,,2");
		break;
	default:m_ctrlComm.SetSettings(",,,1");
		break;
	}
	UpdateData(false);
	
}

void CMyDlg::OnSelchangeCOMBOParityCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_ParityCheck = ((CComboBox*)GetDlgItem(IDC_COMBO_ParityCheck))->GetCurSel();
	switch(m_ParityCheck)
	{
	case 1:m_ctrlComm.SetSettings(",O,,");
		break;
	case 2:m_ctrlComm.SetSettings(",E,,");
		break;
	default:m_ctrlComm.SetSettings(",N,,");
		break;
	}
	UpdateData(false);
	
}

void CMyDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	if(m_Index<0)
	{
		switch(m_ctrlComm.GetPortOpen())
		{
		case 1://关闭串口前先将自动发送功能关闭
			SetDlgItemText(IDC_BUTTON_AutoSend,"自动发送");//更改按键指示
			KillTimer(1);
			//当前串口是打开的则进行关闭串口操作
			m_ctrlComm.SetPortOpen(FALSE);//关闭串口
			SetDlgItemText(IDC_BUTTON1,"打开串口");//更改按键指示
			UpdateData(FALSE);//更改按键状态
			break;
		case 0://当串口是关闭的则进行打开串口操作
			m_ctrlComm.SetCommPort(1);//如果要打开串口则应先选择哪个串口
			m_ctrlComm.SetCommPort(TRUE);
			SetDlgItemText(IDC_BUTTON1,"关闭串口");
			UpdateData(FALSE);
			break;
		default:AfxMessageBox("cannot open or close serial port");
		}
	}
	else
	{
		switch(m_ctrlComm.GetPortOpen())
		{
		case 0:
			m_ctrlComm.SetCommPort(m_Index + 1);
			m_ctrlComm.SetPortOpen(TRUE);
			SetDlgItemText(IDC_BUTTON1,"关闭串口");
			UpdateData(FALSE);
			break;
		case 1:
			SetDlgItemText(IDC_BUTTON_AutoSend,"自动发送");
			KillTimer(1);
			m_ctrlComm.SetPortOpen(FALSE);
			SetDlgItemText(IDC_BUTTON1,"打开串口");
			UpdateData(FALSE);
			break;
		default:AfxMessageBox("cannot open serial port");
		}
	}
	if(m_Index < 0)
		((CComboBox*)GetDlgItem(IDC_COMBO_CommSelect))->SetCurSel(0);//如果没有另外串口选择则显示COM1
	if(m_BaudRate < 0)
		((CComboBox*)GetDlgItem(IDC_COMBO_BaudRate_Select))->SetCurSel(0);//9600
	if(m_Date_Select < 0)
		((CComboBox*)GetDlgItem(IDC_COMBO_Date_Select))->SetCurSel(0);//8
	if(m_StopBit < 0)
		((CComboBox*)GetDlgItem(IDC_COMBO_StopBit))->SetCurSel(0);//1
	if(m_ParityCheck < 0)
		((CComboBox*)GetDlgItem(IDC_COMBO_ParityCheck))->SetCurSel(0);
}

void CMyDlg::OnBUTTONAutoSend() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Timer <= 0)//判断是否打开串口
		AfxMessageBox("请设置自动发送时间间隔");
	else if(!m_ctrlComm.GetPortOpen())//判断是否打开串口
		AfxMessageBox("请打开串口");
	else
	{
		SetDlgItemText(IDC_BUTTON_AutoSend,"自动发送...");
		SetTimer(1,m_Timer,NULL);
	}
	
}

void CMyDlg::OnBUTTONStopAutoSend() 
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_BUTTON_AutoSend,"自动发送");
	KillTimer(1);
	
}

void CMyDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	UpdateData(TRUE);
	if(m_ctrlHexSend.GetCheck())
	{
		CByteArray hexdate;
		int len = String2Hex(m_strTXData,hexdate);
		m_ctrlComm.SetOutput(COleVariant(hexdate));
	}
	else
		m_ctrlComm.SetOutput(COleVariant(m_strTXData));
	CDialog::OnTimer(nIDEvent);
}

int CMyDlg::String2Hex(CString str, CByteArray &senddate)
{
	int hexdate,lowhexdate;
	int hexdatelen = 0;
	int len = str.GetLength();
	senddate.SetSize(len/2);
	for(int i=0; i<len;)
	{
		char lstr,hstr = str[i];
		if(hstr == ' ')
		{
			i++;
			continue;
		}
		i++;
		if(i >= len)
			break;
		lstr = str[i];
		hexdate = ConverHexChar(hstr);
		lowhexdate = ConverHexChar(lstr);
		if((hexdate = 16) = (lowhexdate == 16))
			break;
		else
			hexdate = hexdate * 16 + lowhexdate;
		i++;
		senddate[hexdatelen] = (char)hexdate;
		hexdatelen++;
	}
	senddate.SetSize(hexdatelen);
	return hexdatelen;

}

char CMyDlg::ConverHexChar(char ch)
{
	if((ch>='0') && (ch<='9'))
	{
		return ch-0x30;
	}
	else if((ch>='A') && (ch<='F'))
	{
		return ch-'A'+10;
	}
	else if((ch>='a') && (ch<='f'))
	{
		return ch-'a'+10;
	}
	else
		return (-1);

}

void CMyDlg::OnBUTTONCleanRXData() 
{
	// TODO: Add your control notification handler code here
	m_strRXData.Empty();
	UpdateData(FALSE);
	
}
