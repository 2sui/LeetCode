/*
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 *
 * Here is an example of version numbers ordering:
 *
 * 0.1 < 1.1 < 1.2 < 13.37
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 */

/****************************************************************************************/

int compareVersion(char* version1, char* version2) {
    int v1Len = strlen(version1);
    int v2Len = strlen(version2);
    int v1 = 0;
    int v2 = 0;
    int num1 = 0;
    int num2 = 0;
    
    while ((v1 < v1Len) || (v2 < v2Len))
    {
        while (('.' != version1[v1]) && (v1 < v1Len))
        {
            num1 = num1 * 10 + version1[v1] - '0';
            v1++;
        }
        while ('.' != version2[v2] && (v2 < v2Len))
        {
            num2 = num2 * 10 + version2[v2] - '0';
            v2++;
        }
        
        if (num1 > num2)
        {
            return 1;
        }
        else
        {
            if (num1 < num2)
            {
                return -1;
            }
        }
        
        num1 = num2 = 0;
        v1++;
        v2++;
    }
    return 0;
}
