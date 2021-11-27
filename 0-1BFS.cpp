#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=1e9+7;
vector<pair<int,int>> g[N];
vector<int> level(N, inf);
int n, m;
int bfs(){
	deque<int>d;
	d.push_back(1);
	level[1]=0;
	while(!d.empty()){
		int curr_v=d.front();
		d.pop_front();
		for(auto &child : g[curr_v]){
			int child_v=child.first;
			int child_wt=child.second;
			if(level[curr_v]+child_wt<level[child_v]){
				level[child_v]=level[curr_v]+child_wt;
				if(child_wt==1){
					d.push_back(child_v);
				}else{
					d.push_front(child_v);
				}
			}
		}
	}
	return level[n]==inf ? -1 : level[n];
}
int main(){

    cin>>n>>m;
	for(int i=0; i<m; i++){
		int x,y;
		cin>>x>>y;
		if(x==y) continue;
		g[x].push_back({y,0});
		g[y].push_back({x,1});
	}
    cout<<bfs()<<endl;
}
