#include"general.h"

void rigister(int *page)
{
	struct USER temp={0};//存储信息的用户结构体 
	char judge[10]="\0";//用于判断的密码 
	
	mouse_off(&mouse);

	draw_basic();
	draw_rigister();
	
	mouse_on(mouse);

	while(1)
	{
		mouse_show(&mouse);
		
		if(mouse_press(395,190,760,239)==1)   //输入工号
		{
			mouse_off(&mouse);
			bar1(395,190,760,239,0xffff);
			strcpy(temp.name,"\0");
			Getinfo(395,190,temp.name,10,395,190,760,239);
			mouse_on(mouse);
		}

		else if(mouse_press(395,270,760,319)==1)     //输入密码
		{
			mouse_off(&mouse);
			bar1(395,270,760,319,0xffff);
			strcpy(temp.code,"\0");
			Getcode(395,270,temp.code,10,395,270,760,319);
			mouse_on(mouse);
		}
		else if(mouse_press(395,350,760,399)==1)     //确认密码
		{
			mouse_off(&mouse);
			bar1(395,350,760,399,0xffff);
			strcpy(judge,"\0");
			Getcode(395,350,judge,10,395,350,760,399);
			mouse_on(mouse);
		}
		else if(mouse_press(18,18,52,52)==1)//左上角返回键
		{
			*page=0;//切换至首页）
			break;
		}
		else if(mouse_press(340,465,460,515)==1)//确认键
		{
			if(strcmp(temp.name,"\0")!=0)//用户名不为空 
			{
				if(strcmp(temp.code,"\0")!=0)//密码不为空 
				{
					if(!strcmp(temp.code,judge))//两次密码相同 
					{
						if(save_user(temp)==0)
						{
							*page=1;
							break;
						}
						else
						{
							prt_hz24(400,560,"用户名已被注册！",10,"HZK\\Hzk24h");
							delay(1500);
							bar1(390,560,800,600,0xEBEBEB);
						}
					}
					else
					{
						prt_hz24(400,560,"两次密码不相同！",0,"HZK\\Hzk24h");
						delay(1500);
						bar1(390,560,800,600,0xEBEBEB);
					}  
				}
				else
				{
					prt_hz24(400,560,"密码为空！",0,"HZK\\Hzk24h");
					delay(1500);
					bar1(390,560,800,600,0xEBEBEB);
				}	
			}
			else
			{
				prt_hz24(400,560,"用户名为空！",0,"HZK\\Hzk24h");
				delay(1500);
				bar1(390,560,800,600,0xEBEBEB);
			}	
		}
		else if(mouse_press(555,465,685,515)==1)//"取消"键
		{
			*page=0;//切换至首页
			break;
		}
	}
}

void draw_rigister(void)
{	
	//注册特有界面
	puthz(70,25,"注册",32,32,0xEBEBEB);
	puthz(270,200,"工号", 32,84, 0x000000);
	draw_rigister_box(395,240,"请输入您的工号");
	puthz(270,280,"设定密码", 32,28, 0x000000);
	draw_rigister_box(395,320,"请设定您的密码"); 
	puthz(270,360,"确认密码", 32,28, 0x000000);
	draw_rigister_box(395,400,"请确认您的密码"); 
	
	//确定和取消按钮
	draw_r_rigister_botton(340,465,"确定");
	draw_r_cancel_botton(555,465,"取消");

}

//画出输入栏
void draw_rigister_box(int x1, int y1, char *s)
{
	Line_Thick(x1, y1, x1 + 365, y1, 1, 0xBD32 );
	prt_hz16_size(x1 + 10, y1 - 40, 2, 2, s, 0xBD32, "HZK\\HZK16s");
}

//画出确定按钮
void draw_r_rigister_botton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+120, y1+50, 0x00FF, 0x00FF);
	puthz(x1+25, y1+8, s, 32, 42, 0xFFFFFF);
}

//画出取消按钮
void draw_r_cancel_botton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+120, y1+50, 0xFFFFFF, 0x00FF);
	puthz(x1+25, y1+8, s, 32, 42, 0x00ff);
}
