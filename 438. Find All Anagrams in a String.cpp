/* https://leetcode.com/problems/find-all-anagrams-in-a-string/ */

/* Approach 1: Hash: Brute Force
Intuition: 在 s 中掃描與 p 相同大小的所有子字串(O(n))，再判斷這個子字串是否與 p 為 anagram (O(m))

Time complexity: O(n*m), n=s.size(), m=p.size()
Space complexity: O(n+m) or O(1)
*/

/* Approach 2:
Intuition: 

Time complexity: O(n), n=s.size(), m=p.size()
Space complexity: O(n+m) or O(1)
*/
