// filetestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "filetest.h"
#include "filetestDlg.h"
#include "excel.h"


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
// CFiletestDlg dialog

CFiletestDlg::CFiletestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFiletestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFiletestDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFiletestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFiletestDlg)
	DDX_Control(pDX, IDC_LIST2, m_ExcelList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFiletestDlg, CDialog)
	//{{AFX_MSG_MAP(CFiletestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFiletestDlg message handlers

BOOL CFiletestDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFiletestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFiletestDlg::OnPaint() 
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
HCURSOR CFiletestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFiletestDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CDatabase database;
	CString sDriver = "MICROSOFT EXCEL DRIVER (*.XLS)"; // Excel安装驱动
	CString sExcelFile,sPath;
	CString sSql;
	GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
	sPath.ReleaseBuffer();
	int nPos;
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);
	sExcelFile=sPath+"\\Demo.xls";
	TRY
	{
		// 创建进行存取的字符串
    sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver, sExcelFile, sExcelFile);

    // 创建数据库 (既Excel表格文件)
    if( database.OpenEx(sSql,CDatabase::noOdbcDialog) )
    {
      // 创建表结构(序号、姓名、年龄)
      sSql = "CREATE TABLE Exceldemo (Num Number,Name TEXT,Age NUMBER)";//可以用中文表示序号，姓名，年龄等
      database.ExecuteSQL(sSql);

      // 插入数值
      sSql = "INSERT INTO Exceldemo (Num,Name,Age) VALUES (1,'小西',24)";
      database.ExecuteSQL(sSql);

      sSql = "INSERT INTO Exceldemo (Num,Name,Age) VALUES (2,'小东',22)";
      database.ExecuteSQL(sSql);

      sSql = "INSERT INTO Exceldemo (Num,Name,Age) VALUES (3,'小朱',25)";
      database.ExecuteSQL(sSql);

      sSql = "INSERT INTO Exceldemo (Num,Name,Age) VALUES (4,'小鸭',27)";
      database.ExecuteSQL(sSql);
    }

    // 关闭数据库
    database.Close();

	AfxMessageBox("Excel文件写入成功！");
	}
	CATCH_ALL(e)
	{

		TRACE1("Excel驱动没有安装: %s",sDriver);
	}
	END_CATCH_ALL;
/*	//Workbooks->Workbook->Worksheets->Worksheet->Range;
	_Application app; //Excel应用程序接口
	Workbooks books; //工作簿集合
	_Workbook book;//工作簿
	Worksheets sheets;//工作表集合
	_Worksheet sheet;//工作表
	Range range;//Excel中针对单元格的操作都应先获取其对应的Range对象
	Font font;
	Range cols;
	if (CoInitialize(NULL) != NULL)
{
AfxMessageBox("初始化COM支持库失败!");
return;
}
	//COleVariant类为VARIANT数据类型的包装，在自动化程序中，通常都使用
    //VARIANT数据类型进行参数传递。故下列程序中，函数参数都是通过COleVariant类来转换了的。
	//covOptional?可选参数的VARIANT类型
	COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR); 
	if(!app.CreateDispatch("Excel.Application"))
	{
		this->MessageBox("无法创建Excel应用!");
		return;
	}
	//
	books=app.GetWorkbooks();
	//
	book=books.Add(covOptional);
	//
	sheets=book.GetSheets();
	//
	range=sheet.GetRange(COleVariant("A1"),COleVariant("A1"));
	//
	//range.SetValue(COleVariant("HELLO EXCEL!));//编译有错，注释掉
	//
	font=range.GetFont();
	font.SetBold(COleVariant((short)TRUE));
	//
	range=sheet.GetRange(COleVariant("A2"),COleVariant("A2"));
	range.SetFormula(COleVariant("=RAND()*100000"));
	range.SetNumberFormat(COleVariant("$0.00"));
	//
	cols=range.GetEntireColumn();
	cols.AutoFit();
	//
	app.SetVisible(true);
	app.SetUserControl(true);
	*/
}

void CFiletestDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CDatabase database;
    CString sSql;
    CString sItem1, sItem2,sItem3;
    CString sDriver;
    CString sDsn;
    CString sFile,sPath;

                                    
//获取主程序所在路径,存在sPath中
GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
sPath.ReleaseBuffer ();
    int nPos;
nPos=sPath.ReverseFind ('\\');
sPath=sPath.Left (nPos);

sFile = sPath + "\\Demo.xls";     // 将被读取的Excel文件名

    // 检索是否安装有Excel驱动 "Microsoft Excel Driver (*.xls)" 
    sDriver = GetExcelDriver();
    if (sDriver.IsEmpty())
    {
        // 没有发现Excel驱动
        AfxMessageBox("没有安装Excel驱动!");
        return;
    }
    
    // 创建进行存取的字符串
    sDsn.Format("ODBC;DRIVER={%s};DSN=' ';DBQ=%s", sDriver, sFile);

    TRY
    {
        // 打开数据库(既Excel文件)
        database.Open(NULL, false, false, sDsn);
        
        CRecordset recset(&database);

        // 设置读取的查询语句.
        sSql = "SELECT Num,Name, Age " //设置索引顺序     
               "FROM Exceldemo " ;                
               "ORDER BY Name ";
    
        // 执行查询语句
        recset.Open(CRecordset::forwardOnly, sSql, CRecordset::readOnly);

        // 获取查询结果
        while (!recset.IsEOF())
        {
            //读取Excel内部数值
    recset.GetFieldValue("Num", sItem1);
            recset.GetFieldValue("Name", sItem2);
            recset.GetFieldValue("Age", sItem3);

    //显示记取的内容
    m_ExcelList.AddString( sItem1 + " --> "+sItem2+ " --> "+sItem3 );

            // 移到下一行
            recset.MoveNext();
        }

        // 关闭数据库
        database.Close();
                             
    }
    CATCH(CDBException, e)
    {
        // 数据库操作产生异常时...
        AfxMessageBox("数据库错误: " + e->m_strError);
    }
    END_CATCH;
}
