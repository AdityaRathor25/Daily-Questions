// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

 

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.
 

// Constraints:

// 1 <= text1.length, text2.length <= 1000
// text1 and text2 consist of only lowercase English characters.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int iterativeDP(string &text1, string &text2, int n , int m )
    {
        // vector<vector<int>> dp(n+1 , vector<int> (m+1,0))
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        for(int i = n-1 ; i>=0 ; i--)
        {
            for(int j = m-1 ; j>=0 ; j--)
            {
            if(text1[i]==text2[j])
                curr[j] = 1+next[j+1];
            else 
                curr[j] = max(curr[j+1] , next[j]);
            }
            next=curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        return iterativeDP(text1, text2, n , m);
    }
int main()
{
    return 0;
}