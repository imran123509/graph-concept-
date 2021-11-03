#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int substree_sum[N];
int evencnt[N];
vector<int> graph[N];
void dfs(int vertex, int parent=0){
	if(vertex%2==0){
		evencnt[vertex]++;
	}
     substree_sum[vertex] +=vertex;
	for(int child : graph[vertex]){
		if(child==parent) continue;
		dfs(child, vertex);
		substree_sum[vertex] +=substree_sum[child];
		evencnt[vertex] +=evencnt[child];
	}
}
int main(){

    int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int u, v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1);
	for(int i=1; i<=n; i++){
		cout<<substree_sum[i]<<" "<<evencnt[i]<<endl;
	}
	/*
    int q;
	cin>>q;
	while(q--){
		int v;
		cin>>v;
		cout<<substree[v]<<" "<<evencnt[v]<<endl;
	}
	*/

}
