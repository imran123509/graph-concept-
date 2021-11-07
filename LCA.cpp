#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
//lowest common ancestor
vector<int> graph[N];
int parent[N];
// storing the parent of all node
void dfs(int vertex, int par=-1){
	parent[vertex]=par;
	for(int child : graph[vertex]){
		if(child==par) continue;
		dfs(child, vertex);
	}
}
// storing the path
vector<int> path(int vertex){
	vector<int> ans;
	while(vertex !=-1){
		ans.push_back(vertex);
		vertex=parent[vertex];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n-1; i++){
		int x, y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1);
   int x, y;
   cin>>x>>y;
   vector<int> path_x=path(x);
   vector<int> path_y=path(y);
   int minlen=min(path_x.size(), path_y.size());
   int lca=-1;
   for(int i=0; i<minlen; i++){
   	if(path_x[i]==path_y[i]){
	   	lca=path_x[i];
	   }
   }
   cout<<lca<<endl;
}


/*

13
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11
*/

