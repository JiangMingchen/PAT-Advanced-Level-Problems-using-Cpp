#include<iostream>
#include<string>
#include<stack>
#include <algorithm>
using namespace std;
int main()
{
	long long int a, b;
	cin >> a >> b;
	long long int sum = a + b;
	int sign = 1;
	if (sum < 0)
	{
		sign = -1;
	}
	string temp = to_string(sum);
	int count = 0;
	if (sum == 0)
	{
		count = 1;
	}
	sum = sign * sum;
	while (sum > 0)
	{
		count++;
		sum = (sum - (sum % 10)) / 10;
	}
	int i = 0;
	reverse(temp.begin(), temp.end());
	stack<char> std;
	int flag = 0;
	while (i<count)
	{
		if (flag == 3)
		{
			std.push(',');
			flag = 0;
		}
		std.push(temp[i++]);
		flag++;
	}
	if (sign == -1)
	{
		cout << "-";
	}
	while (!std.empty())
	{
		char a;
		a = std.top();
		cout << a;
		std.pop();
	}
}
