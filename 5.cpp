#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
int main()
{
	char N[110];
	int n[110];
	memset(n, -1, sizeof(n));
	cin >> N;
	if (N[0] == 48 && N[1] == '\0') cout << "zero";
	for (int i = 0; N[i] != '\0'; i++)
	{
		n[i] = N[i] - 48;
	}
	int sum = 0;
	for (int i = 0; n[i] != -1; i++)
	{
		sum += n[i];
	}
	stack<string> result;
	while (sum > 0)
	{
		int pos;
		pos = sum % 10;
		sum = (sum - pos) / 10;
		switch (pos)
		{
		case 0:
			result.push("zero");
			break;
		case 1:
			result.push("one");
			break;
		case 2:
			result.push("two");
			break;
		case 3:
			result.push("three");
			break;
		case 4:
			result.push("four");
			break;
		case 5:
			result.push("five");
			break;
		case 6:
			result.push("six");
			break;
		case 7:
			result.push("seven");
			break;
		case 8:
			result.push("eight");
			break;
		case 9:
			result.push("nine");
			break;
		}
	}
	while (!result.empty())
	{
		cout << result.top();
		if (result.size() != 1) cout << " ";
		result.pop();
	}	
}
