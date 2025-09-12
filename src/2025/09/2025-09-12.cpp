class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels = "aeiou";
        for (char c : vowels)
            if (s.find(c) != string::npos)
                return true;
        return false;
    }
};
