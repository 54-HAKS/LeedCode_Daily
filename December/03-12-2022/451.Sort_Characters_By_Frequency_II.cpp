class Solution 
{
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int> cnt;
        for (char c : s) ++cnt[c];                    // [1] counting character frequencies
        
        set<pair<int,char>> pq;                       // [2] set can be used as a priority queue to
        for (auto[ch,c] : cnt) pq.insert({-c, ch});   //     sort characters using their frequencies
        
        string ss = "";                               // [3] finally, we iterate over (sorted) elements of the
        for (auto[c,ch] : pq)                         //     set and construct chunks of resulting string by
            ss += string(-c, ch);                     //     repeating each character according to its count
        
        return ss;
    }
};