#include<bits/stdc++.h>
using namespace std;
int n, m, sum[100010];
int upper_bound(int L, int R, int x)
{
    int mid, left = L , right = R;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(sum[mid] > x)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    int S = 0;
    int nears = 100000010;
    scanf("%d%d", &n, &m);
    for(int i = 1 ; i <= n; i++)
    {
        int temp;
        scanf("%d", &temp);
        S += temp;
        sum[i] = S;
    }
    for(int i = 1; i <= n; i++)
    {
        int j = upper_bound( i, n + 1, sum[i - 1] + m);
        if(sum[j - 1] - sum[i - 1] == m)
        {
            nears = m;
            break;
        }
        else if(j <= n && sum[j] - sum[i - 1] < nears)
        {
            nears = sum[j] - sum[i - 1];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int j = upper_bound( i, n + 1, sum[i - 1] + nears);
        if(sum[j - 1] - sum[i - 1] == nears)
        {
            printf("%d-%d\n", i, j - 1);
        }
    }

}
