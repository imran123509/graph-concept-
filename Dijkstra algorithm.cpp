#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=1e9+10;
vector<pair<int,int> > graph[N];
void dijkstra(int source){
	vector<int> vis(N, 0);
	vector<int> dist(N, inf);
	set<pair<int, int> > st;
	st.insert({0, source});
	dist[source]=0;
	while(st.empty()>0){
		auto node=*st.begin();
		int v=node.second;
		int v_dist=node.first;
		st.erase(st.begin());
		if(vis[v]) continue;
		vis[v]=1;
		for(auto &child : graph[v]){
			int child_v=child.first;
			int wt=child.second;
			if(dist[v]+wt<dist[child_v]){
				dist[child_v]=dist[v]+wt;
				st.insert({dist[child_v],child_v});
			}
		}
	}
}
int main(){

    
    return 0;

}
