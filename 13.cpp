#include <bits/stdc++.h>
using namespace std;
#define MAXV 1000
int G[MAXV][MAXV] = {0};
int n;
bool vis[MAXV] = {false};
void dfs(int u, int depth)
{
   vis[u] = true;
   for(int i = 0; i < n; i++)
   {
      if(vis[i] == false && G[u][i] != 0)
      {
         dfs(i, depth + 1);
      }
   }
}
int dfstrave()
{
   int count = 0;
   for( int u = 0; u < n; u++)
   {
      if(vis[u] == false)
      {
         count++;
         dfs(u, 1);
      }
   }
   return count;
}
int main()
{
   int m, k;
   vector<int> city;
   cin>>n>>m>>k;
   for(int i = 0; i < m; i++)
   {
      int a, b;
      scanf("%d%d",&a,&b);
      G[a - 1][b - 1] = G[b - 1][a - 1] = 1;
   }
   for(int i = 0; i < k; i++)
   {
      int temp;
      scanf("%d",&temp);
      city.push_back(temp);
   }
   for(vector<int>::iterator v = city.begin(); v != city.end(); v++)
   {
      vis[(*v) - 1] = true;
      int num = dfstrave();
      *v = num;
      memset(vis, false, sizeof(vis));
   }
   for(vector<int>::iterator v = city.begin(); v != city.end(); v++)
   {
      cout<<(*v) - 1<<endl;
   }  
}
