/*
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 */

/****************************************************************************************/

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 2) return numsSize;
    int i = 0;
    
    for (int j = 1; j < numsSize;) {
        
        if (nums[i] != nums[j]) {
            if (j - i > 1) {
                /*
                 the distance of j and i, the nums[i + 1] must be the next different number`s pos.
                 i i+1
                 |  |
                 1  2  3  4  4  4  5  6
                 |
                 j
                 */
                nums[i + 1] = nums[j];
            }
            
            i++;
            j++;
            
        } else {
            j++;
        }
    }
    
    return i + 1;
    
}