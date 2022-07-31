#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            int a;
            cin>>a;
            mp[a]++;
        }
        cout << n - mp.begin()->second <<endl;
    }

    return 0;

}
//c done