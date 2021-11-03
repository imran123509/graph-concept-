#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> a[N];
bool vis[N];
bool iscycle(int vertex, int parent){
	vis[vertex]=true;
	bool iscycle=false;
	for(int child : a[vertex]){
		if(vis[child] && child==parent) continue;
		if(vis[child]) return true;
		
		iscycle |=dfs(child, vertex);
	}
	return iscycle;
}

int main(){
int n, m;
cin>>n>>m;
for(int i=0; i<m; i++){
	int u, v;
	cin>>u>>v;
	a[u].push_back(v);
	a[v].push_back(u);
}
bool iscycle=false;
for(int i=0; i<n; i++){
	if(vis[i]) continue;
	if(dfs(i,0)){
		iscycle=true;
	}
}
cout<<iscycle<<endl;
}