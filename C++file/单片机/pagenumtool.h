// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CTeeShapePanel;

/////////////////////////////////////////////////////////////////////////////
// CPageNumTool wrapper class

class CPageNumTool : public COleDispatchDriver
{
public:
	CPageNumTool() {}		// Calls COleDispatchDriver default constructor
	CPageNumTool(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CPageNumTool(const CPageNumTool& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetPosition();
	void SetPosition(long nNewValue);
	CTeeShapePanel GetShape();
	CString GetText();
	void SetText(LPCTSTR lpszNewValue);
	CString GetFormat();
	void SetFormat(LPCTSTR lpszNewValue);
};
