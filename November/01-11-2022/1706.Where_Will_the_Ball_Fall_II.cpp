class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(m,-1);
        for(int col =0; col<m;col++)
        {
            int x = 0, y = col;
            int i;
            for(i=0;i<n;i++)
            {
                if((y==0 and grid[x][y]==-1) or (y==m-1 and grid[x][y]==1))
                    break;
                if(grid[x][y+grid[x][y]] != grid[x][y])
                    break;
                
                y += grid[x][y];
                x += 1;
            }
            
            if(i==n) ans[col] = y;
        }
        return ans;
    }
};