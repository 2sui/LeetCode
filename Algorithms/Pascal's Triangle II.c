/*
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 */

/****************************************************************************************/

int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int *res = (int*) malloc(sizeof(int) * (*returnSize));
    
    res[0] = 1;
    for (int i = 1 ; i <= rowIndex; i++) {
        res[i] = 0;
        
        for (int j = i; j > 0; j--) {
            res[j] = res[j] + res[j - 1];
        }
    }
    
    return res;
}