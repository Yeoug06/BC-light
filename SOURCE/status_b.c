/* status_bar.c - 状态栏模块实现 */

#include "general.h"
#include "status_b.h"

/* 局部函数原型 */
static void draw_checker_pattern(int x1, int y1, int x2, int y2); // 棋盘格绘制
static void draw_data_block(int block_num, const char* text);      // 数据区块绘制

/*---
函数: init_status_bar
功能: 初始化状态栏背景
---*/
void init_status_bar() {
	// 1. 绘制棋盘格透明背景
	draw_checker_pattern(BAR_X1, BAR_Y1, BAR_X2, BAR_Y2);
	
	// 2. 绘制分割线
	Line1(BAR_X1 + 150, BAR_Y1, BAR_X1 + 150, BAR_Y2, CHECKER_COLOR); // 左侧竖线
	Line1(BAR_X1 + 350, BAR_Y1, BAR_X1 + 350, BAR_Y2, CHECKER_COLOR); // 右侧竖线
	
	// 3. 绘制标题文字
	puthz(BAR_X1 + 10, BAR_Y1 + 10, "交通状态监控", 1, 0, CHECKER_COLOR);
}

/*---
函数: draw_checker_pattern
功能: 棋盘格抖动透明效果实现
参数: x1,y1 - 区域左上角
x2,y2 - 区域右下角
---*/
static void draw_checker_pattern(int x1, int y1, int x2, int y2) {
	int checker_size = 2; // 棋盘格密度
	int x, y = 0;
	for ( y = y1; y <= y2; y++) {
		for (x = x1; x <= x2; x++) {
			// 棋盘格算法：交替绘制颜色与透明
			if (((x / checker_size) + (y / checker_size)) % 2 == 0) {
				Putpixel64k(x, y, CHECKER_COLOR);
			}
		}
	}
}

/*---
函数: draw_status_lights
功能: 绘制信号灯状态
参数: x,y - 基准坐标（通常为区块左上角）
---*/
void draw_status_lights(int x, int y) {
	// 绘制红黄绿三个灯
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
	// 添加标签
	puthz(x + 5 , y + 70, "当前信号灯", 24, 24, WORD_COLOR);
}

/*---
函数: update_traffic_status
功能: 更新路口状态文字
参数: status - 状态文本（"拥挤"/"畅通"）
---*/
void update_traffic_status(const char* status) {
	puthz(BAR_X1 + 160, BAR_Y1 + 60,"路口状态: 畅通", 16, 20, WORD_COLOR);
}

/*---
函数: update_flow
功能: 更新流量数据
参数: vehicles - 车辆数
pedestrians - 行人数量
---*/
void update_flow(int vehicles, int pedestrians) {
	puthz(BAR_X1 + 360, BAR_Y1 + 60, "车流:10辆/分钟", 16, 20, WORD_COLOR);
	puthz(BAR_X1 + 360, BAR_Y1 + 90, "人流:30人/分钟", 16, 20, WORD_COLOR);
}
