//We process the adjacent cells of the popped node, rotting any fresh oranges and pushing them into the queue. The popped orange is already rotten.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int minutes = 0;
        // Step 1: Count fresh oranges and push all rotten oranges
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        // Step 2: Direction arrays
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        // Step 3: BFS
        while(!q.empty() && fresh > 0) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                // Explore four directions
                for(int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    // Boundary check
                    if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                        continue;
                    // Check fresh orange
                    if(grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        fresh--;
                    }
                }
            }

            minutes++;
        }

        // Step 4: Check remaining fresh oranges
        return fresh == 0 ? minutes : -1;
    }
};
