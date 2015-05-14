/*
 * Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 *
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
*/

/****************************************************************************************/

int hammingWeight(uint32_t n) {
    int count = 0;
    for (u_int32_t i = 0; i < 32; i++)
    {
        if (n & (1 << i))
        {
            count++;
        }
    }
    
    return count;
}