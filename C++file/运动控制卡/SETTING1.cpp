// SETTING1.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "SETTING1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SETTING1 dialog


SETTING1::SETTING1(CWnd* pParent /*=NULL*/)
	: CDialog(SETTING1::IDD, pParent)
{
	//{{AFX_DATA_INIT(SETTING1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void SETTING1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SETTING1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SETTING1, CDialog)
	//{{AFX_MSG_MAP(SETTING1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SETTING1 message handlers
