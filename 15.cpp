#include<bits/stdc++.h>
using namespace std;

bool Is_Prime(int n)
{
   if( n <= 1) return false;
   for(int i = 2; i <= sqrt(1.0 * n); i++)
   {
      if(n % i == 0) return false;
   }
   return true;
}

int Decimal(int *a, int radix, int num)
{
   int result = 0;
   for(int i = num - 1; i > -1; i--)
   {
      result += a[num -1 - i] * pow(radix, i);
   }
   return result;
}

int main()
{
   bool p;  
   int N, D;
   while(cin >> N)
   {
      if(N < 0) break;
      cin >> D;
      p = Is_Prime(N);
      if( p == false)
      {
         cout << "No" << endl;
      }
      else
      {
         int a[1000];
         memset(a, -1, sizeof(a));
         int num = 0;
         while(N > 0)
         {
            int digit = N % D;
            N = N / D;
            a[num++] = digit;
         }
         bool judge = Is_Prime(Decimal(a, D, num));
         if(judge == false) cout << "No" << endl;
         else cout << "Yes" << endl;
      }     
   }
}
