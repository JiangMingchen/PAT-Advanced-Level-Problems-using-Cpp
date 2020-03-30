#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n, k = 1, count = 0;
   scanf("%d", &n);
   vector<int> pos(n);
   for(int i = 0; i < n; i++)
   {

      int num;
      scanf("%d", &num);
      pos[num] = i;
   }
   while(1)
   {
      if(pos[0] == 0)
      {
         while(k <= n)
         {
            if( k == n)
            {
               printf("%d", count);
               return 0;
            }
            else if(pos[k] != k)
            {
               swap(pos[0],pos[k]);
               count++;
               break;
            }
            else
            {
               k++;
            }
            
         }
      }
      else
      {
         swap(pos[0], pos[pos[0]]);
         count++;
      }
   }
}
