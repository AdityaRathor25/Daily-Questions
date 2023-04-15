/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std ;
int solve ( vector<int>& coins , int amount  )
    {
        vector<int> dp( amount +1 , INT_MAX);
        dp[0] = 0;
        for( int i = 1 ; i <= amount ; i++ )
        {
            for(int j=0 ; j< coins.size() ; j++)
            {
                if((i-coins[j])>-1 && (dp[i-coins[j]] != INT_MAX) )
                dp[i] = min ( dp[i] , 1+ dp[i-coins[j]]);
            }
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins , amount );
        if(ans == INT_MAX )
            return -1;
        else 
        return ans;
    }
int main()
{
    vector<int> coins = {1,2,5};
    int n = coinChange(coins, 11);
    cout<< "Ans = "<< n;
    return 0;
}