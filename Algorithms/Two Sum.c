/*
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
*/

/****************************************************************************************/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct  node {
    int key;
    int val;
    bool use;
}hashnode;

typedef struct  map {
    int       size;
    hashnode* map;
}hashmap;

int hashmap_create(hashmap* hashmp,int size) {
    hashmp->map = (hashnode*) malloc(sizeof(hashnode) * size * 2);
    if (NULL == hashmp->map) {
        return -1;
    }
    
    hashmp->size = 2 * size;
    memset(hashmp->map, 0, sizeof(hashnode) * hashmp->size);
    return 0;
}

void hashmap_destory(hashmap* hashmp) {
    
    if (NULL != hashmp->map) {
        free(hashmp->map);
    }
    
    return;
}

int hashmap_set(int key, int val, hashmap* hashmp) {
    int hash = key % hashmp->size;
    if (0 > hash) {
        hash = 0;
    }
    
    while (hashmp->map[hash].use) {
        
        if (++hash >= hashmp->size) {
            hash = 0;
        }
    }
    
    hashmp->map[hash].use = true;
    hashmp->map[hash].key = key;
    hashmp->map[hash].val = val;
    
    return 0;
}

int hashmap_get(int key, hashmap* hashmp) {
    int hash = key % hashmp->size;
    if (0 > hash) {
        hash = 0;
    }
    
    while (hashmp->map[hash].use) {
        
        if (hashmp->map[hash].key == key) {
            return hashmp->map[hash].val;
        }
        
        if (++hash >= hashmp->size) {
            hash = 0;
        }
    }
    
    return -1;
}

int* twoSum(int* nums, int numsSize, int target) {
    int* rets = (int*)malloc(2 * sizeof(int));
    int res;
    
    hashmap hash;
    if (-1 == hashmap_create(&hash, numsSize)) {
        return NULL;
    }
    
    for (rets[1] = 0; rets[1] < numsSize; rets[1]++) {
        
        res = target - nums[rets[1]];
        rets[0] = hashmap_get(res, &hash);
        if (-1 == rets[0]) {
            hashmap_set(nums[rets[1]], rets[1], &hash);
        } else {
            hashmap_destory(&hash);
            rets[1]++;
            rets[0]++;
            return rets;
        }
    }
}