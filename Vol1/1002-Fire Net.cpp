#include <iostream>
using namespace std;

char Map[4][4];			//地图信息
int MaxHouse = 0;		//当前最多放置房子的数量
int n;					//地图的边长

/*
	获得地图指定位置的索引号(从0开始，从左到右，从上到下依次递增)
*/
int GetIndex(int Row, int Col)
{
	return Row * n + Col;
}

/*
	通过地图位置的索引号得到该位置的行号(从0开始)
*/
int GetRow(int Index)
{
	return Index / n;
}

/*
	通过地图位置的索引号得到该位置的列号(从0开始)
*/
int GetCol(int Index)
{
	return Index % n;
}

/*
	判断当前位置能否放置房子(上下左右的方向上没有直接接触到其它房子)
*/
bool CanPutHouse(int Row, int Col)
{
	for (int i = Row + 1; i < n; i++)
	{
		if (Map[i][Col] == 'X')
		{
			break;
		}

		if (Map[i][Col] == 'O')
		{
			return false;
		}
	}

	for (int i = Row - 1; i >= 0; i--)
	{
		if (Map[i][Col] == 'X')
		{
			break;
		}

		if (Map[i][Col] == 'O')
		{
			return false;
		}
	}

	for (int i = Col + 1; i < n; i++)
	{
		if (Map[Row][i] == 'X')
		{
			break;
		}

		if (Map[Row][i] == 'O')
		{
			return false;
		}
	}

	for (int i = Col - 1; i >= 0; i--)
	{
		if (Map[Row][i] == 'X')
		{
			break;
		}

		if (Map[Row][i] == 'O')
		{
			return false;
		}
	}

	return true;
}

/*
	从第一个位置开始放置房子，使用回溯法进行递归尝试
	参数：
		Index：当前尝试放置房子位置的索引号
		CurrentHouse：已放置房子的数量
*/
void PutHouse(int Index, int CurrentHouse)
{
	if (Index >= n * n)
	{
		if (CurrentHouse > MaxHouse)
		{
			MaxHouse = CurrentHouse;
		}
		return;
	}
	else
	{
		int Row = GetRow(Index);
		int Col = GetCol(Index);

		if (Map[Row][Col] == '.' && CanPutHouse(Row, Col))
		{
			Map[Row][Col] = 'O';
			PutHouse(Index + 1, CurrentHouse + 1);
			Map[Row][Col] = '.';
		}
		PutHouse(Index + 1, CurrentHouse);
	}
}

int main()
{
	while (true)
	{
		cin >> n;

		if (n == 0)
		{
			break;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> Map[i][j];
			}
		}
		
		MaxHouse = 0;
		PutHouse(0, 0);
		cout << MaxHouse << endl;
	}

   return 0;
}