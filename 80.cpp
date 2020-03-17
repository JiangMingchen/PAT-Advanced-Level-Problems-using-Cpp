#include<bits/stdc++.h>
using namespace std;
struct student
{
   int num, ge, gi, total;
   vector<int> aim;
};
struct graduate
{
   vector<int> list;
   int max, last_total = -1, last_ge = -1;
};
bool cmp(student a, student b)
{
   if(a.total != b.total)
   {
      return a.total > b.total;
   }
   else
   {
      return a.ge > b.ge;
   }
}
int main()
{
   int n, m, k, r = 0;
   scanf("%d%d%d", &n, &m, &k);
   vector<graduate> gra(m);
   vector<student> stu;
   for(int i =  0; i < m; i++)
   {
      scanf("%d", &gra[i].max);
   }
   while(n--)
   {
      student temp;
      temp.num = r++;
      scanf("%d%d", &temp.ge, &temp.gi);
      temp.total = (temp.ge + temp.gi) / 2;
      for(int i = 0; i < k; i++)
      {
         int a;
         scanf("%d", &a);
         temp.aim.push_back(a);
      }
      stu.push_back(temp);
   }
   sort(stu.begin(), stu.end(), cmp);
   for(vector<student>::iterator v = stu.begin(); v!=stu.end(); v++)
   {
      for(int i = 0; i < k; i++)
      {
         int a = (*v).aim[i];
         if(gra[a].max != 0)
         {
            gra[a].list.push_back((*v).num);
            gra[a].max--;
            gra[a].last_total = (*v).total;
            gra[a].last_ge = (*v).ge;
            break;
         }
         else if(gra[a].max == 0)
         {
            if((*v).total == gra[a].last_total && (*v).ge == gra[a].last_ge)
            {
               gra[a].list.push_back((*v).num);
               break;
            }
         }
      }
   }
   for(int i = 0; i < m; i++)
   {
      sort(gra[i].list.begin(), gra[i].list.end());
      for(vector<int>::iterator v = gra[i].list.begin(); v!= gra[i].list.end(); v++)
      {
         printf("%d", (*v));
         if(v != gra[i].list.end() - 1)
         {
            printf(" ");
         }
      }
      printf("\n");
   }
}
