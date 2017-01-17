// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CBrush1;
class CPen1;
class CGradient;
class CValueList;

/////////////////////////////////////////////////////////////////////////////
// CErrorBarSeries wrapper class

class CErrorBarSeries : public COleDispatchDriver
{
public:
	CErrorBarSeries() {}		// Calls COleDispatchDriver default constructor
	CErrorBarSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CErrorBarSeries(const CErrorBarSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetMultiBar();
	void SetMultiBar(long nNewValue);
	BOOL GetAutoMarkPosition();
	void SetAutoMarkPosition(BOOL bNewValue);
	CBrush1 GetBarBrush();
	CPen1 GetBarPen();
	long GetBarStyle();
	void SetBarStyle(long nNewValue);
	long GetBarWidthPercent();
	void SetBarWidthPercent(long nNewValue);
	BOOL GetDark3D();
	void SetDark3D(BOOL bNewValue);
	long GetOffsetPercent();
	void SetOffsetPercent(long nNewValue);
	BOOL GetSideMargins();
	void SetSideMargins(BOOL bNewValue);
	BOOL GetUseOrigin();
	void SetUseOrigin(BOOL bNewValue);
	double GetOrigin();
	void SetOrigin(double newValue);
	long GetOriginPos(long SomeValueIndex);
	BOOL GetAutoBarSize();
	void SetAutoBarSize(BOOL bNewValue);
	void BarImageLoad(LPCTSTR FileName);
	void BarImageClear();
	CGradient GetGradient();
	long GetStackGroup();
	void SetStackGroup(long nNewValue);
	long GetConePercent();
	void SetConePercent(long nNewValue);
	long GetBarWidth();
	void SetBarWidth(long nNewValue);
	CPen1 GetErrorPen();
	CValueList GetErrorValues();
	long GetErrorWidth();
	void SetErrorWidth(long nNewValue);
	long GetErrorWidthUnits();
	void SetErrorWidthUnits(long nNewValue);
	long AddErrorBar(double AX, double AY, double AError, LPCTSTR AXLabel, unsigned long Value);
};
