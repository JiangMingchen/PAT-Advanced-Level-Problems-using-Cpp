#include<bits/stdc++.h>
using namespace std;
bool cmp(string a, string b)
{
   string s1 = a + b;
   string s2 = b + a;
   return s1 < s2;
}
int main()
{
   int k = 0, count = 0, n, flag = 0;
   scanf("%d", &n);
   getchar();
   vector<string> num(n);
   string min;
   for(int i = 0; i < n; i++)
   {
       cin >> num[i];
   }
   sort(num.begin(), num.end(), cmp);
   for(int i = 0; i < n; i++)
   {
      min += num[i];
   }
   for(int i = 0; i < min.size(); i++)
   {
      if(min[i] == '0')
      {
         continue;
      }
      else
      {
         flag = 1;
         for(int j = i; j < min.size(); j++)
         {
            printf("%c", min[j]);
         }
         break;
      }
   }
   if(flag == 0)
   {
      printf("0");
   }
}
