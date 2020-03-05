#include<bits/stdc++.h>
using namespace std;
int main()
{
   int dis[100010];
   dis[0] = 0;
   int n, m;
   int total = 0;
   scanf("%d", &n);
   for(int i = 1; i <= n; i++)
   {
      int distance;
      scanf("%d", &distance);
      total += distance;
      dis[i] = total;
   }
   scanf("%d", &m);
   while(m--)
   {
      int a, b, d;
      scanf("%d%d", &a, &b);
      if(a < b) 
         d = dis[b - 1] - dis[a - 1];
      else 
         d = dis[a - 1] - dis[b - 1];
      if(d > total / 2) 
         printf("%d\n", total - d);
      else 
         printf("%d\n", d);
   }
}
