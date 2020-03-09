#include<bits/stdc++.h>
using namespace std;
struct person
{
   char name[10];
   int age;
   int worths;
};
struct agelist
{
   vector<person> people;
};
bool cmp(person a, person b)
{
   if(a.worths != b.worths)
      return a.worths > b.worths;
   else
   {
      if(a.age != b.age)
         return a.age < b.age;
      else
         return strcmp(a.name, b.name) < 0;      
   }  
}
int main()
{
   agelist rk[210];
   vector<person> p;
   vector<person> thiscase;
   int n, q;
   scanf("%d%d", &n, &q);
   for(int i = 0; i < n; i++)
   {
      person a;
      scanf("%s%d%d", a.name, &a.age, &a.worths);
      p.push_back(a);
   }
   sort(p.begin(), p.end(), cmp);
   for(vector<person>::iterator v = p.begin(); v != p.end(); v++)
   {
      if(rk[(*v).age].people.size() <= 100)
      {
         rk[(*v).age].people.push_back(*v);
         thiscase.push_back(*v);
      }
   }
   for(int i = 0; i < q; i++)
   {
      int num, ag1, ag2, count = 0;
      scanf("%d%d%d", &num, &ag1, &ag2);
      printf("Case #%d:\n",i+1);
      for(int i = 0; i < thiscase.size() && count < num; i++)
      {
         if(thiscase[i].age >= ag1 && thiscase[i].age <= ag2)
         {
            printf("%s %d %d\n", thiscase[i].name, thiscase[i].age, thiscase[i].worths);
            count++;
         }
      }
      if(count == 0)
      {
         printf("None\n");
      }
   }
}
