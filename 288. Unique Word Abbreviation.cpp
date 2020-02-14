/* https://leetcode.com/problems/unique-word-abbreviation/ */

/* Approach 1: hashMap + hashSet
Intuition: 

Time complexity: pre-processing: O(n), for each isUnique: O(1); n is the number of words in the dictionary
Space complexity: O(n)
*/

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary)
    {
        for(auto s : dictionary)
        {
            // to prevent duplicate word
            if(dict.count(s) == 0)
            {
                ++abbrDict[toAbbr(s)];
            }
            
            dict.insert(s);
        }
    }
    
    bool isUnique(string word)
    {
        string abbr = toAbbr(word);
        
        // if word not in AbbrDict (also not in dict), it's unique
        bool wordNotInAbbrDict = abbrDict.count(abbr) == 0;
        
        // if word in dict and abbrDict[word] == 1, it's unique
        bool wordInDictUnique = dict.count(word) == 1 && abbrDict[abbr] == 1;

        if(wordNotInAbbrDict || wordInDictUnique)
        {
            return true;
        }
        
        return false;
    }
    
    string toAbbr(string s)
    {
        if(s.size() < 2) return s;
        
        return s[0] + to_string(s.size() - 2) + s.back();
    }
    
    unordered_set<string> dict;
    unordered_map<string, int> abbrDict;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
