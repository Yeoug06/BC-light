#include"general.h"

void homepage(int *page)
{
	mouse_off(&mouse);
	delay(100);
	
	draw_basic();
	draw_homepage();//�����׽���
	
	mouse_on(mouse);
	
	while(1)
	{
		mouse_show(&mouse);
		
		if(mouse_press(340,465,470,515)==1)
		{
			*page=1;//�л�����¼����
			break;
		}
		else if(mouse_press(555,465,685,515)==1)
		{
			*page=2;//�л���ע�����
			break;
		}
		/*����Ϊ����ʱ�����ڣ�����ǰɾ��������*/
		else if(mouse_press(0,0,20,20)==1)
		{
			*page=3;//�л���ע�����
			break;
		}
		delay(15);
	}
}

void draw_homepage()
{
    //��ҳ���н���
	bar1(0,0,80,80,0x004B84);
	Readbmp64k(295,175,"PIC\\hust.bmp"); 
	Readbmp64k(559,174,"PIC\\aia.bmp"); 
	
	puthz(350,370,"��ӭ����", 32, 32, 0x000000);
	puthz(447,415,"�źŵƿ���ϵͳ", 32,32, 0x000000);
	
	draw_h_login_botton(340,465,"��¼");
	draw_h_rigister_botton(555,465,"ע��");
}

//������¼��ť
void draw_h_login_botton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+120, y1+50, 0x00FF, 0x00FF);
	puthz(x1+25, y1+8, s, 32, 42, 0xFFFFFF);
}

//����ע�ᰴť
void draw_h_rigister_botton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+120, y1+50, 0xFFFFFF, 0x00FF);
	puthz(x1+25, y1+8, s, 32, 42, 0x00FF);
}
