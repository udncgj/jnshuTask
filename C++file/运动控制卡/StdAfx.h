// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__9A314E9B_8A3F_4FCF_A11D_B59551BC997E__INCLUDED_)
#define AFX_STDAFX_H__9A314E9B_8A3F_4FCF_A11D_B59551BC997E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#define NORUN       0
#define RUNNING     1
#define PAUSE       2
#define CONTINUE    3

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT


// This macro is the same as IMPLEMENT_OLECREATE, except it passes TRUE
//  for the bMultiInstance parameter to the COleObjectFactory constructor.
//  We want a separate instance of this application to be launched for
//  each automation proxy object requested by automation controllers.
#ifndef IMPLEMENT_OLECREATE2
#define IMPLEMENT_OLECREATE2(class_name, external_name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
	AFX_DATADEF COleObjectFactory class_name::factory(class_name::guid, \
		RUNTIME_CLASS(class_name), TRUE, _T(external_name)); \
	const AFX_DATADEF GUID class_name::guid = \
		{ l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } };

#endif // IMPLEMENT_OLECREATE2
#ifndef ListView_SetCheckState
#define ListView_SetCheckState(hwndLV, i, fCheck) \
	ListView_SetItemState(hwndLV, i, \
INDEXTOSTATEIMAGEMASK((fCheck)+1), LVIS_STATEIMAGEMASK)

class CWorkdata 
{
public:
	CWorkdata()
	{
		Init();
	}
	void Init()
	{		
		m_fXPos=0;
		m_fYPos=0;
		m_fZPos=0;
	}	
	float m_fXPos;
	float m_fYPos;
	float m_fZPos; //зјБъ
};
void      DoEvent();
void    Delay(long time);

#endif
void	DoEvent();
void Delay(long time);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__9A314E9B_8A3F_4FCF_A11D_B59551BC997E__INCLUDED_)
