// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CAreaSeries;
class CArrowSeries;
class CBarSeries;
class CBubbleSeries;
class CCandleSeries;
class CErrorBarSeries;
class CFastLineSeries;
class CGanttSeries;
class CHorizBarSeries;
class CLineSeries;
class CPieSeries;
class CPointSeries;
class CPolarSeries;
class CShapeSeries;
class CSurfaceSeries;
class CVolumeSeries;
class CTeeFunction;
class CMarks;
class CValueList;
class CBezierSeries;
class CContourSeries;
class CErrorSeries;
class CPoint3DSeries;
class CRadarSeries;
class CClockSeries;
class CWindRoseSeries;
class CBar3DSeries;
class CImageBarSeries;
class CTeePoint2D;
class CDonutSeries;
class CTriSurfaceSeries;
class CBoxPlotSeries;
class CHorizBoxPlotSeries;
class CHistogramSeries;
class CColorGridSeries;
class CHorizLineSeries;
class CBarJoinSeries;
class CHighLowSeries;
class CWaterfallSeries;
class CSmithSeries;
class CPyramidSeries;
class CMapSeries;
class CFunnelSeries;
class CCalendarSeries;
class CValueLists;

/////////////////////////////////////////////////////////////////////////////
// CSeries wrapper class

class CSeries : public COleDispatchDriver
{
public:
	CSeries() {}		// Calls COleDispatchDriver default constructor
	CSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSeries(const CSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	BOOL GetActive();
	void SetActive(BOOL bNewValue);
	CAreaSeries GetAsArea();
	CArrowSeries GetAsArrow();
	CBarSeries GetAsBar();
	CBubbleSeries GetAsBubble();
	CCandleSeries GetAsCandle();
	CErrorBarSeries GetAsErrorBar();
	CFastLineSeries GetAsFastLine();
	CGanttSeries GetAsGantt();
	CHorizBarSeries GetAsHorizBar();
	CLineSeries GetAsLine();
	CPieSeries GetAsPie();
	CPointSeries GetAsPoint();
	CPolarSeries GetAsPolar();
	CShapeSeries GetAsShape();
	CSurfaceSeries GetAsSurface();
	CVolumeSeries GetAsVolume();
	unsigned long GetColor();
	void SetColor(unsigned long newValue);
	BOOL GetColorEachPoint();
	void SetColorEachPoint(BOOL bNewValue);
	long GetCount();
	short GetCursor();
	void SetCursor(short nNewValue);
	VARIANT GetDataSource();
	void SetDataSource(const VARIANT& newValue);
	long GetFirstValueIndex();
	CTeeFunction GetFunctionType();
	long GetHorizontalAxis();
	void SetHorizontalAxis(long nNewValue);
	CString GetLabelsSource();
	void SetLabelsSource(LPCTSTR lpszNewValue);
	long GetLastValueIndex();
	CMarks GetMarks();
	CString GetName();
	void SetName(LPCTSTR lpszNewValue);
	CString GetPercentFormat();
	void SetPercentFormat(LPCTSTR lpszNewValue);
	unsigned long GetPointColor(long Index);
	void SetPointColor(long Index, unsigned long newValue);
	CString GetPointLabel(long Index);
	void SetPointLabel(long Index, LPCTSTR lpszNewValue);
	double GetPointValue(long Index);
	void SetPointValue(long Index, double newValue);
	long GetSeriesType();
	BOOL GetShowInLegend();
	void SetShowInLegend(BOOL bNewValue);
	CString GetTitle();
	void SetTitle(LPCTSTR lpszNewValue);
	CString GetValueFormat();
	void SetValueFormat(LPCTSTR lpszNewValue);
	CString GetValueMarkText(long ValueIndex);
	long GetVerticalAxis();
	void SetVerticalAxis(long nNewValue);
	CValueList GetXValues();
	CValueList GetYValues();
	long GetZOrder();
	long Add(double AValue, LPCTSTR ALabel, unsigned long Value);
	long AddNull(LPCTSTR SomeLabel);
	long AddXY(double AX, double AY, LPCTSTR ALabel, unsigned long Value);
	long CalcXPos(long SomeValueIndex);
	long CalcXPosValue(double SomeValue);
	long CalcXSizeValue(double SomeValue);
	long CalcYPos(long SomeValueIndex);
	long CalcYPosValue(double SomeValue);
	long CalcYSizeValue(double SomeValue);
	void CheckDataSource();
	void Clear();
	long Clicked(long XCoord, long YCoord);
	void Delete(long Index);
	void FillSampleValues(long NumValues);
	long GetMousePoint();
	BOOL IsNull(long ValueIndex);
	void RefreshSeries();
	void SetFunction(long AFunction);
	void SwapValues(long a, long b);
	double XScreenToValue(long ScreenCoord);
	CString XValueToText(double SomeValue);
	double YScreenToValue(long ScreenCoord);
	CString YValueToText(double SomeValue);
	CBezierSeries GetAsBezier();
	CContourSeries GetAsContour();
	CErrorSeries GetAsError();
	CPoint3DSeries GetAsPoint3D();
	CRadarSeries GetAsRadar();
	long AddNullXY(double X, double Y, LPCTSTR ALabel);
	CString LegendString(long LegendIndex, long LegendTextStyle);
	unsigned long LegendItemColor(long LegendIndex);
	long CountLegendItems();
	long LegendToValueIndex(long LegendIndex);
	long VisibleCount();
	void AssignValues(long SeriesIndex);
	long GetHorizontalAxisCustom();
	void SetHorizontalAxisCustom(long nNewValue);
	long GetVerticalAxisCustom();
	void SetVerticalAxisCustom(long nNewValue);
	CClockSeries GetAsClock();
	CWindRoseSeries GetAsWindRose();
	CBar3DSeries GetAsBar3D();
	CImageBarSeries GetAsImageBar();
	void DisconnectAxisCustom(BOOL IsHorizontal);
	CTeePoint2D GetMouseValues();
	void AddArray(long ArraySize, const VARIANT& YArray, const VARIANT& XArray);
	long GetDepth();
	void SetDepth(long nNewValue);
	CDonutSeries GetAsDonut();
	CTriSurfaceSeries GetAsTriSurface();
	CBoxPlotSeries GetAsBoxPlot();
	CHorizBoxPlotSeries GetAsHorizBoxPlot();
	CHistogramSeries GetAsHistogram();
	CColorGridSeries GetAsColorGrid();
	CHorizLineSeries GetAsHorizLine();
	CBarJoinSeries GetAsBarJoin();
	CHighLowSeries GetAsHighLow();
	CWaterfallSeries GetAsWaterfall();
	CSmithSeries GetAsSmith();
	CPyramidSeries GetAsPyramid();
	CMapSeries GetAsMap();
	CFunnelSeries GetAsFunnel();
	CCalendarSeries GetAsCalendar();
	void FreeDatasource(BOOL SurePrompt);
	long GetDatasourceType();
	void SetDatasourceType(long nNewValue);
	CValueLists GetValueLists();
	BOOL IsNan(double Value);
	void DeleteRange(long Start, long Quantity);
};
