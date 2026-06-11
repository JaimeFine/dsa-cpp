/*
18. 4Sum
Solved in 44'14''
Medium

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> output;
        if (nums.size() < 4) return output;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left1 = i + 1, left2 = i + 2, right = nums.size() - 1;
            while (left1 < left2 && left2 < right) {
                long long sum = (long long)nums[i] + nums[left1] +
                    nums[left2] + nums[right];
                if (sum == target) {
                    output.push_back(
                        {nums[i], nums[left1], nums[left2], nums[right]}
                    );
                    while (left2 < right && nums[left2] == nums[left2 + 1])
                        left2++;
                    while (left2 < right && nums[right] == nums[right - 1])
                        right--;
                    left2++;
                    right--;
                    if (left2 >= right) {
                        left1++;
                        while (
                            left1 < nums.size() - 2 &&
                            nums[left1] == nums[left1 - 1]
                        )
                            left1++;
                        left2 = left1 + 1;
                        right = nums.size() - 1;
                    }
                } else if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left2++;
                }
                if (left2 >= right) {
                    left1++;
                    while (
                        left1 < (int)nums.size() - 2 &&
                        nums[left1] == nums[left1 - 1]
                    ) {
                        left1++;
                    }
                    left2 = left1 + 1;
                    right = (int)nums.size() - 1;
                }
            }
        }
        return output;  
    }
};

// AI's standard answer:
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> output;
        int n = nums.size();
        
        // 1. Guard rail for small arrays
        if (n < 4) return output;
        
        sort(nums.begin(), nums.end());
        
        // First Loop: Fixes the 1st number
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for the 1st number
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Second Loop: Fixes the 2nd number
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for the 2nd number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                // Classic Two-Pointer Setup for the remaining 3rd and 4th numbers
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        output.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for the 3rd and 4th numbers on the fly
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } 
                    else if (sum < target) {
                        left++;
                    } 
                    else {
                        right--;
                    }
                }
            }
        }
        return output;
    }
};