// start lab exam 
// problem slove number b ** 
#include <bits/stdc++.h>
using namespace std;
using namespace std;
#define MX 10005

const int N = 100000;
int data[N+10], save[4*N+10];
int inf = 1 << 28;
int n;

void build_tree(int node, int st, int en, int a[], int A[])
{
    if(st==en)
    {
        A[node] = a[st];
        return;
    }
    int mid = st+ ((en-st)>>1);
    int left = node<<1;
    int right = (node<<1)+1;
    build_tree(left, st, mid, a, A);
    build_tree(right, mid+1, en, a, A);
    A[node] = min(A[left], A[right]);
}
int query_tree(int node, int st, int en, int a, int b, int A[])
{
    if(a>b)
        return inf;

    if(st==a && en==b)
        return A[node];
    int mid = st+ ((en-st)>>1);
    int left = node<<1;
    int right = (node<<1)+1;

    int l = query_tree(left, st, mid, a, min(b, mid), A);
    int r = query_tree(right ,mid+1, en, max(a, mid+1), b, A);
    return min(l, r);
}

void Build(int tot)
{
    build_tree(1, 1, tot, data, save);
}
int query(int a, int b)
{
    return query_tree(1, 1, n, a, b, save);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int test, t;
    int q, a, b;
    cin >> test;
    for(t=1; t<=test; t++)
    {
        cin >> n >> q;
        for(int i=1; i<=n; i++)
             scanf("%d", &data[i]);
        Build(n);
        cout << "Case " << t  <<  ":" << endl;
        for(int i=1; i<=q; i++)
        {
           scanf("%d %d", &a, &b);
           printf("%d\n",  query(a, b));
        }
    }
    return 0;
}

// problem slove number g**

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
// problem slove number h;; 

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int pos1,pos2;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='A'){
            pos1 = i;
            
            break;
        }
    }
    for (int i = s.size()-1; i >=0; i--)
    {
        if (s[i]=='Z')
        {
             
            pos2=i;
            
            break;
        }
       

    }
    cout<<pos2-pos1+1<<"\n";

    return 0;
    
}

// problem c slove;

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
int main(){
    int t,n;
    scanf("%d",&t) ;
    for (int tc = 0; tc < t; tc++)
    {
        scanf("%d",&n);
        int a[n];
        int couter=0,l;
        for (int j = 0; j < n; j++)
        {
            cin>>a[j];
        }
        sort(a,a+n);
        int size = n/2;
        while (a[size-2] !=a[size-1])
        {
            size=size/2;
        }
        for (int j =size-2 ; j < n; j++)
        {
           if (a[j]>a[size-1])
           {
                couter =n-j+2;
           }
           
        }
        
        cout<<couter<<endl;

    }
    return 0;
    
}


// problem number e slove,,
#include<bits/stdc++.h>
#define mx 100005
using namespace std;
int arr[mx];
int tree[mx*3];
void init(int node,int b,int e)
{
    if(b==e){
        tree[node]=arr[b];
        return;
    }
    int left =node*2;
    int right = node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]= tree[left]+tree[right];
}
int query(int node,int b,int e,int i, int j)
{
    if(b>j || e<i){
        return 0;
    }
    if(b>=i && e<=j){
        return tree[node];
 }
    int left =node*2;
    int right = node*2+1;
    int mid=(b+e)/2;
    int q1=query(left,b,mid,i,j);
    int q2=query(right,mid+1,e,i,j);
     return q1+q2;
}
void update(int node,int b,int e,int i,int newvalue)
{
    if(i>e || i<b)
        return;
    if(b>=i && e<=i){
        tree[node]=newvalue;
        return;
    }
    int left =node*2;
    int right = node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]= tree[left]+tree[right];
}
int main()
{
    int t,n,q,v,x,y,z;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case %d:\n",i);
        scanf("%d %d",&n,&q);
        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
            init(1,0,n-1);
        for(int k=0;k<q;k++)
        {
            scanf("%d",&x);
            if(x==1)
            {
                scanf("%d",&y);
                printf("%d\n",arr[y]);
                arr[y]=0;
                update(1,0,n-1,y,0);
            }
            else if(x==2)
            {
                scanf("%d %d",&y,&z);
                arr[y]+=z;
                update(1,0,n-1,y,arr[y]);
                //printf("%d\n",ans);
            }
            else
            {
                scanf("%d %d",&y,&z);
                int ans=query(1,0,n-1,y,z);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}


// problem number A slove;

#include<bits/stdc++.h>
using namespace std;
int main(){
    int coute= 0;
    int arr[3];
    for (int i = 0; i <3; i++)
    {
        cin>>arr[i];
        if (arr[i]>=10)
        {
            coute++;
        }
        
    }
    cout<<coute<<endl;
    return 0;
}

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