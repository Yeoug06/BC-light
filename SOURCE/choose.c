#include"general.h"

void mode_choose(int *page) {
	mouse_off(&mouse);
	delay(100);
	
	draw_basic2();
	draw_mode_choose();//����ģʽѡ�����
	draw_partical_button();
	
	init_status_bar();
	
	// ���¶�̬����
	draw_status_lights(200,100);
	update_traffic_status("��ͨ");
	update_flow(120, 30);
	//big_lights(200, 100);
	
	
	mouse_on(mouse);
	
	while (1) {
		mouse_show(&mouse);
		if (mouse_press(100, 715, 230, 740) == 1) 
		{
			display_flow();//��ʾ���г���
		} 
		else if (mouse_press(18, 18, 52, 52) == 1) { //���ذ�ť
			*page = 0; //�л�����ҳ
			break;
		} 
		else if (mouse_press(100, 715, 230, 740) == 1) {
			*page = 2; //�л�����ҳ
			break;
		}

		
//		else if(mouse_press(200,715,330,740)==1)
//		{
//			*page=0;//�л�����ҳ
//			break;
//		}
//		else if(mouse_press(300,715,430,740)==1)
//		{
//			*page=0;//�л�����ҳ
//			break;
//		}
//		else if(mouse_press(400,715,530,740)==1)
//		{
//			*page=0;//�л�����ҳ
//			break;
//		}
//		else if(mouse_press(500,715,630,740)==1)
//		{
//			*page=0;//�л�����ҳ
//			break;
//		}
		delay(15);
	}
	
}
void draw_mode_choose(void) {
	Readbmp64k(0, 80, "PIC\\map.bmp");
	bar1(100, 715, 230, 740, 0xffffff);
	bar1(300, 715, 430, 740, 0xffffff);
	bar1(500, 715, 630, 740, 0xffffff);
	bar1(700, 715, 830, 740, 0xffffff);
	bar1(900, 715, 1020, 740, 0xffffff);
	
}

void display_flow(void) {
	bar1(900, 715, 1020, 740, 0xffffff);
}


