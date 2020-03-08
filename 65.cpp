#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int a, b, c;
   int t, T;
   scanf("%d", &t);
   T = t;
   while(t--)
   {
      scanf("%lld%lld%lld", &a, &b, &c);
      long long int res = a + b;
      if(a > 0 && b > 0 && res < 0)//判断正移除
      {
         printf("Case #%d: true\n", T - t);
      }
      else if(a < 0 && b < 0 && res >= 0)//判断负溢出
      {
         printf("Case #%d: false\n", T - t);
      }
      else if(res > c)
      {
            printf("Case #%d: true\n", T - t);
      }
      else
      {
            printf("Case #%d: false\n", T - t);        
      }     
   }
}
