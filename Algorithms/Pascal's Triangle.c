/*
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */

/****************************************************************************************/

int** generate(int numRows, int** columnSizes, int* returnSize) {
    if (numRows < 1 || !columnSizes || !returnSize) {
        return NULL;
    }
    
    *returnSize = 0;
    for (int i = 0; i < numRows; i++) {
        (*returnSize)++;
    }
    
    int **res = (int**) malloc(sizeof(int*) * numRows);
    *columnSizes = (int*) malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; i++) {
        (*columnSizes)[i] = i + 1;
        res[i] = (int*) malloc(sizeof(int) * (*columnSizes)[i]);
    }
    
    res[0][0] = 1;
    if (numRows > 1) {
        res[1][0] = res[1][1] = 1;
    }
    
    if (numRows > 2) {
        
        for (int i = 2; i < numRows; i++) {
            res[i][0] = res[i][i] = 1;
            for (int j = i - 1; j > 0; j--) {
                res[i][j] = res[i - 1][j] +res[i - 1][j - 1];
            }
        }
    }
    
    return res;
    
}