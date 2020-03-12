#include<bits/stdc++.h>
using namespace std;
int main()
{
   string sc;
   cin >> sc;
   stack<int> exp;
   int e = 0, dot, flag1, flag2;
   for(int i = sc.size() - 1; i > 0; i--)
   {
      if(sc[i] == '+')
      {
         flag2 = 1;
         break;
      }
      else if(sc[i] == '-')
      {
         flag2 = -1;
         break;
      }
      exp.push(sc[i] - '0');
      sc.erase(sc.begin() + i);
   }
   sc.erase(sc.end() - 2, sc.end());
   int k = exp.size() - 1;
   while(!exp.empty())
   {
      e += exp.top() * pow(10, k--);
      exp.pop();
   }
   e *= flag2;
   for(int i = 0; i < sc.size(); i++)
   {
      if(sc[i] == '.')
      {
         dot = i;
         break;
      }
   }
   while(e != 0)
   {
      if(e > 0)
      {
         if(sc[dot + 1] != '\0')
         {
            sc[dot] = sc[dot + 1];
            sc[++dot] = '.';
            e--;
         }
         else
         {
            sc.insert(dot++, "0");
            e--;
         }
      }
      else
      {
         if(sc[dot - 1] != '+' && sc[dot - 1] != '-')
         {
            sc[dot] = sc[dot - 1];
            sc[--dot] = '.';
            e++;
         }
         else
         {
            sc.insert(dot + 1, "0");
            e++;
         }        
      }             
   }
   if(sc[1] == '.')
   {
      sc.insert(1, "0");
   }
   if(sc[sc.size() - 1] == '.')
   {
      sc.erase(sc.end() - 1);
   }
   if(sc[0] == '+')
   {
      sc.erase(sc.begin());
   }
   cout << sc;
} 
