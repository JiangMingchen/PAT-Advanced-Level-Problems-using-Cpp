#include<iostream>
#include<cmath>
using namespace std;

class member
{
public:
	int exp;//指数
	float coe;//系数
	member(int _exp = -1, float _coe = 0) {exp = _exp; coe = _coe; }
	void print();
	~member(){}
};
void member::print()
{
	cout << exp << " ";
	printf("%.1f", coe);
}
int main()
{
	int K, e;
	float c;
	cin >> K;
	member p1[15];
	member p2[15];
	for (int i = 0; i < K; i++)
	{
		cin >> e >> c;
		member a(e, c);
		p1[i] = a;
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> e >> c;
		member a(e, c);
		p2[i] = a;
	}
	member p[30];
	int j = 0, k = 0;
	int count = 0;
	while (p1[j].exp != -1 && p2[k].exp != -1)
	{
		member temp;
		p1[j].exp > p2[k].exp ? temp = p1[j++] : temp = p2[k++];
		if ((count != 0) && (temp.exp == p[count - 1].exp))
		{
			p[count - 1].coe += temp.coe;
		}
		else
		{
			p[count++] = temp;
		}
	}
	while(p1[j].exp != -1)
	{
		if (p1[j].exp == p[count - 1].exp)
		{
			p[count - 1].coe += p1[j++].coe;
		}
		else
		{
			p[count++] = p1[j++];
		}
	}
	while (p2[k].exp != -1)
	{
		if (p1[j].exp == p[count - 1].exp)
		{
			p[count - 1].coe += p2[k++].coe;
		}
		else
		{
			p[count++] = p2[k++];
		}
	}
	K = 0;
	int m = 0;
	while (p[m].exp != -1)
	{
		if (abs(p[m].coe) >= 0.05)
		{
			K++;
		}
		m++;
	}
	cout << K;
	m = 0;
	while (p[m].exp != -1)
	{
		if (abs(p[m].coe) <= 0.05)
		{
			m++;
			continue;
		}
		if (m < count)
		{
			cout << " ";
		}
		p[m++].print();
	}
}
