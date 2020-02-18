#include<iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int a[10001];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int sum = -1;
	int start, end;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		for (int j = i; j < n; j++)
		{
			temp += a[j];
			if (temp > sum)
			{
				sum = temp;
				start = a[i];
				end = a[j];
			}
		}
	}
	if (sum < 0)
	{
		cout << 0 << " " << a[0] <<" "<< a[n - 1];
	}
	else
	{
		cout << sum << " " << start << " " << end;
	}
}
