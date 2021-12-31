#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int parent[N];
int size[N];
void make(int v){
	parent[v]=v;
	size[v]=1;
}
int Find(int v){
	if(v==parent[v]) return v;
	//path compretion
	return parent[v]=Find(parent[v]);
}
void Union(int a, int b){
	a=Find(a);
	b=Find(b);
	if(a !=b){
		//union by size
	if(size[a]<size[b])
	swap(a,b);
	parent[b]=a;
	size[a] +=size[b];
	}
}
int main(){

   int n, k;
   cin>>n>>k;
   for(int i=1; i<=n; i++){
   	make(i);
   }
   int ct_component=0;
   while(k--){
   	int u,v;
	   cin>>u>>v;
	   Union(u,v);
   }
   for(int i=1; i<=n; i++){
   	if(Find(i)==i) ct_component++;
   }
   
}
