// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CValueList;
class CPieOtherSlice;
class CExplodedSlices;
class CPen1;
class CTeeShadow;

/////////////////////////////////////////////////////////////////////////////
// CPieSeries wrapper class

class CPieSeries : public COleDispatchDriver
{
public:
	CPieSeries() {}		// Calls COleDispatchDriver default constructor
	CPieSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CPieSeries(const CPieSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

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
	BOOL GetUsePatterns();
	void SetUsePatterns(BOOL bNewValue);
	CValueList GetPieValues();
	BOOL GetDark3D();
	void SetDark3D(BOOL bNewValue);
	long GetExplodeBiggest();
	void SetExplodeBiggest(long nNewValue);
	CPieOtherSlice GetOtherSlice();
	CExplodedSlices GetExplodedSlice();
	CPen1 GetPiePen();
	CTeeShadow GetShadow();
	long GetAngleSize();
	void SetAngleSize(long nNewValue);
};
