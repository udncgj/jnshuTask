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
/***********************��ʼ������**************************

    �ú����а����˿��ƿ���ʼ�����õĿ⺯�������ǵ���
    
    ���������Ļ��������Ա�����ʾ�����������ȵ���
    
    ����ֵ<=0��ʾ��ʼ��ʧ�ܣ�����ֵ>0��ʾ��ʼ���ɹ�

***********************************************************/
int CCtrlCard::Init_Board()
{
	Result = adt856_initial() ;         //����ʼ������    
	
	if (Result <= 0) return Result;	
    
    for (int i = 1; i<=MAXAXIS; i++)
	{
		
		set_range (0, i, 8000000 / 5);         //�趨��Χ,���ó�ʼ����Ϊ5
		
		set_command_pos (0, i, 0);        //���߼�������
		
		set_actual_pos (0, i, 0);         //��ʵλ������
		
		set_startv (0, i, 100);          //�趨��ʼ�ٶ�
		
		set_speed (0, i, 100);           //�趨�����ٶ�

       	set_acc (0, i, 625);              //�趨���ٶ�
		
    }
    
    return 1;
	
}


/**********************�ͷſ��ƿ�����***********************

    �ú����а������ͷſ��ƿ��Ŀ⺯�������Ǵ˺���Ӧ��

	���������ʱ�����   
***********************************************************/

int CCtrlCard::End_Board ()
{
	Result = adt856_end();
	
	return Result;
}


/********************����stop0�źŷ�ʽ**********************

   �ú��������趨stop0�źŵ�ģʽ

   ������ axis�����
          value   0����Ч  1����Ч
		  logic   0���͵�ƽֹͣ  1���ߵ�ƽֹͣ
   Ĭ��ģʽΪ����Ч

   ����ֵ=0��ȷ������ֵ=1����
  *********************************************************/
int CCtrlCard::Setup_Stop0Mode(int axis, int value, int logic)
{
	Result = set_stop0_mode(0, axis, value ,logic);

	return Result;

}


/********************����stop1�źŷ�ʽ**********************

   �ú��������趨stop1�źŵ�ģʽ

   ������ axis�����
          value   0����Ч  1����Ч
		  logic   0���͵�ƽֹͣ  1���ߵ�ƽֹͣ
   Ĭ��ģʽΪ����Ч

   ����ֵ=0��ȷ������ֵ=1����
  *********************************************************/
int CCtrlCard::Setup_Stop1Mode(int axis, int value, int logic)
{
	Result = set_stop1_mode(0, axis, value, logic);

	return Result;

}

/********************����stop2�źŷ�ʽ**********************

   �ú��������趨stop2�źŵ�ģʽ

   ������ axis����ţ�1-6��
          value   0����Ч  1����Ч
		  logic   0���͵�ƽֹͣ  1���ߵ�ƽֹͣ
   Ĭ��ģʽΪ����Ч

   ����ֵ=0��ȷ������ֵ=1����
***********************************************************/
int CCtrlCard::Setup_Stop2Mode(int axis, int value, int logic)
{
	Result = set_stop2_mode(0, axis, value, logic);

	return Result;

}

/*********************����ʵ��λ�ü�����********************
cardno	   ����

axis	   ��ţ�1-6��

value	   �������巽ʽ

0��        A/B��������		1����/�£�PPIN/PMIN����������

dir		  ��������

0��	      A��ǰB��PPIN�����������ϼ���
		  B��ǰA��PMIN�����������¼���
1��       B��ǰA��PMIN�����������ϼ���
		  A��ǰB��PPIN�����������¼���

freq	  A/B��������ʱ�ı�Ƶ����/����������ʱ��Ч

0��4��Ƶ     1��2��Ƶ        2������Ƶ

����ֵ	     0����ȷ	   	 1������

��ʼ��ʱ״̬Ϊ��A/B���������룬����Ϊ0��4��Ƶ
***********************************************************/
int CCtrlCard::Actualcount_Mode(int axis,int value, int dir,int freq)
{

	Result = set_actualcount_mode(0, axis, value,dir,freq);
	
	return Result;
}

/********************�������������ʽ***********************
      
	�ú���������������Ĺ�����ʽ

	������axis-��ţ� value-���巽ʽ 0�����士���巽ʽ 1�����士����ʽ

    ����ֵ=0��ȷ������ֵ=1����

    Ĭ�����巽ʽΪ���士����ʽ

    ���������Ĭ�ϵ����߼�����ͷ�������ź����߼�

***********************************************************/
int CCtrlCard::Setup_PulseMode(int axis, int value)
{
	Result = set_pulse_mode(0, axis, value, 0, 0);
	
	return Result;	

}

/*********************������λ�źŷ�ʽ**********************

   �ú��������趨��/��������λ����nLMT�źŵ�ģʽ

   ������ axis����ţ�1-6��

          value   0����Чʱ����ֹͣ  1����Чʱ����ֹͣ
		  
		  logic    0���͵�ƽ��Ч  1���ߵ�ƽ��Ч

   Ĭ��ģʽΪ������λ��Ч������λ��Ч���͵�ƽ��Ч

   ����ֵ=0��ȷ������ֵ=1����
***********************************************************/
int CCtrlCard::Setup_LimitMode(int axis, int value, int logic)
{
	Result = set_limit_mode(0, axis, value,  logic);

	return Result;

}

/******************����COMP+�Ĵ������������****************
cardno	   ����

axis		��ţ�1-6��

value		0����Ч				1����Ч

����ֵ	    0����ȷ				1������

��ʼ��ʱ״̬Ϊ����Ч
ע�⣺�����λ���Ǽ���ֹͣ����ô����ֵ�Ϳ��ܻس����趨ֵ��
������趨��ΧʱӦ���ǵ���һ�㡣
***********************************************************/
int CCtrlCard::Setsoft_LimitMode1(int axis, int value)
{
    Result =  set_softlimit_mode1(0, axis, value);

	return Result;

}

/******************����COMP-�Ĵ������������****************
cardno	   ����

axis		��ţ�1-6��

value		0����Ч				1����Ч

����ֵ	    0����ȷ				1������

��ʼ��ʱ״̬Ϊ����Ч

ע�⣺�����λ���Ǽ���ֹͣ����ô����ֵ�Ϳ��ܻس����趨ֵ��
������趨��ΧʱӦ���ǵ���һ�㡣
***********************************************************/
int CCtrlCard::Setsoft_LimitMode2(int axis, int value)
{
    Result =  set_softlimit_mode2(0, axis, value);

	return Result;

}

/****************����COMP+/-�Ĵ������������****************
cardno	   ����

axis		��ţ�1-6��

value		0���߼�λ�ü�����		1��ʵ��λ�ü�����

����ֵ	    0����ȷ				1������

Ĭ��ģʽΪ : �߼�λ�ü�����
�˺������趨�����λ�ıȽ϶���
***********************************************************/
int CCtrlCard::Setsoft_LimitMode3(int axis, int value)
{
    Result =  set_softlimit_mode3(0, axis, value);

	return Result;

}

/****************�ŷ���λ�ź�nINPOS���趨*******************
cardno	   ����

axis		��ţ�1-6��

value		0����Ч				1����Ч

logic		0���͵�ƽ��Ч		1���ߵ�ƽ��Ч

����ֵ	    0����ȷ				1������
Ĭ��ģʽΪ : ��Ч���͵�ƽ��Ч
***********************************************************/
int CCtrlCard::Inpos_Mode(int axis, int value, int logic)
{
	Result = set_inpos_mode(0, axis,value,logic);
	
	return Result;
}

/****************�ŷ������ź�nALARM���趨*******************
cardno	   ����

axis		��ţ�1-6��

value		0����Ч					1����Ч

logic		0���͵�ƽ��Ч			1���ߵ�ƽ��Ч

����ֵ	    0����ȷ					1������
Ĭ��ģʽΪ : ��Ч���͵�ƽ��Ч
***********************************************************/

int CCtrlCard:: Setup_AlarmMode(int axis,int value,int logic)
{
	Result = set_alarm_mode(0, axis,value,logic);
	
	return Result;
}


/************************�����ٶ�ģ��***********************

    ���ݲ�����ֵ���ж������ٻ��ǼӼ���

    ���÷�Χ���Ǿ������ʵĲ���  
	
	������ĳ�ʼ�ٶȡ������ٶȺͼ��ٶ�

    ������axis   -���

	      startv -��ʼ�ٶ�

		  speed  -�����ٶ�

          add    -���ٶ�

          dec    -���ٶ�

		  ratio  -����

          mode   -ģʽ
    
    ����ֵ=0��ȷ������ֵ=1����

***********************************************************/
int CCtrlCard::Setup_Speed(int axis, long startv, long speed, long add ,long dec,long ratio,int mode)
{
	//�����˶�
	if (startv - speed >= 0) 
	{
		Result = set_range(0, axis, 8000000/ratio);
		
		set_startv(0, axis, startv/ratio);
		
		set_speed (0, axis, startv/ratio);
	}
	else//��/�����˶�
	{
		if (mode == 0)//��ѡ��ֱ�߼Ӽ���ʱ������Ӧ�Ĵ���
		{
            set_dec1_mode(0,axis,0);//��Ϊ�ԳƷ�ʽ
			
			set_dec2_mode(0,axis,0);//����Ϊ�Զ�����

            set_ad_mode(0,axis,0);//����Ϊֱ�߼Ӽ��ٷ�ʽ
			
			Result = set_range(0, axis, 8000000/ratio);
			
			set_startv(0, axis, startv/ratio);
			
			set_speed (0, axis, speed/ratio);
			
			set_acc (0, axis, add/125/ratio);
					
			
		}
		else if(mode==1)//��ѡ��ֱ�߼Ӽ���ʱ������Ӧ�Ĵ���
		{
			
			set_dec1_mode(0,axis,1);//��Ϊ�ǶԳƷ�ʽ
			
			set_dec2_mode(0,axis,0);//����Ϊ�Զ�����

		    set_ad_mode(0,axis,0);////����Ϊֱ�߼Ӽ��ٷ�ʽ	

			Result = set_range(0, axis, 8000000/ratio);
			
			set_startv(0, axis, startv/ratio);
			
			set_speed (0, axis, speed/ratio);
			
			set_acc (0, axis, add/125/ratio);
			
			set_dec (0, axis, dec/125/ratio);
						
		
		}
		else if(mode==2)//��ѡ��S���߼Ӽ���ʱ������Ӧ�Ĵ���
		{
			float time;//ʱ��Ķ���

			float addvar;//���ٶȱ仯��

			long k;//Ҫ������Ľ��

            time = (float)(speed-startv)/(add/2);//�������ٶ�ʱ��

			addvar=add/(time/2);//���ٶȱ仯��

			k=(long)(62500000/addvar)*ratio;

            set_dec2_mode(0,axis,0);//����Ϊ�Զ�����

            set_ad_mode(0,axis,1);////����ΪS���߼Ӽ��ٷ�ʽ	

			Result = set_range(0, axis, 8000000/ratio);
			
			set_startv(0, axis, startv/ratio);
			
			set_speed (0, axis, speed/ratio);
			
			set_acc (0, axis, add/125/ratio);
			
			set_acac (0, axis,k );					
			
		}		
		
	}
	
	return Result;
	
}


/************************������������***********************

    �ú����������������˶����˶�

    ������ axis-��ţ�value-���������
    
    ����ֵ=0��ȷ������ֵ=1����

***********************************************************/
int CCtrlCard::Axis_Pmove(int axis, long value)
{
	Result = pmove(0, axis, value);
	
	return Result;

}


/************************���ắ����������***********************

    �ú����������������˶����˶�

    ������ axis-��ţ�value-���巽��
    
    ����ֵ=0��ȷ������ֵ=1����

***********************************************************/
int CCtrlCard::Axis_Cmove(int axis, long value)
{
	Result = continue_move(0, axis, value);
	
	return Result;

}


/**********************����岹����*********************

     �ú�����������XY��ZW������в岹�˶�
	 no ->   1: X-Y       2:Z-W
    
    ����ֵ=0��ȷ������ֵ=1����

***********************************************************/
int CCtrlCard::Interp_Move2(int no, long value1, long value2)
{
	Result = inp_move2(0, no, value1, value2);

	return Result;

}


/*********************����岹����**********************

    �ú�����������XYZ������в岹�˶�
    
    ����ֵ=0��ȷ������ֵ=1����

***********************************************************/
int CCtrlCard::Interp_Move3(long value1, long value2, long value3)
{
	Result = inp_move3(0, value1, value2, value3);

	return Result;

}


/*******************����岹����****************************

    �ú�����������XYZW������в岹�˶�

    ����ֵ=0��ȷ������ֵ=1����

***********************************************************/
int CCtrlCard::Interp_Move4(long value1, long value2, long value3, long value4)
{
	Result = inp_move4(0, value1, value2, value3, value4);

	return Result;

}

/*******************����岹����***********************
    �ú�����������XYZWUV������в岹�˶�
    ����ֵ=0��ȷ������ֵ=1����
******************************************************/
int CCtrlCard::Interp_Move6(long value1, long value2, long value3, long value4, long value5, long value6)
{
	Result = inp_move6(0, value1, value2, value3, value4,value5, value6);

	return Result;

}

/**********************˳ʱ��CWԲ���岹����*****************

 no	    	����岹�����      1��X-Y    2��Z-W

 x,y		Բ���岹���յ�λ�ã��������㣩
				
 i,j		Բ���岹��Բ�ĵ�λ�ã��������㣩

            �ú�����������XY��ZW�����Բ���岹�˶�
    
             ����ֵ=0��ȷ������ֵ=1����

***********************************************************/
int CCtrlCard::Interp_Arc(int no, long x, long y, long i,long j)
{
	Result = inp_cw_arc(0,no,x,y,i,j);

	return Result;
}


/**********************��ʱ��CCWԲ���岹����****************
no	    	����岹�����      1��X-Y    2��Z-W

x,y		Բ���岹���յ�λ�ã��������㣩
				
i,j		Բ���岹��Բ�ĵ�λ�ã��������㣩

    �ú�����������XY��ZW�����Բ���岹�˶�
    
    ����ֵ=0��ȷ������ֵ=1����

***********************************************************/
int CCtrlCard::Interp_CcwArc(int no, long x, long y, long i,long j)
{
	Result = inp_ccw_arc(0,no,x,y,i,j);

	return Result;
}


/*****************�������Ŀɱ价���ܵ��趨******************
      �ɱ价�����ǿ��԰�������μ������������ֵ��ѡ�趨��
	�����λ����ֱ�߶�����ת�˶��Ļ����ô˹��ܿ���λ�úܷ���.
    ����ֵ	0����ȷ					1������
***********************************************************/
int CCtrlCard::SetCircle_Mode(int axis, int value)
{
	Result = set_circle_mode(0,  axis, value);
	
	return Result;
}


/********************�����ź��˲���������*******************

  	value		0���˲���Ч			1���˲���Ч

	Ĭ��ģʽΪ : ��Ч

***********************************************************/
int CCtrlCard::Setup_InputFilter(int axis,int number,int value)
{
	
	Result = set_input_filter(0, axis, number, value);

	return Result;
}


/*******************�����ź��˲�ʱ�䳣������****************
axis		��ţ�1-6��

value      ���Գ�ȥ�����������      �����ӳ�
***********************************************************/
int CCtrlCard::Setup_FilterTime(int axis,int value)
{
	
	Result = set_filter_time(0, axis, value);
	
	return Result;
}


/************************��ȡ�˶���Ϣ***********************

    �ú������ڷ����ᵱǰ���߼�λ�ã�ʵ��λ�ú������ٶ�

    ������axis-���,LogPos-�߼�λ��,ActPos-ʵ��λ��,Speed-�����ٶ�
    
    ����ֵ=0��ȷ������ֵ=1����

***********************************************************/
int CCtrlCard::Get_CurrentInf(int axis, long &LogPos, long &ActPos, long &Speed)
{
	Result = get_command_pos(0, axis, &LogPos);
    
    get_actual_pos (0, axis, &ActPos);
    
    get_speed (0, axis, &Speed);

	return Result;
}

/*****************ֹͣ������********************************

    �ú����������������ֹͣ�������

	������axis-��š�mode-���ٷ�ʽ(0������ֹͣ, 1������ֹͣ)
    
    ����ֵ=0��ȷ������ֵ=1����

***********************************************************/
int CCtrlCard::StopRun(int axis, int mode)
{
	if(mode == 0)       //����ֹͣ
    {
        Result = sudden_stop(0, axis);
	}   
    else                 //����ֹͣ
    {
        Result = dec_stop(0, axis);
	}   
    return Result;
	
}


/*****************��ȡ�������״̬**************************

    �ú������ڻ�ȡ���������״̬��岹����״̬

    ������axis=no -��ţ�value-״ָ̬��(0-������������0����������)
	  
		  mode(0-��ȡ��������״̬��1����ȡ�岹����״̬)
    
    ����ֵ=0��ȷ������ֵ=1����

***********************************************************/
int CCtrlCard::Get_Status(int axis, int &value, int mode)
{


	if (mode==0)          //��ȡ��������״̬

		Result=get_status(0,axis,&value);

	else                  //��ȡ�岹����״̬

		Result=get_inp_status(0,axis,&value);

	return Result;

}


/*****************������ٺ���******************************

no		1��X-Y��X-Y-Z��X-Y-Z-W�岹		2��Z-W�岹

      �ú������������������������

      ����ֵ��0��ȷ ����ֵ��1����

***********************************************************/

int CCtrlCard::AllowDec(int no)
{
      Result=inp_dec_enable(0,no);

	  return Result;
}


/*****************��ֹ���ٺ���******************************

 no		1��X-Y��X-Y-Z��X-Y-Z-W�岹 	2��Z-W�岹

      �ú����������������н�ֹ����

      ����ֵ��0��ȷ ����ֵ��1����

***********************************************************/
int CCtrlCard::ForbidDec(int no)
{
	Result=inp_dec_disable(0,no);

	return Result;

}


/*******************��ȡ��Ĵ���ֹͣ��Ϣ********************
       �ú������ڻ�ȡ��ֹͣ����Ϣ
     
	   value:����״̬��ָ��  0���޴���  1��Ϊ���ֽڳ��ȵ�ֵ

	   ����ֵ��0��ȷ ����ֵ��1����

***********************************************************/
int CCtrlCard::Get_ErrorInf(int axis, int &value)
{
	Result=get_stopdata(0,axis,&value);

	return Result;
}


/************************��ȡ�����岹״̬*********************
       �ú������ڻ�ȡ�����岹����д��״̬

       value���岹״̬��ָ��  0��������д��  1������д��
     
	   ����ֵ��0��ȷ ����ֵ��1����

************************************************************/
int CCtrlCard::Get_AllowInpStatus(int no, int &value)
{
	Result=get_inp_status2(0,no,&value);

	return Result;
}


/**********************�趨���ٷ�ʽ************************
       �ú��������趨�Գƻ�ǶԳƺ��Զ����ֶ�����

	   ����ֵ��0��ȷ ����ֵ��1����
**********************************************************/
int CCtrlCard::Set_DecMode(int axis, int mode1, int mode2)
{   
	int result1,result2;

	result1=set_dec1_mode(0,axis,mode1);

	result2=set_dec2_mode(0,axis,mode2);

	Result=result1 && result2;

	return Result;
}


/**********************�趨���ٵ�************************
       �ú��������趨�ֶ����ٹ����еļ��ٵ�

	   ����ֵ��0��ȷ ����ֵ��1����
**********************************************************/
int CCtrlCard::Set_DecPos(int axis, long value, long startv, long speed, long add)
{
	float addtime;

	long  DecPulse;   //����ʱ���ѵ�����

	addtime=float(speed-startv)/add;

	DecPulse=long((startv+speed)*addtime)/2;

	Result=set_dec_pos(0,axis,value-DecPulse);

    return Result;
}


/**********************�趨��Χ************************
       �ú��������趨�ٶȡ��Ӽ��١��Ӽ��ٵı仯�ʵı���

	   ����ֵ��0��ȷ ����ֵ��1����
******************************************************/
int CCtrlCard::Setup_Range(int axis, long value)
{
	Result=set_range(0,axis,value);
	
	return Result;
}


/***********************��ȡ�����*******************************

     �ú������ڶ�ȡ���������

     ������number-�����(0 ~ 47)

     ����ֵ��0 �� �͵�ƽ��1 �� �ߵ�ƽ��-1 �� ����

****************************************************************/
int CCtrlCard::Read_Input(int number)
{
	Result = read_bit(0, number);
    
	return Result;
}


/*********************������㺯��******************************

    �ú���������������ź�

    ������ number-�����(0 ~ 31),value 0-�͵�ƽ��1���ߵ�ƽ

    ����ֵ=0��ȷ������ֵ=1����
****************************************************************/

int CCtrlCard::Write_Output(int number, int value)
{
	Result = write_bit(0, number, value);

	return Result;

}


/*******************����λ�ü�����*******************************

     �ú������������߼�λ�ú�ʵ��λ��

     ������axis-���,pos-���õ�λ��ֵ

      mode 0�������߼�λ��,��0������ʵ��λ��

     ����ֵ=0��ȷ������ֵ=1����
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


/*******************����COMP+�Ĵ���*******************************

      cardno	 ����
	  axis		 ��ţ�1-6��
      value	     ��Χֵ��-2147483648~+2147483647��
	 ����ֵ	     0����ȷ				1������

****************************************************************/
int CCtrlCard::Setup_Comp1(int axis, long value)
{
	Result= set_comp1(0, axis, value);

    return Result;
}


/*******************����COMP-�Ĵ���*******************************

      cardno	 ����
	  axis		 ��ţ�1-6��
      value	     ��Χֵ��-2147483648~+2147483647��
	 ����ֵ	     0����ȷ				1������

****************************************************************/
int CCtrlCard::Setup_Comp2(int axis, long value)
{
	Result= set_comp2(0, axis, value);
	
    return Result;
}



