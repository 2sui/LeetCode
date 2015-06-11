/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

/****************************************************************************************/

int climbStairs(int n) {
    if (n < 3) return n;
    int last_one = 2, last_two = 1, res;
    
    for (int i = 0 ; i < n - 2; i++) {
        res = last_one + last_two; // number of odd number situation and even number situation
        last_two = last_one;
        last_one = res;
    }
    
    return res;
    
}