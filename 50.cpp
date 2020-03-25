#include<bits/stdc++.h>
using namespace std;
int main()
{
   bool hash[300] = {false};
   char s1[10010], s2[10010];
   fgets(s1, 10010, stdin);
   fgets(s2, 10010, stdin);
   for(int i = 0; s2[i] != '\0'; i++)
   {
      hash[s2[i]] = true;
   }
   for(int i = 0; s1[i] != '\0'; i++)
   {
      if(hash[s1[i]] != true)
      {
         printf("%c", s1[i]);
      }
   }
}
