class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int lenY = grid.size();
        int lenX = grid[0].size();
        for(int y = 0; y < lenY; y++) 
        for(int x = 0; x < lenX; x++) {
            if(!(y == 0 && x == 0)) {
                if(y == 0) grid[y][x] += grid[y][x - 1];
                else if( x == 0) grid[y][x] += grid[y - 1][x];
                else grid[y][x] = max(grid[y][x - 1], grid[y - 1][x]) + grid[y][x];
            }
        }
        return grid[lenY - 1][lenX - 1];
    }
};