/*
 * Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
 */

/****************************************************************************************/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> mp;
        for (int i = 0; i < nums.size(); i++) {
            auto it = mp.lower_bound((long)nums[i] - (long)t);
            if (it != mp.end() && *it <= (long)nums[i] + (long)t) {
                return true;
            }
            
            mp.insert((long)nums[i]);
            
            // make sure that the element in set will not deleted when nums[i - k] is same with nums[m] (m > i - k and m <i).
            if (i >= k) {
                mp.erase((long)nums[i - k]);
            }
        }
        
        return false;
    }
    
};