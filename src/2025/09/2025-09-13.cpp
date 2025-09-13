class Solution {
public:
    int maxFreqSum(string s) {
        string vowels = "aeiou";
        string consonants = "bcdfghjklmnpqrstvwxyz";
        vector<int> freqVowel(vowels.size(), 0);
        vector<int> freqConsonant(consonants.size(), 0);
        for (char c : s) {
            if (vowels.find(c) != string::npos)
                freqVowel[vowels.find(c)]++;
            else if (consonants.find(c) != string::npos)
                freqConsonant[consonants.find(c)]++;
        }
        int maxFreqVowel = *max_element(freqVowel.begin(), freqVowel.end());
        int maxFreqConsonant = *max_element(freqConsonant.begin(), freqConsonant.end());
        return maxFreqVowel + maxFreqConsonant;
    }
};
