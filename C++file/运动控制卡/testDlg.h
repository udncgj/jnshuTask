// testDlg.h : header file
//

#if !defined(AFX_TESTDLG_H__00F1C8AA_5F4A_425A_B610_A611110A7342__INCLUDED_)
#define AFX_TESTDLG_H__00F1C8AA_5F4A_425A_B610_A611110A7342__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTestDlgAutoProxy;


/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog
#define MAINTIMER 1001                 //主程序定时器

class CTestDlg : public CDialog
{
	DECLARE_DYNAMIC(CTestDlg);
	friend class CTestDlgAutoProxy;

// Construction
public:
	CTestDlg(CWnd* pParent = NULL);	// standard constructor
	int ShowSubItem (int Item, int Column);//添加数据
	int InsertItemEx (int Item);
	void AddMessage(CString str);
	int RunData(int mode);
	void ReadData(int num,int i);
	void SystemParameter(bool sr);//系统参数的存取
//	int Init_MotionCard();
//	int RunData(int mode);
//	int Init_MotionCard();
//	void set_move_speed(int card,int axis,int spdRange);
//	void AddMessage(CString str);

	virtual ~CTestDlg();

	long m_Startv[3];   //初始速度
	long m_Speed[3];          //驱动速度
	long m_Add[3];   	                 //加速度
	long m_Dec[3];                      //减速度
	long m_Pulse[3];          //轴的驱动脉冲数
	long m_Ratio[3];          //倍率
	long m_log,m_act,m_spd;
	long m_logx,m_actx,m_spdx;
	long m_logy,m_acty,m_spdy;
	long m_logz,m_actz,m_spdz;
	long m_read[3];
	long m_Pos[3];//XYZ工作位置
	long m_pos[3];//XYZ相对位置
	CMenu m_Menu;
	CBrush m_brush;//画刷
	CPoint m_Point;
	CPoint m_OldPoint;
	bool m_bRightX;
	bool m_bLiftX;
	bool m_bForwardY;
	bool m_bBackwardY;
	bool m_bUpperZ;
	bool m_bDownZ;
	bool m_bHomeX,m_bHomeY;
	bool m_bData;
	bool m_bLimit_X;
	bool m_bLimitX;
	bool m_bLimit_Y;
	bool m_bLimitY;
	long m_nPosX;
	long m_nPosY;
	long m_nPosZ;
	int m_MaxNodeNo;//列表最大行号
	int m_CurColumn;//当前列
	int m_CurItem;//当前行
	int m_Cycles;//循环次数
	int m_Item;//选中行
	int m_SubItem;//选中列
	int width1;
	int width2;

// Dialog Data
	//{{AFX_DATA(CTestDlg)
	enum { IDD = IDD_TEST_DIALOG };
	CListBox	m_listDraw;
	CEdit	m_cEdit;
	CListCtrl	m_listMain;
	CString	m_strData;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void Serialize(CArchive& ar);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CTestDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnIOchack();
	afx_msg void OnSelect();
	afx_msg void OnSetting();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnAddpos();
	afx_msg void OnModifypos();
	afx_msg void OnInsertpos();
	afx_msg void OnDelpos();
	afx_msg void OnButHome();
	afx_msg void OnButStop();
	afx_msg void OnButStart();
	afx_msg void OnButton7();
	afx_msg void OnOpen();
	afx_msg void OnSave();
	afx_msg void OnClickList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKillfocusEditData();
	afx_msg void OnSave1();
	afx_msg void OnRead1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__00F1C8AA_5F4A_425A_B610_A611110A7342__INCLUDED_)
