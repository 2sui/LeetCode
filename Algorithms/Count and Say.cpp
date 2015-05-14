/*
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 */

/****************************************************************************************/

/*
 *  This answer will lead to overflow with type long.
 *
 
char* countAndSay(int n) {
 unsigned long long nN;
 unsigned long long base;
 long long tgt, lastgt, count;
 unsigned long long res = 1;
 
 for (; n > 1; n--)
 {
 nN = res;
 base = 1;
 count = 1;
 lastgt = -1;
 
 
 for (; res;)
 {
 if (res = res / 10)
 {
 base *= 10;
 }
 }
 
 res = 0;
 
 while (nN)
 {
 tgt = nN / base;
 
 if (lastgt == tgt)
 {
 count++;
 }
 else
 {
 if (lastgt != -1)
 {
 res = res * 10 + count;
 res = res * 10 + lastgt;
 }
 
 lastgt = tgt;
 count = 1;
 }
 
 nN = nN - tgt * base;
 base /= 10;
 }
 
 res = res * 10 + count;
 res = res * 10 + tgt;
 }
 
 for (nN = res, base = 1; nN;)
 {
 if (nN = nN / 10)
 {
 base++;
 }
 }
 
 *//* this may lead to memory leak. *//*
 char *str = (char*)malloc(base + 1);
 sprintf(str, "%d", res);
 return str;
}
*/

/* so there is a better way to fix that. */
string countAndSay(int n)
{
    if (n < 2)
    {
        return n == 1? "1" : " ";
    }
    
    std::string res = "1";
    std::string tmp;
    int             count;
    char          mod;
    
    for (; n > 1; n--)
    {
        tmp.clear();
        count = 1;
        mod = res[0];
        
        for (int i = 1; i < res.size(); i++)
        {
            if (mod == res[i])
            {
                count++;
            }
            else
            {
                tmp.push_back('0' + count);
                tmp.push_back(mod);
                count = 1;
                mod = res[i];
            }
        }
        
        tmp.push_back('0' + count);
        tmp.push_back(mod);
        res = tmp;
    }
    
    return res;
}