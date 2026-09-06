class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<bool>>& vis, int color, int newColor, int n, int m){
        image[row][col] = newColor;
        vis[row][col] = true;

        if(row-1 >= 0 && !vis[row-1][col] && image[row-1][col] == color)
            dfs(row-1, col, image, vis, color, newColor, n, m);
        
        if(row+1 < n && !vis[row+1][col] && image[row+1][col] == color)
            dfs(row+1, col, image, vis, color, newColor, n, m);

        if(row, col+1 < m && !vis[row][col+1] && image[row][col+1] == color)
            dfs(row, col+1, image, vis, color, newColor, n, m);
        
        if(row, col-1 >= 0 && !vis[row][col-1] && image[row][col-1] == color)
            dfs(row, col-1, image, vis, color, newColor, n, m);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dfs(sr, sc, image, vis, image[sr][sc], color, n, m);
        return  image;
    }
};