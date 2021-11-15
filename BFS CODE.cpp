#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> graph[N];
int vis[N];
int level[N];
void bfs(int source){
	queue<int> q;
	q.push(source);
	vis[source]=1;
	while(!q.empty()){
		int curr_vertex=q.front();
		q.pop();
		cout<<curr_vertex<<" ";
		for(int child : graph[curr_vertex]){
			if(!vis[child]){
				q.push(child);
				vis[child]=1;
				level[child]=level[curr_vertex]+1;
			}
		}
	}
	cout<<endl;
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
	bfs(1);
	for(int i=1; i<=n; i++){
		cout<<i<<" "<<level[i]<<endl;
	}

}
