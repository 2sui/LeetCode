/*
* Write a function to find the longest common prefix string amongst an array of strings.
*/

/****************************************************************************************/

char* longestCommonPrefix(char** strs, int strsSize) {
    if (0 == strsSize) return "";
    if (1 == strsSize) return strs[0];
    
    int j, i;
    char *res = NULL;
    
    for (j = 0; strs[0][j] != 0;)
    {
        for (i = 0; i < strsSize; i++)
        {
            if ((strs[0][j] != strs[i][j]) || (0 == strs[i][j]))
            {
                goto SOMETHINGWRONG;
            }
        }
        
        j++;
    }
    
SOMETHINGWRONG:
    if (j == 0) return "";
    res = (char*)malloc(j + 1);
    memcpy(res, strs[0], j);
    res[j] = 0;
    return res;
}