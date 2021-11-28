#include<bits/stdc++.h>
using namespace std;
class SGTree{
	vector<int> seg;
	public;
	SGTree(){
		seg.resize(4*n+1);
	}
	void build(int ind, int low, int high, int arr[], int seg[]){
	if(low==high){
		seg[ind]=arr[low];
		return;
	}
	int mid=(low+high)>>1;
	build(2*ind+1, low,mid,arr,seg);
	build(2*ind+2, mid+1, high,arr,seg);
	seg[ind]=min(seg[2*ind+1], seg[2*ind+1]);
}
int query(int ind, int low, int high, int l, int r, int seg[]){
	if(r<low || high<l) return INT_MAX;
	if(low>=l && high<=r) return seg[ind];
	int mid=(low+high)>>1;
	int left=query(2*ind+1, low, mid, l,r,seg);
	int right=query(2*ind+2, mid+1, high, l,r,seg);
	return min(left,right);
}
void updated(int ind, int low, int high, int i,int val, int seg[]){
	if(low==high){
		seg[ind]=val;
		return;
	}
	int mid=(low+high)>>1;
	if(i<=mid) updated(2*ind+1, low, mid,i, val,seg);
	else updated(2*ind+2, mid+1, high, i, val, seg);
	seg[ind]=min(seg[2*ind+1], seg[2*ind+2]);
}
};

