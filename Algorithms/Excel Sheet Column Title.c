/*
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 * For example:
 *
 * 1 -> A
 * 2 -> B
 * 3 -> C
 * ...
 * 26 -> Z
 * 27 -> AA
 * 28 -> AB
 * Credits:
 * Special thanks to @ifanchu for adding this problem and creating all test cases.
 */

/****************************************************************************************/

void revers(char *str, int n)
{
    char tmp;
    for (int i = 0; i < (n / 2); i++)
    {
        tmp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = tmp;
    }
}

char* convertToTitle(int n) {
    int size = 1;
    int bg = n;
    int count = 0;
    
    for (;0 < (bg = bg / 26);)
    {
        size++;
    }
    
    char   *str = malloc(size * sizeof(char));
    memset(str, 0, size * sizeof(char));
    
    for (int i = 0; n > 0; i++)
    {
        bg = n % 26;
        n = n / 26;
        if (bg)
        {
            str[i] = bg + 'A' - 1;
        }
        else
        {
            str[i] = 'Z';
            n--;
        }
        
        count++;
    }
    
    revers(str, count);
    return str;
}