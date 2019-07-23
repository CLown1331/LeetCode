class Solution {
public:
    int dp[505][505];
    int solve(int x, int y, vector<int>& piles) {
        if (x > y) return 0;
        int &ret = dp[x][y];
        if (~ret) return ret;
        return ret = max({
            solve(x + 1, y - 1, piles) + piles[x] - piles[y],
            solve(x + 1, y - 1, piles) - piles[x] + piles[y],
            solve(x + 2, y, piles) + piles[x] - piles[x + 1],
            solve(x + 2, y, piles) - piles[x] + piles[x + 1],
            solve(x, y - 2, piles) - piles[y] + piles[y - 1],
            solve(x, y - 2, piles) - piles[y] + piles[y - 1]
        });
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof dp);
        return solve(0, piles.size() - 1, piles) > 0;
    }
};
