/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (39.04%)
 * Total Accepted:    264K
 * Total Submissions: 664.8K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
        string s[32];
        s[1] = "1";
        for (int i = 1; i < 30; i++) {
            char pre = 'z';
            int cnt = 0;
            for (const char& c: s[i]) {
                if (c != pre) {
                    if (pre != 'z')  {
                        s[i + 1].push_back(cnt + '0');
                        s[i + 1].push_back(pre);
                    }
                    pre = c;
                    cnt = 1;
                } else {
                    cnt++;
                }
            }
            s[i + 1].push_back(cnt + '0');
            s[i + 1].push_back(pre);
        }
        return s[n];
    }
};

