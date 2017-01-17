// CtrlCard.cpp: implementation of the CCtrlCard class.
//
////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "test.h"
#include "CtrlCard.h"
#include "adt856.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

////////////////////////////////////////////////////////////////////
// Construction/Destruction
////////////////////////////////////////////////////////////////////

CCtrlCard::CCtrlCard()
{

}
/***********************初始化函数**************************

    该函数中包含了控制卡初始化常用的库函数，这是调用
    
    其他函数的基础，所以必须在示例程序中最先调用
    
    返回值<=0表示初始化失败，返回值>0表示初始化成功

***********************************************************/
int CCtrlCard::Init_Board()
{
	Result = adt856_initial() ;         //卡初始化函数    
	
	if (Result <= 0) return Result;	
    
    for (int i = 1; i<=MAXAXIS; i++)
	{
		
		set_range (0, i, 8000000 / 5);         //设定范围,设置初始倍率为5
		
		set_command_pos (0, i, 0);        //清逻辑计数器
		
		set_actual_pos (0, i, 0);         //清实位计数器
		
		set_startv (0, i, 100);          //设定起始速度
		
		set_speed (0, i, 100);           //设定驱动速度

       	set_acc (0, i, 625);              //设定加速度
		
    }
    
    return 1;
	
}


/**********************释放控制卡函数***********************

    该函数中包含了释放控制卡的库函数，这是此函数应在

	程序结束的时候调用   
***********************************************************/

int CCtrlCard::End_Board ()
{
	Result = adt856_end();
	
	return Result;
}


/********************设置stop0信号方式**********************

   该函数用于设定stop0信号的模式

   参数： axis－轴号
          value   0－无效  1－有效
		  logic   0－低电平停止  1－高电平停止
   默认模式为：无效

   返回值=0正确，返回值=1错误
  *********************************************************/
int CCtrlCard::Setup_Stop0Mode(int axis, int value, int logic)
{
	Result = set_stop0_mode(0, axis, value ,logic);

	return Result;

}


/********************设置stop1信号方式**********************

   该函数用于设定stop1信号的模式

   参数： axis－轴号
          value   0－无效  1－有效
		  logic   0－低电平停止  1－高电平停止
   默认模式为：无效

   返回值=0正确，返回值=1错误
  *********************************************************/
int CCtrlCard::Setup_Stop1Mode(int axis, int value, int logic)
{
	Result = set_stop1_mode(0, axis, value, logic);

	return Result;

}

/********************设置stop2信号方式**********************

   该函数用于设定stop2信号的模式

   参数： axis－轴号（1-6）
          value   0－无效  1－有效
		  logic   0－低电平停止  1－高电平停止
   默认模式为：无效

   返回值=0正确，返回值=1错误
***********************************************************/
int CCtrlCard::Setup_Stop2Mode(int axis, int value, int logic)
{
	Result = set_stop2_mode(0, axis, value, logic);

	return Result;

}

/*********************设置实际位置计数器********************
cardno	   卡号

axis	   轴号（1-6）

value	   输入脉冲方式

0：        A/B脉冲输入		1：上/下（PPIN/PMIN）脉冲输入

dir		  计数方向

0：	      A超前B或PPIN脉冲输入向上计数
		  B超前A或PMIN脉冲输入向下计数
1：       B超前A或PMIN脉冲输入向上计数
		  A超前B或PPIN脉冲输入向下计数

freq	  A/B脉冲输入时的倍频，上/下脉冲输入时无效

0：4倍频     1：2倍频        2：不倍频

返回值	     0：正确	   	 1：错误

初始化时状态为：A/B相脉冲输入，方向为0，4倍频
***********************************************************/
int CCtrlCard::Actualcount_Mode(int axis,int value, int dir,int freq)
{

	Result = set_actualcount_mode(0, axis, value,dir,freq);
	
	return Result;
}

/********************设置脉冲输出方式***********************
      
	该函数用于设置脉冲的工作方式

	参数：axis-轴号， value-脉冲方式 0－脉冲＋脉冲方式 1－脉冲＋方向方式

    返回值=0正确，返回值=1错误

    默认脉冲方式为脉冲＋方向方式

    本程序采用默认的正逻辑脉冲和方向输出信号正逻辑

***********************************************************/
int CCtrlCard::Setup_PulseMode(int axis, int value)
{
	Result = set_pulse_mode(0, axis, value, 0, 0);
	
	return Result;	

}

/*********************设置限位信号方式**********************

   该函数用于设定正/负方向限位输入nLMT信号的模式

   参数： axis－轴号（1-6）

          value   0－有效时立即停止  1－有效时减速停止
		  
		  logic    0－低电平有效  1－高电平有效

   默认模式为：正限位有效、负限位有效、低电平有效

   返回值=0正确，返回值=1错误
***********************************************************/
int CCtrlCard::Setup_LimitMode(int axis, int value, int logic)
{
	Result = set_limit_mode(0, axis, value,  logic);

	return Result;

}

/******************设置COMP+寄存器做软件限制****************
cardno	   卡号

axis		轴号（1-6）

value		0：无效				1：有效

返回值	    0：正确				1：错误

初始化时状态为：无效
注意：软件限位总是减速停止，那么计数值就可能回超出设定值，
因此在设定范围时应考虑到这一点。
***********************************************************/
int CCtrlCard::Setsoft_LimitMode1(int axis, int value)
{
    Result =  set_softlimit_mode1(0, axis, value);

	return Result;

}

/******************设置COMP-寄存器做软件限制****************
cardno	   卡号

axis		轴号（1-6）

value		0：无效				1：有效

返回值	    0：正确				1：错误

初始化时状态为：无效

注意：软件限位总是减速停止，那么计数值就可能回超出设定值，
因此在设定范围时应考虑到这一点。
***********************************************************/
int CCtrlCard::Setsoft_LimitMode2(int axis, int value)
{
    Result =  set_softlimit_mode2(0, axis, value);

	return Result;

}

/****************设置COMP+/-寄存器做软件限制****************
cardno	   卡号

axis		轴号（1-6）

value		0：逻辑位置计数器		1：实际位置计数器

返回值	    0：正确				1：错误

默认模式为 : 逻辑位置计数器
此函数是设定软件限位的比较对象。
***********************************************************/
int CCtrlCard::Setsoft_LimitMode3(int axis, int value)
{
    Result =  set_softlimit_mode3(0, axis, value);

	return Result;

}

/****************伺服到位信号nINPOS的设定*******************
cardno	   卡号

axis		轴号（1-6）

value		0：无效				1：有效

logic		0：低电平有效		1：高电平有效

返回值	    0：正确				1：错误
默认模式为 : 无效，低电平有效
***********************************************************/
int CCtrlCard::Inpos_Mode(int axis, int value, int logic)
{
	Result = set_inpos_mode(0, axis,value,logic);
	
	return Result;
}

/****************伺服报警信号nALARM的设定*******************
cardno	   卡号

axis		轴号（1-6）

value		0：无效					1：有效

logic		0：低电平有效			1：高电平有效

返回值	    0：正确					1：错误
默认模式为 : 无效，低电平有效
***********************************************************/

int CCtrlCard:: Setup_AlarmMode(int axis,int value,int logic)
{
	Result = set_alarm_mode(0, axis,value,logic);
	
	return Result;
}


/************************设置速度模块***********************

    依据参数的值，判断是匀速还是加减速

    设置范围，是决定倍率的参数  
	
	设置轴的初始速度、驱动速度和加速度

    参数：axis   -轴号

	      startv -初始速度

		  speed  -驱动速度

          add    -加速度

          dec    -减速度

		  ratio  -倍率

          mode   -模式
    
    返回值=0正确，返回值=1错误

***********************************************************/
int CCtrlCard::Setup_Speed(int axis, long startv, long speed, long add ,long dec,long ratio,int mode)
{
	//匀速运动
	if (startv - speed >= 0) 
	{
		Result = set_range(0, axis, 8000000/ratio);
		
		set_startv(0, axis, startv/ratio);
		
		set_speed (0, axis, startv/ratio);
	}
	else//加/减速运动
	{
		if (mode == 0)//当选择直线加减速时进行相应的处理
		{
            set_dec1_mode(0,axis,0);//设为对称方式
			
			set_dec2_mode(0,axis,0);//设置为自动减速

            set_ad_mode(0,axis,0);//设置为直线加减速方式
			
			Result = set_range(0, axis, 8000000/ratio);
			
			set_startv(0, axis, startv/ratio);
			
			set_speed (0, axis, speed/ratio);
			
			set_acc (0, axis, add/125/ratio);
					
			
		}
		else if(mode==1)//当选择直线加减速时进行相应的处理
		{
			
			set_dec1_mode(0,axis,1);//设为非对称方式
			
			set_dec2_mode(0,axis,0);//设置为自动减速

		    set_ad_mode(0,axis,0);////设置为直线加减速方式	

			Result = set_range(0, axis, 8000000/ratio);
			
			set_startv(0, axis, startv/ratio);
			
			set_speed (0, axis, speed/ratio);
			
			set_acc (0, axis, add/125/ratio);
			
			set_dec (0, axis, dec/125/ratio);
						
		
		}
		else if(mode==2)//当选择S曲线加减速时进行相应的处理
		{
			float time;//时间的定义

			float addvar;//加速度变化率

			long k;//要算出来的结果

            time = (float)(speed-startv)/(add/2);//整个加速度时间

			addvar=add/(time/2);//加速度变化率

			k=(long)(62500000/addvar)*ratio;

            set_dec2_mode(0,axis,0);//设置为自动减速

            set_ad_mode(0,axis,1);////设置为S曲线加减速方式	

			Result = set_range(0, axis, 8000000/ratio);
			
			set_startv(0, axis, startv/ratio);
			
			set_speed (0, axis, speed/ratio);
			
			set_acc (0, axis, add/125/ratio);
			
			set_acac (0, axis,k );					
			
		}		
		
	}
	
	return Result;
	
}


/************************单轴驱动函数***********************

    该函数用于驱动单个运动轴运动

    参数： axis-轴号，value-输出脉冲数
    
    返回值=0正确，返回值=1错误

***********************************************************/
int CCtrlCard::Axis_Pmove(int axis, long value)
{
	Result = pmove(0, axis, value);
	
	return Result;

}


/************************单轴函数连续驱动***********************

    该函数用于驱动单个运动轴运动

    参数： axis-轴号，value-脉冲方向
    
    返回值=0正确，返回值=1错误

***********************************************************/
int CCtrlCard::Axis_Cmove(int axis, long value)
{
	Result = continue_move(0, axis, value);
	
	return Result;

}


/**********************两轴插补函数*********************

     该函数用于驱动XY或ZW两轴进行插补运动
	 no ->   1: X-Y       2:Z-W
    
    返回值=0正确，返回值=1错误

***********************************************************/
int CCtrlCard::Interp_Move2(int no, long value1, long value2)
{
	Result = inp_move2(0, no, value1, value2);

	return Result;

}


/*********************三轴插补函数**********************

    该函数用于驱动XYZ三轴进行插补运动
    
    返回值=0正确，返回值=1错误

***********************************************************/
int CCtrlCard::Interp_Move3(long value1, long value2, long value3)
{
	Result = inp_move3(0, value1, value2, value3);

	return Result;

}


/*******************四轴插补函数****************************

    该函数用于驱动XYZW四轴进行插补运动

    返回值=0正确，返回值=1错误

***********************************************************/
int CCtrlCard::Interp_Move4(long value1, long value2, long value3, long value4)
{
	Result = inp_move4(0, value1, value2, value3, value4);

	return Result;

}

/*******************六轴插补函数***********************
    该函数用于驱动XYZWUV六轴进行插补运动
    返回值=0正确，返回值=1错误
******************************************************/
int CCtrlCard::Interp_Move6(long value1, long value2, long value3, long value4, long value5, long value6)
{
	Result = inp_move6(0, value1, value2, value3, value4,value5, value6);

	return Result;

}

/**********************顺时针CW圆弧插补函数*****************

 no	    	参与插补的轴号      1：X-Y    2：Z-W

 x,y		圆弧插补的终点位置（相对于起点）
				
 i,j		圆弧插补的圆心点位置（相对于起点）

            该函数用于驱动XY或ZW轴进行圆弧插补运动
    
             返回值=0正确，返回值=1错误

***********************************************************/
int CCtrlCard::Interp_Arc(int no, long x, long y, long i,long j)
{
	Result = inp_cw_arc(0,no,x,y,i,j);

	return Result;
}


/**********************逆时针CCW圆弧插补函数****************
no	    	参与插补的轴号      1：X-Y    2：Z-W

x,y		圆弧插补的终点位置（相对于起点）
				
i,j		圆弧插补的圆心点位置（相对于起点）

    该函数用于驱动XY或ZW轴进行圆弧插补运动
    
    返回值=0正确，返回值=1错误

***********************************************************/
int CCtrlCard::Interp_CcwArc(int no, long x, long y, long i,long j)
{
	Result = inp_ccw_arc(0,no,x,y,i,j);

	return Result;
}


/*****************计数器的可变环功能的设定******************
      可变环功能是可以把这个环形计数器的最大数值任选设定，
	如果定位不是直线而是旋转运动的话，用此功能控制位置很方便.
    返回值	0：正确					1：错误
***********************************************************/
int CCtrlCard::SetCircle_Mode(int axis, int value)
{
	Result = set_circle_mode(0,  axis, value);
	
	return Result;
}


/********************输入信号滤波功能设置*******************

  	value		0：滤波无效			1：滤波有效

	默认模式为 : 无效

***********************************************************/
int CCtrlCard::Setup_InputFilter(int axis,int number,int value)
{
	
	Result = set_input_filter(0, axis, number, value);

	return Result;
}


/*******************输入信号滤波时间常数设置****************
axis		轴号（1-6）

value      可以除去最大噪音幅度      输入延迟
***********************************************************/
int CCtrlCard::Setup_FilterTime(int axis,int value)
{
	
	Result = set_filter_time(0, axis, value);
	
	return Result;
}


/************************获取运动信息***********************

    该函数用于反馈轴当前的逻辑位置，实际位置和运行速度

    参数：axis-轴号,LogPos-逻辑位置,ActPos-实际位置,Speed-运行速度
    
    返回值=0正确，返回值=1错误

***********************************************************/
int CCtrlCard::Get_CurrentInf(int axis, long &LogPos, long &ActPos, long &Speed)
{
	Result = get_command_pos(0, axis, &LogPos);
    
    get_actual_pos (0, axis, &ActPos);
    
    get_speed (0, axis, &Speed);

	return Result;
}

/*****************停止轴驱动********************************

    该函数用于立即或减速停止轴的驱动

	参数：axis-轴号、mode-减速方式(0－立即停止, 1－减速停止)
    
    返回值=0正确，返回值=1错误

***********************************************************/
int CCtrlCard::StopRun(int axis, int mode)
{
	if(mode == 0)       //立即停止
    {
        Result = sudden_stop(0, axis);
	}   
    else                 //减速停止
    {
        Result = dec_stop(0, axis);
	}   
    return Result;
	
}


/*****************获取轴的驱动状态**************************

    该函数用于获取单轴的驱动状态或插补驱动状态

    参数：axis=no -轴号，value-状态指针(0-驱动结束，非0－正在驱动)
	  
		  mode(0-获取单轴驱动状态，1－获取插补驱动状态)
    
    返回值=0正确，返回值=1错误

***********************************************************/
int CCtrlCard::Get_Status(int axis, int &value, int mode)
{


	if (mode==0)          //获取单轴驱动状态

		Result=get_status(0,axis,&value);

	else                  //获取插补驱动状态

		Result=get_inp_status(0,axis,&value);

	return Result;

}


/*****************允许减速函数******************************

no		1：X-Y或X-Y-Z或X-Y-Z-W插补		2：Z-W插补

      该函数用于驱动过程中允许减速

      返回值＝0正确 返回值＝1错误

***********************************************************/

int CCtrlCard::AllowDec(int no)
{
      Result=inp_dec_enable(0,no);

	  return Result;
}


/*****************禁止减速函数******************************

 no		1：X-Y或X-Y-Z或X-Y-Z-W插补 	2：Z-W插补

      该函数用于驱动过程中禁止减速

      返回值＝0正确 返回值＝1错误

***********************************************************/
int CCtrlCard::ForbidDec(int no)
{
	Result=inp_dec_disable(0,no);

	return Result;

}


/*******************获取轴的错误停止信息********************
       该函数用于获取轴停止的信息
     
	   value:错误状态的指针  0：无错误  1：为两字节长度的值

	   返回值＝0正确 返回值＝1错误

***********************************************************/
int CCtrlCard::Get_ErrorInf(int axis, int &value)
{
	Result=get_stopdata(0,axis,&value);

	return Result;
}


/************************获取连续插补状态*********************
       该函数用于获取连续插补允许写入状态

       value：插补状态的指针  0：不允许写入  1：允许写入
     
	   返回值＝0正确 返回值＝1错误

************************************************************/
int CCtrlCard::Get_AllowInpStatus(int no, int &value)
{
	Result=get_inp_status2(0,no,&value);

	return Result;
}


/**********************设定减速方式************************
       该函数用于设定对称或非对称和自动或手动减速

	   返回值＝0正确 返回值＝1错误
**********************************************************/
int CCtrlCard::Set_DecMode(int axis, int mode1, int mode2)
{   
	int result1,result2;

	result1=set_dec1_mode(0,axis,mode1);

	result2=set_dec2_mode(0,axis,mode2);

	Result=result1 && result2;

	return Result;
}


/**********************设定减速点************************
       该函数用于设定手动减速过程中的减速点

	   返回值＝0正确 返回值＝1错误
**********************************************************/
int CCtrlCard::Set_DecPos(int axis, long value, long startv, long speed, long add)
{
	float addtime;

	long  DecPulse;   //减速时花费的脉冲

	addtime=float(speed-startv)/add;

	DecPulse=long((startv+speed)*addtime)/2;

	Result=set_dec_pos(0,axis,value-DecPulse);

    return Result;
}


/**********************设定范围************************
       该函数用于设定速度、加减速、加减速的变化率的倍率

	   返回值＝0正确 返回值＝1错误
******************************************************/
int CCtrlCard::Setup_Range(int axis, long value)
{
	Result=set_range(0,axis,value);
	
	return Result;
}


/***********************读取输入点*******************************

     该函数用于读取单个输入点

     参数：number-输入点(0 ~ 47)

     返回值：0 － 低电平，1 － 高电平，-1 － 错误

****************************************************************/
int CCtrlCard::Read_Input(int number)
{
	Result = read_bit(0, number);
    
	return Result;
}


/*********************输出单点函数******************************

    该函数用于输出单点信号

    参数： number-输出点(0 ~ 31),value 0-低电平、1－高电平

    返回值=0正确，返回值=1错误
****************************************************************/

int CCtrlCard::Write_Output(int number, int value)
{
	Result = write_bit(0, number, value);

	return Result;

}


/*******************设置位置计数器*******************************

     该函数用于设置逻辑位置和实际位置

     参数：axis-轴号,pos-设置的位置值

      mode 0－设置逻辑位置,非0－设置实际位置

     返回值=0正确，返回值=1错误
****************************************************************/
	 
int CCtrlCard::Setup_Pos(int axis, long pos, int mode)
{
	if(mode==0)
	{
		Result = set_command_pos(0, axis, pos);
	}
	else
	{
		Result = set_actual_pos(0, axis, pos);
	}
	
	return Result;
	
}


/*******************设置COMP+寄存器*******************************

      cardno	 卡号
	  axis		 轴号（1-6）
      value	     范围值（-2147483648~+2147483647）
	 返回值	     0：正确				1：错误

****************************************************************/
int CCtrlCard::Setup_Comp1(int axis, long value)
{
	Result= set_comp1(0, axis, value);

    return Result;
}


/*******************设置COMP-寄存器*******************************

      cardno	 卡号
	  axis		 轴号（1-6）
      value	     范围值（-2147483648~+2147483647）
	 返回值	     0：正确				1：错误

****************************************************************/
int CCtrlCard::Setup_Comp2(int axis, long value)
{
	Result= set_comp2(0, axis, value);
	
    return Result;
}



