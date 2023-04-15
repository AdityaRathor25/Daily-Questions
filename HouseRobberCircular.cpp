/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    int startInd = 0;
    int secondInd = 1;
    int lastInd = n - 1;
    int secondLastInd = n - 2;
    int excludeLast = solve(nums, startInd, secondLastInd);
    int excludeFirst = solve(nums, secondInd, lastInd);
    return max(excludeLast, excludeFirst);
}
long long solve(vector<int> &nums, int stInd, int n)
{
    long long prev2 = 0;
    long long prev1 = nums[stInd];
    for (int i = stInd + 1; i <= n; i++)
    {
        long long ans = max(nums[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();
    if (n == 1)
    {
        return valueInHouse[0];
    }

    // case 1 he robbs 1st house and excludes last
    // 0-based indexing
    long long sum1 = solve(valueInHouse, 0, n - 2);

    // case2 he excludes 1st and robbs last
    // 0-based indexing
    long long sum2 = solve(valueInHouse, 1, n - 1);
    return max(sum1, sum2);
}
int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << rob(nums);
    return 0;
}