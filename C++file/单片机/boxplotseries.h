// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CPointer;
class CPen1;

/////////////////////////////////////////////////////////////////////////////
// CBoxPlotSeries wrapper class

class CBoxPlotSeries : public COleDispatchDriver
{
public:
	CBoxPlotSeries() {}		// Calls COleDispatchDriver default constructor
	CBoxPlotSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CBoxPlotSeries(const CBoxPlotSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CPointer GetPointer();
	BOOL GetDark3D();
	void SetDark3D(BOOL bNewValue);
	CPointer GetExtrOut();
	CPen1 GetMedianPen();
	CPointer GetMildOut();
	double GetPosition();
	void SetPosition(double newValue);
	double GetWhiskerLength();
	void SetWhiskerLength(double newValue);
	CPen1 GetWhiskerPen();
	CPointer GetBox();
	double MaxXValue();
	double MinXValue();
};
