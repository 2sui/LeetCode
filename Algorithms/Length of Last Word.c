/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example,
 * Given s = "Hello World",
 * return 5.
 */

/****************************************************************************************/

int lengthOfLastWord(char* s) {
    int len = strlen(s), beg = -1, end = 0, i = 0;
    if (len < 1) return 0;
    for (i = len - 1; i > -1; i--) {
        if (s[i] != ' ') break;
    }
    
    if (i < 0) return 0;
    end = i;
    for (; i > -1; i--) {
        if (s[i] < 65) {
            beg = i;
            break;
        }
    }
    
    return end - beg;
}
}