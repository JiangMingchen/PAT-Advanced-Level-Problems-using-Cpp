#include<bits/stdc++.h>
using namespace std;
struct car
{
   string plate;
   int time;
   int status = -1;
};
struct record
{
   string plate;
   int intime, outtime;
};
bool cmp(car a, car b)
{
   if(a.plate != b.plate)
   {
      return a.plate < b.plate;
   }
   else if(a.time != b.time)
   {
     return a.time < b.time;
   }
   else if(a.status != b.status)
   {
      return a.status < b.status;
   }
}
bool cmp2(record a, record b)
{
   if(a.intime != b.intime)
   {
      return a.intime < b.intime;
   }
}
bool cmp3(record a, record b)
{
   return a.plate < b.plate;
}
bool cmp4(car a, car b)
{
   if(a.time != b.time)
   {
      return a.time > b.time;
   }
   else
   {
      return a.plate < b.plate;
   }
   
}
int main()
{
   int n, k;
   vector<car> vec;
   vector<record> r;
   scanf("%d%d", &n, &k);
   while(n--)
   {
      car temp;
      int hour, min, sec;
      string stat;
      char c;
      cin>> temp.plate;
      scanf("%d%c%d%c%d", &hour, &c, &min, &c, &sec);
      temp.time = sec + min * 60 + hour * 3600;
      cin>>stat;
      if(stat == "in")
      {
         temp.status = 0;
      }
      else
      {
         temp.status = 1;
      } 
      vec.push_back(temp);
   }
   sort(vec.begin(), vec.end(), cmp);
   for(int i = 0; i < vec.size(); i++)
   {
      if(vec[i].plate == vec[i + 1].plate && vec[i].status == 0 && vec[i + 1].status == 1)
      {
         record temp;
         temp.plate = vec[i].plate;
         temp.intime = vec[i].time;
         temp.outtime = vec[i + 1].time;
         r.push_back(temp);
      }
   }
   sort(r.begin(), r.end(), cmp2);
   while(k--)
   {
      int hour, min, sec, count = 0, t;
      char c;
      scanf("%d%c%d%c%d", &hour, &c, &min, &c, &sec);
      t = sec + min * 60 + hour * 3600;
      for(int i = 0; i < r.size(); i++)
      {
         if(r[i].intime <= t && r[i].outtime > t)
         {
            count++;
         }
         if(r[i].intime > t)
         {
            break;
         }
      }
      printf("%d\n", count);
   }
   sort(r.begin(), r.end(), cmp3);
   vector<car> total;
   for(int i = 0; i < r.size(); i++)
   {
      if(i == 0 || r[i].plate != r[i - 1].plate)
      {
         car temp;
         temp.plate = r[i].plate;
         temp.time = r[i].outtime - r[i].intime;
         total.push_back(temp);
      }
      else if(i != 0 && r[i].plate == r[i - 1].plate)
      {
         total.back().time += r[i].outtime - r[i].intime;
      }
   }
   sort(total.begin(), total.end(), cmp4);
   for(int i = 0; i < total.size(); i++)
   {
      if(total[i].time ==  total[i + 1].time)  
      {  
         cout << total[i].plate << " ";
      }
      if(total[i].time != total[i + 1].time)
      {
         cout << total[i].plate << " ";
         int h, m, s;
         h = total[i].time / 3600;
         m = total[i].time % 3600 / 60;
         s = total[i].time % 60;
         printf("%02d:%02d:%02d", h, m, s);
         break;
      }
   }
}
