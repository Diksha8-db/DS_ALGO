class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                auto const[row,col] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++){
                    int newRow = row + dir[i].first;
                    int newCol = col + dir[i].second;

                    if(newCol < 0 || newRow < 0 || newRow >= n || newCol >= m || grid[newRow][newCol] == -1) continue;
                    if(!visited[newRow][newCol]){
                        q.push({newRow,newCol});
                        grid[newRow][newCol] = grid[row][col] + 1;
                        visited[newRow][newCol] = true;
                    }
                }
            }
        }
    }
};
