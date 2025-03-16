#include"general.h"

void main()
{
	int page=0;
	int func=0;
	
	SetSVGA64k();
	mouse_init();
	
	while(1)
	{
		switch (page) 
		{
			case 0:
				homepage(&page);//首页
				break;
			case 1:
				login(&page,&func);//登录
				break;
			case 2:
				rigister(&page);//注册
				break;
			case 3:
				mode_choose(&page);//模式选择
				break;
			case 4:
			
			//	map(&page);//地图
				break;
		}
	}
	CloseSVGA();
}
