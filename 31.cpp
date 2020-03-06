#include<bits/stdc++.h>
using namespace std;
int main()
{
   char u[30][30];
   memset(u, ' ', sizeof(u));
   char str[100];
   scanf("%s", str);
   int n = strlen(str);
   int n1, n2;
   if( n % 3 == 0)
   {
      n2 = n / 3 + 2;
      n1 = n2 -2;;
   }
   else if(n % 3 == 1)
   {
      n2 = (n -1) / 3 + 1;
      n1 = n2;
   }
   else if(n % 3 == 2)
   {
      n2 = (n - 2) / 3 + 2;
      n1 = n2 - 1;
   }
   int count = 0, decount = n - 1;
   for(int i = 0; i < n1; i++)
   {
      u[i][0] = str[count++];
      u[i][n2 - 1] = str[decount--];
   }
   for(int i = 1; i < n2 - 1; i++)
   {
      u[n1 -1][i] = str[count++];
   }
   for(int i = 0; i < n1; i++)
   {
      for(int j = 0; j < n2; j++)
      {
         printf("%c", u[i][j]);
      }
      printf("\n");
   }
}
