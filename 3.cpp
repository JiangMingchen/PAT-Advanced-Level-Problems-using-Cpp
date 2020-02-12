#include <iostream>
#include <cstdio>
#include<map>
#include<string.h>
#define MAX 9999999
using namespace std;
class cal
{
public:
	int length;
	int number;
	cal(int len = MAX, int num = 0) { length = len; number = number; }
};
int arcs[600][600];//邻接矩阵
cal D[600];//保存最短路径长度
int p[600][600];//路径
int final[600];//若final[i] = 1则说明 顶点vi已在集合S中
int n = 0;//顶点个数
int v0 = 0;//源点
int v, w;
int ShortestPath_DIJ(map<int,int> cityteam,int citysave)
{
	map<int, int> ct = cityteam;
	int team = 0;
	for (v = 0; v < n; v++) //循环 初始化
	{
		final[v] = 0; D[v].length = arcs[v0][v];
		for (w = 0; w < n; w++) p[v][w] = 0;//设空路径
		if (D[v].length < MAX) { p[v][v0] = 1; p[v][v] = 1; D[v].number++; }
	}
	D[v0].length = 0; final[v0] = 1;
	for (int i = 1; i < n; i++)
	{
		int min = MAX;
		for (w = 0; w < n; w++)
		{

			if (!final[w])
			{
				if (D[w].length < min) { v = w; min = D[w].length;}
			}
		}
		final[v] = 1;
		for (w = 0; w < n; w++)
		{
			if (!final[w] && ((min + arcs[v][w]) <= D[w].length))
			{
				if ((min + arcs[v][w]) == D[w].length)
				{
					D[w].number += D[v].number;
					//上行修改特别感谢https://blog.csdn.net/tiantangrenjian/article/details/19434417
					//原来错误地写成D[w].number++;
					if (cityteam[w] + ct[v] > ct[w])
					{
						ct[w] = ct[v] + cityteam[w];
					}
				}
				else
				{
					D[w].number = D[v].number;
					//上行修改特别感谢https://blog.csdn.net/tiantangrenjian/article/details/19434417
					//原来错误地写成D[w].number = 1;
					ct[w] += ct[v];
				}
				D[w].length = min + arcs[v][w];
				p[w][w] = 1;
			}
		}
	}
	return ct[citysave] + cityteam[0];
}

int main()
{
	int M;//道路数
	int cityin; //所在城市
	int citysave;//救援城市
	int teamnumber;//救援队数量
	cin >> n >> M >> cityin >> citysave;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arcs[i][j] = MAX;
		}
	}
	map<int, int> cityteam;
	int c1;
	int c2;
	int length;
	for (int i = 0; i < n; i++)
	{
		cin >> teamnumber;
		cityteam[i] = teamnumber;
	}
	int team;
	for (int i = 0; i < M; i++)
	{
		cin >> c1 >> c2 >> length;
		arcs[c1][c2] = length;
		arcs[c2][c1] = length;
	}
	if (cityin == citysave)
	{
		cout << 1 << " " << cityteam[cityin];
		return 0;
	}
	if (cityin != 0)
	{
		for (int i = 0; i < n; i++)
		{
			int temp;
			temp = arcs[0][i];
			arcs[0][i] = arcs[cityin][i];
			arcs[cityin][i] = temp;
		}
		for (int i = 0; i < n; i++)
		{
			int temp;
			temp = arcs[i][0];
			arcs[i][0] = arcs[i][cityin];
			arcs[i][cityin] = temp;
		}
		int temp = cityteam[0];
		cityteam[0] = cityteam[cityin];
		cityteam[cityin] = temp;
	}
	int change;
	if (citysave == 0) change = cityin;
	else change = citysave;
	team = ShortestPath_DIJ(cityteam,change);
	cal temp;
	temp = D[0];
	D[0] = D[cityin];
	D[cityin] = temp;
	if (D[citysave].number == 0) team = 0;
	cout << D[citysave].number << " " << team;
}
