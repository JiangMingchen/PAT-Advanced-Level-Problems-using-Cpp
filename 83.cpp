#include<bits/stdc++.h>
using namespace std;
struct student
{
   string name;
   string id;
   int grade;
};
bool cmp(student a, student b)
{
   return a.grade > b.grade;
}
int main()
{
   vector<student> stu;
   int n;
   scanf("%d", &n);
   while(n--)
   {
      student temp;
      cin >> temp.name >> temp.id >> temp.grade;
      stu.push_back(temp);
   }
   sort(stu.begin(), stu.end(), cmp);
   int low, high;
   scanf("%d%d", &low, &high);
   int flag = 0;
   for(vector<student>::iterator v = stu.begin(); v != stu.end(); v++)
   {
      if((*v).grade >= low && (*v).grade <= high)
      {
         flag = 1;
         cout << (*v).name << " " <<  (*v).id << endl;
      }
   }
   if(flag == 0)
   {
      printf("NONE");
   }
}
