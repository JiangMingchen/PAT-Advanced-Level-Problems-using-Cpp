#include<bits/stdc++.h>
using namespace std;
int main()
{
   string shop, eva;
   int extra = 0, miss = 0;
   int hash[70] = {0};
   cin >> shop;
   cin >> eva;
   for(int i = 0; i < shop.size(); i++)
   {
      if(shop[i] >= '0' && shop[i] <= '9')
      {
         hash[shop[i] - '0']++;
         extra++;
      }
      else if(shop[i] >= 'A' && shop[i] <= 'Z')
      {
         hash[shop[i] - 'A' + 10]++;
         extra++;
      }
      else if(shop[i] >= 'a' && shop[i] <= 'z')
      {
         hash[shop[i] - 'a' + 37]++;
         extra++;
      }
   }
   for(int i = 0; i < eva.size(); i++)
   {
      if(eva[i] >= '0' && eva[i] <= '9' && hash[eva[i] - '0'] > 0)
      {
         hash[eva[i] - '0']--;
         extra--;
      }
      else if(eva[i] >= 'A' && eva[i] <= 'Z' && hash[eva[i] - 'A' + 10] > 0)
      {
         hash[eva[i] - 'A' + 10]--;
         extra--;
      }
      else if(eva[i] >= 'a' && eva[i] <= 'z' && hash[eva[i] - 'a' + 37] > 0)
      {
         hash[eva[i] - 'a' + 37]--;
         extra--;
      }
      else
      {
         miss++;
      }  
   }
   if(miss != 0)
   {
      printf("No %d", miss);
   }
   else
   {
      printf("Yes %d", extra);
   }
}
