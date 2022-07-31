#include <iostream>
using namespace std;
// d
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    int c[n];
	    for(int i=0;i<n;i++){
	        c[i]=0;
	    }
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(a[i]==a[j]){
	                c[i]++;
	            }
	        }
	    }
	    int k=0;
	    for(int i=0;i<n;i++){
	        if(c[i]>k){
	            k=c[i];
	        }
	    }
	    cout<<n-k<<endl;
	}
	return 0;
}
//d done