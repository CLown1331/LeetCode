/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (50.11%)
 * Total Accepted:    318.1K
 * Total Submissions: 633.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector <vector <int> > ret;
        if (!n) return ret;
        for (int m = 0; m < (1 << n); m++) {
            vector < int > ans;
            for (int i = 0; i < n; i++) {
                if (m & (1 << i)) {
                    ans.push_back(nums[i]);
                }
            }
            ret.push_back(ans);
        }
        return ret;
    }
};
