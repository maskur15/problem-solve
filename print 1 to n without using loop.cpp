#include<bits/stdc++.h>
using namespace std;
void loop(int n)
{
    if(n==1)
        cout << 1 << endl;
    else {
        cout << n<< endl;
        loop(n-1);
    }
}
int main()
{
    int n;
    cin >> n;
    loop(n);
    
}
