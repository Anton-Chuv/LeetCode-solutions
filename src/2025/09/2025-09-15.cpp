#include <string>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    int canBeTypedWords(string input, string broke) {
        int count = 0;
        set<char> brokeChar;
        for (char c: broke) brokeChar.insert(c);
        bool flagBadWord = false;
        for (char c: input) {
            if (flagBadWord) {
                if (c == ' ') flagBadWord = false;
                continue;
            }
            if (brokeChar.find(c) != brokeChar.end()) {
                flagBadWord = true;
                continue;
            }
            if (c == ' ') count++;
        }
        if (!flagBadWord) count++;
        return count;
    }
};

int main() {
    cout << Solution().canBeTypedWords("hello world", "ad") << endl;
}
