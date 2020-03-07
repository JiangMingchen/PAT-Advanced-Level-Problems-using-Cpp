#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a[3], b[3], sum[3], incre = 0;
   int radix[3] = {10, 17, 29};
   char dot;
   scanf("%d%c%d%c%d", &a[0], &dot, &a[1], &dot, &a[2]);
   scanf("%d%c%d%c%d", &b[0], &dot, &b[1], &dot, &b[2]);
   for(int i = 2; i > 0; i--)
   {
      sum[i] = (a[i] + b[i] + incre) % radix[i];
      incre = (a[i] + b[i] + incre) / radix[i];
   }
   sum[0] = a[0] + b[0] + incre;
   printf("%d.%d.%d", sum[0], sum[1], sum[2]);
}
