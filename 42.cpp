#include<bits/stdc++.h>
using namespace std;
struct card
{
   char kind;
   int number;
   int pos;
};
bool cmp(card a, card b)
{
   return a.pos < b.pos;
}

int main()
{
   char k[5] = {'S', 'H', 'C', 'D'};
   card cd[55];
   for(int i = 0; i < 4; i++)
   {
      for(int j = 1; j <=13; j++)
      {
         cd[i * 13 + j].number = j;
         cd[i * 13 + j].kind = k[i];
         cd[i * 13 + j].pos = i * 13 + j;
      }
   }
   cd[53].kind = cd[54].kind = 'J';
   cd[53].number = 1;
   cd[53].pos = 53;
   cd[54].number = 2;
   cd[54].pos = 54;
   int times, position[55];
   scanf("%d", &times);
   for(int i = 1; i <= 54; i++)
   {
      scanf("%d", &position[i]);
   }
   while(times--)
   {
      for(int i = 1; i <= 54; i++)
      {
         cd[i].pos = position[i];
      }
      sort(cd + 1,cd + 55, cmp);
   }
   for(int i = 1; i <= 54; i++)
   {
      printf("%c%d", cd[i].kind, cd[i].number);
      if(i != 54) printf(" ");
   }
}
