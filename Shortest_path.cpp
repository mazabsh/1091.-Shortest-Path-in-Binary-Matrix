#include<iostream> 
#include<queue> 

using namespace std; 

class Solution{
public: 

     int shortestPathBinaryMatrix(vector<vector<int>>& grid){
       int n = grid.size();
       if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;  
       vector<pair<int,int>> directions={{-1,0},{0,-1},{1,0},{0,1},{-1,-1},{1,1},{-1,1},{1,-1}}; 
       queue<pair<int,int>> q; 
       q.push({0,0}); 
       grid[0][0]=1;
       int path =1; 
       while(!q.empty()){
         int sz = q.size(); 
         for(int i=0;i<sz;++i){
           auto [x,y] = q.front(); 
           q.pop(); 
           if(x==n-1 && y==n-1) return path; 
           for(auto [dx,dy]: directions){
             int nx = x+dx; 
             int ny=y+dy; 
             if(nx<n && nx>=0 && ny<n && ny>=0 && grid[nx][ny]==0){
               q.push({nx,ny}); 
               grid[nx][ny]=1; 
             } 
           }
         }
         ++path; 
       }
       return -1; 
     }
}; 
int main(){
  vector<vector<int>> grid={{0,0,0},{1,1,0},{1,1,0}};
  Solution sol; 
  cout << sol.shortestPathBinaryMatrix(grid) << endl; 
  return 0; 
}
