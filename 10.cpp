#include <bits/stdc++.h>
using namespace std;
int toN(char c)
{
   if(c >= '0' && c <= '9') return c - '0';
   else return c - 'a' + 10;
}
long long int toD(string number, long long int radix)
{
   long long int num = 0, ant = 1;
   for(int i = number.size() - 1; i > -1; i--, ant *= radix)
   {
      num += ant * toN(number[i]);
      if(num < 0 || ant < 0) return -1;
   }
   return num;
}

long long int trial(string number, long long int aim)
{
   long long int radix = 2;
   long long int r = aim;
   string temp = number;
   sort(temp.begin(), temp.end());
   if(temp.back() >= 'a' && temp.back() <= 'z') radix = temp.back() - 'a' + 11;
   else radix = temp.back() - 47;
   while(r >= radix)
   {
      long long int mid = (r + radix) >> 1;
      long long int t = toD (number, mid);
      if(t >= aim || t == -1) r = mid - 1;
      else radix = mid + 1;
   }
      if(toD(number, radix) == aim) return radix;
      else return -1;
}
int main()
{
   string n1, n2;
   int tag, radix;
   long long int aim;
   cin >> n1>> n2 >> tag >> radix;
   string temp;
   if(tag == 1) {aim = toD(n1,radix); temp = n2;}
   else {aim = toD(n2,radix); temp = n1;}
   long long int conclusion = trial(temp, aim);
   if(conclusion > 0) cout<<conclusion;
   else cout<<"Impossible";
}
