// testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include "IOChackDlg.h"
#include "SettingDlg.h"
#include "DlgProxy.h"
#include "NewButton.h"
#include "CtrlCard.h"

#include "adt856.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CWorkdata  g_data;
CCtrlCard	g_CtrlCard;
int g_WorkStatus = NORUN;
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
// CTestDlg dialog

IMPLEMENT_DYNAMIC(CTestDlg, CDialog);

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDlg)
	m_strData = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CTestDlg::~CTestDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
	DDX_Control(pDX, IDC_POSDRAW, m_listDraw);
	DDX_Control(pDX, IDC_EDIT_DATA, m_cEdit);
	DDX_Control(pDX, IDC_LIST, m_listMain);
	DDX_Text(pDX, IDC_EDIT_DATA, m_strData);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_IOCHACK, OnIOchack)
	ON_COMMAND(ID_SELECT, OnSelect)
	ON_COMMAND(ID_SETTING, OnSetting)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_ADDPOS, OnAddpos)
	ON_BN_CLICKED(IDC_MODIFYPOS, OnModifypos)
	ON_BN_CLICKED(IDC_INSERTPOS, OnInsertpos)
	ON_BN_CLICKED(IDC_DELPOS, OnDelpos)
	ON_BN_CLICKED(IDC_BUTTON4, OnButHome)
	ON_BN_CLICKED(IDC_BUTTON3, OnButStop)
	ON_BN_CLICKED(IDC_BUTTON1, OnButStart)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_COMMAND(ID_OPEN, OnOpen)
	ON_COMMAND(ID_SAVE, OnSave)
	ON_NOTIFY(NM_CLICK, IDC_LIST, OnClickList)
	ON_EN_KILLFOCUS(IDC_EDIT_DATA, OnKillfocusEditData)
	ON_BN_CLICKED(IDC_SAVE1, OnSave1)
	ON_BN_CLICKED(IDC_READ1, OnRead1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

BOOL CTestDlg::OnInitDialog()
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
	
	//*************��ʼ��856��**************
	if (g_CtrlCard.Init_Board() <= 0)
	{		
        MessageBox( "���ƿ���ʼ��ʧ��!");				
	}                
    else
		MessageBox ("�˶����ƿ�����ʹ��!");

	long m_Startv[]={100,100,100};   //��ʼ�ٶ�
	long m_Speed[]={200,200,200};          //�����ٶ�
	long m_Add[]  ={625,625,625};   	                 //���ٶ�
	long m_Dec[]  ={625,625,625};                      //���ٶ�
	long m_Pulse[]={10000,10000,10000};          //�������������
	long m_Ratio[]={5,5,5};          //����
	for(int l=1; l<MAXAXIS+1; l++)
		g_CtrlCard.Setup_Speed(l,m_Startv[l-1],m_Speed[l-1],m_Add[l-1],m_Dec[l-1],m_Ratio[l-1],0);

	m_bRightX=0;
	m_bLiftX=0;
	m_bForwardY=0;
	m_bBackwardY=0;
	m_bHomeX=0;
	m_bHomeY=0;
	m_Cycles=5;
	m_bData=0;

	GetDlgItem(IDC_EDIT_DATA)->ShowWindow(false);

	//�б�
	m_listMain.SetExtendedStyle(LVS_EX_GRIDLINES  |LVS_EX_FULLROWSELECT |LVS_EX_ONECLICKACTIVATE);//|LVS_EX_CHECKBOXES	 
/*	LVS_EX_GRIDLINES //���Ʊ��,�����ߡ�
����LVS_EX_SUBITEMIMAGES //����Ŀͼ���б�
����LVS_EX_CHECKBOXES //����ѡ��
����LVS_EX_TRACKSELECT //�Զ�����
����LVS_EX_HEADERDRAGDROP//����ͷ������ק
����LVS_EX_FULLROWSELECT //ѡ�����У�����ѡ�����С�
����LVS_EX_ONECLICKACTIVATE//���������ѡ����Ŀ��
����LVS_EX_TWOCLICKACTIVATE//˫������
����LVS_EX_FLATSB//��ƽ������
����LVS_EX_REGIONAL
����LVS_EX_INFOTIP
����LVS_EX_UNDERLINEHOT
����LVS_EX_UNDERLINECOLD
����LVS_EX_MULTIWORKAREAS//�๤����*/
	m_listMain.SetBkColor(RGB(240,240,255));//������ɫ(��)
	m_listMain.SetTextColor(RGB(0,215,0));//�ı���ɫ
	m_listMain.SetTextBkColor(RGB(230,230,230));//�ı�����ɫ
//	m_listMain.SetTextColor(RGB(0,0,255));
//	m_listMain.SetTextBkColor(RGB(240,240,255));
	LV_COLUMN lvc;
	lvc.mask=LVCF_FMT|LVCF_WIDTH |LVCF_TEXT|LVCF_SUBITEM;
	lvc.fmt=LVCFMT_CENTER;
	CRect rc;
	GetDlgItem(IDC_LIST)->GetWindowRect(&rc);
	width1=(rc.right-rc.left)*50/350-1;
	width2=(rc.right-rc.left)*100/350-1;
	int width[]={width1,width2,width2,width2};
	char *column[]={"���","X������","Y������","Z������"};
	char *AxisNum[]={"1","2","3","4"};
	CString str;
	for(int i=0;i<4;i++)
	{	
		lvc.cx=width[i];//���
		lvc.pszText=column[i];//����
		lvc.iSubItem=i;
		m_listMain.InsertColumn(i,&lvc);//�ڱ���ģʽ�²���һ��
		m_listMain.InsertItem(i,AxisNum[i]);// ��ʼ���б�ؼ��е���
	}
	for(int k=0;k<4;k++)
	{
		for(int j=1;j<7;j++)
		{
			double a=100*k+10*j;
			str.Format("%7.3f",a);
			m_listMain.SetItemText(k,j,str);
		}	
		ListView_SetCheckState(m_listMain.m_hWnd, k, true);//ѡ�и���
		
	}
//	m_listMain.SetTextColor(RGB(0,215,0));
//	m_listMain.SetTextBkColor(RGB(230,230,230));

    UpdateData(FALSE);
	SetTimer(MAINTIMER,50,NULL);        //������ʱ��

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestDlg::OnPaint() 
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
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

BOOL CTestDlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

void CTestDlg::OnIOchack() 
{
	// TODO: Add your command handler code here
	CIOChackDlg dlg;
	dlg.DoModal();
	
}

void CTestDlg::OnSelect() 
{
	// TODO: Add your command handler code here
	CSettingDlg dlg;
	int tab=1;
	dlg.m_ntab=tab;
	dlg.DoModal();
	
}

void CTestDlg::OnSetting() 
{
	// TODO: Add your command handler code here
	CSettingDlg dlg;
	int tab=2;
	dlg.m_ntab=tab;
	dlg.DoModal();
	
}

void CTestDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	g_CtrlCard.StopRun(1,1);
	g_CtrlCard.StopRun(2,1);
	g_CtrlCard.StopRun(3,1);
	g_CtrlCard.End_Board();	//���жԿ����ͷ�
	
}

void CTestDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default


//	int Stopdata[6];

//	UINT nID1[]={IDC_POSX,IDC_POSY,IDC_POSZ};
//	UINT nID2[]={IDC_POSACTX,IDC_POSACTY,IDC_POSACTZ};
//	UINT nID3[]={IDC_RUNSPEEDX,IDC_RUNSPEEDY,IDC_RUNSPEEDZ};
//	UINT nID4[]={m_nPosX,m_nPosY,m_nPosZ};

	CStatic *lbl;
	CString str,stopinf;
//	int status[6];

	lbl=(CStatic*)GetDlgItem(IDC_STATIC_CYCLES);
    str.Format("%d",m_Cycles);
	lbl->SetWindowText(str);
	int Num=m_listMain.GetItemCount();//����
	lbl=(CStatic*)GetDlgItem(IDC_STATIC_NUM);
    str.Format("%d",Num);
	lbl->SetWindowText(str);

	//x������
	g_CtrlCard.Get_CurrentInf(1,m_logx,m_actx,m_spdx);
	lbl=(CStatic*)GetDlgItem(IDC_POSX);
	str.Format("%ld",m_logx);
	lbl->SetWindowText(str);
	lbl=(CStatic*)GetDlgItem(IDC_RUNSPEEDX);
	str.Format("%ld",m_spdx*5);
	lbl->SetWindowText(str);
/*	if(m_logx<=0)//��������λ
	{
		m_bLimit_X =1;
		if(m_bLiftX==1)
			g_CtrlCard.StopRun(1,1);
	}
	if(m_logx>0)
		m_bLimit_X =0;
	if(m_logx>350)//��������λ
	{
		m_bLimitX =1;
		if(m_bRightX==1)
			g_CtrlCard.StopRun(1,1);
	}
	if(m_logx<=350)
		m_bLimitX =0;*/
	//y������
	g_CtrlCard.Get_CurrentInf(2,m_logy,m_acty,m_spdy);
	lbl=(CStatic*)GetDlgItem(IDC_POSY);
	str.Format("%ld",m_logy);
	lbl->SetWindowText(str);
	lbl=(CStatic*)GetDlgItem(IDC_RUNSPEEDY);
	str.Format("%ld",m_spdy*5);
	lbl->SetWindowText(str);
/*	if(m_logy<=0 && m_bBackwardY==1)
	{
		m_bLimit_Y =1;
		if(m_bBackwardY==1)
			g_CtrlCard.StopRun(2,1);
	}
	if(m_logy>0)
		m_bLimit_Y =0;
	if(m_logy>350 && m_bForwardY==1)
	{
		m_bLimitY =1;
		if(m_bForwardY==1)
			g_CtrlCard.StopRun(2,1);
	}
	if(m_logy<=350)
		m_bLimitY =0;*/
	//z������
	g_CtrlCard.Get_CurrentInf(3,m_logz,m_actz,m_spdz);
	lbl=(CStatic*)GetDlgItem(IDC_POSZ);
	str.Format("%ld",m_logz);
	lbl->SetWindowText(str);
	lbl=(CStatic*)GetDlgItem(IDC_RUNSPEEDZ);
	str.Format("%ld",m_spdz*5);
	lbl->SetWindowText(str);
/*	for (int i=1; i<MAXAXIS+1; i++)
	{

		g_CtrlCard.Get_CurrentInf(i,m_log,m_act,m_spd);    //��ȡ�߼�λ�á�ʵ��λ�ú������ٶ�
		nID4[i-1]=m_log;

		//******��ʾ�߼�λ��*********
		lbl=(CStatic*)GetDlgItem(nID1[i-1]);
		str.Format("%ld",m_log);
		lbl->SetWindowText(str);

		//******��ʾʵ��λ��*********
		lbl=(CStatic*)GetDlgItem(nID2[i-1]);
		str.Format("%ld",m_act);
		lbl->SetWindowText(str);

		//******��ʾ�����ٶ�*********
		lbl=(CStatic*)GetDlgItem(nID3[i-1]);
		str.Format("%ld",m_spd*5);
		lbl->SetWindowText(str);

		//******��ȡ����״̬*********
		g_CtrlCard.Get_Status(i,status[i-1],0);
	}
*/
	//��ǰλ��
	CRect rect;
	GetDlgItem(IDC_POSDRAW)->GetWindowRect(&rect);
	ScreenToClient(rect);
	CClientDC dc(this);
	dc.SelectStockObject(BLACK_BRUSH);//�ڻ�ˢ��NULL_BRUSHΪ�ջ�ˢ
	dc.SetROP2(R2_NOTCOPYPEN);//ȡ��������ɫ
	dc.Ellipse(m_OldPoint.x,m_OldPoint.y,m_OldPoint.x+10,m_OldPoint.y+10);
	m_Point.x=rect.left+m_logx*(rect.right-rect.left)/400+1;
	m_Point.y=rect.top+m_logy*(rect.bottom-rect.top)/400+1;
	dc.SetROP2(R2_COPYPEN);//ȡ��ǰ������ɫ
	dc.Ellipse(m_Point.x,m_Point.y,m_Point.x+10,m_Point.y+10);
	m_OldPoint=m_Point;

//	m_strMessage="";
	
	CDialog::OnTimer(nIDEvent);
}

BOOL CTestDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_LBUTTONDOWN)
	{
		long runpos;
		if(pMsg->hwnd == GetDlgItem(IDC_RIGHTX)->m_hWnd)// && m_bLimitX==0)
		{
			m_bRightX=1;
//	        g_CtrlCard.Axis_Cmove(1,0);
			ReadData(0,1);
			runpos=350-m_read[0];
			g_CtrlCard.Axis_Pmove(1,runpos);
		}
		if(pMsg->hwnd == GetDlgItem(IDC_LIFTX)->m_hWnd)// && m_bLimit_X==0)
		{
			m_bLiftX=1;
//	        g_CtrlCard.Axis_Cmove(1,1);
			ReadData(0,1);
			runpos=0-m_read[0];
			g_CtrlCard.Axis_Pmove(1,runpos);
		}
		if(pMsg->hwnd == GetDlgItem(IDC_FORWARDY)->m_hWnd)// && m_bLimitY==0)
		{
			m_bForwardY=1;
//	        g_CtrlCard.Axis_Cmove(2,0);
			ReadData(0,2);
			runpos=350-m_read[1];
			g_CtrlCard.Axis_Pmove(2,runpos);
		}
		if(pMsg->hwnd == GetDlgItem(IDC_BACKWARDY)->m_hWnd)// && m_bLimit_Y==0)
		{
			m_bBackwardY=1;
//	        g_CtrlCard.Axis_Cmove(2,1);
			ReadData(0,2);
			runpos=0-m_read[1];
			g_CtrlCard.Axis_Pmove(2,runpos);
		}
		if(pMsg->hwnd == GetDlgItem(IDC_UPPERZ)->m_hWnd)
		{
			m_bUpperZ=1;
//	        g_CtrlCard.Axis_Cmove(3,0);
			ReadData(0,3);
			runpos=350-m_read[2];
			g_CtrlCard.Axis_Pmove(3,runpos);
		}
		if(pMsg->hwnd == GetDlgItem(IDC_DOWNZ)->m_hWnd)
		{
			m_bDownZ=1;
//	        g_CtrlCard.Axis_Cmove(3,1);
			ReadData(0,3);
			runpos=0-m_read[2];
			g_CtrlCard.Axis_Pmove(3,runpos);
		}
	}
	else if(pMsg->message == WM_LBUTTONUP)
	{
		if(m_bRightX == 1 || m_bLiftX == 1)
		{
		    g_CtrlCard.StopRun(1,1);
		    m_bRightX=0;
		    m_bLiftX=0;
		}
		if(m_bForwardY == 1 || m_bBackwardY == 1)
		{
		    g_CtrlCard.StopRun(2,1);
		    m_bForwardY=0;
			m_bBackwardY=0;
		}
		if(m_bUpperZ == 1 || m_bDownZ == 1)
		{
		    g_CtrlCard.StopRun(3,1);
		    m_bUpperZ=0;
			m_bDownZ=0;
		}
	}
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) return TRUE;//ʹESC�����˳����
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) 
	{
		if(GetFocus()==GetDlgItem(IDC_EDIT_DATA))
		{
			UpdateData(true);
			m_listMain.SetItemText(m_Item,m_SubItem,m_strData);
			GetDlgItem(IDC_EDIT_DATA)->ShowWindow(false);
		}
		return TRUE;//ʹENTER�����˳����
	}
	return CDialog::PreTranslateMessage(pMsg);
}

HBRUSH CTestDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CTestDlg::OnAddpos() 
{
	// TODO: Add your control notification handler code here
	//�������
	UINT nIDPos[]={IDC_POSX,IDC_POSY,IDC_POSZ};
	UINT nState=LVIS_SELECTED;
	UINT nMask=LVIS_SELECTED; 
	double  pos=0.0;
	CString str;
	int MaxItem, MaxIndex,Column;
	char buff[20];
	MaxItem	= m_listMain.GetItemCount() - 1;//��ȡ�˲˵��е�����
	ShowSubItem(MaxItem + 1, 0);//�������к�����������������
	ListView_SetCheckState(m_listMain.m_hWnd, MaxItem+1, true);//ѡ�и���

//	int result=ListView_GetCheckState(m_listMain.m_hWnd, MaxItem+1);//�ж��Ƿ�ѡ��	
	
	itoa(MaxItem+2,buff,10);//����ת��λ�ַ���
	m_listMain.SetHotItem(MaxItem+1);
	m_listMain.SetSelectionMark(MaxItem+1);	
	
	m_listMain.SetItemState(MaxItem+1,nState,nMask);
	m_listMain.SetFocus();
	m_listMain.EnsureVisible(MaxItem+1,true);	
	
	MaxIndex  = m_listMain.GetSelectionMark();
	if (MaxIndex<0) return;
	for (Column = 1; Column < 4; Column ++)
	{
		GetDlgItem(nIDPos[Column-1])->GetWindowText(str);
		m_listMain.SetItemText(MaxIndex,Column,str);
	}
}

int CTestDlg::ShowSubItem(int Item, int Column)
{
	//������ǰ�����кź�����к�
	m_CurItem = Item;
	m_CurColumn = Column;
	m_MaxNodeNo = Item > m_MaxNodeNo ? Item : m_MaxNodeNo;

    // Make sure that the item is visible
    if (!m_listMain.EnsureVisible (Item, TRUE)) 
    {
		InsertItemEx (Item);
		if (!m_listMain.EnsureVisible (Item, TRUE)) 
			return NULL;
    }
    return 1;
}

int CTestDlg::InsertItemEx(int Item)
{	
	//����һ�������ڽ���
	CString PointNo;
	PointNo.Format("%d",(Item + 1));
    int Result = m_listMain.InsertItem (Item, PointNo);		
    return Result;
}

void CTestDlg::OnModifypos() 
{
	// TODO: Add your control notification handler code here
	//�޸�����	
	UINT nIDPos[]={IDC_POSX,IDC_POSY,IDC_POSZ};
	CString str;
	int MaxIndex  = m_listMain.GetSelectionMark();//��ȡ��������һ��
	if (MaxIndex<0) return;
	
	for (int Column = 1; Column < 4; Column ++)
	{
		GetDlgItem(nIDPos[Column-1])->GetWindowText(str);
		m_listMain.SetItemText(MaxIndex,Column,str);//�ڹ̶����С���д��ֵ
	}
	m_listMain.SetHotItem(MaxIndex);//����List view�ؼ��ĵ�ǰ����(����״̬);һֱ���ڸ���״̬ 
	m_listMain.SetSelectionMark(MaxIndex);//����List view�ؼ���ѡ�б��;��ѡ�к�������ɫ������ͬ����Ȼ��ɫ�����Լ�����
	m_listMain.EnsureVisible(MaxIndex,true);//λ���ض���¼
	UINT nState=LVIS_SELECTED;
	UINT nMask=LVIS_SELECTED;       
	m_listMain.SetItemState(MaxIndex,nState,nMask);//nState����Ҫ���õ�״ֵ̬.nMask������Ϊ����Ҫ���õ��������,ָ����Ӧ�Ǹ���״̬
	m_listMain.SetFocus();//���ü��̽��㵽ָ������	
}

void CTestDlg::OnInsertpos() 
{
	// TODO: Add your control notification handler code here
	CString str;	
	UINT nIDPos[]={IDC_POSX,IDC_POSY,IDC_POSZ};	
	int MaxItem	  = m_listMain.GetItemCount();
	int MaxIndex  = m_listMain.GetSelectionMark();
	int SelCount=1;
	
	if (MaxIndex < 0)
	{
		return;
	}
	
	ShowSubItem(MaxItem, 0);
	for (int Item = MaxItem; Item >= MaxIndex; Item --)
	{
		for (int Column = 1; Column < 4; Column ++)
		{
			CString ItemText = m_listMain.GetItemText(Item-1, Column);
			m_listMain.SetItemText(Item, Column, ItemText);
		}
		ListView_SetCheckState(m_listMain.m_hWnd, MaxItem, true);//ѡ�и���
	}
	for (int Column = 1; Column < 4; Column ++)//����
	{
		GetDlgItem(nIDPos[Column-1])->GetWindowText(str);		
		m_listMain.SetItemText(MaxIndex,Column,str);
	}
	
	m_listMain.SetHotItem(MaxIndex);
	m_listMain.SetSelectionMark(MaxIndex);
	m_listMain.EnsureVisible(MaxIndex,true);
	UINT nState=LVIS_SELECTED;
	UINT nMask=LVIS_SELECTED;       
	m_listMain.SetItemState(MaxIndex,nState,nMask);
	m_listMain.SetFocus();	
}

void CTestDlg::OnDelpos() 
{
	// TODO: Add your control notification handler code here
	//ɾ������
	CString strItemNo;
	int MaxIndex  = 0,MinIndex=0,ItemCount =0;  //��ȡѡ������к�
	int SelCount=1;
	int Item, Index;
	char buff[10];
	UINT nState=LVIS_SELECTED;
	UINT nMask=LVIS_SELECTED;  
	
	MaxIndex  = m_listMain.GetSelectionMark();  //��ȡѡ������к�
	if (MaxIndex < 0)
	{
		return;
	}
	MinIndex = MaxIndex - SelCount + 1;
	for (Item = MinIndex, Index = MinIndex; Index <= MaxIndex; Index ++)
	{
		m_listMain.DeleteItem(Item);//ɾ��λ��ָ������λ�õļ�¼
	}	
	ItemCount = m_listMain.GetItemCount();	//�ٴλ�ȡ����
	for (Item = MinIndex; Item < ItemCount; Item ++)
	{
		strItemNo.Format("%d", Item + 1);
		m_listMain.SetItemText(Item, 0, strItemNo);//��Item�У�0�У�д�µ��к�
	}	
	if ( ItemCount==0 )
	{
		return;
	}	
	else
	{			
		itoa(MaxIndex+1,buff,10);	
		m_listMain.SetHotItem(MaxIndex);
		m_listMain.SetSelectionMark(MaxIndex);  
		m_listMain.SetItemState(MaxIndex,nState,nMask);
		m_listMain.SetFocus();
	} 
}

void CTestDlg::OnButHome() 
{
	// TODO: Add your control notification handler code here
	if(m_bHomeX==0 || m_bHomeY==0)
	{
	CString strX,strY;
	int retnX = -1;
	//SetHomeMode(int m_nCardNum,int m_nAxisNum,int m_nHomeDir,int m_nStop0Active,int m_nLimitActive,int m_nStop1Active,
	//			long m_nBackRange,long m_nEncoderZRange,long m_nOffset)
	
	retnX = GetHomeStatus_Ex(0,1);
	retnX=SetHomeMode_Ex(0,1,0,0,0,-1,2000,400,100);
	                   //���š���š����㷽��stop0��/�ߵ�ƽֹͣ��limit��/�ߵ�ƽֹͣ��
	                  //stop1��/��ֹͣ/-1�����ñ�����Z�ࡢstop0���˳����롢��ԭ��ƫ��
	//SetHomeSpeed(int m_nCardNum,int m_nAxisNum,long m_nStartSpeed,long m_nSearchSpeed,long m_nHomeSpeed,long m_nAcc,long m_nZPhaseSpeed)
	retnX=SetHomeSpeed_Ex(0,1,100,500,200,100,200);
	retnX=HomeProcess_Ex(0,1);
	strX.Format("��ԭ��״̬��%ld",retnX);
	int retnY = -1;
	retnY = GetHomeStatus_Ex(0,2);
	retnY = SetHomeMode_Ex(0,2,0,0,0,-1,2000,400,100);
	retnY = SetHomeSpeed_Ex(0,2,100,500,200,100,200);
	retnY = HomeProcess_Ex(0,2);
	strY.Format("��ԭ��״̬��%ld",retnY);
//	GetDlgItem(IDC_HOME_STATUS)->SetWindowText(str);
	if(retnX>20 || retnX<0 )
	{
		MessageBox("����ʧ��");
		return;		
	}
	if(retnY>20 || retnY<0 )
	{
		MessageBox("����ʧ��");
		return;		
	}
	while(true)
	{
		DoEvent();
		Sleep(1);
		retnX = GetHomeStatus_Ex(0,1);
		strX.Format("��ԭ��״̬��%ld",retnX);
		retnY = GetHomeStatus_Ex(0,2);
		strY.Format("��ԭ��״̬��%ld",retnY);
//		GetDlgItem(IDC_HOME_STATUS)->SetWindowText(str);
		if(retnX>20 || retnX<0 )
		{
			MessageBox("X����ʧ��");
			return;
			
		}
		else if(retnX==0)
		{
			MessageBox("X����ɹ�");
			return;
			
		}
		else
		{
			//������ѯ״̬
		}
		if(retnY>20 || retnY<0 )
		{
			MessageBox("Y����ʧ��");
			return;
			
		}
		else if(retnY==0)
		{
			MessageBox("Y����ɹ�");
			return;
			
		}
		else
		{
			//������ѯ״̬
		}
	}
	}
	else
	{
		if(g_WorkStatus==RUNNING)
			AddMessage("�����У��޷����и�λ");
		else
		{
		//�ص����
			bool work=0;
			int result;
		while(1)
		{  
			for(int i=1;i<4;i++)
			{
			    ReadData(0,i);
		    	m_pos[i-1]=0-m_read[i-1];
			}
			if(work==0){
	    	result=g_CtrlCard.Interp_Move2(1,m_pos[0],m_pos[1]);
			work=1;
		    SetDlgItemText(IDC_BUTSTART,"��ʼ");
			}
	    	if(result==1)
			{
	    		AddMessage("δ�ߵ��ӹ�λ");
				break;
			}
	    	ReadData(0,1);
	    	if(m_read[0]==0)
			{
		    	ReadData(0,2);
		    	if(m_read[1]==0)
				{
			    	AddMessage("�ص�ԭ��");
			    	Delay(1);
					break;
				}
			}
			Delay(100);
		}
		}
	}
}

void CTestDlg::OnButStop() 
{
	// TODO: Add your control notification handler code here
	g_WorkStatus=NORUN;
	g_CtrlCard.StopRun(1,1);
	g_CtrlCard.StopRun(2,1);
	g_CtrlCard.StopRun(3,1);
	SetDlgItemText(IDC_BUTSTART,"��ʼ");
}

void CTestDlg::OnButStart() 
{
	// TODO: Add your control notification handler code here
	int result = -1;
	if(!m_bHomeX || !m_bHomeY)
	{
		AddMessage("ϵͳû�и�λ!");
		return;
	}
	if(g_WorkStatus!=NORUN)
	{
		AddMessage("ϵͳ��æ!");
	}
	if(m_listMain.GetItemCount()<=0)
	{
		AddMessage("û�мӹ�����!");
		return;
	}
	AddMessage("�ӹ���ʼ...");
	g_WorkStatus=RUNNING;
	RunData(1);
	Delay(1000);
	OnButHome();
	SetDlgItemText(IDC_BUTSTART,"��ʼ");
}

void CTestDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	m_bHomeX=1;
	m_bHomeY=1;
//	GetDlgItem(IDC_EDIT_DATA)->SetWindowPos(NULL,0,0,100,100,SWP_NOMOVE);//SWP_NOMOVE
//  HWND_BOTTOM������������Z��ĵײ����������hWnd��ʶ��һ�����㴰�ڣ��򴰿�ʧȥ����λ�ã����ұ������������ڵĵײ���
//  HWND_DOTTOPMOST���������������зǶ��㴰��֮�ϣ��������ж��㴰��֮�󣩡���������Ѿ��ǷǶ��㴰����ñ�־�������á�
//  HWND_TOP:����������Z��Ķ�����
//  HWND_TOPMOST:�������������зǶ��㴰��֮�ϡ���ʹ����δ�������Ҳ�����ֶ���λ�á�
//	CEdit *edit = (CEdit*)GetDlgItem(IDC_EDIT_DATA);
//	edit->ShowWindow(m_data);//��ʾ
//	edit->EnableWindow(m_data);//��ɫ
	GetDlgItem(IDC_EDIT_DATA)->ShowWindow(false);
}

void CTestDlg::AddMessage(CString str)
{
	CListBox *list=(CListBox*)GetDlgItem(IDC_MESSAGE);
	list->InsertString(-1,str);
	list->SetCurSel(list->GetCount()-1);
}

int CTestDlg::RunData(int mode)
{
	int result=0;//����ֵ
	int Num=m_listMain.GetItemCount();//����
	int i=1;
	CString str;
	CStatic *lbl;
	while(1)
	{   
		
		::DoEvent();
		Delay(1);
		if(i>5)
			g_WorkStatus = NORUN;
		if(g_WorkStatus == NORUN)
			break;
		for(int step=1;step<=Num;)
		{
			lbl=(CStatic*)GetDlgItem(IDC_STATIC_STEP);
            str.Format("%d",step);
        	lbl->SetWindowText(str);
			lbl=(CStatic*)GetDlgItem(IDC_STATIC_I);
            str.Format("%d",i);
        	lbl->SetWindowText(str);
			if(g_WorkStatus == NORUN)
				break;
		    ::DoEvent();
		    Delay(1);
			for(int j=1;j<4;j++)
			{
				CString Coord; //��ʾѭ������
				Coord = m_listMain.GetItemText(step-1,j);
				m_Pos[j-1] = atol(Coord);
				ReadData(1,j);
			}
			switch(g_WorkStatus)
			{
			case NORUN:
				break;
			case PAUSE:
				{
					ReadData(0,1);
					if(m_Pos[0]==m_read[0])
					{
						ReadData(0,2);
						if(m_Pos[1]==m_read[1])
						{
							Delay(1);
							step++;
							g_WorkStatus=RUNNING;
						}
					}
					if(g_WorkStatus == NORUN)break; //��ָֹͣ���������
					break;
				}
/*				continue;
			case CONTINUE:	
				{
					g_WorkStatus = RUNNING;
					break;
				}
				*/
			case RUNNING:
				{
					result=g_CtrlCard.Interp_Move2(1,m_pos[0],m_pos[1]);
					SetDlgItemText(IDC_BUTSTART,"������");
					if(result==1)
						AddMessage("δ�ߵ��ӹ�λ");
					else
						g_WorkStatus = PAUSE;
					if(g_WorkStatus == NORUN)break; //��ָֹͣ���������
					break;
				}
			default:
				break;
			}
		}
		i++;
	}
	AddMessage("��ɲ���");

	AddMessage("ֹͣ�ӹ���");	
	return g_WorkStatus==NORUN?0:1;
}

void CTestDlg::ReadData(int num,int i)
{
	//0��λ�ã�1���������λ��
	long log,act,spd;
	g_CtrlCard.Get_CurrentInf(i,log,act,spd);
	m_read[i-1]=log;
	if(num==1)
	m_pos[i-1] = m_Pos[i-1]-m_read[i-1];
}

void CTestDlg::OnOpen() 
{
	// TODO: Add your command handler code here
	char    Flat[10];
	int     num=0;
	CString str;
//	if (g_globVar.m_nRunStatus!=NORUN) return;
	
	char filestr[50]="DOT(*.dot)|*.dot||";
	CFileDialog dlg(TRUE,"DOT",NULL,OFN_HIDEREADONLY,filestr);
//	char filestr[50]="XLS(*.xls)|*.xls||";
//	CFileDialog dlg(TRUE,"XLS",NULL,OFN_HIDEREADONLY,filestr);
	if (dlg.DoModal()==IDCANCEL) return;
	CString path=dlg.GetPathName();//����Ŀ¼���ļ���
	FILE *pf=fopen(path,"rb");//rb�Ƕ��������ļ�
//	FILE *pf=fopen(path,"r");
	if (!pf)
	{
		MessageBox("�ļ���ʧ��!", "����", MB_ICONSTOP);
		fclose(pf);
		return ;
	}
	int i;
	fread(Flat,sizeof(int),1,pf);//Flat�Ƕ�ȡ�����ݴ�ŵ��ڴ��ָ��/sizeof(int)��ÿ�ζ�ȡ���ֽ���/1�Ƕ�ȡ����/pf��Ҫ��ȡ���ļ���ָ��    
	num=atoi(Flat);	
	m_listMain.DeleteAllItems();//ɾ�����е����Ȼ�µľͻ�ӵ�ԭ����ĺ���
//	for(i=0;i<num;i++)
//	{
//		str.Format("%d",i+1);
//		m_listMain.InsertItem(1,str);
//		CString fileread[20];
//		for(int j=1;j<4;j++)
//		{
//			fread(fileread,1,10,pf);
//			m_listMain.SetItemText(1,1,fileread[1]);
//		}
//		ShowSubItem(i, 0);//�������к�����������������
//		ListView_SetCheckState(m_listMain.m_hWnd, i, true);//ѡ�и���
//	}
	for (i=0; i<num; i++)
	{
		fread(&g_data,sizeof(CWorkdata),1,pf);
		str.Format("%d",i+1);
		m_listMain.InsertItem(i,str);
		
		str.Format("%7.3f",g_data.m_fXPos);
		m_listMain.SetItemText(i,1,str);
		
		str.Format("%7.3f",g_data.m_fYPos);
		m_listMain.SetItemText(i,2,str);
		
		str.Format("%7.3f",g_data.m_fZPos);
		m_listMain.SetItemText(i,3,str);
		
		ShowSubItem(i, 0);//�������к�����������������
		ListView_SetCheckState(m_listMain.m_hWnd, i, true);//ѡ�и���
	}	
	fclose(pf);	
}

void CTestDlg::OnSave() 
{
	// TODO: Add your command handler code here
	char filestr[50]="DOT(*.dot)|*.dot||";
	CFileDialog dlg(FALSE,"DOT",NULL,OFN_HIDEREADONLY,filestr);
	//FALSE����һ������Ի����ļ���չ�����ļ���ʼ������ָ����ʾ�ļ�����
//	CFileDialog dlg(FALSE,"XLS",NULL,OFN_HIDEREADONLY,filestr);
	if (dlg.DoModal()==IDCANCEL) return;
	CString path=dlg.GetPathName();
	
	FILE *pf=fopen(path,"wb");
//	FILE *pf=fopen(path,"w");
	//wbֻд�򿪻��½�һ���������ļ���ֻ����д����
	if (!pf)
	{
		MessageBox("�ļ�����ʧ��!", "����", MB_ICONSTOP);
		fclose(pf);
		return ;
	}
	char Flat[10]="1";	
	int Num=0;
	CString Coord;
	int i=0;

	Num=m_listMain.GetItemCount();//����
	itoa(Num,Flat,10);
	fwrite(Flat,sizeof(Num),1,pf);//��������
/*	for(i=0;i<Num;i++)
	{
//		CString filewrite="";
		CString filewrite[3];
		fwrite("\n",1,strlen("\n"),pf);
		for(int j=1;j<4;j++)
		{
		    Coord=m_listMain.GetItemText(i,j);
			filewrite[j-1]=Coord+"\t";
			fwrite(filewrite[j-1],1,strlen(filewrite[j-1]),pf);
//			filewrite+=Coord+"\t";
//			fwrite(Coord,1,strlen(Coord),pf);
//			fwrite("\t",1,strlen("\t"),pf);
		}
//		fwrite(filewrite,1,strlen(filewrite),pf);
	}
	*/
	for ( i=0; i<Num; i++)
	{
		Coord=m_listMain.GetItemText(i,1);		
		g_data.m_fXPos =(float)atof(Coord);//atof���ַ���ת���ɸ�������
		
		Coord=m_listMain.GetItemText(i,2);
		g_data.m_fYPos = (float)atof(Coord);
		
		Coord=m_listMain.GetItemText(i,3);
		g_data.m_fZPos = (float)atof(Coord);
		
		fwrite(&g_data,sizeof(CWorkdata),1,pf);
	}
	fclose(pf);
//	fileDlg.m_ofn.lpstrTitle="����Ի���";
//	fileDlg.m_ofn.lpstrFilter="Text File(*.txt)\0*.txt\0All Files(*.*)\0\0";
//	fileDlg.m_ofn.lpstrDefExt="txt";
}

void CTestDlg::OnClickList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NM_LISTVIEW* pNMListView = ( NM_LISTVIEW* )pNMHDR;
	m_Item=pNMListView->iItem;
	m_SubItem=pNMListView->iSubItem;
	if(m_Item>=0 && m_SubItem>0)
	{
		CRect rect;
		GetDlgItem(IDC_LIST)->GetWindowRect(&rect);
		ScreenToClient(rect);//screen(��Ļ����)to(�ͻ�������)
	    m_strData=m_listMain.GetItemText(m_Item,m_SubItem);
	    GetDlgItem(IDC_EDIT_DATA)->ShowWindow(true);
		int x=rect.left+width1+(m_SubItem-1)*97;
		int y=rect.top+18+m_Item*13;
	    GetDlgItem(IDC_EDIT_DATA)->SetWindowPos(NULL,x,y,width2+5,16,SWP_NOZORDER);
	    UpdateData(FALSE);
	}
	*pResult = 0;
}


void CTestDlg::OnKillfocusEditData() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT_DATA)->ShowWindow(false);
}

void CTestDlg::SystemParameter(bool sr)
{
/*	CArchive& ar;
	if(sr==0)
	{
		//���ݶ�ȡ
		int i=5;
		char ch='b';
		float f=1.2f;
		CString str("asdffghfdfh");
		ar<<i<<ch<<f<<str;
	}
	else
	{
		//���ݱ���
	}*/
}
/*C:\Documents and Settings\Administrator\����\*/
void CTestDlg::OnSave1() 
{
	// TODO: Add your control notification handler code here
	CFile file;
    file.Open( "YourFile.MDT", CFile::modeWrite|CFile::modeCreate );
    CArchive ar( &file,CArchive::store );
    Serialize( ar );
    ar.Close();
    file.Close();
}

void CTestDlg::OnRead1() 
{
	// TODO: Add your control notification handler code here
	CFile file;
    file.Open( "YourFile.MDT", CFile::modeRead );
    CArchive ar( &file,CArchive::load );
    Serialize( ar );
    ar.Close();
    file.Close();
}

void CTestDlg::Serialize(CArchive& ar) 
{
	if (ar.IsStoring())
	{	// storing code
		int i=5;
		char ch='b';
		float f=1.2f;
		CString str="abcsdfg";
		ar<<i<<ch<<f<<str;
	}
	else
	{	// loading code
		int i;
		char ch;
		float f;
		CString str;
		CString strResult;
		ar>>i>>ch>>f>>str;
		strResult.Format("%d,%c,%f,%s",i,ch,f,str);
		AddMessage(strResult);
	}
}
