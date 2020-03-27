#include<bits/stdc++.h>
using namespace std;
struct station
{
   double per, distance;
};
bool cmp(station a, station b)
{
   if(a.distance != b.distance)
   {
      return a.distance < b.distance;
   }
   else
   {
      return a.per < b.per;
   }
   
}
int main()
{
   int num;
   double cost = 0.0, t = 0.0, tank, per_oil, dis;
   scanf("%lf%lf%lf%d", &tank, &dis, &per_oil, &num);
   vector<station> sta(num + 1);
   for(int i = 0; i < num; i++)
   {
      scanf("%lf%lf", &sta[i].per, &sta[i].distance);
   }
   sta[num].per = 0;
   sta[num].distance = dis;
   sort(sta.begin(), sta.end(), cmp);
   if(sta[0].distance != 0)
   {
      printf("The maximum travel distance = 0.00");
      return 0;
   }
   int now = 0;
   while(now != num)
   {
      int flag = 0;
      for(int i = now + 1; i < num + 1; i++)
      {
         if(sta[i].per < sta[now].per && sta[i].distance <= tank * per_oil + sta[now].distance)
         {
            if(t < (sta[i].distance - sta[now].distance) / per_oil)
            {
               cost += sta[now].per * ((sta[i].distance - sta[now].distance) / per_oil - t);
               t = 0;
            }
            else
            {
               t -= (sta[i].distance - sta[now].distance) / per_oil;
            }
            flag = 1;
            now = i;
         }
         else
         {
            flag = 0;
         }
      }
      if(flag == 0)
      {  

         int minper = 100000, pos = -1;
         for(int i = now + 1; i < num + 1; i++) 
         {
            if(sta[i].distance <= tank * per_oil + sta[now].distance && sta[i].per <= minper)
            {
               minper = sta[i].per;
               pos = i;
            }
         }
         if(pos == -1)
         {
            printf("The maximum travel distance = %.2lf", sta[now].distance + tank * per_oil);
            return 0;
         }
         else
         {
            cost += sta[now].per * (tank - t);
            t = tank - (sta[pos].distance - sta[now].distance) / per_oil; 
            now = pos;
         }
      }
   }
   printf("%.2lf", cost);
}
