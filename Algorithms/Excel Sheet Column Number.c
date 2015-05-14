/*
 * Related to question Excel Sheet Column Title
 *
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 *
 * For example:
 *
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
*/

/****************************************************************************************/

// int titleToNumber(char* s) {
//     int len = strlen(s);
//     int base = 'A' - 1;
//     int tenth = 1;
//     int cur = 0;
//     int totol = 0;

//     for (int i = 0; i < len; i++)
//     {
//         cur = s[len - 1 - i] - base;

//         if (i > 0)
//         {
//             tenth *= 26;
//             totol += tenth * cur;
//         }
//         else
//         {
//             totol += cur;
//         }
//     }

//     return totol;

// }

int titleToNumber(char* s) {
    int totol = 0;
    int len = strlen(s);
    
    for (int i = 0; i < len; i++)
    {
        totol = totol * 26 + s[i] - 'A' + 1;
    }
    
    return totol;
}