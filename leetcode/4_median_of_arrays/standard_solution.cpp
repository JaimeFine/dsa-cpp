#include <vector>
#include <algorithm>
#include <climits> // For INT_MIN and INT_MAX

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is the smaller array to minimize the search range (O(log(min(m, n))))
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        
        // k is the combined length of the left half for the merged array
        // (+1 to handle both odd and even total lengths correctly)
        int half_len = (m + n + 1) / 2;

        int low = 0;
        int high = m; // Search range for partition index 'i' in nums1 [0, m]

        while (low <= high) {
            // i is the partition index for nums1 (number of elements in the left part of nums1)
            int i = low + (high - low) / 2; 
            
            // j is derived from i, based on the required total left length (half_len)
            int j = half_len - i;

            // Define the four boundary elements using sentinels (INT_MIN/INT_MAX)
            // LeftX: Max element on the left side of nums1's partition
            int leftX = (i == 0) ? INT_MIN : nums1[i - 1];
            
            // RightX: Min element on the right side of nums1's partition
            int rightX = (i == m) ? INT_MAX : nums1[i];

            // LeftY: Max element on the left side of nums2's partition
            int leftY = (j == 0) ? INT_MIN : nums2[j - 1];
            
            // RightY: Min element on the right side of nums2's partition
            int rightY = (j == n) ? INT_MAX : nums2[j];

            // Check the Order Condition: Max of Left <= Min of Right
            if (leftX <= rightY && leftY <= rightX) {
                // Perfect Partition Found!
                
                // Case 1: Odd total number of elements
                if ((m + n) % 2 == 1) {
                    // The median is the largest element in the left half
                    return static_cast<double>(std::max(leftX, leftY));
                } 
                // Case 2: Even total number of elements
                else {
                    // Median is the average of (Largest Left + Smallest Right)
                    double left_max = static_cast<double>(std::max(leftX, leftY));
                    double right_min = static_cast<double>(std::min(rightX, rightY));
                    return (left_max + right_min) / 2.0;
                }
            } 
            // If the partition in nums1 is too far right (leftX is too large)
            else if (leftX > rightY) { 
                high = i - 1; // Move the partition point 'i' to the left
            } 
            // If the partition in nums1 is too far left (leftY is too large)
            else { // leftY > rightX
                low = i + 1; // Move the partition point 'i' to the right
            }
        }
        
        // This line should technically never be reached if the inputs are valid
        return 0.0; 
    }
};
