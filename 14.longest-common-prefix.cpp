/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.75%)
 * Total Accepted:    387.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_length = INT_MAX;
        set < char > st;
        string ret = "";
        for (const string& s: strs) {
            min_length = min((int)s.size(), min_length);
        }
        if (min_length == INT_MAX) return ret;
        for (int i = 0 ; i < min_length; i++) {
            st.clear();
            for (const string& s: strs) {
                st.insert(s[i]);
            }
            if (st.size() == 1) ret.push_back(*st.begin());
            else break;
        }
        return ret;
    }
};
