#include<bits/stdc++.h>
using namespace std;
int main()
{
   int hash[1010] = {0};
   int n, m;
   scanf("%d%d", &n, &m);
   while(n--)
   {
      int temp;
      scanf("%d", &temp);
      hash[temp]++;
   }
   for(int i = 0; i < m / 2 + 1; i++)
   {
      if(hash[i] > 0)
      {
         hash[i]--;
         if(hash[m - i] > 0)
         {
            printf("%d %d", i, m - i);
            return 0;
         }
         else 
         {
            hash[i]++;
         }
      }
   }
   printf("No Solution");
}
