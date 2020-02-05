/* https://leetcode.com/problems/minimum-increment-to-make-array-unique/ */

/* Approach 1:
Intuition: 從最小的數字開始掃描，比如 [1 1 2 2 3 7]，當遇到 A[0]=1 時代表下一個數字至少要 2，
           所以 A[1]=1 需要加到 2 ，A[2]=2 需要加到 3，以此類推。
           像這樣排序之後從小的開始往上加，和直接挑重複的數字加，累積的 count 會是一樣的。           
           Algorithm:
           先排序，然後設定 need = 0，遍歷 A 的元素 a:
           如果 a 小於當前所需的大小 need，代表 a 需要增加到 need 的值，++need，count += need - a
           如果 a 等於當前所需的大小 need，代表 a 是可以不用增加的，++need
           如果 a 大於當前所需的大小 need，代表 a 是可以不用增加的，need = a + 1

Time complexity: O(nlogn)
Space complexity: O(1)
*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& A)
    {
        sort(A.begin(), A.end());
        
        int count = 0;
        int need = 0;
        
        for(auto a : A)
        {
            if(a < need)
            {
                count += need - a;
                ++need;
            }
            else if(a == need)
            {
                ++need;
            }
            else if(a > need)
            {
                need = a + 1;
            }
        }
        
        return count;
    }
};

/* Approach 2: 不排序的作法
Intuition: 先掃過一遍，找出所有重複的數字，
           再找出"還沒被用過的數字"，將重複的數字加到這個"還沒被用過的數字"，計算 count。
           實際做法會先將這些重複的數字 a 扣到 0，count -= a
           當找到"還沒被用過的數字" val 時再加到該數字 count += val
           注意:雖然題目說 0 <= A[i] < 40000，但有可能全都是 39999 的情況，
                所以 array 大小最好是 2 倍的 40000。

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& A)
    {
        vector<int> freq(80000, 0);
        
        for(auto a : A)
        {
            ++freq[a];
        }
        
        int dup = 0;
        int count = 0;
        
        for(int i = 0; i < 80000; ++i)
        {
            if(freq[i] > 1)
            {
                dup += freq[i] - 1;
                count -= i * (freq[i] - 1);
            }
            else if(dup > 0 && freq[i] == 0)
            {
                --dup;
                count += i;
            }
        }
        
        return count;
    }
};
