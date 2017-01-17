// Para1.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "Para1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPara1 dialog


CPara1::CPara1(CWnd* pParent /*=NULL*/)
	: CDialog(CPara1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPara1)
	m_nPara1 = 0;
	//}}AFX_DATA_INIT
}


void CPara1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPara1)
	DDX_Text(pDX, IDC_EDIT1, m_nPara1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPara1, CDialog)
	//{{AFX_MSG_MAP(CPara1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPara1 message handlers
int CPara1::GetParaValue()
{
	return m_nPara1;
}
