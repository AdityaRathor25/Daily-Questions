// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".
 

// Constraints:

// 1 <= s.length <= 1000
// s consists only of lowercase English letters.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int rec(string &s , int n )
    {
        vector<vector<int>> dp(n , vector<int> (n));
        for(int i = n-1 ; i>=0 ; i--)
        {
            dp[i][i]=1;
            for(int j = i+1 ; j<n ; j++)
            {
            if(s[i]==s[j])
                dp[i][j] = 2+dp[i+1][j-1];
            else 
                dp[i][j] = max(dp[i][j-1] , dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        return rec(s , n );
    }
int main()
{
    return 0;
}