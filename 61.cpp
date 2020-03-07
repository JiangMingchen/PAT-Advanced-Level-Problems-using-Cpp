#include<bits/stdc++.h>
using namespace std;
int main()
{
   int capital[26], english[2][26], number[10], order[3], flag = 0;
   for(int i = 0; i < 26; i++)
   {
      capital[i] = 0;
   }
   for(int i = 0; i < 2; i++)
   {
      for(int j = 0; j < 2; j++)
      {
         english[i][j] = 0;
      }
   }
   string a, b, c, d, day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
   cin >> a >> b >> c >> d;
   for(int i = 0; i < min(a.size(), b.size()); i++)
   {
      if(a[i] == b[i])
      {
         if(a[i] >= 'A' && a[i] <= 'N')
         {
            if(flag == 0 && a[i] <= 'G')
               order[flag] = a[i] - 'A';
            if(flag == 1)
            {
               order[flag] = a[i] - 'A' + 10;
               break;
            }
            flag++;
         }
         else if(a[i] >= '0' && a[i] <= '9' && flag == 1)
         {
            order[flag] = a[i] - '0';
            break;
         }
      }
   }
   for(int i = 0; i < min(c.size(), d.size()); i++)
   {
      if(c[i] == d[i])
      {
         if(c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z')
         {
            order[2] = i;
            break;
         }
      }
   }
   cout << day[order[0]] << " ";
   printf("%02d:%02d", order[1], order[2]);
}
