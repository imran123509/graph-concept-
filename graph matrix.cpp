#include<bits/stdc++h>
using namespace std;
void dfs(int i, int j, int initialcolor, int newcolor,vector<vector<int>>&image){
	int n=image.size();
	int m=image[0].size();
	if(i<0 || j<0 ||) return;
	if(i>=n || j>=m) return;
	if(image[i][j] !=initialcolor) return;
	image[i][j]=initialcolor;
	dfs(i-1, j, initialcolor, image, newcolor);
	dfs(i+1, j, initialcolor, image,newcolor);
	dfs(i, j-1, initialcolor, image,newcolor);
	dfs(i, j+1, initialcolor, image,newcolor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
int initialcolor=image[sr][sr];
if(initialcolor !=newcolor)
dfs(sr, sc, initialcolor,newcolor, image);
return image;
int main(){

    
    return 0;

}
