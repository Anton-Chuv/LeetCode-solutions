#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        long long totalAltSum = 0;
        set<pair<int, int>> moves;
        for (auto x: swaps) {
            if (x[0] < x[1])
                moves.insert({x[0],x[1]});
            else
                moves.insert({x[1],x[0]});
        }
        for (int i = 0; i < nums.size(); i++) {
            int bestMove = i;
            int bestDif = 0;
            vector<int> possibleMoves = {i};
            for (auto p: moves) {
                if (p.first == nums[i])
                    possibleMoves.push_back(p.second);
            }
            for (int n: possibleMoves) {
                int dif = 0;
                if ((i - n) % 2 == 0) continue;
                if (i % 2 == 0) {
                    dif = nums[n] - nums[i];
                }
                else {
                    dif = nums[i] - nums[n];
                }
                if ()
                // здесь нужно с рекурсией рассматреть цепочечные замены, т.к. эта цепь может быть любой длины, а время на контест закончилось TODO сделать позже
            }

        }
    }
};
