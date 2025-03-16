#include"general.h"

void homepage(int *page)
{
	mouse_off(&mouse);
	delay(100);
	
	draw_basic();
	draw_homepage();//绘制首界面
	
	mouse_on(mouse);
	
	while(1)
	{
		mouse_show(&mouse);
		
		if(mouse_press(340,465,470,515)==1)
		{
			*page=1;//切换至登录界面
			break;
		}
		else if(mouse_press(555,465,685,515)==1)
		{
			*page=2;//切换至注册界面
			break;
		}
		/*以下为调试时便捷入口，验收前删除！！！*/
		else if(mouse_press(0,0,20,20)==1)
		{
			*page=3;//切换至注册界面
			break;
		}
		delay(15);
	}
}

void draw_homepage()
{
    //主页特有界面
	bar1(0,0,80,80,0x004B84);
	Readbmp64k(295,175,"PIC\\hust.bmp"); 
	Readbmp64k(559,174,"PIC\\aia.bmp"); 
	
	puthz(350,370,"欢迎进入", 32, 32, 0x000000);
	puthz(447,415,"信号灯控制系统", 32,32, 0x000000);
	
	draw_h_login_botton(340,465,"登录");
	draw_h_rigister_botton(555,465,"注册");
}

//画出登录按钮
void draw_h_login_botton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+120, y1+50, 0x00FF, 0x00FF);
	puthz(x1+25, y1+8, s, 32, 42, 0xFFFFFF);
}

//画出注册按钮
void draw_h_rigister_botton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+120, y1+50, 0xFFFFFF, 0x00FF);
	puthz(x1+25, y1+8, s, 32, 42, 0x00FF);
}
