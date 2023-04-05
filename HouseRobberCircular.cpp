#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums , int ind , int lastInd)
    {
        int prev2=0;
        int prev1 = nums[ind];
        for(int i = ind+1 ; i<= lastInd ; i++ )
        {
            int include = prev2 + nums[i];
            int exclude = prev1;
            int curr = max ( include , exclude );
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1)
            return nums[0];
        int startInd=0;
        int secondInd = 1;
        int lastInd = n-1;
        int secondLastInd = n-2;
        int excludeLast = solve(nums ,startInd , secondLastInd);
        int excludeFirst = solve(nums , secondInd , lastInd );
        return max(excludeLast , excludeFirst);
    }
int main()
{
    vector<int> nums = {1,2,3,1};
    cout<<rob(nums);
    return 0;
}