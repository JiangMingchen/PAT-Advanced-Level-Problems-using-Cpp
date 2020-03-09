#include<bits/stdc++.h>
using namespace std;
struct student 
{
   int id;
   char name[100];
   int grade; 
};
bool cmp_id(student a, student b)
{
   return a.id < b.id;
}
bool cmp_name(student a, student b)
{
   if(strcmp(a.name, b.name) != 0)
      return strcmp(a.name, b.name) < 0;
   else
      return a.id < b.id;
}
bool cmp_grade(student a, student b)
{
   if(a.grade != b.grade)
      return a.grade < b.grade;
   else
      return a.id < b.id;
}
int main()
{
   vector<student>stu;
   int n, c;
   scanf("%d%d", &n, &c);
   for(int i = 0; i < n; i++)
   {
      int ID, GRADE;
      char NAME[100];
      scanf("%d%s%d", &ID, &NAME, &GRADE);
      student st;
      st.id  = ID;
      strcpy(st.name, NAME);
      st.grade = GRADE;
      stu.push_back(st);
   }
   switch(c)
   {
      case 1:
      {
         sort(stu.begin(), stu.begin() + n, cmp_id);
         break;
      }
      case 2:
      {
         sort(stu.begin(), stu.begin() + n, cmp_name);
         break;
      }
      case 3:
      {
         sort(stu.begin(), stu.begin() + n, cmp_grade);
         break;
      }
   }
   for(vector<student>::iterator v = stu.begin(); v!=stu.end(); v++)
   {
      student pos = *v;
      printf("%06d %s %d\n", pos.id, pos.name, pos.grade);
   }
}
