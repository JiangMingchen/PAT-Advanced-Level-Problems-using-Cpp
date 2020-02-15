#include<iostream>
using namespace std;
struct person
{
	string number;
	int intime;
	int outtime;
};
int main()
{
	int count;
	int h, m, s;
	char trash;
	string number;
	string unlock, lock;
	person people[1000];
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> number >> h >> trash >> m >> trash >> s;
		int intime = h * 3600 + m * 60 + s;
		people[i].number = number;
		people[i].intime = intime;
		cin >> h >> trash >> m >> trash >> s;
		int outtime = h * 3600 + m * 60 + s;
		people[i].outtime = outtime;
	}
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (people[j].intime > people[j + 1].intime)
			{
				swap(people[j], people[j + 1]);
			}
		}
	}
	unlock = people[0].number;
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (people[j].outtime > people[j + 1].outtime)
			{
				swap(people[j], people[j + 1]);
			}
		}
	}
	lock = people[count - 1].number;
	cout << unlock << " " << lock;
}
