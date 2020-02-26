#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct student
{
	string id;
	int c, m, e, a, rank;
	char subject;
};
vector<student>stu;
vector<int> cc, mm, ee, aa;
student best(student a)
{
	int temp;
	a.rank = find(aa.begin(), aa.end(), a.a) - aa.begin() + 1;
	a.subject = 'A';
	temp = find(cc.begin(), cc.end(), a.c) - cc.begin() + 1;
	if (temp < a.rank) { a.rank = temp; a.subject = 'C'; }
	temp = find(mm.begin(), mm.end(), a.m) - mm.begin() + 1;
	if (temp < a.rank) { a.rank = temp; a.subject = 'M'; }
	temp = find(ee.begin(), ee.end(), a.e) - ee.begin() + 1;
	if (temp < a.rank) { a.rank = temp; a.subject = 'E'; }
	return a;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int C, M, E;
	string ID;
	for (int i = 0; i < n; i++)
	{
		cin >> ID >> C >> M >> E;
		cc.push_back(C);
		mm.push_back(M);
		ee.push_back(E);
		student a;
		a.id = ID;
		a.c = C;
		a.m = M;
		a.e = E;
		a.a = (int)((C + M + E) / 3 + 0.5);
		aa.push_back(a.a);
		stu.push_back(a);
	}
	sort(cc.begin(), cc.end(),greater<int>());
	sort(mm.begin(), mm.end(),greater<int>());
	sort(ee.begin(), ee.end(),greater<int>());
	sort(aa.begin(), aa.end(),greater<int>());
	for (vector<student>::iterator v = stu.begin(); v != stu.end(); v++)
	{
		*v = best(*v);
	}
	vector<student> id;
	for (int i = 0; i < m; i++)
	{
		string num;
		int flag = 0;
		student nobody;
		nobody.a = -1;
		cin >> num;
		for (vector<student>::iterator v = stu.begin(); v != stu.end(); v++)
		{
			if ((*v).id == num) { id.push_back(*v); flag = 1; break; }
		}
		if (flag == 0) id.push_back(nobody);
		
	}
	for (vector<student>::iterator v = id.begin(); v != id.end(); v++)
	{
		if ((*v).a != -1) cout << (*v).rank << " " << (*v).subject;
		else cout << "N/A";
		if (v != id.end() - 1) cout << endl;
	}
}
