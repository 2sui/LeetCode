/*
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 *
 * Credits:
 * Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
 */

/****************************************************************************************/

int rob(int* nums, int numsSize) {
    int *maxlist = 0, max = 0;
    if (numsSize > 0)
    {
        maxlist = (int*)malloc(sizeof(int)*numsSize);
        
    }
    else
    {
        return (int)maxlist;
    }
    
    maxlist[0] = nums[0];
    
    if (numsSize > 1)
    {
        maxlist[1] = nums[1] > nums[0] ? nums[1] : nums[0];
    }
    
    for (int i = 2; i < numsSize; i++)
    {
        maxlist[i] = maxlist[i - 1] > (maxlist[i - 2] + nums[i]) ? maxlist[i - 1] : maxlist[i - 2] + nums[i];
        // maxlist[i - 2] is not robbed, maxlist[i - 1] is robbed, if maxlist[i] is maxlist[i - 2] + nums[i] ,then the maxlist[i] changes to be robbed and maxlist[i - 1] changes to not  be robbed
    }
    
    max = maxlist[numsSize - 1];
    free(maxlist);
    return max;
}