#include "mouse_info.h"
#include "image_info.h"
#include "histogram_equal.h"
#include "saltpep_median_sobel.h"
#include "rotate.h"
#include "dct_idct.h"

int main()
{
	while (1)
	{
		cout << "||-����ͼ����ϵͳ-" << endl;
		cout << "||1.����ͼ��ͳ�Ʋ���" << endl;
		cout << "||2.ʵʱ��ʾ����Ҷ�" << endl;
		cout << "||3.��ʾֱ��ͼ������" << endl;
		cout << "||4.ͼ��ƽ����ֵ�˲�" << endl;
		cout << "||5.ͼ���񻯣�Sobel" << endl; 
		cout << "||6.ͼ����ת����Ƕ�" << endl;
		cout << "||7.DCT�任�Լ���ԭ" << endl;
		cout << "||8.�˳�ͼ����ϵͳ" << endl;
		cout << "||  ���������ѡ��" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1 :
			show_image_info();
			break;
		case 2 :
			show_mouse_info();
			break;
		case 3 :
			show_hist_equal();
			break;
		case 4 :
			cout << "��������ֵ�˲�ģ���С(1-9):";
			int m;
			cin >> m;
			median_blur(m);
			break;
		case 5 :
			sobel();
			break;
		case 6 :
			cout << "��������ת�ǶȵĴ�С:";
			double angle;
			cin >> angle;
			img_rotate(angle);
			break;
		case 7 :
			show_dct_idct();
			break;
		case 8 :
			return 0;
		}
	}
}