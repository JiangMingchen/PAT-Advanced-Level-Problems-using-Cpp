#include<iostream>
using namespace std;
int main()
{
	int n;
	int pos = 0, req;
	int time = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &req);
		if (req > pos) time += (req - pos) * 6 + 5;
		else time += (pos - req) * 4 + 5;
		pos = req;
	}
	cout << time;
}
