/*
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
*/

/****************************************************************************************/

int reverse(int x) {
    if ((10 >  x) && (x > -10))
    {
        return x;
    }
    
    long y = 0, res = 0, xX = x;
    bool   obs = false;
    
    if (xX < 0)
    {
        obs = true;
        xX = xX * (-1);
    }
    
    for (; xX > 0;)
    {
        res = xX % 10 + 10 * res;
        if (res > 0x7fffffff)  return 0;
        xX = xX / 10;
    }
    
    return obs ? res * (-1): res;
}