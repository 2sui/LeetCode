/*
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 *
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 *
 * [show hint]
 *
 * Related problem: Reverse Words in a String II
 *
 * Credits:
 * Special thanks to @Freezen for adding this problem and creating all test cases.
*/

/****************************************************************************************/

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        
        if (n < 2)
        {
            return;
        }
        
        k = k % n;
        reverse(nums, nums + n );
        reverse(nums, nums + k);
        reverse(nums + k, nums + n );
    }
};