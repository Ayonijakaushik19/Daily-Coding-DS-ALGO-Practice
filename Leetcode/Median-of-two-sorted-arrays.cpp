/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 
Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        int n=nums1.size(),m=nums2.size();
        int lo=0,hi=n;
        while(lo<=hi){
            int px=lo+(hi-lo)/2;
            int py=(n+m+1)/2-px;
            
            double mxlx=(px==0?INT_MIN:nums1[px-1]);
            double mnlx=(px==n?INT_MAX:nums1[px]);
            
            double mxry=(py==0?INT_MIN:nums2[py-1]);
            double mnry=(py==m?INT_MAX:nums2[py]);
            
            if(mxlx<=mnry and mxry<=mnlx){
                if((n+m)%2==0)
                    return (max(mxlx,mxry)+min(mnlx,mnry))/2.0;
                else
                    return max(mxlx,mxry);
            }
            if(mxlx>mnry)
                hi=px-1;
            else
                lo=px+1;
        }
        return -1;
    }
};
