#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int height[N], depth[N];
vector<int> graph[N];
void dfs(int vertex, int parent){
	/* take action on vertex before entring the vertex note
	*/
	

	for(auto &child : graph[vertex]){
			/* take action on child before entring the child note
	*/
	
		if(child==parent) continue;
		depth[child]=depth[vertex]+1;
		dfs(child, vertex);
		height[vertex]=max(height[vertex], height[child]+1);
			/* take action on child after exiting the child note
	*/
	}
		/* take action on vertex before exiting the child note
	*/
}
int main(){
int n;
cin>>n;
for(int i=0; i<n-1; ++i){
	int u, v;
	cin>>u>>v;
	graph[u].push_back(v);
	graph[v].push_back(u);
}
dfs(1,0);
for(int i=1; i<=n; i++){
	cout<<depth[i]<<" "<<height[i]<<endl;
}

}
