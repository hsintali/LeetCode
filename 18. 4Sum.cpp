/* https://leetcode.com/problems/4sum/ */

/* Approach 1: Two pointer + 1 pointer (3sum)
Intuition: 透過 3sum 作為 subroutine，外加一層 for loop 遍歷第四個數。
           
Time complexity: O(n^3)
Space complexity: O(1)
*/

/* Approach 2: Two pointer (2sum)
Intuition: 透過 2sum 作為 subroutine，分別使用 2sum 找出 (a, b) 並存下來，然後找出 (c, d) 使得 (a + b) = target - (c + d)。
           
Time complexity: O(n^2)
Space complexity: O(n)
*/
