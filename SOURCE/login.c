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
	draw_login();//�����������������
	
	mouse_on(mouse);
	
	while(1)
	{
		mouse_show(&mouse);
		
		if(mouse_press(395,190,760,237)==1)//����˺ſ� 
		{
			mouse_off(&mouse);
			strcpy(name,"\0");
			bar1(395,190,760,237,0xFFFFFF);
			Getinfo(395,190,name,10,395,190,760,237);//�õ��˺� 
			mouse_on(mouse);
		}
		else if(mouse_press(395,290,760,337)==1)//�������� 
		{
			mouse_off(&mouse);
			strcpy(code,"\0");
			bar1(395,290,760,337,0xFFFFFF);
			Getcode(395,290,code,10,395,290,760,337);//�õ����� 
			mouse_on(mouse);
		}
		else if(mouse_press(340,465,460,515)==1)//�����¼
		{
			i=Check_info(UL,name,code);
			if(i>=0)
			{
				*func=i;
				DestroyUList(&UL);
				*page=3;      //����������
				break;
			}
			if(i==-2)//����������� 
			{
				prt_hz24(570,550,"�������",0,"HZK\\Hzk24h");
				delay(1500);
				bar1(570,550,690,574,0xffff);
			}
			if(i==-3)//�û������� 
			{
				prt_hz24(570,550,"�û������ڣ�",0,"HZK\\Hzk24h");
				delay(1500);
				bar1(570,550,570+144,574,0xffff);
			} 
		}
		else if(mouse_press(18,18,52,52)==1)//���ϽǷ��ؼ�
		{
			*page=0;//�л�����ҳ����ҳ��
			break;
		}
		else if(mouse_press(400,400,620,424)==1)//"ע��"��
		{
			*page=2;//�л���ע��
			break;
		}

		else if(mouse_press(555,465,685,515)==1)//"ȡ��"��
		{
			*page=0;//�л�����ҳ
			break;
		}
	}
}

void draw_login(void)
{
	//��¼���н���
	puthz(70,25,"��¼",32,32,0xDCDCDC);
	//��¼�����
	puthz(270,200,"����", 32,84, 0x000000);
	draw_login_box(395,240,"���������Ĺ���");
	puthz(270,300,"����", 32,84, 0x000000);
	draw_login_box(395,340,"��������������"); 
	//ע��
	puthz(395,400,"û���˺ţ�����ע�ᣡ",24,24,0x00FF);

	//ȷ����ȡ����ť
	draw_l_login_botton(340,465,"��¼");
	draw_l_cancel_botton(555,465,"ȡ��");
}

//����������
void draw_login_box(int x1, int y1, char *s)
{
	Line_Thick(x1, y1, x1 + 365, y1, 1, 0xBD32 );
	prt_hz16_size(x1 + 10, y1 - 40, 2, 2, s, 0xBD32, "HZK\\HZK16s");
}

//������¼��ť
void draw_l_login_botton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+120, y1+50, 0x00FF, 0x00FF);
	puthz(x1+25, y1+8, s, 32, 42, 0xFFFFFF);
}

//����ȡ����ť
void draw_l_cancel_botton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+120, y1+50, 0xFFFFFF, 0x00FF);
	puthz(x1+25, y1+8, s, 32, 42, 0x00FF);
}
