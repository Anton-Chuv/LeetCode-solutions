#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> output;
        set<string> wordSet(wordlist.begin(), wordlist.end());
        map<string, int> lowerWordMap;
        map<string, int> vowelWordMap;

        for (int i = 0; i < wordlist.size(); i++) {
            string lower = wordlist[i];
            transform(lower.begin(), lower.end(), lower.begin(),  [](unsigned char c){ return std::tolower(c); });
            string vowel = lower;
            replace(vowel.begin(), vowel.end(), 'a', '0');
            replace(vowel.begin(), vowel.end(), 'e', '0');
            replace(vowel.begin(), vowel.end(), 'i', '0');
            replace(vowel.begin(), vowel.end(), 'o', '0');
            replace(vowel.begin(), vowel.end(), 'u', '0');
            if (lowerWordMap.find(lower) == lowerWordMap.end()) {
                lowerWordMap[lower] = i;
            }
            if (vowelWordMap.find(vowel) == vowelWordMap.end()) {
                vowelWordMap[vowel] = i;
            }
        }

        for (const string& query : queries) {
            if (wordSet.find(query) != wordSet.end()) {
                output.push_back(query);
            } else {
                string lowerQuery = query;
                transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(),  [](unsigned char c){ return std::tolower(c); });
                if (lowerWordMap.find(lowerQuery) != lowerWordMap.end()) {
                    output.push_back(wordlist[lowerWordMap[lowerQuery]]);
                } else {
                    string vowelQuery = lowerQuery;
                    replace(vowelQuery.begin(), vowelQuery.end(), 'a', '0');
                    replace(vowelQuery.begin(), vowelQuery.end(), 'e', '0');
                    replace(vowelQuery.begin(), vowelQuery.end(), 'i', '0');
                    replace(vowelQuery.begin(), vowelQuery.end(), 'o', '0');
                    replace(vowelQuery.begin(), vowelQuery.end(), 'u', '0');
                    if (vowelWordMap.find(vowelQuery) != vowelWordMap.end()) {
                        output.push_back(wordlist[vowelWordMap[vowelQuery]]);
                    } else {
                        output.push_back("");
                    }
                }
            }
        }

        return output;
    }
};

int main() {
    Solution solution;
    vector<string> wordlist = {"j","kite","hare","Hare"};
    vector<string> queries = {"J","keet","keto"};
    vector<string> output = solution.spellchecker(wordlist, queries);
    for (const string& word : output) {
        cout << word << endl;
    }
    return 0;
}
