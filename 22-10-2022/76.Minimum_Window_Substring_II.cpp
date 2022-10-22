class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        // we are calculating what frequencies do we need to have substring window
        for(int i = 0; i < t.size(); i++){
            freq[t[i]]++;
        }
        // we assume that whole s is our substring window and decrease frequencies for letters we have
        for(int i = 0; i < s.size(); i++){
            freq[s[i]]--;
        }
        // if we do not have certain letters then we return ""
        for(auto it: freq){
            if(it.second > 0){
                return "";
            }
        }
        // we now trying to make minimum window substring that have left side on 0
        int l = 0;
        int r = s.size()-1;
        while(freq[s[r]] < 0){
            freq[s[r]]++;
            r--;
        }
        int best_length = r-l + 1;
        int best_l = l;
        // we now trying to make minimum window substring
        while(r < s.size()){
            // if it is possible we try to minimize left 
            if(freq[s[l]] < 0){
                freq[s[l]]++;
                l++;
                // whenever we minimize from the left then we can check if it is minimum and save result
                if(r-l+1 < best_length){
                    best_length = r-l+1;
                    best_l = l;
                }
            } else {
                // if not we have to increase right
                r++;
                freq[s[r]]--;
            }
        }
        return s.substr(best_l, best_length);
    }
};