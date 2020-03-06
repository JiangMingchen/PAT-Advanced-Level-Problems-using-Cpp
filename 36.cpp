#include<bits/stdc++.h>
using namespace std;
struct student
{
   char gender;
   string name;
   string id;
   int grade;
};
bool cmp(student a, student b)
{
   if(a.gender != b.gender)
      return a.gender < b.gender;
   else
      return a.grade > b.grade;
}

int main()
{
   int num, flag = 1, dif;
   student stu[1000];
   scanf("%d", &num);
   int N = num;
   while(num)
   {
      int gd;
      char gen;
      string nm, ID;
      cin >> nm >> gen >> ID >> gd;
      stu[N -num].name = nm;
      stu[N - num].gender = gen;
      stu[N -num].id = ID;
      stu[N - num].grade = gd;
      num--;
   }
   sort(stu, stu + N, cmp);
   if(stu[0].gender == 'F')
   {
      dif = stu[0].grade;
      cout << stu[0].name << " " << stu[0].id << endl;
   }
   else
   {
      flag = 0;
      cout << "Absent" << endl;
   }
   if(stu[N - 1].gender == 'M')
   {
      dif -= stu[N - 1].grade;
      cout << stu[N - 1].name << " " << stu[N - 1].id << endl;
   }
   else
   {
      flag = 0;
      cout << "Absent" << endl;
   }  
   if(flag == 1)
   {
      cout << dif;
   }
   else
   {
      cout << "NA";
   } 
}
