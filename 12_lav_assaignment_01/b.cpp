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