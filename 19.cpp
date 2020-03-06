#include<bits/stdc++.h>
using namespace std;
int main()
{
   stack<int> number;
   vector<int> num;
   int decimal, base;
   scanf("%d%d", &decimal, &base);
   if(decimal == 0)
   {
      printf("Yes\n0");
      return 0;
   }
   while(decimal > 0)
   {
      int digit = decimal % base;
      number.push(digit);
      decimal = decimal / base;
   }
   if(number.size() == 1)
   {
      printf("Yes\n%d", number.top());
      return 0;
   }
   while(!number.empty())
   {
      num.push_back(number.top());
      number.pop();
   }
   int i = 0, k = num.size() - 1, flag = 0;
   while( i != k &&  i < k)
   {
      if(num[i++] == num[k--])
         flag = 1;
      else
      {
         flag = 0;
         break;
      }
   }
   if(flag == 1)
      printf("Yes\n");
   else
      printf("No\n");
   for(vector<int>::iterator v = num.begin(); v != num.end(); v++)
   {
      printf("%d", *v);
      if(v != num.end() - 1)
          printf(" ");
   }
}
