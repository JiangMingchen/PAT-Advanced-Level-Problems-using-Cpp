#include<bits/stdc++.h>
using namespace std;
struct goods
{
   float amount, price, per;
};
bool cmp(goods a, goods b)
{
   return a.per > b.per;
}
int main()
{
   int n, d;
   float benefit = 0.0;
   scanf("%d%d", &n, &d);
   vector<goods> good(n);
   for(int i = 0; i < n; i++)
   {
      scanf("%f", &good[i].amount);
   }
   for(int i = 0; i < n; i++)
   {
      scanf("%f", &good[i].price);
      good[i].per = good[i].price / good[i].amount;
   }
   sort(good.begin(), good.end(), cmp);
   for(int i = 0; i < n; i++)
   {
      if(good[i].amount >= d)
      {
         benefit += d * good[i].per;
         break;
      }
      else
      {
         d -= good[i].amount;
         benefit += good[i].amount * good[i].per;
      }
   }
   printf("%.2f", benefit);
}
