// 单片机Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "单片机.h"
#include "单片机Dlg.h"
#include "Setting.h"

#include "adxfunction.h"
#include "annotationtool.h"
#include "areaseries.h"
#include "arrowseries.h"
#include "aspect.h"
#include "averagefunction.h"
#include "axes.h"
#include "axis.h"
#include "axisarrowtool.h"
#include "axislabels.h"
#include "axistitle.h"
#include "bar3dseries.h"
#include "barjoinseries.h"
#include "barseries.h"
#include "bezierseries.h"
#include "bmpexport.h"
#include "bollingerfunction.h"
#include "boxplotseries.h"
#include "brush.h"
#include "bubbleseries.h"
#include "calendarcell.h"
#include "calendarcellupper.h"
#include "calendarseries.h"
#include "candleseries.h"
#include "canvas.h"
#include "chartfont.h"
#include "chartimagetool.h"
#include "circlelabels.h"
#include "clockseries.h"
#include "colorbandtool.h"
#include "colorgridseries.h"
#include "colorlinetool.h"
#include "contourlevel.h"
#include "contourlevels.h"
#include "contourseries.h"
#include "cursortool.h"
#include "curvefittingfunction.h"
#include "donutseries.h"
#include "dragmarkstool.h"
#include "drawline.h"
#include "drawlinelist.h"
#include "drawlinetool.h"
#include "environment.h"
#include "errorbarseries.h"
#include "errorseries.h"
#include "expavgfunction.h"
#include "explodedslices.h"
#include "export.h"
#include "fastlineseries.h"
#include "funnelseries.h"
#include "ganttseries.h"
#include "gifexport.h"
#include "gradient.h"
#include "highlowseries.h"
#include "histogramseries.h"
#include "horizbarseries.h"
#include "horizboxplotseries.h"
#include "horizlineseries.h"
#include "htmlexport.h"
#include "imagebarseries.h"
#include "import.h"
#include "jpegexport.h"
#include "legend.h"
#include "legendsymbol.h"
#include "lineseries.h"
#include "macdfunction.h"
#include "mappolygon.h"
#include "mappolygonlist.h"
#include "mapseries.h"
#include "marks.h"
#include "markstiptool.h"
#include "metafileexport.h"
#include "movingavgfunction.h"
#include "nativeexport.h"
#include "nearesttool.h"
#include "page.h"
#include "pagenumtool.h"
#include "panel.h"
#include "pcxexport.h"
#include "pen.h"
#include "pieotherslice.h"
#include "pieseries.h"
#include "pngexport.h"
#include "point3dseries.h"
#include "pointer.h"
#include "pointseries.h"
#include "polarseries.h"
#include "printer.h"
#include "pyramidseries.h"
#include "radarseries.h"
#include "rmsfunction.h"
#include "rotatetool.h"
#include "rsifunction.h"
#include "scroll.h"
#include "series.h"
#include "seriesmarkposition.h"
#include "seriesmarkspositions.h"
#include "shapeseries.h"
#include "smithseries.h"
#include "stddeviationfunction.h"
#include "strings.h"
#include "surfaceseries.h"
#include "tchart.h"
#include "teefont.h"
#include "teefunction.h"
#include "teeopengl.h"
#include "teepoint2d.h"
#include "teepoint3d.h"
#include "teeshadow.h"
#include "teeshapepanel.h"
#include "textexport.h"
#include "titles.h"
#include "toollist.h"
#include "tools.h"
#include "trisurfaceseries.h"
#include "valuelist.h"
#include "valuelists.h"
#include "volumeseries.h"
#include "wall.h"
#include "walls.h"
#include "waterfallseries.h"
#include "windroseseries.h"
#include "xlsexport.h"
#include "xmlexport.h"
#include "zoom.h"


#include <ctime>

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
	m_nSCMModel = -1;
	m_nTest1 = 0;
	m_nTest2 = 0;
	m_strSend = _T("");
	m_strMessage = _T("");
	m_nReadTime = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_ADD_READTIME, m_cReadTime);
	DDX_Control(pDX, IDC_CHART2, m_ctrlChart2);
	DDX_Control(pDX, IDC_CHART1, m_ctrlChart1);
	DDX_Control(pDX, IDC_SCMModel, m_SCMModel);
	DDX_Control(pDX, IDC_MSCOMM, m_ctrlComm);
	DDX_CBIndex(pDX, IDC_SCMModel, m_nSCMModel);
	DDX_Text(pDX, IDC_TEST1, m_nTest1);
	DDX_Text(pDX, IDC_TEST2, m_nTest2);
	DDX_Text(pDX, IDC_SEND, m_strSend);
	DDX_Text(pDX, IDC_MESSAGE, m_strMessage);
	DDX_Control(pDX, IDC_TCHART, m_ctrlChart);
	DDX_Text(pDX, IDC_ADD_READTIME, m_nReadTime);
	DDV_MinMaxInt(pDX, m_nReadTime, 10, 5000);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_SERIAL, OnSerial)
	ON_CBN_EDITCHANGE(IDC_SCMModel, OnEditchangeSCMModel)
	ON_BN_CLICKED(IDC_BUTSCM, OnButscm)
	ON_WM_TIMER()
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
	m_Menu.LoadMenu(IDR_MENU);
	SetMenu(&m_Menu);

	m_nCom = 0;
    m_nDate = 0;
	m_nBaudRate = 0;
	m_nParity = 0;
	m_nStopBit = 0;
    m_bHex = 0;
	m_nSCMModel = 0;
	m_SCMModel.SetCurSel(0);
	m_nReadTime = 100;

	UpdateData(false);

	m_count=101;
	Test1 = new int[m_count];
	Test2 = new int[m_count];

/*	CRect rc;  
    GetClientRect(&rc);  
    rc.top += 30;  
    rc.left += 50;  
	rc.bottom -= 80;  
	rc.right -= 50;  
	m_ctrlChart.Create("mschart", WS_CHILD| WS_VISIBLE, rc, this, 10); 

//	m_ctrlChart.SetTitle("测试");
	m_ctrlChart.Series(0).Clear();
//	m_ctrlChart.GetPage().SetMaxPointsPerPage(60);
	srand((int)time(0));
	char strTime[25];
	for(int i=0; i<60; i++)
	{
		itoa(i,strTime,10);
		int dTemper = rand()%100;
		m_ctrlChart.Series(0).AddXY(i,dTemper,strTime,RGB(255,0,0));
	}
	m_ctrlChart.GetAxis().GetLeft().SetMinMax(0,100);
*/
//	m_ctrlChart.SetHeight(200);//设置图表高度
//  long Height_size = m_ctrlChart.GetHeight();//获取当前图表的高度
//    m_ctrlChart.SetWidth(500);//设置图表宽度
	m_ctrlChart.GetHeader().GetText().SetItem(0,COleVariant("TeeChart"));//标题
	m_ctrlChart.GetHeader().GetText().Add(COleVariant("追加的标题"));//追加的标题
	m_ctrlChart.GetAxis().GetBottom().GetTitle().SetCaption("X轴的标题");//X轴的标题
	m_ctrlChart.GetAxis().GetLeft().GetTitle().SetCaption("Y轴的标题");//Y轴的标题
	m_ctrlChart.GetAxis().GetBottom().SetMinMax(0,m_count);//X轴的范围
	m_ctrlChart.GetAxis().GetLeft().SetMinMax(0,20);//Y轴的范围
	m_ctrlChart.GetLegend().SetVisible(false);//隐藏图例
//	m_ctrlChart.Series(0).GetMarks().SetVisible(true);//标记Y轴的值

	//使用代码添加折线
	m_ctrlChart.GetAspect().SetView3D(false);//
	m_ctrlChart.AddSeries(0);//
	m_ctrlChart.AddSeries(0);//
//	m_ctrlChart.Series(0).FillSampleValues(999);
//	m_ctrlChart.Series(1).FillSampleValues(999);
//	m_ctrlChart.Series(0).SetColor(RGB(255,0,0));
//	m_ctrlChart.Series(1).SetColor(RGB(0,255,0));

	m_ctrlChart.Series(0).SetTitle("a");//
	m_ctrlChart.Series(1).SetTitle("b");//

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

void CMyDlg::OnSerial() 
{
	// TODO: Add your command handler code here
	CSetting dlg;
	dlg.m_nCom = m_nCom;
	dlg.m_nDate = m_nDate;
	dlg.m_nBaudRate = m_nBaudRate;
	dlg.m_nParity = m_nParity;
	dlg.m_nStopBit = m_nStopBit;
	dlg.m_bHex = m_bHex;
	if(IDOK == dlg.DoModal())
	{
		m_nCom = dlg.m_nCom;
	    m_nDate = dlg.m_nDate;
	    m_nBaudRate = dlg.m_nBaudRate;
	    m_nParity = dlg.m_nParity;
	    m_nStopBit = dlg.m_nStopBit;
		m_bHex = dlg.m_bHex;
		
	    switch(m_nBaudRate)
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
		switch(m_nParity)
		{
		case 1:m_ctrlComm.SetSettings(",O,,");
		    break;
	    case 2:m_ctrlComm.SetSettings(",E,,");
		    break;
	    default:m_ctrlComm.SetSettings(",N,,");
		    break;
		}
		switch(m_nDate)
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
		switch(m_nStopBit)
		{
	    case 1:m_ctrlComm.SetSettings(",,,2");
	    	break;
    	default:m_ctrlComm.SetSettings(",,,1");
    		break;
		}
	}
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

void CMyDlg::OnEditchangeSCMModel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_nSCMModel = ((CComboBox*)GetDlgItem(IDC_SCMModel))->GetCurSel();
}

void CMyDlg::OnButscm() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_nReadTime<10)
		return;
	if(m_nCom<0)
	{
		switch(m_ctrlComm.GetPortOpen())
		{
		case 1://关闭串口前先将自动发送功能关闭
			KillTimer(1);
			KillTimer(2);
			KillTimer(3);
			KillTimer(4);
			//当前串口是打开的则进行关闭串口操作
			m_ctrlComm.SetPortOpen(FALSE);//关闭串口
			SetDlgItemText(IDC_BUTSCM,"打开链接");//更改按键指示
			UpdateData(FALSE);//更改按键状态
			break;
		case 0://当串口是关闭的则进行打开串口操作
			m_ctrlComm.SetCommPort(1);//如果要打开串口则应先选择哪个串口
			m_ctrlComm.SetCommPort(TRUE);
			SetDlgItemText(IDC_BUTSCM,"断开链接");
			SetTimer(1,100,NULL);
			m_nTest1 = 0;
			m_nTest2 = 0;
			SetTimer(2,1000,NULL);
			SetTimer(3,1500,NULL);
			SetTimer(4,m_nReadTime,NULL);
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
			m_ctrlComm.SetCommPort(m_nCom + 1);
			m_ctrlComm.SetPortOpen(TRUE);
			SetDlgItemText(IDC_BUTSCM,"断开链接");
			SetTimer(1,100,NULL);
			m_nTest1 = 0;
			m_nTest2 = 0;
			SetTimer(2,1000,NULL);
			SetTimer(3,1500,NULL);
			SetTimer(4,m_nReadTime,NULL);
			UpdateData(FALSE);
			break;
		case 1:
			KillTimer(1);
			KillTimer(2);
			KillTimer(3);
			KillTimer(4);
			m_ctrlComm.SetPortOpen(FALSE);
			SetDlgItemText(IDC_BUTSCM,"打开链接");
			UpdateData(FALSE);
			break;
		default:AfxMessageBox("cannot open serial port");
		}
	}
}

void CMyDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == 1)
	{
		UpdateData(false);
	}
	if(nIDEvent == 2)
	{
		m_nTest1++;
		m_nTest2--;
	}
	if(nIDEvent == 3)
	{
		m_nTest1--;
		m_nTest2+=2;
	}
	if(nIDEvent == 4)
	{
		int m_nChart1 = ((CButton*)GetDlgItem(IDC_CHART1))->GetCheck();
		int m_nChart2 = ((CButton*)GetDlgItem(IDC_CHART2))->GetCheck();
		LeftMoveArray(Test1,m_nTest1);
		LeftMoveArray(Test2,m_nTest2);
	    m_ctrlChart.Series(0).Clear();
	    m_ctrlChart.Series(1).Clear();
		for(int i=0; i<m_count; i++)
		{
			if(m_nChart1==1)
			m_ctrlChart.Series(0).AddXY(i,Test1[i],NULL,RGB(255,0,0));
			if(m_nChart2==1)
			m_ctrlChart.Series(1).AddXY(i,Test2[i],NULL,RGB(0,255,0));
		}
	}
	CDialog::OnTimer(nIDEvent);
}

BEGIN_EVENTSINK_MAP(CMyDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CMyDlg)
	ON_EVENT(CMyDlg, IDC_MSCOMM, 1 /* OnComm */, OnOnCommMscomm, VTS_NONE)
	ON_EVENT(CMyDlg, IDC_TCHART, 20 /* OnMouseMove */, OnOnMouseMoveTchart, VTS_I4 VTS_I4 VTS_I4)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CMyDlg::OnOnCommMscomm() 
{
	// TODO: Add your control notification handler code here
	
}

void CMyDlg::LeftMoveArray(int* ptr,int data)
{
	for(int i=1;i<m_count;++i)
	{
		ptr[i-1] = ptr[i];
	}
	ptr[m_count-1] = data;
}

void CMyDlg::OnOnMouseMoveTchart(long Shift, long X, long Y) 
{
	// TODO: Add your control notification handler code here
	int mPoint = -1;
	double xValue = m_ctrlChart.Series(0).XScreenToValue(X)+0.5;
	mPoint = (int)(xValue);
	if(mPoint < 0)
		return;
	CValueList xList = m_ctrlChart.Series(0).GetXValues();
	CValueList yList = m_ctrlChart.Series(0).GetYValues();
	CString strXLabel = m_ctrlChart.Series(0).GetPointLabel(mPoint);
	int dYLabel = (int)yList.GetValue(mPoint);
	CToolList tlist = m_ctrlChart.GetTools();
	CTools tools = tlist.GetItems(1);
	CAnnotationTool anntool = tools.GetAsAnnotation();
	CString strTopNote;
	strTopNote.Format("Time:%ss Temperature:%3d ℃",strXLabel,dYLabel);
	anntool.SetText(strTopNote);
}

BOOL CMyDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) return TRUE;//使ESC键不退出软件
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) 
	{
		if(GetFocus()==GetDlgItem(IDC_ADD_READTIME))
		{
			UpdateData(true);
		}
		return TRUE;//使ENTER键不退出软件
	}
	return CDialog::PreTranslateMessage(pMsg);
}
