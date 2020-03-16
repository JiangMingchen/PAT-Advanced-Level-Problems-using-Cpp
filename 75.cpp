#include<bits/stdc++.h>
using namespace std;
struct user
{
   int id, total = 0, perfect = 0, rank, count = 0, score[5] =  {-1, -1 , -1, -1, -1};
};
bool cmp(user a, user b)
{
   if(a.total != b.total)
   {
      return a.total > b.total;
   }
   else if(a.perfect != b.perfect)
   {
      return a.perfect > b.perfect;
   }
   else if(a.count != b.count)
   {
      return a.count > b.count;
   }
   else
   {
      return a.id < b.id;
   }
}
int main()
{
   int n, k, m, full[5];
   scanf("%d%d%d", &n, &k, &m);
   vector<user>id(n+1);
   for(int i = 0; i < k; i++)
   {
      scanf("%d", &full[i]);
   }
   while(m--)
   {
      int ID, NUM, SCORE;
      scanf("%d%d%d", &ID, &NUM, &SCORE);
      NUM--;
      if(SCORE != -1)
      {
         id[ID].count = 1;
      }
      if(SCORE == -1)
      {
         SCORE++;
      }
      if(SCORE <= id[ID].score[NUM])
      {
         continue;
      }
      else
      {
         id[ID].id = ID;
         if(id[ID].total != 0 && id[ID].score[NUM] != -1)
         {
            id[ID].total -= id[ID].score[NUM];
         }
         id[ID].score[NUM] = SCORE;
         id[ID].total += SCORE;
         if(SCORE == full[NUM])
         {
            id[ID].perfect++;
         }
      }  
   }
   sort(id.begin(), id.end(), cmp);
   int r = 1;
   for(int i = 0; i < n; i++)
   {
      if(i != 0 && id[i].total != id[i - 1].total)
      {
         r = i + 1;
         id[i].rank = r;
      }
      else
      {
         id[i].rank = r;
      }
      
   }
   for(int i = 0; i < n; i++)
   {
      if(id[i].count == 0)
      {
         break;
      }
      printf("%d %05d %d", id[i].rank, id[i].id, id[i].total);
      for(int j = 0; j < k; j++)
      {
         if(id[i].score[j] != -1)
         {
            printf(" %d", id[i].score[j]);
         }
         else
         {
            printf(" -");
         }     
      }
      printf("\n");
   }
}
