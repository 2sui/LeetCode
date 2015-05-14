/*
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
 *
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
*/

/****************************************************************************************/

int trailingZeroes(int n) {
    int trails = 0, base = 1;
    
    for (; base <= n / 5;)
    {
        base = base * 5;
        trails += n / base;
    }
    
    return trails;
}