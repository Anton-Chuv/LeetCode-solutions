#include <iostream>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int max = 0;
        int count = 0;
        vector<int> basketsType = {fruits[0], -1};
        vector<int>::iterator lastTree; // last seen tree with fruit from second basket;
        auto iter = fruits.begin();
        // find first tree with 3 type (if there is more then 2 type tree)
        while (iter != fruits.end() && (find(basketsType.begin(), basketsType.end(), *iter) != basketsType.end() || find(basketsType.begin(), basketsType.end(), -1) != basketsType.end())) {
            if (*iter != basketsType[0]) {
                basketsType[1] = basketsType[0];
                lastTree = iter;
            }
            basketsType[0] = *iter;
            count++;
            iter++;
        }
        // if there 1 or 2 type of tree return len of row
        if (iter == fruits.end())
            return count;

        while (iter != fruits.end()) {
            if (find(basketsType.begin(), basketsType.end(), *iter) == basketsType.end()) {
                if (count > max)
                    max = count;
                count = iter - lastTree;
            }
            if (*iter != basketsType[0]) {
                basketsType[1] = basketsType[0];
                lastTree = iter;
            }
            basketsType[0] = *iter;
            count++;
            iter++;
        }
        if (count > max)
            max = count;
        return max;
    }
};

int main() {
    cout << "hi" << endl;

    Solution sol;

    vector<int> v = {0};

    cout << sol.totalFruit(v);

    return 0;
}