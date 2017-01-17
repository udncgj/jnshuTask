// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CPointer;
class CPen1;
class CValueList;

/////////////////////////////////////////////////////////////////////////////
// CGanttSeries wrapper class

class CGanttSeries : public COleDispatchDriver
{
public:
	CGanttSeries() {}		// Calls COleDispatchDriver default constructor
	CGanttSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CGanttSeries(const CGanttSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CPointer GetPointer();
	BOOL GetDark3D();
	void SetDark3D(BOOL bNewValue);
	CPen1 GetConnectingPen();
	CValueList GetEndValues();
	CValueList GetStartValues();
	CValueList GetNextTask();
	long AddGantt(double AStart, double AEnd, double AY, LPCTSTR SomeLabel);
	long AddGanttColor(double AStart, double AEnd, double AY, LPCTSTR AXLabel, unsigned long Value);
};
