#include <iostream>
using namespace std;

string WordA, WordB;		//原始字符串和目标字符串
int Length;			//输入字符串的长度
stack<char> Word;		//记录当前操作后字符串的状态
vector<char> Op;		//记录当前已进行的操作

/*
	将整个操作当成一颗二叉树(Eg：左边代表入栈，右边代表出栈)进行深度优先遍历
	当遍历到根节点的时候，根据遍历路径判断对应操作后的字符串与目标字符串是否相同
	相同则输入对应路径的操作，否则继续遍历(遍历过程中会剪掉错误的分支)
	参数：
		Pop：已进行出栈操作的次数
		Push：已进行入栈操作的次数
*/
void Dfs(int Pop, int Push)
{
	//当转换完成后一定有出栈和入栈的次数相等，且等于字符串的长度
	if (Push == Pop && Push == Length)
	{
		for (int i = 0; i < Op.size(); i++)
		{
			cout << Op[i] << " ";
		}
		cout << endl;
	}

	//遍历左节点(尝试入栈操作)
	if (Push < Length)
	{
		Word.push(WordA[Push]);
		Op.push_back('i');
		Dfs(Pop, Push + 1);
		Word.pop();
		Op.pop_back();
	}

	//遍历右节点(尝试出栈操作)
	if (Pop < Length && Pop < Push && Word.top() == WordB[Pop])
	{
		char Top = Word.top();
		Word.pop();
		Op.push_back('o');
		Dfs(Pop + 1, Push);
		Word.push(Top);
		Op.pop_back();
	}
}

int main()
{
	while (cin >> WordA >> WordB)
	{
		Length = WordA.length();

		cout << "[" << endl;
		Dfs(0, 0);
		cout << "]" << endl;
	}

	return 0;
}
