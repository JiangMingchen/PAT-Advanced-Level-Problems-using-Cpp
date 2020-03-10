#include<bits/stdc++.h>
using namespace std;
struct record
{
   string name;
   int mon, day, h, m;
   bool status;
};
struct line
{
   record on;
   record off;
   int minute = 0;
   float fare = 0;
};
struct person
{
   string name;
   int mon;
   float amount = 0.0;
   stack<record> on;
   stack<record> off;
   stack<line> l;
};
bool cmp(record a, record b)
{
   if(a.name != b.name)
      return a.name < b.name;
   else if (a.mon != b.mon)
      return a.mon < b.mon;
   else if(a.day != b.day)
      return a.day < b.day;
   else if(a.h != b.h)
      return a.h < b.h;
   else if(a.m != b.m)
      return a.m < b.m;
   else if(a.status != b.status)
      return a.status < b.status;
}
int toll[24];
float fare(record a, record b, int& time)
{
   float f = 0;
   while(a.day < b.day || a.h < b.h || a.m < b.m)
   {
      time++;
      f += toll[a.h];
      a.m++;
      if(a.m >= 60)
      {
         a.m = 0;
         a.h++;
      }
      if(a.h >= 24)
      {
         a.h = 0;
         a.day++;
      }
   }
   return f / 100;
}
int main()
{
   int n;
   person p[1000];
   vector<record> list;
   for(int i = 0; i < 24; i++)
   {
      scanf("%d", &toll[i]);
   }
   scanf("%d", &n);
   while(n--)
   {
      string sta;
      char dot;
      record it;
      cin>>it.name;
      scanf("%d%c%d%c%d%c%d", &it.mon, &dot, &it.day, &dot, &it.h, &dot, &it.m);
      cin>>sta;
      if(sta == "on-line") 
      {
         it.status = false;
      }
      else 
      {
         it.status = true;
      }
      list.push_back(it);
   }
   sort(list.begin(), list.end(), cmp);
   int count = 0;
   for(vector<record>::iterator v = list.begin(); v != list.end(); v++)
   {
      if(v == list.begin())
      {
         p[count].name = (*v).name;
         p[count].mon = (*v).mon;
      }
      if(v!= list.begin() && (*v).name != (*(v-1)).name)
      {
         p[++count].name = (*v).name;
         p[count].mon = (*v).mon;
      }
      if((*v).status == 0 && (*(v + 1)).status == 1 && (*(v + 1)).name == (*v).name)
      {
         p[count].on.push(*v);
      }
      else if((*v).status == 1 && (*(v - 1)).status == 0)
      {
         p[count].off.push(*v);
      }
      else
      {
         continue;
      } 
   }
   for(int i = 0; i <= count; i++)
   {
      while(!p[i].on.empty() && !p[i].off.empty())
      {
         line temp;
         temp.on = p[i].on.top();
         p[i].on.pop();
         temp.off = p[i].off.top();
         p[i].off.pop();
         temp.fare = fare(temp.on,temp.off,temp.minute);
         p[i].l.push(temp);
         p[i].amount += temp.fare;
      }
   }
   for(int i = 0; i <= count; i++)
   {
      if(p[i].l.empty()) continue;
      cout<<p[i].name << " ";
      printf("%02d\n",p[i].mon);
      while(!p[i].l.empty())
      {
         line a = p[i].l.top();
         printf("%02d:%02d:%02d ", a.on.day, a.on.h, a.on.m);
         printf("%02d:%02d:%02d ", a.off.day, a.off.h, a.off.m);
         printf("%d $%.2f\n", a.minute, a.fare);
         p[i].l.pop();
      }
      printf("Total amount: $%.2f\n",p[i].amount);
   }
}
