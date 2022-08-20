#include <bits/stdc++.h>
using namespace std;
int main(){
    int test_case,days,q;
    cin>>test_case;
    while(test_case--)
    {
        cin>>days;
        int income[days];
        int spent[days];
        for(int i=0;i<days;i++)
        {
            cin>>income[i];
        }
        for(int i=0;i<days;i++)
        {
            cin>>spent[i];
        }
        cin>>q;
        int query[q];
        int result[q];
        int sum =0;
        for(int i=0;i<q;i++)
        {
            cin >>query[i]; 
        }
        for(int i=0;i<q;i++)
        {
            sum =0;

            for(int j=0;j<=query[i];j++)
            {

                sum =sum+(income[j]-spent[j]);
            }
            if(sum<0)
            {
                result[i]=0;
            }
            else
            {
                result[i]=1;
            }
        }
        for(int i=0;i<q;i++)
        {
            cout<<result[i]<<' ';
        }
    }
    return 0;
}