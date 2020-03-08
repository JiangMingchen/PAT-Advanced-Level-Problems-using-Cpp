#include<bits/stdc++.h>
using namespace std;
struct account
{
   string user;
   string password;
   bool modify = false;
};

int main()
{
   int n, count = 0;
   account id[1010];
   scanf("%d", &n);
   for(int i = 0; i < n; i++)
   {
      string us, pass;
      cin >> us >> pass;
      id[i].user = us;
      id[i].password = pass;
   }
   for(int i = 0; i < n; i++)
   {
      int flag = 0;
      for(int j = 0; j < id[i].password.size(); j++)
      {
         if(id[i].password[j] == '1')
         {
            id[i].password[j] = '@';
            flag = 1;
         }
         else if(id[i].password[j] == '0')
         {
            id[i].password[j] = '%';
            flag = 1;
         }
         else if(id[i].password[j] == 'l')
         {
            id[i].password[j] = 'L';
            flag = 1;
         }
         else if(id[i].password[j] == 'O')
         {
            id[i].password[j] = 'o';
            flag = 1;
         }
      }
      if(flag == 1)
      {
         id[i].modify = true;
         count++;
      }
   }
   if(count == 0)
   {
      if(n == 1)
         printf("There is 1 account and no account is modified");
      else
         printf("There are %d accounts and no account is modified", n);      
      return 0;
   }
   else
   {
      cout << count << endl; 
      for(int i = 0; i < n; i++)
      {
         if(id[i].modify == true)
         {
            cout<< id[i].user << " " << id[i].password << endl;
         }
      }
   }  
}
