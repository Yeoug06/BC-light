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
				homepage(&page);//��ҳ
				break;
			case 1:
				login(&page,&func);//��¼
				break;
			case 2:
				rigister(&page);//ע��
				break;
			case 3:
				mode_choose(&page);//ģʽѡ��
				break;
			case 4:
			
			//	map(&page);//��ͼ
				break;
		}
	}
	CloseSVGA();
}
