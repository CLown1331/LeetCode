/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.39%)
 * Total Accepted:    441.8K
 * Total Submissions: 1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        for (const int& x: nums) {
            sum = max(sum + x, 0);
            ans = max(sum, ans);
        }
        if (ans == 0) ans = *max_element(nums.begin(), nums.end());
        return ans;
    }
};
