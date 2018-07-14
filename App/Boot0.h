#ifndef _boot0_h
#define _boot0_h

#define FLASH_UPDATEFLAG_ADDR	((unsigned int)(0x8006000))//0x800600 start update flag data

#define PROGRAM_UPGRADE_MODE       0x55FFFF55 //upgrade mode，run in bootload 
#define PROGRAM_NORMAL_MODE        0xAA0000AA //normal mode，run to app
#define	JUMP_IAP				   0xAABBBBAA
#define	JUMP_AAP				   0xBBAAAABB


#define Flash_IAP_ADDR  0x8000400   //0x8000400 start size 23k end(0x8006000)
#define Flash_APP_ADDR  0x8006400   //0x8006400 start  size 30k end(0x800DC00)

#define	Flash_Test_ADD	0x8000400

#pragma pack(push,1)
typedef struct
{
	unsigned int Jump_flag;				//Bootloader_0程序跳转标记
	unsigned int bootloader_Version;	//Bootloader版本
	unsigned char bootloader0_Flag;		//bootloader1软件版本
	unsigned char bootloader1_Flag;		//bootloader1软件版本大小
}_Updata;
#pragma pack(pop)

#define Updata			((_Updata*)(FLASH_UPDATEFLAG_ADDR))	//设备分区表的地址信息

static void JumpToCode(unsigned int addr);
void jump_iap_app(void);
#endif

