#include <iostream>
#include <string.h>

using namespace std;

struct Square
{
	int Top, Right, Bottom, Left;
};

Square Squares[25];		//不同种类方块的信息
int GameBoard[25];		//当前棋盘的状态(存储Squares中的索引号)
int SquareNumber[25];		//不同种类方块的数目
int TypeNumber;			//方块种类的数目
int TotalNumber;		//方块的总数目
int N;				//棋盘的边长

/*
	从左到右从上到下依次尝试放入方块，尝试的过程中只需要和当前位置左边和上方的方块进行比较即可
	参数：
		Index：从当前位置开始尝试放入方块
*/
bool DFS(int Index)
{
	//所有的方块都被放置完成则表示该游戏可以完成
	if (Index == TotalNumber)
	{
		return true;
	}

	//尝试将不同类型的方块放到Index位置上
	for (int i = 0; i < TypeNumber; i++)
	{
		//如果当前种类的方块用完则跳过
		if (SquareNumber[i] == 0)
		{
			continue;
		}

		//棋盘上最左边一列的方块Index % N的值为0
		//如果当前放置的位置处于棋盘最左边则不需要和其左边的方块进行比较判断
		if (Index % N != 0)
		{
			if (Squares[GameBoard[Index - 1]].Right != Squares[i].Left)
			{
				continue;
			}
		}

		//棋盘上最上边一行的方块Index < N
		//如果当前放置位置处于棋盘的最顶端则不需要和其上方的方块进行比较判断
		if (Index >= N)
		{
			if (Squares[GameBoard[Index - N]].Bottom != Squares[i].Top)
			{
				continue;
			}
		}

		//尝试放入该方块
		SquareNumber[i]--;
		GameBoard[Index] = i;

		if (DFS(Index + 1))
		{
			//如果放入当前方块后游戏可以完成，则结束递归
			return true;
		}

		//如果放入当前方块后游戏不能完成，则返回放入前的状态
		SquareNumber[i]++;
	}

	return false;
}

int main()
{
	int Top, Right, Bottom, Left;
	int Times = 0;

	while (cin >> N && N != 0)
	{	
		memset(Squares, 0, 25 * sizeof(Square));
		memset(GameBoard, 0, 25 * sizeof(int));
		memset(SquareNumber, 0, 25 * sizeof(int));
		TypeNumber = 0;
		TotalNumber = N * N;

		Times++;

		for (int i = 0; i < TotalNumber; i++)
		{		
			cin >> Top >> Right >> Bottom >> Left;

			int Index;
			
			for (Index = 0; Index < TypeNumber; Index++)
			{
				if (Squares[Index].Top == Top && Squares[Index].Right == Right &&
					Squares[Index].Bottom == Bottom && Squares[Index].Left == Left)
				{
					SquareNumber[Index]++;
					break;
				}
			}
			
			if (Index == TypeNumber)
			{
				Squares[Index].Top = Top;
				Squares[Index].Right = Right;
				Squares[Index].Bottom = Bottom;
				Squares[Index].Left = Left;
				SquareNumber[Index] = 1;
				TypeNumber++;
			}
		}

		if (Times != 1)
		{
			cout << endl;
		}

		if (DFS(0))
		{
			cout << "Game " << Times << ": Possible" << endl;
		}
		else
		{
			cout << "Game " << Times << ": Impossible" << endl;
		}
	}

	return 0;
}
