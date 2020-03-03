#include<bits/stdc++.h>
using namespace std;
struct customer
{
   int id;
   int time;
   int window;
};

struct cmp
{
   bool operator () (customer a, customer b)
   {
      if(a.time != b.time)
      {
         return a.time > b.time;
      }
      else
      {
         return a.window > b.window;
      }
   }
};

int main()
{
   int cusneed[1001];
   int win[22];
   memset(cusneed, 0, sizeof(cusneed));
   memset(win, 0, sizeof(win));
   int n, m, k, q;
   priority_queue<customer, vector<customer>, cmp> queue;
   scanf("%d%d%d%d", &n, &m, &k, &q);
   for(int i = 1; i <= k; i++)
   {
      scanf("%d", &cusneed[i]);
   }
   for(int i = 0; i < m; i++)
   {
      for(int j = 1; j <= n; j++)
      {
         if(win[j] >= 540 || win[j] < 0)
         {
            win[j] = -1;
         }
         else
         {
            win[j] += cusneed[i * n + j];
         } 
         customer cus;
         cus.id = i * n +j;
         cus.window = j;
         cus.time = win[j];
         cusneed[i * n + j] = win[j];
         queue.push(cus);       
      }
   }

   int extra = n * m + 1;
   while(extra <= k)
   {
      customer c = queue.top();
      customer cus;
      queue.pop();
      if(win[c.window] >= 540 || win[c.window] < 0)
      {
         win[c.window] = -1;
      }
      else
      {
         win[c.window] += cusneed[extra];
      }
      cus.id = extra;
      cus.window = c.window;
      cus.time = win[c.window];
      cusneed[extra] = win[c.window];
      queue.push(cus);
      extra++;
   }
   int id,timeneed;
   while(q--)
   {
      scanf("%d", &id);
      timeneed = cusneed[id];
      if(timeneed < 0)
      {
         printf("Sorry\n");
      }
      else
      {
         int hour = timeneed / 60 + 8;
         int min = timeneed % 60;
         printf("%02d:%02d\n", hour, min);
      }
   }

}

