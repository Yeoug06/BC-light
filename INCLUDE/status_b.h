/* status_bar.h - ״̬��ģ������ */

#ifndef STATUS_B_H
#define STATUS_B_H

/* ��ɫ���� */
#define CHECKER_COLOR 0xFFFF    // ���̸��ɫ��16λ5:6:5��ʽ��
#define RED_LIGHT     0xF800    // ���
#define YELLOW_LIGHT  0xFFE0    // �Ƶ�
#define GREEN_LIGHT   0x07E0    // �̵�
#define WORD_COLOR    0x0000   // ��ʾ����ɫ


/* ״̬�����곣�� */
#define BAR_X1 180
#define BAR_Y1 82
#define BAR_X2 670
#define BAR_Y2 220

/* ���ܺ������� */
void init_status_bar(void);                   // ��ʼ��״̬��
void draw_status_lights(int x, int y);        // �����źŵ�
void update_traffic_status(const char* status); // ����·��״̬
void update_flow(int vehicles, int pedestrians); // ������������

#endif
