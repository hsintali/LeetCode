/* https://leetcode.com/problems/count-primes/ */

/* Approach 1: Naive
Intuition:

Time complexity: O( sqrt(n) )
Space complexity: O(1)
*/

class Solution {
public:
    int countPrimes(int n)
    {
        int count = 0;
        
        for(int i = 1; i < n; ++i)
        {
            if(isPrime(i)) ++count;
        }
        
        return count;
    }
    
    bool isPrime(int n)
    {
        if(n <= 1) return false;
        
        for(int i = 2; i * i <= n; ++i)
        {
            if(n % i == 0) return false;
        }
        
        return true;
    }
};

/* Approach 2: hashMap (Sieve of Eratosthenes)
Intuition:

Time complexity: O( n * log(log(n)) )
Space complexity: O(n)
*/

class Solution {
public:
    int countPrimes(int n)
    {
        int count = 0;
        vector<bool> isPrime(n, true);
        
        for(int i = 2; i * i < n; ++i)
        {
            if(isPrime[i] == false) continue;
            
            for(int j = i * i; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
        
        for(int i = 2; i < n; ++i)
        {
            if(isPrime[i]) ++count;
        }
        
        return count;
    }
};
