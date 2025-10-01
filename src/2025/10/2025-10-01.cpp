class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = numBottles;
        count += (numBottles - 1) / (numExchange - 1);
        return count;

    }
};
