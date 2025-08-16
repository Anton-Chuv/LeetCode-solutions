#include <stdlib.h>
int compareIntegers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
long long perfectPairs(int* nums, int numsSize) {
    long long ans = 0;
    for (int i = 0; i < numsSize; i++)
        nums[i] = abs(nums[i]);
    qsort(nums, numsSize, sizeof(int), compareIntegers);
    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        while (j < numsSize && nums[i] * 2 >= nums[j]) j++;
        ans += j - i - 1;
    }
    return ans;
}
