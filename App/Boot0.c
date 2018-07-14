#include "Boot0.h"
void jump_iap_app()
{
	//if((Updata->Jump_flag == PROGRAM_NORMAL_MODE) || (Updata->bootloader0_Flag == 0)) //���������ģʽ����bootloader0_Flagδ����λ �����Boot
	if(Updata->Jump_flag == JUMP_IAP)//����bootģʽ����APP
	{
		;//JumpToCode(Flash_IAP_ADDR);
	}
	else if(Updata->Jump_flag == JUMP_AAP)//����APP����boot
	{
		;//JumpToCode(Flash_APP_ADDR);
	}
	else//����ֱ�ӽ�ȥAPP
	{
		//JumpToCode(Flash_APP_ADDR);
		JumpToCode(Flash_Test_ADD);
	}		
}

/*******************************************************************
�� �� ����	 __set_MSP
����˵����	���ö�ջָ���ַ
��	  ����	��
�� �� ֵ��	��
*******************************************************************/
__asm void __set_MSP(unsigned int mainStackPointer)
{
	msr msp, r0
	bx lr
}
/*******************************************************************
�� �� ����	Jump_To_Code
����˵����	��ת����ַ��Ӧ�ĳ���������
��	  ����	addr:	�Դ���洢���׵�ַ
�� �� ֵ��	��
*******************************************************************/
static void JumpToCode(unsigned int addr)
{
	
	volatile unsigned int* IapSpInitVal = (volatile unsigned int*)addr;
	unsigned int  IapJumpAddr;
	IapJumpAddr = *(unsigned int *)(addr + 4);
//	__set_MSP(*p);		//ȡ����ʼ��MSP��ֵ
//	((void (*)(void))(*(p + 1)))();
	if(((*IapSpInitVal) & 0x2FFE0000)==0x20000000)//���ջ����ַ�Ƿ�Ϸ�.
	{
		__set_MSP(*IapSpInitVal);
		((void (*)(void))IapJumpAddr)();		
	}		
}



