class Solution {
public:
    
    
    int uniquePaths(int m, int n) {
        int grid [101][101] = {0};
        grid[0][0] = 1;
        
        for(int i=0;i<m;i++) 
            grid[i][0] = 1;
        
        for(int i=0;i<n;i++)
            grid[0][i] = 1;
      
        
        
        
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++)
        //         cout << grid[i][j] << " ";
        //     cout << endl;
        // }
        
        
        
        
        return grid[m-1][n-1];
    }
};