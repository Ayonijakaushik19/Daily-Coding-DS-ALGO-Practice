/*
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 
Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case)
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if( n==0) return "";
        int size=0,left,right,start=-1;
        for(int i=0; i<=2*n-1; i++){
            left = i/2;
            right = i/2 + i%2;
            while( left>=0 && right<n && s[left] == s[right]){
                if( size < ( right - left +1)){
                    size = ( right - left +1);
                    start = left;
                }
                left--; right++;
            }            
        }
        return s.substr(start,size);
    }
};
