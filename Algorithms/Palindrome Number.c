/*
* Determine whether an integer is a palindrome. Do this without extra space.
*/

/****************************************************************************************/

bool isPalindrome(int x) {
    if (0 > x) return false;
    if (0 == x) return true;
    
    int base = 1;
    int left = 0;
    int right = 0;
    
    while(x / base > 9)
    {
        base *= 10;
    }
    
    for (;x;)
    {
        left = x / base;
        right = x % 10;
        
        if (left != right) return false;
        
        x -= left * base;
        x /= 10;
        base /= 100;
    }
    
    return true;
}