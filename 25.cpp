#include<bits/stdc++.h>
using namespace std;

struct student
{
   long long int number;
   int score;
   int finalrank;
   int localrank;
   int location;
};
bool cmp(student a, student b)//分数高，序号小的在前
{
   if(a.score != b.score)
   return a.score > b.score;
   else
   return a.number < b.number;
}

int main()
{
   student stu[30000];
   int n, k, sc, count = 0;
   long long int num;
   scanf("%d", &n);
   int N = n;
   while(n)
   {
      scanf("%d", &k);
      while(k)
      {
         scanf("%lld", &num);
         scanf("%d", &sc);
         stu[count].number = num;
         stu[count].score = sc;
         stu[count].location = N - n + 1;
         count++;
         k--;
      }
      n--;
   }
   sort(stu, stu + count,cmp);
   int r[111], l[111];
   for(int i = 0; i < 111; i++)
   {
      r[i] = 1;
      l[i] = 0;
   }
   for(int i = 0; i < count; i++)
   {
      if(i !=0 && stu[i].score != stu[i - 1].score)
      {
         r[0] = i + 1;
         r[stu[i].location] = l[stu[i].location] + 1;
      }
      else
      {
         if(i!= 0 && stu[i].location != stu[i - 1].location)
         {
            r[stu[i].location] = l[stu[i].location] + 1;
         }
      }
      l[stu[i].location]++;
      stu[i].finalrank = r[0];
      stu[i].localrank =  r[stu[i].location];
   }
   printf("%d\n", count);
   for(int i = 0; i < count; i++)
   {
      printf("%013lld %d %d %d\n", stu[i].number, stu[i].finalrank, stu[i].location, stu[i].localrank);
   }
}