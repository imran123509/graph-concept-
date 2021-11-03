#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> g[N];
bool vis[N];
void dfs(int vertex){
	vis[vertex]=true;
	for(auto &child : g[vertex]){
		if(vis[child]) continue;
		dfs(child);
	}
}
int main(){
int n, m;
cin>>n>>m;
for(int i=0; i<m; ++i){
	int u, v;
	cin>>u>>v;
	g[u].push_back(v);
	g[v].push_back(u);
}
int count=0;
for(int i=0; i<n; i++){
	if(vis[i]) continue;
	dfs(i);
	count++;
}
cout<<count<<endl;

}
