#include "Boot0.h"
void jump_iap_app()
{
	//if((Updata->Jump_flag == PROGRAM_NORMAL_MODE) || (Updata->bootloader0_Flag == 0)) //如果是正常模式或者bootloader0_Flag未被置位 则进入Boot
	if(Updata->Jump_flag == JUMP_IAP)//进入boot模式升级APP
	{
		;//JumpToCode(Flash_IAP_ADDR);
	}
	else if(Updata->Jump_flag == JUMP_AAP)//进入APP升级boot
	{
		;//JumpToCode(Flash_APP_ADDR);
	}
	else//否则直接进去APP
	{
		//JumpToCode(Flash_APP_ADDR);
		JumpToCode(Flash_Test_ADD);
	}		
}

/*******************************************************************
函 数 名：	 __set_MSP
功能说明：	设置堆栈指针地址
参	  数：	无
返 回 值：	无
*******************************************************************/
__asm void __set_MSP(unsigned int mainStackPointer)
{
	msr msp, r0
	bx lr
}
/*******************************************************************
函 数 名：	Jump_To_Code
功能说明：	跳转到地址对应的程序区运行
参	  数：	addr:	对代码存储区首地址
返 回 值：	无
*******************************************************************/
static void JumpToCode(unsigned int addr)
{
	
	volatile unsigned int* IapSpInitVal = (volatile unsigned int*)addr;
	unsigned int  IapJumpAddr;
	IapJumpAddr = *(unsigned int *)(addr + 4);
//	__set_MSP(*p);		//取出初始的MSP的值
//	((void (*)(void))(*(p + 1)))();
	if(((*IapSpInitVal) & 0x2FFE0000)==0x20000000)//检查栈顶地址是否合法.
	{
		__set_MSP(*IapSpInitVal);
		((void (*)(void))IapJumpAddr)();		
	}		
}



