///given the amount and the denomination find number of ways to 
///make this amount 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j;
    cin >> n >> m;
    int coin[m];
   unsigned long long int arr[m][n+1];
    memset(arr,0,sizeof(arr));
    for(i=0;i<m;i++)
       {
         cin >> coin[i]; arr[i][0]=1;
       }
    sort(coin,coin+m);
    for(i=coin[0];i<=n;)
    {
        arr[0][i]=1;
        i=i+coin[0];
    }
    for(i=1;i<m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j>=coin[i])
                arr[i][j]+=arr[i-1][j]+arr[i][j-coin[i]];
            else
                arr[i][j]=arr[i-1][j] ;
        }
    }
    cout << arr[m-1][n] << endl;

}

