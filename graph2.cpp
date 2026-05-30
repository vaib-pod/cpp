//733. Flood fill
class Solution {
public:
    void dfs(vector<vector<int>>& image , int r , int c,int color,int original){
        int m = image.size();
        int n = image[0].size();

        if(r<0 || r>=m || c<0 || c>=n || image[r][c]!=original){
            return;
        }
        image[r][c] = color;
        dfs(image, r-1 ,c,color ,original);
        dfs(image, r+1 ,c ,color,original);
        dfs(image, r ,c-1,color,original );
        dfs(image, r ,c+1,color ,original);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        if(original!=color) dfs(image, sr, sc,color,original);
        return image;
    }
};
