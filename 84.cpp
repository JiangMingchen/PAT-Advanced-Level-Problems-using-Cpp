#include<bits/stdc++.h>
using namespace std;
int main()
{
   string in,out,miss;
   bool hash[40] = {false};
   cin >> in;
   cin >> out;
   for(int i = 0; i < out.size(); i++)
   {
      if(out[i] >= '0' && out[i] <= '9')
      {
         hash[out[i] - '0'] = true;
      }
      else if(out[i] >= 'A' && out[i] <= 'Z')
      {
         hash[out[i] - 'A' + 10] = true;
      }
      else if(out[i] >= 'a' && out[i] <= 'z')
      {
         hash[out[i] - 'a' + 10] = true;
      }
      else
      {
         hash[36] = true;
      }
   }
   for(int i = 0; i < in.size(); i++)
   {
      if(in[i] >= '0' && in[i] <= '9' && hash[in[i] - '0'] == false)
      {
         cout<<in[i];
         hash[in[i] - '0'] = true;
      }
      else if(in[i] >= 'A' && in[i] <= 'Z' && hash[in[i] - 'A' + 10] == false)
      {
         cout << in[i];
         hash[in[i] - 'A' + 10] = true;
      }
      else if(in[i] >= 'a' && in[i] <= 'z' && hash[in[i] - 'a' + 10] == false)
      {
         cout << (char)(in[i] - 'a' + 'A');
         hash[in[i] - 'a' + 10] = true;
      }
      else
      {
         if(hash[36] == false)
         {
            cout << "_";
            hash[36] = true;
         }
      }
   }
}
