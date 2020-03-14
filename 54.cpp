#include<bits/stdc++.h>
using namespace std;
struct number
{
   int num;
   int count = 0;
};
bool cmp(number a, number b)
{
   return a.count > b.count;
}
int main()
{
   vector<int>pixel;
   vector<number>calc;
   int m, n, max = 0, major;
   scanf("%d%d", &m, &n);
   for(int i = 0; i < m; i++)
   {
      for(int j = 0; j < n; j++)
      {
         int temp;
         scanf("%d", &temp);
         pixel.push_back(temp);
      }
   }
   sort(pixel.begin(), pixel.end());
   for(int i = 0; i < m * n; i++)
   {
      if(i == 0 || pixel[i] != pixel[i - 1])
      {
         number temp;
         temp.num = pixel[i];
         calc.push_back(temp);
      }
      else
      {
         calc.back().count++;
      }
   }
   sort(calc.begin(), calc.end(), cmp);
   printf("%d", calc[0].num);
}
