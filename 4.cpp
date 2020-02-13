#include<iostream>
#include<vector>
#include<map>
#include<string.h>
using namespace std;

int non_leaf[110];
int total_lv = 2;
struct TreeNode//定义二叉树
{
	int num;
	int children;
	int level;
	vector<TreeNode> child;
};

void CreateTree(vector<TreeNode>::iterator root,map<int,vector<int>> childline,int lv)
{
	if (lv > total_lv)total_lv = lv;
	if (root->children == 0)
	{
		non_leaf[lv-1]++;
	}
	while (root->child.size() < root->children)
	{
		TreeNode NewNode;
		if(!childline[root->num].empty()) NewNode.num = childline[root->num].at(root->child.size());
		NewNode.children = childline[NewNode.num].size();
		NewNode.level = lv;
		root->child.push_back(NewNode);
	}
	lv++;
	for (vector<TreeNode>::iterator it = root->child.begin(); it != root->child.end(); it++)
		CreateTree(it,childline,lv);
}

int main()
{
	memset(non_leaf, 0, sizeof(non_leaf));
	int m, n;
	int parent_number;
	int child_number;
	int children_num;
	map<int, vector<int>> childline;
	cin >> n >> m;
	if (n == 1) {cout << 1; return 0;}
	vector<TreeNode> root;
	TreeNode rt;
	rt.num = 1;
	rt.level = 1;
	for (int i = 0; i < m; i++)
	{
		cin >> parent_number >> children_num;
		if (parent_number == 1) { rt.children = children_num; root.push_back(rt); }
		for (int j = 0; j < children_num; j++)
		{
			cin >> child_number;
			childline[parent_number].push_back(child_number);
		}
	}
	CreateTree(root.begin(), childline, total_lv);
	int count = 1;
	while (count < total_lv)
	{
		cout << non_leaf[count];
		if (++count < total_lv)cout << " ";
	}
}
