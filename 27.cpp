#include<bits/stdc++.h>
using namespace std;
int main()
{
   int earth[3];
   for(int i = 0; i < 3; i++)
   {
      scanf("%d", &earth[i]);
   }
   int mars[6];
   for(int i = 0; i < 3; i++)
   {
      for(int j = 1; j > -1; j--)
      {
         int digit = earth[i] % 13;
         mars[i * 2 + j] = digit;
         earth[i] /= 13;
      }
   }
   printf("#");
   for(int i = 0; i < 6; i++)
   {
      if(mars[i] == 10)
         printf("A");
      else if(mars[i] == 11)
         printf("B");
      else if(mars[i] == 12)
         printf("C");
      else
         printf("%d", mars[i]);    
   }
}
