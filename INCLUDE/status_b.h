/* status_bar.h - 状态栏模块声明 */

#ifndef STATUS_B_H
#define STATUS_B_H

/* 颜色定义 */
#define CHECKER_COLOR 0xFFFF    // 棋盘格灰色（16位5:6:5格式）
#define RED_LIGHT     0xF800    // 红灯
#define YELLOW_LIGHT  0xFFE0    // 黄灯
#define GREEN_LIGHT   0x07E0    // 绿灯
#define WORD_COLOR    0x0000   // 提示字颜色


/* 状态栏坐标常量 */
#define BAR_X1 180
#define BAR_Y1 82
#define BAR_X2 670
#define BAR_Y2 220

/* 功能函数声明 */
void init_status_bar(void);                   // 初始化状态栏
void draw_status_lights(int x, int y);        // 绘制信号灯
void update_traffic_status(const char* status); // 更新路口状态
void update_flow(int vehicles, int pedestrians); // 更新流量数据

#endif
