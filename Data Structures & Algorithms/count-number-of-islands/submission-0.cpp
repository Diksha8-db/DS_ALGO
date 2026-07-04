class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    int n,m;
    void dfs(vector<vector<bool>>& visited, int row, int col,vector<vector<char>>& grid){
        visited[row][col] = true;
        // base case
        if(row == -1 && col == m-1){
            return;
        }

        for(int i = 0; i < 4; i++){
            int newRow = row + dir[i].first;
            int newCol = col + dir[i].second;

            if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= m || grid[newRow][newCol] == '0') continue;
            if(!visited[newRow][newCol]){
                dfs(visited,newRow,newCol,grid);
            } 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int noOfIsland = 0;

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    if(!visited[i][j]){
                        dfs(visited,i,j,grid);
                        noOfIsland++;
                    }
                }
            }
        }
        return noOfIsland;
    }
};
