#include <iostream>
#include <string>
using namespace std;

/*
	获得字符对应的数字码
*/
int GetIntegerCode(char PlainCode)
{
	if (PlainCode == '_')
	{
		return 0;
	}

	if (PlainCode >= 'a' && PlainCode <= 'z')
	{
		return PlainCode - 'a' + 1;
	}

	if (PlainCode == '.')
	{
		return 27;
	}

	return -1;
}

/*
	获得数字码对应的字符
*/
char GetPlainCode(int IntegerCode)
{
	if (IntegerCode == 0)
	{
		return '_';
	}

	if (IntegerCode >= 1 && IntegerCode <= 26)
	{
		return 'a' + IntegerCode - 1;
	}

	if (IntegerCode == 27)
	{
		return '.';
	}

	return '\0';
}

/*
	CipherCode[i] = (PlainCode[(k * i) % n] - i) % 28
	
	注意到CipherCode和PlainCode的值都在区间[0, 27]内，所以：
	PlainCode[(k * i) % n] = (CipherCode[i] + i) % 28
*/
string Decryption(string& CiperText, int K)
{
	int Length = CiperText.length();
	string PlainText(CiperText);
	for (int i = 0; i < Length; i++)
	{
		char CipherPlainCode = CiperText[i];
		int CipherIntegerCode = GetIntegerCode(CipherPlainCode);

		PlainText[(K * i) % Length] = GetPlainCode((CipherIntegerCode + i) % 28);
	}
	return PlainText;
}

int main()
{
	while (true)
	{
		int K;
		string CipherText;

		cin >> K;
		if (K == 0)
		{
			break;
		}

		cin >> CipherText;

		string PlainText = Decryption(CipherText, K);
		cout << PlainText << endl;
	}

	return 0;
}