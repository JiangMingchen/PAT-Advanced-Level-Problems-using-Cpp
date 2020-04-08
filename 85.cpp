#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n, p, left, right, mid, ans = 0, s[100000];
   scanf("%d%d", &n, &p);
   for(int i = 0; i < n; i++)
   {
      scanf("%d", &s[i]);
   }
   sort(s, s + n);
   for(int i = 0; i < n; i++)
   {
      if(s[n - 1] <= (long long)s[i] * p && ans < n - i)
      {
         ans = n - i;
         continue;
      }
      left = i;
      right = n - 1;
      while(left < right)
      {
         mid = (left + right) / 2;
         if(s[mid] > (long long)s[i] * p)
         {
            right = mid;
         }
         else
         {
            left = mid + 1;
         }     
      }
      if(left - i > ans)
      {
         ans = left - i;
      }
   }
   printf("%d", ans);
}
