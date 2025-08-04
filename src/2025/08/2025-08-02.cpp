#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freqMap1;
        map<int, int> freqMap2;
        int cheapest = basket1[0];
        for (int i = 0; i < basket1.size(); i++) {
            if (cheapest > basket1[i])
                cheapest = basket1[i];
            if (cheapest > basket2[i])
                cheapest = basket2[i];
            if (freqMap1.find(basket1[i]) == freqMap1.end()) {
                freqMap1[basket1[i]] = 1;
                freqMap2[basket1[i]] = 0;
            }
            else
                freqMap1[basket1[i]]++;
            if (freqMap2.find(basket2[i]) == freqMap2.end()) {
                freqMap1[basket2[i]] = 0;
                freqMap2[basket2[i]] = 1;
            }
            else
                freqMap2[basket2[i]]++;
        }
        vector<pair<int, int>> ex1;
        vector<pair<int, int>> ex2;
        for (auto itr = freqMap1.begin(); itr != freqMap1.end(); itr++) {
            int key = itr->first;
            int ex = freqMap1[key] - freqMap2[key];
            if (ex % 2 != 0)
                return -1;
            if (ex > 0)
                ex1.push_back({key, ex/2});
            if (ex < 0)
                ex2.push_back({key, -ex/2});
        }
        sort(ex1.begin(), ex1.end(), [](auto &left, auto &right) {
            return left.first < right.first;
        });
        sort(ex2.begin(), ex2.end(), [](auto &left, auto &right) {
            return left.first > right.first;
        });
        long long count = 0;
        auto itr2 = ex2.begin();
        for (auto itr1 = ex1.begin(); itr1 != ex1.end(); itr1++) {
            while (itr1->second != 0) {
                if (itr1->second < itr2->second) {
                    if (min(itr1->first, itr2->first) <= cheapest * 2)
                        count += (long long)min(itr1->first, itr2->first) * (long long)itr1->second;
                    else 
                        count += cheapest * 2 * itr1->second;
                    itr2->second -= itr1->second;
                    itr1->second = 0;

                }
                if (itr1->second >= itr2->second) {
                    if (min(itr1->first, itr2->first) <= cheapest * 2)
                        count += (long long)min(itr1->first, itr2->first) * (long long)itr2->second;
                    else 
                        count += cheapest * 2 * itr2->second;
                    itr1->second -= itr2->second;
                    itr2->second = 0;
                    itr2++;
                }

            }
        }
        return count;
    }
};

int main() {
    cout << "hi" << endl;

    Solution sol;
    vector<int> a = {84,80,43,8,80,88,43,14,100,88};
    vector<int> b = {32,32,42,68,68,100,42,84,14,8};
    cout << sol.minCost(a, b);

    return 0;
}