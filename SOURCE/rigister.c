#include"general.h"

void rigister(int *page)
{
	struct USER temp={0};//�洢��Ϣ���û��ṹ�� 
	char judge[10]="\0";//�����жϵ����� 
	
	mouse_off(&mouse);

	draw_basic();
	draw_rigister();
	
	mouse_on(mouse);

	while(1)
	{
		mouse_show(&mouse);
		
		if(mouse_press(395,190,760,239)==1)   //���빤��
		{
			mouse_off(&mouse);
			bar1(395,190,760,239,0xffff);
			strcpy(temp.name,"\0");
			Getinfo(395,190,temp.name,10,395,190,760,239);
			mouse_on(mouse);
		}

		else if(mouse_press(395,270,760,319)==1)     //��������
		{
			mouse_off(&mouse);
			bar1(395,270,760,319,0xffff);
			strcpy(temp.code,"\0");
			Getcode(395,270,temp.code,10,395,270,760,319);
			mouse_on(mouse);
		}
		else if(mouse_press(395,350,760,399)==1)     //ȷ������
		{
			mouse_off(&mouse);
			bar1(395,350,760,399,0xffff);
			strcpy(judge,"\0");
			Getcode(395,350,judge,10,395,350,760,399);
			mouse_on(mouse);
		}
		else if(mouse_press(18,18,52,52)==1)//���ϽǷ��ؼ�
		{
			*page=0;//�л�����ҳ��
			break;
		}
		else if(mouse_press(340,465,460,515)==1)//ȷ�ϼ�
		{
			if(strcmp(temp.name,"\0")!=0)//�û�����Ϊ�� 
			{
				if(strcmp(temp.code,"\0")!=0)//���벻Ϊ�� 
				{
					if(!strcmp(temp.code,judge))//����������ͬ 
					{
						if(save_user(temp)==0)
						{
							*page=1;
							break;
						}
						else
						{
							prt_hz24(400,560,"�û����ѱ�ע�ᣡ",10,"HZK\\Hzk24h");
							delay(1500);
							bar1(390,560,800,600,0xEBEBEB);
						}
					}
					else
					{
						prt_hz24(400,560,"�������벻��ͬ��",0,"HZK\\Hzk24h");
						delay(1500);
						bar1(390,560,800,600,0xEBEBEB);
					}  
				}
				else
				{
					prt_hz24(400,560,"����Ϊ�գ�",0,"HZK\\Hzk24h");
					delay(1500);
					bar1(390,560,800,600,0xEBEBEB);
				}	
			}
			else
			{
				prt_hz24(400,560,"�û���Ϊ�գ�",0,"HZK\\Hzk24h");
				delay(1500);
				bar1(390,560,800,600,0xEBEBEB);
			}	
		}
		else if(mouse_press(555,465,685,515)==1)//"ȡ��"��
		{
			*page=0;//�л�����ҳ
			break;
		}
	}
}

void draw_rigister(void)
{	
	//ע�����н���
	puthz(70,25,"ע��",32,32,0xEBEBEB);
	puthz(270,200,"����", 32,84, 0x000000);
	draw_rigister_box(395,240,"���������Ĺ���");
	puthz(270,280,"�趨����", 32,28, 0x000000);
	draw_rigister_box(395,320,"���趨��������"); 
	puthz(270,360,"ȷ������", 32,28, 0x000000);
	draw_rigister_box(395,400,"��ȷ����������"); 
	
	//ȷ����ȡ����ť
	draw_r_rigister_botton(340,465,"ȷ��");
	draw_r_cancel_botton(555,465,"ȡ��");

}

//����������
void draw_rigister_box(int x1, int y1, char *s)
{
	Line_Thick(x1, y1, x1 + 365, y1, 1, 0xBD32 );
	prt_hz16_size(x1 + 10, y1 - 40, 2, 2, s, 0xBD32, "HZK\\HZK16s");
}

//����ȷ����ť
void draw_r_rigister_botton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+120, y1+50, 0x00FF, 0x00FF);
	puthz(x1+25, y1+8, s, 32, 42, 0xFFFFFF);
}

//����ȡ����ť
void draw_r_cancel_botton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+120, y1+50, 0xFFFFFF, 0x00FF);
	puthz(x1+25, y1+8, s, 32, 42, 0x00ff);
}
