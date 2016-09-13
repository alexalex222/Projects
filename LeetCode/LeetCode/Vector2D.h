#include<vector>
using namespace std;
class Vector2D {
private:
	vector<vector<int>>::iterator x;
	vector<int>::iterator y;
	vector<vector<int>> myVec;
public:
    Vector2D(vector<vector<int>>& vec2d) {
		myVec = vec2d;
		x = myVec.begin();
		if(x != myVec.end()) {
			while(x->size() < 1 && x != myVec.end()-1) {
				x++;
			}
		}
		
		if(x != myVec.end()) y = x->begin();
			
    }

    int next() {
		int result;
		result = *y;
		y++;
		return result;
		
    }

    bool hasNext() {
		while(x != myVec.end()) {
			while(x->size() < 1 && x != myVec.end()-1) {
				x++;
			}
			if(y == x->end() && x == myVec.end() -1) {
				return false;
			}			
			else {
				if(y == x->end()) {
					x++;
					while(x->size() < 1 && x != myVec.end()) {
						x++;
					} 
						
					if(x != myVec.end()) {
						y = x->begin();
						return true;
					}
				}
				else return true;
			}	
		}
		return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
