/* status_bar.c - ״̬��ģ��ʵ�� */

#include "general.h"
#include "status_b.h"

/* �ֲ�����ԭ�� */
static void draw_checker_pattern(int x1, int y1, int x2, int y2); // ���̸����
static void draw_data_block(int block_num, const char* text);      // �����������

/*---
����: init_status_bar
����: ��ʼ��״̬������
---*/
void init_status_bar() {
	// 1. �������̸�͸������
	draw_checker_pattern(BAR_X1, BAR_Y1, BAR_X2, BAR_Y2);
	
	// 2. ���Ʒָ���
	Line1(BAR_X1 + 150, BAR_Y1, BAR_X1 + 150, BAR_Y2, CHECKER_COLOR); // �������
	Line1(BAR_X1 + 350, BAR_Y1, BAR_X1 + 350, BAR_Y2, CHECKER_COLOR); // �Ҳ�����
	
	// 3. ���Ʊ�������
	puthz(BAR_X1 + 10, BAR_Y1 + 10, "��ͨ״̬���", 1, 0, CHECKER_COLOR);
}

/*---
����: draw_checker_pattern
����: ���̸񶶶�͸��Ч��ʵ��
����: x1,y1 - �������Ͻ�
x2,y2 - �������½�
---*/
static void draw_checker_pattern(int x1, int y1, int x2, int y2) {
	int checker_size = 2; // ���̸��ܶ�
	int x, y = 0;
	for ( y = y1; y <= y2; y++) {
		for (x = x1; x <= x2; x++) {
			// ���̸��㷨�����������ɫ��͸��
			if (((x / checker_size) + (y / checker_size)) % 2 == 0) {
				Putpixel64k(x, y, CHECKER_COLOR);
			}
		}
	}
}

/*---
����: draw_status_lights
����: �����źŵ�״̬
����: x,y - ��׼���꣨ͨ��Ϊ�������Ͻǣ�
---*/
void draw_status_lights(int x, int y) {
	// ���ƺ����������
//	mouse_off(&mouse);
	draw_botton(x, y, x + 90, y + 52, 0x4211, 0xFFFF);
	Circlefill(x, y + 26, 20, 0xFFFF);
	Circlefill(x + 45, y + 26, 20, 0xFFFF);
	Circlefill(x + 90, y + 26, 20, 0xFFFF);
//	mouse_on(mouse);
//	while (1) 
//	{
//		mouse_show(&mouse);
//		if (mouse_press(x, y + 26,x+40,  y + 26+40) == 1)
//		{
//			big_red_light(200, 100);
//			
//		}
//		else if (mouse_press(x + 45, y + 26,x + 45+40, y + 26+40) == 1)
//		{
//			big_yellow_light(200, 100);
//			
//		}
//		else if (mouse_press(x + 90,y + 26,x + 90+40,y + 26) == 1)
//		{
//			big_green_light(200, 100);
//			
//		}
//	}
	// ��ӱ�ǩ
	puthz(x + 5 , y + 70, "��ǰ�źŵ�", 24, 24, WORD_COLOR);
}

/*---
����: update_traffic_status
����: ����·��״̬����
����: status - ״̬�ı���"ӵ��"/"��ͨ"��
---*/
void update_traffic_status(const char* status) {
	puthz(BAR_X1 + 160, BAR_Y1 + 60,"·��״̬: ��ͨ", 16, 20, WORD_COLOR);
}

/*---
����: update_flow
����: ������������
����: vehicles - ������
pedestrians - ��������
---*/
void update_flow(int vehicles, int pedestrians) {
	puthz(BAR_X1 + 360, BAR_Y1 + 60, "����:10��/����", 16, 20, WORD_COLOR);
	puthz(BAR_X1 + 360, BAR_Y1 + 90, "����:30��/����", 16, 20, WORD_COLOR);
}
