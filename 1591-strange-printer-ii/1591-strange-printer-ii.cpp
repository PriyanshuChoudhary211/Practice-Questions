class Solution {
public:
    bool dfs(int col, unordered_set<int> overlaps[], vector<int> &vis) {
    if (vis[col] != 0)
        return vis[col] == 2;
    vis[col] = 1;
    for (auto col1 : overlaps[col])
        if (!dfs(col1, overlaps, vis))
            return false;
    vis[col] = 2;
    return true;
}
    bool isPrintable(vector<vector<int>>& grid) {
         vector<array<int, 4>> rects(61, {INT_MAX, INT_MAX, INT_MIN, INT_MIN});
    unordered_set<int> overlaps[61];
    for (int i = 0; i < grid.size(); ++i)
        for (int j = 0; j < grid[0].size(); ++j) {
            int col = grid[i][j];
            rects[col][0] = min(rects[col][0], i);
            rects[col][1] = min(rects[col][1], j);
            rects[col][2] = max(rects[col][2], i);
            rects[col][3] = max(rects[col][3], j);
        }
    for (auto col = 0; col <= 60; ++col)
        for (int i = rects[col][0]; i <= rects[col][2]; ++i)
            for (int j = rects[col][1]; j <= rects[col][3]; ++j)
                if (grid[i][j] != col)
                    overlaps[col].insert(grid[i][j]);
    for (auto col = 0; col <= 60; ++col)
        if (!dfs(col, overlaps, vector<int>(61) = {}))
            return false;
    return true;
    }
};