/*
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 *
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 */

/****************************************************************************************/

class LRUCache{
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        
        if (Mp.find(key) != Mp.end()) {
            int value = Mp[key]->value;
            Lt.erase(Mp[key]);
            Lt.push_front({key, value});
            Mp[key] = Lt.begin();
            return value;
            
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        
        if  (Mp.find(key) == Mp.end()) {
            
            if (Mp.size() >= cap) {
                int lkey = Lt.back().key;
                Lt.pop_back();
                Mp.erase(lkey);
            }
            
            Lt.push_front({key, value});
            Mp[key] = Lt.begin();
            
        } else {
            Lt.erase(Mp[key]);
            Lt.push_front({key, value});
            Mp[key] = Lt.begin();
        }
    }
    
private:
    struct  Pair {
        int key;
        int value;
    };
    std::list<struct Pair>   Lt;
    std::unordered_map<int, std::list<struct Pair>::iterator>  Mp;
    int  cap;
};