// CtrlCard.h: interface for the CCtrlCard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CTRLCARD_H__792BC8C3_F372_497B_B0A1_6F065F0C19DD__INCLUDED_)
#define AFX_CTRLCARD_H__792BC8C3_F372_497B_B0A1_6F065F0C19DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*********************** 运动控制模块 ********************

    为了简单、方便、快捷地开发出通用性好、可扩展性强、
    
    维护方便的应用系统，我们在控制卡函数库的基础上将
    
    所有库函数进行了分类封装。下面的示例使用一块运动
    
    控制卡

********************************************************/
#define  MULTIPLE  5//倍率
#define  MAXAXIS  3    //最大轴数

class CCtrlCard  
{
public:
	
	int Setup_Stop0Mode(int axis, int value, int logic);
	int Setup_Stop1Mode(int axis, int value, int logic);
	int Setup_Stop2Mode(int axis, int value, int logic);	

	int Actualcount_Mode(int axis,int value, int dir,int freq);
   	int AllowDec(int no);
    int Axis_Pmove(int axis ,long value);
	int Axis_Cmove(int axis ,long value);

    int Setsoft_LimitMode1(int axis, int value);
    int Setsoft_LimitMode2(int axis, int value);
    int Setsoft_LimitMode3(int axis, int value);
	
	int Setup_LimitMode(int axis, int value, int logic);
	int Setup_PulseMode(int axis, int value);

	int Setup_Comp1(int axis, long value);
    int Setup_Comp2(int axis, long value);

	int Setup_Pos(int axis, long pos, int mode);
    int SetCircle_Mode(int axis, int value);

	int Write_Output(int number, int value);
	int Read_Input(int number);

	int Get_CurrentInf(int axis, long &LogPos, long &ActPos, long &Speed);
	int Get_Status(int axis, int &value, int mode);
	int Get_AllowInpStatus(int no, int &value);
	
	int Set_DecPos(int axis, long value, long startv, long speed, long add);
    int Set_DecMode(int axis, int mode1, int mode2);

	int Get_ErrorInf(int axis, int &value);
	int StopRun(int axis, int mode);

	int Interp_Move2(int no, long value1, long value2);
    int Interp_Move3(long value1, long value2, long value3);
	int Interp_Move4(long value1, long value2, long value3, long value4);
    int Interp_Move6(long value1, long value2, long value3, long value4, long value5, long value6);

    int Setup_Range(int axis, long value);	
	int Interp_Arc(int no, long x, long y, long i,long j);	
	int Interp_CcwArc(int no, long x, long y, long i,long j);


	int End_Board();
    int ForbidDec(int no);
	int Init_Board();	
    int Setup_Speed(int axis ,long startv ,long speed ,long  add ,long dec,long ratio,int mode);

	int Inpos_Mode(int axis, int value, int logic);
    int Setup_AlarmMode(int axis,int value,int logic);

	int Setup_InputFilter(int axis,int number,int value);
    int Setup_FilterTime(int axis,int value);
  
	CCtrlCard();
	int Result;  //返回值
	int no;
	
};

#endif // !defined(AFX_CTRLCARD_H__792BC8C3_F372_497B_B0A1_6F065F0C19DD__INCLUDED_)
