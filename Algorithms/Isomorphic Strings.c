/*
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 *
 * Given "foo", "bar", return false.
 *
 * Given "paper", "title", return true.
 *
 * Note:
 * You may assume both s and t have the same length.
 */

/****************************************************************************************/

bool isIsomorphic(char* s, char* t) {
    int posS[256] = {0}, posT[256] = {0}, len = strlen(s);
    
    for (int i = 0; i < len; i++)
    {
        //  if the last pos is same
        if (posS[s[i]] != posT[t[i]])
        {
            return false;
        }
        
        // renew last pos
        posS[s[i]] = i + 1;
        posT[t[i]] = i + 1;
    }
    
    return true;
}