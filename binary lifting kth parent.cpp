#include<bits/stdc++.h>
using namespace std;
const int N=17;
const int nn=40;
int table[N][40];
void build(vector<int> &arr){
	int sz=arr.size();
	for(int i=0; i<sz; i++){
		table[0][i]=arr[i];
	}
	for(int i=1; i<N; i++){
		for(int j=0; j<sz; j++){
			table[i][j]=table[i-1][table[i-1][j]];
		}
	}
	
}
int query(int a, int k){
	for(int i=0; i<N; i++){
		int mask=(1<<i);
		if((k&mask)>0){
			a=table[i][a];
		}
	}
	return a;
}
int main(){
	int n;

	cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	int q;
	cin>>q;
	build(a);
	while(q--){
		int a, b;
		cin>>a>>b;
		int ans=query(a,b);
		cout<<ans<<endl;
	}
}



/*

7
parent  0 0 0 1 3 2 3
index   0 1 2 3 4 5 6
        0
		1/\2
		/	\5
		3
		/4\6
6
5 1
6 2
3 2
3 3
6 3
4 1
*/