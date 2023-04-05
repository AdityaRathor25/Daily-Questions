#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solveRecc(vector<int>& nums )
    {
        int n = nums.size();
        int prevprev = 0;
        int prev = nums[0];
        int curr=0;
        for(int i=1 ; i<n ; i++)
        {
            int include =0;
            if(i>1)
                include = prevprev + nums[i];
            else
                include =  nums[i];
            int exclude = prev;
            curr = max(include , exclude);
            prevprev=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        return solveRecc(nums);   
    }
int main()
{
    vector<int> nums = {2,7,9,3,1};
    cout<<rob(nums);
    return 0;
}