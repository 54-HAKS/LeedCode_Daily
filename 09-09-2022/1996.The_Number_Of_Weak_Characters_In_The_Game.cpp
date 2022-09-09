class Solution {
public:
    // the idea is to
    // 1. rearrange the order of attack in ascending order and  that of defense in descending order 
    // 2. count weak characters (those defenses less than the current maximum defense)
    // 3. update the maximum defense
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        // the final answer to be returned
        int weakCharacters = 0;
        // record maximum defense. since 1 <= defense_i <= 10 ^ 5
        // we can set the init value to x where x < 1
        int maxDefense = 0;
        // sort properties with custom sort comparator
        sort(p.begin(), p.end(), [](const vector<int>& x, const vector<int>& y) {
            // if the attack is same, then sort defense in descending order  
            // otherwise, sort attack in in ascending order 
           return x[0] == y[0] ? x[1] < y[1] : x[0] > y[0];
        });
        for (auto& x : p) {
            // x[1] is defense of properties[i]
            // if it is less than current maxDefense, then it means it is a weak character
            weakCharacters += x[1] < maxDefense;
            // update maxDefense
            maxDefense = max(maxDefense, x[1]);
        }
        return weakCharacters;
    }
};