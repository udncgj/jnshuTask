// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CNativeExport wrapper class

class CNativeExport : public COleDispatchDriver
{
public:
	CNativeExport() {}		// Calls COleDispatchDriver default constructor
	CNativeExport(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CNativeExport(const CNativeExport& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void SaveToFile(LPCTSTR FileName, BOOL IncludeData);
	VARIANT SaveToStream(BOOL IncludeData);
};
