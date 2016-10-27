class ValidWordAbbr {
private:
	set<string> dict;
	unordered_map<string, int> myMap;
public:
    ValidWordAbbr(vector<string> &dictionary) {
		for(string s : dictionary) {
			dict.insert(s);
			string abbrWord;
			string firstLetter(1, s[0]);
			string lastLetter(1, s[s.size() - 1]);
			if(s.size() == 1) {
				abbrWord = firstLetter;
			}
			else {	
				if(s.size() > 2) {
					abbrWord = firstLetter + to_string(s.size() - 2) + lastLetter;
				}
				else {
					abbrWord = firstLetter  + lastLetter;
				}
				if(myMap.find(abbrWord) == myMap.end()) {
					myMap.emplace(abbrWord, 1);
				}
				else {
					myMap[abbrWord]++;
				}
			}		
		}
    }

    bool isUnique(string word) {
        string abbrWord;
		string firstLetter(1, word[0]);
		string lastLetter(1, word[word.size() -1]);
		if(word.size() == 1) {
			abbrWord = firstLetter;
		}
		else if(word.size() > 2) {
			abbrWord = firstLetter + to_string(word.size() - 2) + lastLetter;
		}
		else {
			abbrWord = firstLetter + lastLetter;
		}

		if(myMap.find(abbrWord) == myMap.end()) {
			return true;
		}
		else if(myMap[abbrWord] == 1) {
			if(dict.find(word) != dict.end()) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
