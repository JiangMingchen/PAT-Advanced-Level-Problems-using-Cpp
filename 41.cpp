#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n, hash[10000] = {0};
   vector<int> bet;
   scanf("%d", &n);
   while(n--)
   {
      int temp;
      scanf("%d", &temp);
      bet.push_back(temp);
      hash[temp]++;
   }
   for(int i = 0; i < bet.size(); i++)
   {
      if(hash[bet[i]] == 1)
      {
         printf("%d", bet[i]);
         return 0;
      }
   }
   printf("None");
}
