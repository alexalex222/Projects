#include<list>
#include<map>
using namespace std;

struct cacheNode {
	int key;
	int val;
	cacheNode(int k, int v) {
		key = k;
		val = v;
	}
};
class LRUCache{
private:
	unordered_map<int, list<cacheNode>::iterator> myMap;
	list<cacheNode> cacheList;
	int capacity;
public:
    LRUCache(int capacity) {
		this->capacity = capacity;
    }
    
    int get(int key) {
		if(myMap.find(key) != myMap.end()) {
			cacheList.splice(cacheList.begin(), cacheList, myMap[key]);
			myMap[key] = cacheList.begin();
			return myMap[key]->val;
		}
		else {
			return -1;
		}
    }
    
    void set(int key, int value) {
		if(myMap.find(key) == myMap.end()) {
			if(static_cast<int>(myMap.size()) == capacity) {
				myMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			cacheList.push_front(cacheNode(key, value));
			myMap.emplace(key, cacheList.begin());
		}
		else {
			cacheList.splice(cacheList.begin(), cacheList, myMap[key]);
			myMap[key] = cacheList.begin();
			myMap[key]->val = value;
		}
    }
};
