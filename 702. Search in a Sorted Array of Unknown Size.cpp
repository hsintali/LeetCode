/* https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/ */

/* Approach 1: binary search
Intuition:先使用倍增法找出 target 所在區間，再用 binary search

Time complexity: O(log k), where k is the index of target
Space complexity: O(1)
*/

// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target)
    {
        // search interval
        int start = 0;
        int end = 1;
        
        while(reader.get(end) < target)
        {
            start = end;
            end <<= 1;
        }
        
        // binary search        
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            
            int val = reader.get(mid);
            if(val == target)
            {
                return mid;
            }
            else if(val < target)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }   
        }
        
        if(reader.get(start) == target) return start;
        else if(reader.get(end) == target) return end;
        else return -1;    
    }
};
