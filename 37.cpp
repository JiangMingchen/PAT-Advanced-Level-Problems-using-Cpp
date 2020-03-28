#include<bits/stdc++.h>
using namespace std;
int main()
{
   vector<int> pos_coupons, neg_coupons, pos_products, neg_products;
   int c, p, sum = 0;
   scanf("%d", &c);
   while(c--)
   {
      int temp;
      scanf("%d", &temp);
      if(temp > 0)
      {
         pos_coupons.push_back(temp);
      }
      else
      {
         neg_coupons.push_back(temp);
      }
   }
   scanf("%d", &p);
   while(p--)
   {
      int temp;
      scanf("%d", &temp);
      if(temp > 0)
      {
         pos_products.push_back(temp);
      }
      else
      {
         neg_products.push_back(temp);
      }
   }
   sort(pos_products.begin(), pos_products.end(), greater<int>());
   sort(pos_coupons.begin(), pos_coupons.end(), greater<int>());
   sort(neg_products.begin(), neg_products.end());
   sort(neg_coupons.begin(), neg_coupons.end());
   for(int i = 0; i < pos_coupons.size(); i++)
   {
      if(i < pos_products.size())
      {
         sum += pos_products[i] * pos_coupons[i];
      }
   }
   for(int i = 0; i < neg_coupons.size(); i++)
   {
      if(i < neg_products.size())
      {
         sum += neg_products[i] * neg_coupons[i];
      }
   }
   printf("%d", sum);
}
