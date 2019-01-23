/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (30.30%)
 * Total Accepted:    314.1K
 * Total Submissions: 1M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */
class Solution {
public:
    int mySqrt(int x) {
        double lo = 1, hi = x, mid = (hi + lo) / 2;
        for (int i = 0; i < 64; i++) {
            mid = (hi + lo) / 2;
            if (mid * mid > x) {
                hi = mid - 1;
            }
            else if (mid * mid < x) {
                lo = mid + 1;
            }
        }
        return mid;
    }
};
