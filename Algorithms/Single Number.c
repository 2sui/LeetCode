/*
 * Given an array of integers, every element appears twice except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

/****************************************************************************************/

/*
 * Key : M ^ N ^ M = N
 */
int singleNumber(int* nums, int numsSize) {
    if (0 == numsSize) return 0;
    
    int res = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        res = nums[i] ^ res;
    }
    
    return res;
    
}