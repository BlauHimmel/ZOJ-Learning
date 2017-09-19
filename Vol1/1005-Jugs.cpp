#include <iostream>
using namespace std;

int BottleA;	//A瓶子当前的水的体积
int BottleB;	//B瓶子当前的水的体积

/*
	假定A瓶子的容积小于B瓶子

	循环如下操作：
		倒满A瓶子
		将A瓶子的水到入B瓶子
		B瓶子的水的体积是否满足要求？
			是->停止循环
			否->B瓶子是否装满了？
				是->清空B瓶子
				否->不做任何操作
*/
int main()
{
	int VolumA, VolumB, TargetVolum;

	while (cin >> VolumA >> VolumB >> TargetVolum)
	{
		while (true)
		{
			if (BottleA == 0)
			{
				BottleA = VolumA;
				cout << "fill A" << endl;
			}

			if (BottleA + BottleB < VolumB)
			{
				BottleB += BottleA;
				BottleA = 0;
			}
			else
			{
				BottleA -= (VolumB - BottleB);
				BottleB = VolumB;
			}
			cout << "pour A B" << endl;

			if (BottleB == TargetVolum)
			{
				cout << "success" << endl;
				break;
			}

			if (BottleB == VolumB)
			{
				BottleB = 0;
				cout << "empty B" << endl;
			}
		}
	}

	return 0;
}