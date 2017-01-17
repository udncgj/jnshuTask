// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "windroseseries.h"

// Dispatch interfaces referenced by this interface
#include "pen.h"
#include "pointer.h"
#include "valuelist.h"
#include "circlelabels.h"
#include "brush.h"


/////////////////////////////////////////////////////////////////////////////
// CWindRoseSeries properties

/////////////////////////////////////////////////////////////////////////////
// CWindRoseSeries operations

long CWindRoseSeries::GetXRadius()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CWindRoseSeries::SetXRadius(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CWindRoseSeries::GetYRadius()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CWindRoseSeries::SetYRadius(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CWindRoseSeries::GetXCenter()
{
	long result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CWindRoseSeries::GetYCenter()
{
	long result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CWindRoseSeries::GetCircleWidth()
{
	long result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CWindRoseSeries::GetCircleHeight()
{
	long result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

unsigned long CWindRoseSeries::GetCircleBackColor()
{
	unsigned long result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CWindRoseSeries::SetCircleBackColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

BOOL CWindRoseSeries::GetCircled()
{
	BOOL result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWindRoseSeries::SetCircled(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CWindRoseSeries::GetRotationAngle()
{
	long result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CWindRoseSeries::SetRotationAngle(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

double CWindRoseSeries::PointToAngle(long XCoord, long YCoord)
{
	double result;
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0xc, DISPATCH_METHOD, VT_R8, (void*)&result, parms,
		XCoord, YCoord);
	return result;
}

double CWindRoseSeries::GetAngleIncrement()
{
	double result;
	InvokeHelper(0x1e, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void CWindRoseSeries::SetAngleIncrement(double newValue)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x1e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

BOOL CWindRoseSeries::GetCloseCircle()
{
	BOOL result;
	InvokeHelper(0x1f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWindRoseSeries::SetCloseCircle(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x1f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CPen1 CWindRoseSeries::GetPen()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x20, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CPen1(pDispatch);
}

CPointer CWindRoseSeries::GetPointer()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x21, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CPointer(pDispatch);
}

double CWindRoseSeries::GetRadiusIncrement()
{
	double result;
	InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void CWindRoseSeries::SetRadiusIncrement(double newValue)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x22, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

CValueList CWindRoseSeries::GetAngleValues()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x23, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CValueList(pDispatch);
}

CValueList CWindRoseSeries::GetRadiusValues()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x24, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CValueList(pDispatch);
}

void CWindRoseSeries::DrawRing(double Value, long Z)
{
	static BYTE parms[] =
		VTS_R8 VTS_I4;
	InvokeHelper(0x26, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Value, Z);
}

CPen1 CWindRoseSeries::GetCirclePen()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x27, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CPen1(pDispatch);
}

CCircleLabels CWindRoseSeries::GetCircleLabels()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x28, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CCircleLabels(pDispatch);
}

CBrush1 CWindRoseSeries::GetBrush()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CBrush1(pDispatch);
}

void CWindRoseSeries::LoadBackImage(LPCTSTR FileName)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 FileName);
}

void CWindRoseSeries::ClearBackImage()
{
	InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL CWindRoseSeries::GetClockWiseLabels()
{
	BOOL result;
	InvokeHelper(0x9b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWindRoseSeries::SetClockWiseLabels(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x9b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CWindRoseSeries::GetCircleLabelsInside()
{
	BOOL result;
	InvokeHelper(0x9c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWindRoseSeries::SetCircleLabelsInside(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x9c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CWindRoseSeries::GetTransparency()
{
	long result;
	InvokeHelper(0x73, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CWindRoseSeries::SetTransparency(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x73, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}
