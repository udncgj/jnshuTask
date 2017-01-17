// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "DlgProxy.h"
#include "testDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestDlgAutoProxy

IMPLEMENT_DYNCREATE(CTestDlgAutoProxy, CCmdTarget)

CTestDlgAutoProxy::CTestDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CTestDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CTestDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CTestDlgAutoProxy::~CTestDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CTestDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CTestDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CTestDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CTestDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CTestDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_ITest to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {DB7A57E1-D3A7-48EF-B88A-42F45380B2EB}
static const IID IID_ITest =
{ 0xdb7a57e1, 0xd3a7, 0x48ef, { 0xb8, 0x8a, 0x42, 0xf4, 0x53, 0x80, 0xb2, 0xeb } };

BEGIN_INTERFACE_MAP(CTestDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CTestDlgAutoProxy, IID_ITest, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {16BBC133-38D4-4231-A3C2-AD917FFA4090}
IMPLEMENT_OLECREATE2(CTestDlgAutoProxy, "Test.Application", 0x16bbc133, 0x38d4, 0x4231, 0xa3, 0xc2, 0xad, 0x91, 0x7f, 0xfa, 0x40, 0x90)

/////////////////////////////////////////////////////////////////////////////
// CTestDlgAutoProxy message handlers
