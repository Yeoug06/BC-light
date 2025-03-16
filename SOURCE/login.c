#include"general.h"

void login(int *page,int *func)
{
	char name[10]="\0";
	char code[10]="\0";
	int i=-5;
	
	UserList UL={0};
	InitUList(&UL);
	ReadAllUser(&UL);
	
	mouse_off(&mouse);
	
	draw_basic();
	draw_login();//绘制设置新密码界面
	
	mouse_on(mouse);
	
	while(1)
	{
		mouse_show(&mouse);
		
		if(mouse_press(395,190,760,237)==1)//点击账号框 
		{
			mouse_off(&mouse);
			strcpy(name,"\0");
			bar1(395,190,760,237,0xFFFFFF);
			Getinfo(395,190,name,10,395,190,760,237);//得到账号 
			mouse_on(mouse);
		}
		else if(mouse_press(395,290,760,337)==1)//点击密码框 
		{
			mouse_off(&mouse);
			strcpy(code,"\0");
			bar1(395,290,760,337,0xFFFFFF);
			Getcode(395,290,code,10,395,290,760,337);//得到密码 
			mouse_on(mouse);
		}
		else if(mouse_press(340,465,460,515)==1)//点击登录
		{
			i=Check_info(UL,name,code);
			if(i>=0)
			{
				*func=i;
				DestroyUList(&UL);
				*page=3;      //进入主界面
				break;
			}
			if(i==-2)//密码输入错误 
			{
				prt_hz24(570,550,"密码错误！",0,"HZK\\Hzk24h");
				delay(1500);
				bar1(570,550,690,574,0xffff);
			}
			if(i==-3)//用户不存在 
			{
				prt_hz24(570,550,"用户不存在！",0,"HZK\\Hzk24h");
				delay(1500);
				bar1(570,550,570+144,574,0xffff);
			} 
		}
		else if(mouse_press(18,18,52,52)==1)//左上角返回键
		{
			*page=0;//切换至上页（首页）
			break;
		}
		else if(mouse_press(400,400,620,424)==1)//"注册"键
		{
			*page=2;//切换至注册
			break;
		}

		else if(mouse_press(555,465,685,515)==1)//"取消"键
		{
			*page=0;//切换至首页
			break;
		}
	}
}

void draw_login(void)
{
	//登录特有界面
	puthz(70,25,"登录",32,32,0xDCDCDC);
	//登录输入框
	puthz(270,200,"工号", 32,84, 0x000000);
	draw_login_box(395,240,"请输入您的工号");
	puthz(270,300,"密码", 32,84, 0x000000);
	draw_login_box(395,340,"请输入您的密码"); 
	//注册
	puthz(395,400,"没有账号？立即注册！",24,24,0x00FF);

	//确定和取消按钮
	draw_l_login_botton(340,465,"登录");
	draw_l_cancel_botton(555,465,"取消");
}

//画出输入栏
void draw_login_box(int x1, int y1, char *s)
{
	Line_Thick(x1, y1, x1 + 365, y1, 1, 0xBD32 );
	prt_hz16_size(x1 + 10, y1 - 40, 2, 2, s, 0xBD32, "HZK\\HZK16s");
}

//画出登录按钮
void draw_l_login_botton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+120, y1+50, 0x00FF, 0x00FF);
	puthz(x1+25, y1+8, s, 32, 42, 0xFFFFFF);
}

//画出取消按钮
void draw_l_cancel_botton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+120, y1+50, 0xFFFFFF, 0x00FF);
	puthz(x1+25, y1+8, s, 32, 42, 0x00FF);
}
