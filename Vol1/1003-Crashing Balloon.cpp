#include <iostream>
using namespace std;

bool ALegal, BLegal;    //A和B的分数是否合法

/*
    保证传入的参数中A的分数小于B的分数
*/
void Judge(int AScore, int BScore, int Number)
{
    //只有分数较小者A说真话，分数较大者B说假话，分数较小者A才会赢
	if (AScore == 1)
	{
		ALegal = true;

		if (BScore == 1)
		{
			BLegal = true;
		}
	}

    //所有的因数计算完成后结束递归
	if (Number == 1 || (ALegal && BLegal))
	{
		return;
	}

	if (AScore % Number == 0)
	{
		Judge(AScore / Number, BScore, Number - 1);
	}

	if (BScore % Number == 0)
	{
		Judge(AScore, BScore / Number, Number - 1);
	}

	Judge(AScore, BScore, Number - 1);
}

int main()
{
	int AScore, BScore;

	while ((cin >> AScore >> BScore) && AScore != 0 && BScore != 0)
	{
		ALegal = false;
		BLegal = false;

		if (AScore > BScore)
		{
			int Tmp = AScore;
			AScore = BScore;
			BScore = Tmp;
		}

		Judge(AScore, BScore, 100);

		if (ALegal && !BLegal)
		{
			cout << AScore << endl;
		}
		else
		{
			cout << BScore << endl;
		}
	}

	return 0;
}