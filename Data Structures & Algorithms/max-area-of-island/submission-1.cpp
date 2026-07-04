class Solution {
public:
    int n,m;
    int dfs(int row,int col,vector<vector<bool>>& visited,vector<vector<int>>& grid){
        if(row < 0 || col < 0 || row >= n || col >= m || visited[row][col] || grid[row][col] == 0) return 0;

        visited[row][col] = true;
        return 1 + dfs(row,col-1,visited,grid) + dfs(row,col+1,visited,grid) + dfs(row-1,col,visited,grid) + dfs(row+1,col,visited,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    maxArea = max(maxArea,dfs(i,j,visited,grid));
                }
            }
        }

        return maxArea;
    }
};
