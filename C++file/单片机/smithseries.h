// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CPen1;
class CTeeFont;
class CValueList;
class CPointer;

/////////////////////////////////////////////////////////////////////////////
// CSmithSeries wrapper class

class CSmithSeries : public COleDispatchDriver
{
public:
	CSmithSeries() {}		// Calls COleDispatchDriver default constructor
	CSmithSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSmithSeries(const CSmithSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetXRadius();
	void SetXRadius(long nNewValue);
	long GetYRadius();
	void SetYRadius(long nNewValue);
	long GetXCenter();
	long GetYCenter();
	long GetCircleWidth();
	long GetCircleHeight();
	unsigned long GetCircleBackColor();
	void SetCircleBackColor(unsigned long newValue);
	BOOL GetCircled();
	void SetCircled(BOOL bNewValue);
	long GetRotationAngle();
	void SetRotationAngle(long nNewValue);
	// method 'AngleToPoint' not emitted because of invalid return type or parameter type
	double PointToAngle(long XCoord, long YCoord);
	CPen1 GetCCirclePen();
	CPen1 GetCirclePen();
	BOOL GetCLabels();
	void SetCLabels(BOOL bNewValue);
	CTeeFont GetCLabelsFont();
	CValueList GetResistenceValues();
	CValueList GetReactanceValues();
	CPointer GetPointer();
	CPen1 GetRCirclePen();
	BOOL GetRLabels();
	void SetRLabels(BOOL bNewValue);
	CTeeFont GetRLabelsFont();
};
