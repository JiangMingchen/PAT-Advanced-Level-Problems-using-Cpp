#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   scanf("%d", &n);
   vector<string> str;
   getchar();
   for(int i = 0; i < n; i++)
   {
      string s;
      getline(cin, s);
      reverse(s.begin(), s.end());
      str.push_back(s);
   }
   string same;
   int maxsize = min(str[0].size(), str[1].size());
   for(int i = 1; i < n; i++)
   {
      int flag = 0;
      same = "";
      for(int j = 0; j < maxsize; j++)
      {
         if(str[i][j] == str[i - 1][j])
         {
            same.push_back(str[i][j]);
            flag = 1;
         }
         else
         {
            if(flag == 1)
            {
               break;
            }  
         }        
         if(flag == 0)
         {
            cout << "nai";
            return 0;
         } 
      }
      maxsize = same.size();
      if(maxsize == 0)
      {
         cout << "nai";
         return 0;
      }
   }
   reverse(same.begin(), same.end());
   if(same[0] == ' ')
   {
      same.erase(same.begin());
   }
   cout << same;
}
