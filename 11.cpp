#include <bits/stdc++.h>
using namespace std;
float result[3];
void judge(int tag)
{
   tag %= 3;
   switch (tag)
   {
      case 0: cout<<"W"; break;
      case 1: cout<<"T"; break;
      case 2: cout<<"L"; break;
   }
   cout<<" ";
}
int main()
{
   vector<float> bet;
   for(int i = 0; i < 9; i ++)
   {
      float temp;
      cin>>temp;
      bet.push_back(temp);
   }
   for(int i = 0; i < 7; i += 3)
   {
      result[i / 3] = max(max(bet[i], bet[i + 1]), bet[i + 2]);
      int tag = find(bet.begin() + i,bet.begin() + i + 3, result[i / 3]) - bet.begin() - i;
      judge(tag);
   }
   printf("%.2f", (result[0] * result[1] * result[2] * 0.65 - 1) * 2);
}
