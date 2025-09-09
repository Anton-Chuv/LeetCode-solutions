#include <vector>
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long count = 0;
        std::vector<long long> rememberPeople(delay);
        std::vector<long long> tellingPeople(forget - delay);
        rememberPeople[delay - 1] = 1;
        for (int i = 1; i < n; i++) {
            long long countOfDay = 0;
            tellingPeople.erase(tellingPeople.begin());
            tellingPeople.push_back(*rememberPeople.begin());
            rememberPeople.erase(rememberPeople.begin());
            for (long long tell: tellingPeople) {
                countOfDay += tell % 1000000007;
            }
            rememberPeople.push_back(countOfDay);
        }
        for (long long tell: tellingPeople)
            count += tell % 1000000007;
        for (long long remember: rememberPeople)
            count += remember % 1000000007;
        return count % 1000000007;
    }
};
