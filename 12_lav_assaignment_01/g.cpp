// problem g
#include <iostream>
  #include <cstdio>
  #include <algorithm>
  #include <cstring>
  #include <string>
  #include <cmath>
  using namespace std;
  #define ll long long
  const int N=10005;
 const int mod=1e9+7;
 const int maxn=1e7;
 int main()
 {
     int n;
     while(cin>>n){
         int a=n/100;
         int b=(b-a*100)/10;
         int c=n%10;
         if(a==c) cout<<"Yes"<<endl;
         else cout<<"No"<<endl;
     }
     return 0;
}