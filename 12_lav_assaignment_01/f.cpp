// problem number F slove
#include<bits/stdc++.h>
using namespace std;
int main(){
    int couter = 0;
    int a,b,c;
    cin>>a>>b>>c;
    if (a !=b)
    {
        couter++;
    }
     if(b !=c){
        couter++;
    }
    if (c !=a)
    {
        couter++;
    }
    if (a==b && b==c && c==a)
    {
        cout<<"1";
        return 0;
    }
    
    cout<<couter<<endl;

    return 0;
    
}