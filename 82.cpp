#include<bits/stdc++.h>
using namespace std;
int main()
{
   string d[4] = {"", "Shi", "Bai", "Qian"};
   string num[11] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"};
   string number, str[2];
   cin >> number;
   if(number == "0")
   {
      cout << "ling";
      return 0;
   }
   if(number[0] == '-')
   {
      cout<< "Fu ";
      number.erase(number.begin());
   }
   int n = number.length();
   if(n <= 4)
   {
      str[1] = number;
   }
   else if(n > 4 && n <= 8)
   {
      str[1] = number.substr(n - 4, n);
      str[0] = number.substr(0, n - 4);   
   }
   else
   {
      str[1] = number.substr(n - 4, n);
      str[0] = number.substr(1, n - 5);
      cout << num[number[0] - '0'] << " Yi";
      if(str[0] != "0000")
      {
         cout << " ";
      }
   }
   for(int k = 0; k < 2; k++)
   {
      for(int i = 0; i < str[k].size(); i++)
      {
         if(str[k][i] == '0')
         {
            int j = i + 1, flag = 0;
            while(j < str[k].size())
            {
               if(str[k][j++] != '0')
               {
                  flag = 1;
               }
            }
            if(flag == 1 && str[k][i - 1] != '0')
            cout << " ling";
         }  
         else
         {
            if(i != 0) cout << " ";
            cout << num[str[k][i] - '0'];
            if(i != str[k].size() - 1)
            {
               cout << " " << d[str[k].size() - i - 1];
            }
         }    
      }
      if(k == 0)
      {
         if(str[0] != "0000" && str[0] != "")
         {
            if(str[1] != "0000")
            {
               if(str[1][0] != '0')
                  cout << " Wan ";
               else
                  cout<< " Wan";  
            }
            else
            {
               cout<< " Wan";
               return 0;
            }
         }
      }
   }
}
