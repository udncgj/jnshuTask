// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CPen1;

/////////////////////////////////////////////////////////////////////////////
// CFastLineSeries wrapper class

class CFastLineSeries : public COleDispatchDriver
{
public:
	CFastLineSeries() {}		// Calls COleDispatchDriver default constructor
	CFastLineSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFastLineSeries(const CFastLineSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CPen1 GetLinePen();
	long AddRealTime(double X, double Y, LPCTSTR SomeLabel, unsigned long SomeColor);
	BOOL GetDrawAllPoints();
	void SetDrawAllPoints(BOOL bNewValue);
};
