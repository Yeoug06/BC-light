#include"general.h"

void draw_basic(void)
{
	/*共有界面*/
	//底色,顶栏,底部
	bar1(0,0,1024,768,0xEBEBEB);
	bar1(0,0,1024,80,0x004B84);
	Readbmp64k(240,10,"PIC\\topwords.bmp"); 
	Readbmp64k(0,603,"PIC\\building.bmp");
	
	//内容框
	Circlefill(255,160,20,0xFFFFFF);
	Circlefill(769,160,20,0xFFFFFF);
	bar1(235,160,789,525,0xFFFFFF);
	bar1(255,140,769,545,0xFFFFFF);
	Circlefill(255,525,20,0xFFFFFF);
	Circlefill(769,525,20,0xFFFFFF);
	
	//返回上一级圆圈箭头
	Circlefill(40,40,23,0x007BD9);
	Line_Thick(44,30,33,41,1,0xEBEBEB);
	Line_Thick(33,41,44,52,1,0xEBEBEB);
}

void draw_botton(int x1, int y1, int x2, int y2, int cowercolor, int bordercolor)
{
	Cirbar(x1,y1,x2,y2,bordercolor);
	Cirbar(x1,y1+1,x2,y2-2,cowercolor);
}
