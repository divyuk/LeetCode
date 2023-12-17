#include <vector>
#include <algorithm>
#include <climits>

class Solution {
private:
    std::vector<long long> preSum;

    void calcPresum(std::vector<int>& v) {
        int n = v.size();
        preSum.clear();
        preSum.resize(n, v[0]);
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + v[i];
        }
    }

    long long rangeSum(int i, int j) {
        if (i == 0) return preSum[j];
        return preSum[j] - preSum[i - 1];
    }

    long long getCost(std::vector<int>& v, long long st, long long en, long long mid) {
        long long costLeft = (v[mid] * (mid - st + 1)) - rangeSum(st, mid);
        long long costRight = rangeSum(mid, en) - (v[mid] * (en - mid + 1));
        return costLeft + costRight;
    }

    long long costEq(std::vector<int>& v, long long k) {
        long long n = v.size(), ptr1 = 0, ptr2 = k - 1, cost = LLONG_MAX;
        for (; ptr2 < n; ptr2++, ptr1++) {
            // Decide what is min cost in range ptr1 - ptr2
            // If odd elements, the median will give min cost
            if ((ptr2 - ptr1 + 1) % 2 == 1) {
                cost = std::min(cost, getCost(v, ptr1, ptr2, (ptr1 + ptr2) / 2));
            }
            // If even elements, check which median will give min cost
            else {
                cost = std::min({cost, getCost(v, ptr1, ptr2, (ptr1 + ptr2) / 2), getCost(v, ptr1, ptr2, (ptr1 + ptr2) / 2 + 1)});
            }
        }
        return cost;
    }

public:
    int maxFrequencyScore(std::vector<int>& nums, long long k) {
        int n = nums.size();
        long long ptr1 = 1, ptr2 = n;
        sort(nums.begin(), nums.end());
        while (ptr1 < ptr2) {
            long long mid = ptr1 + (ptr2 - ptr1 + 1) / 2;
            calcPresum(nums);

            if (costEq(nums, mid) <= k) {
                ptr1 = mid;
            } else {
                ptr2 = mid - 1;
            }
        }

        return static_cast<int>(ptr1);
    }
};
