#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        while (nums1.size() > 2 && nums2.size() > 2) {
            double med1, med2;

            med1 = (nums1.size() % 2 == 0)
                ? (static_cast<double>(nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1])) / 2 : nums1[nums1.size() / 2];
            med2 = (nums2.size() % 2 == 0) 
                ? (static_cast<double>(nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1])) / 2 : nums2[nums2.size() / 2];

            int m = std::min(nums1.size(), nums2.size());
            m = (m % 2 == 0) ? m / 2 - 1 : m / 2; 

            if (med1 < med2) {
                nums1.assign(nums1.begin() + m, nums1.end());
                nums2.resize(nums2.size() - m);
            } else {
                nums2.assign(nums2.begin() + m, nums2.end());
                nums1.resize(nums1.size() - m);
            }
        }

        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        std::sort(nums1.begin(), nums1.end());
        double med;

        med = (nums1.size() % 2 == 0)
            ? static_cast<double>(nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2
            : nums1[nums1.size() / 2];

        return med;
    }
};
