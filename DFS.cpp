#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> adj[N];
bool vis[N];
void dfs(int vertex){
	vis[vertex]=true;
	cout<<vertex<<" ";
	for(auto &child : adj[vertex]){
		if(vis[child])continue;
		
		dfs(child);
	
	}
}
int main(){
int n, m;
cin>>n>>m;
for(int i=0; i<m; ++i){
	int u, v;
	cin>>u>>v;
	adj[u].push_back(v);
	adj[v].push_back(u);
	
}
    dfs(1);
    

}
