#include"general.h"

void big_lights(int x1,int y1)
{
	draw_botton(x1, y1, x1+90, y1+52, 0x4211, 0xFFFF);
	Circlefill(x1, y1+25, 20, 0xFFFF);//°×Ìî³äºìµÆÎ»
	Circlefill(x1+45, y1+25, 20, 0xFFFF);//°×Ìî³ä»ÆµÆÎ»
	Circlefill(x1+90, y1+25, 20, 0xFFFF);//°×Ìî³äÂÌµÆÎ»
}
void big_red_light(int x1,int y1)
{
	Circlefill(x1+45, y1+25, 20, 0xFFFF);//°×Ìî³ä»ÆµÆÎ»
	Circlefill(x1+90, y1+25, 20, 0xFFFF);//°×Ìî³äÂÌµÆÎ»
	Circlefill(x1, y1+25, 20, 0xF800);//ºìÌî³äºìµÆÎ»
}
void big_yellow_light(int x1,int y1)
{
	Circlefill(x1, y1+25, 20, 0xFFFF);//°×Ìî³äºìµÆÎ»
	Circlefill(x1+90, y1+25, 20, 0xFFFF);//°×Ìî³äÂÌµÆÎ»
	Circlefill(x1+45, y1+25, 20, 0x07E0);//»ÆÌî³ä»ÆµÆÎ»
}
void big_green_light(int x1,int y1)
{
	Circlefill(x1, y1+25, 20, 0xFFFF);//°×Ìî³äºìµÆÎ»
	Circlefill(x1+45, y1+25, 20, 0xFFFF);//°×Ìî³ä»ÆµÆÎ»
	Circlefill(x1+90, y1+25, 20, 0xFFE0);//°×Ìî³ä»ÆµÆÎ»
}


void small_lights(int x2, int y2)
{
	Circlefill(x2, y2, 12, 0xFFFF);
	Circlefill(x2, y2, 11, 0x4211);
}
void small_red_light(int x2,int y2)
{
	Circlefill(x2, y2, 10, 0xF800);
}
void small_yellow_light(int x2,int y2)
{
	Circlefill(x2, y2, 10, 0x07E0);
}
void small_green_light(int x2,int y2)
{
	Circlefill(x2, y2, 10, 0xFFE0);
}
