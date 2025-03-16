#include"general.h"

void draw_basic2(void)
{
	/*共有界面2*/
	//底色,顶栏,底部
	bar1(0,0,1024,768,0xEBEBEB);
	bar1(0,0,1024,80,0x004B84);
	Readbmp64k(240,10,"PIC\\topwords.bmp"); 
	
	//返回上一级圆圈箭头
	Circlefill(40,40,23,0x007BD9);
	Line_Thick(44,30,33,41,1,0xEBEBEB);
	Line_Thick(33,41,44,52,1,0xEBEBEB);
	
	//下部功能选择
	draw_bottom_blank();
}

void draw_bottom_blank(void)
{
	bar1(0,700,1024,768,0x004B84);
}
