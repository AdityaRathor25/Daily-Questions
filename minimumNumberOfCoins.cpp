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
    vector<int> fruits = {1,2,3};
    int n = coinChange(fruits, 11);
    cout<< "Ans = "<< n;
    return 0;
}