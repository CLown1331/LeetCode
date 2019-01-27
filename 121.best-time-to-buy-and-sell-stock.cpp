/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (45.71%)
 * Total Accepted:    416.4K
 * Total Submissions: 910.1K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * 
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        vector < int > f(n, INT_MAX);
        vector < int > s(n, INT_MIN);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                f[i] = prices[i];
            } else {
                f[i] = min(f[i - 1], prices[i]);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                s[i] = prices[i];
            } else {
                s[i] = max(s[i + 1], prices[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans, s[i] - f[i]);
        }
        return ans;
    }
};
