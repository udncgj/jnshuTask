// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CMarksTipTool wrapper class

class CMarksTipTool : public COleDispatchDriver
{
public:
	CMarksTipTool() {}		// Calls COleDispatchDriver default constructor
	CMarksTipTool(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CMarksTipTool(const CMarksTipTool& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	VARIANT GetSeries();
	void SetSeries(const VARIANT& newValue);
	long GetMouseAction();
	void SetMouseAction(long nNewValue);
	long GetStyle();
	void SetStyle(long nNewValue);
	long GetDelay();
	void SetDelay(long nNewValue);
};
