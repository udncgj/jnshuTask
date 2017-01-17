// Result.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "Result.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResult dialog


CResult::CResult(CWnd* pParent /*=NULL*/)
	: CDialog(CResult::IDD, pParent)
{
	//{{AFX_DATA_INIT(CResult)
	m_nResult = 0;
	//}}AFX_DATA_INIT
}


void CResult::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResult)
	DDX_Text(pDX, IDC_EDIT1, m_nResult);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CResult, CDialog)
	//{{AFX_MSG_MAP(CResult)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResult message handlers
void CResult::SetResultValue(int nResult)
{
	m_nResult = nResult;
}