/*
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 * [
 *     [2],
 *    [3,4],
 *   [6,5,7],
 *  [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 */

/****************************************************************************************/

int minimumTotal(int **triangle, int numRows) {
    if (numRows < 1) return 0;
    if (numRows < 2) return triangle[0][0];
    int *lastRow = triangle[numRows - 1], tmp;
    
    for (int i = numRows - 2; i > -1; i--) {
        for (int j = 0; j <= i; j++) {
            tmp = (lastRow[j] < lastRow[j + 1]) ? lastRow[j] : lastRow[j + 1];
            lastRow[j] = triangle[i][j] + tmp; // update last-row. It is  i row that  do with last-row, so the last-row seems like i + 1 row, and the triangle only has i + 1 rows totality.
        }
    }
    
    return lastRow[0];
    
}