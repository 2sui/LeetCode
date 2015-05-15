/*
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 *
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/

/****************************************************************************************/

int myAtoi(char* str) {
    long res = 0;
    int len = strlen(str);
    int pos = 0;
    bool  minus = false;
    
    for (pos = 0; pos < len; pos++)
    {
        if (str[pos] != ' ') break;
    }
    
    if (str[pos] == '-' || str[pos] == '+')
    {
        minus = str[pos] == '-' ? true : false;
        pos++;
    }
    
    
    for (; pos < len; pos++)
    {
        if (48 <= str[pos] && 57 >= str[pos])
        {
            res = res * 10 + str[pos] - 48;
            if (res > 2147483648)
            {
                res = 2147483648;
                break;
            }
        }
        else
        {
            break;
        }
    }
    
    res = minus ? res * (-1) :  res;
    
    if (res > 2147483647) res = 2147483647;
    
    return res;
}