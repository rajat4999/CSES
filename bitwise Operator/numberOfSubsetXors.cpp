#include <bits/stdc++.h>
using namespace std;

int basis[30];
int s;
void insert(int x){
    for(int i=29;i>=0;i--){
        if(x&(1<<i)){
            if(!basis[i]){
                basis[i]=x;
                s++;
                return;
            }
            x^=basis[i];
        }
    }
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	memset(basis,0,sizeof(basis));
	s=0;
	for(int i=0;i<n;i++){
	    int x;
	    cin>>x;
	    insert(x);
	}
	int ans=0;
	

	
	cout<<(1LL<<s)<<endl;
	

}
