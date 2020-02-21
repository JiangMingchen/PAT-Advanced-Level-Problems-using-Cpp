#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class item
{
public:
	int exp;
	float coe;
	item(int e = 0, float c = 0) { exp = e; coe = c; }
	item operator *(const item& b)
	{
		item t;
		t.exp = this->exp + b.exp;
		t.coe = this->coe * b.coe;
		return t;
	}
};
bool cmp(item a, item b)
{
	return a.exp < b.exp ? 1 : 0;
}
int main()
{
	int n;
	int e;
	float c;
	item a[11];
	item b[11];
	vector<item> result;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %f", &e,& c);
		a[i].exp = e;
		a[i].coe = c;
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %f", &e, &c);
		b[i].exp = e;
		b[i].coe = c;
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m ; j++)
		{
			result.push_back(a[i] * b[j]);
		}
	}
	sort(result.begin(), result.end(), cmp);
	for (vector<item>::iterator v = result.begin() + 1; v != result.end(); v++)
	{
		if ((*v).exp == (*(v - 1)).exp)
		{
			(*(v - 1)).coe += (*v).coe;
			result.erase(v--);
			if ((*v).coe == 0) result.erase(v--);
		}
	}
	reverse(result.begin(), result.end());
	cout << result.size();
	for (int i = 0; i < result.size(); i++)
	{
		if (i != result.size())cout << " ";
		cout << result[i].exp << " ";
		printf("%.1f", result[i].coe);
	}
}
