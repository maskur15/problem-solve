#include<bits/stdc++.h>
using namespace std;
bool isSubset(int x[],int n,int sum)
{
    int i,j;
    bool check[n][sum+1];
    for(i=0;i<n;i++)
        check[i][0]=true;
    for(i=1;i<=sum;i++)
        check[0][i]=false;
    check[0][x[0]]=true;
    for(i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
            {
                if(check[i-1][j])
                    check[i][j]=true;
                else if(x[i]<=j)
                    check[i][j]=check[i-1][j-x[i]];
            }
    }
    return check[n-1][sum];
}
bool equalpartition(int x[],int n,int sum)
{
    if(sum%2==0)
    {
        sum=sum/2;
        isSubset(x,n,sum);
    }
    else
    return false;
}
int main()
{
    int n,i,sum=0;
    cin >> n;
    int x[n];
    for(i=0;i<n;i++)
        {
            cin >> x[i];
            sum+=x[i];
        }
    if(equalpartition(x,n,sum))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}
