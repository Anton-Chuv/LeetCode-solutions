class Solution {
public:
    string sortVowels(string s) {
        string vowels = "AEIOUaeiou";
        string filteredVowels = "";
        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                filteredVowels += c;
            }
        }
        sort(filteredVowels.begin(), filteredVowels.end());
        string result = s;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (vowels.find(s[i]) != string::npos) {
                result[i] = filteredVowels[j++];
            }
        }
        return result;
    }
};
