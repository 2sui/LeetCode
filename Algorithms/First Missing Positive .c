/*
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 */

/****************************************************************************************/

// int firstMissingPositive(int* nums, int numsSize) {
//     if (numsSize == 0) return 1;
//     int forward_min = -1, forward_max = -1, min = -1, max = -1, positnum = 0;
//     for (int i = 0; i < numsSize; i++) {
//         if (nums[i] > 0) {
//             positnum++;
//             if ((-1 == min) || (nums[i] < min)) {
//                 min = nums[i];
//             }

//             if ((-1 == max) || (nums[i] > max)) {
//                 max = nums[i];
//             }

//             if ((-1 == forward_min) || (forward_min == nums[i])) {
//                 forward_min = nums[i] - 1;
//             }

//             if ((-1 == forward_max) || (forward_max == nums[i])) {
//                 forward_max = nums[i] + 1;
//             }
//         }
//     }

//     if (-1 == forward_min) return 1;
//     if (positnum == max) return forward_max;
//     if (forward_min > min) {
//         return forward_min;

//     } else {
//         if (forward_min > 0) return 1;
//     }
//     return forward_max;
// }
int firstMissingPositive(int* nums, int numsSize) {
    if (numsSize == 0) return 1;
    int tmp;
    for (int i = 0; i < numsSize; i++) {
        /* put nums[i] to right position in the loop */
        while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            tmp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = tmp;
        }
    }
    
    /* if there are some missing numbers, the missing position is not match(no matter it is -1 or bigger than numsSize, it will be moved to missing position) */
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) return i + 1;
    }
    
    return numsSize + 1;
}
