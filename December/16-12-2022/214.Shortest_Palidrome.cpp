class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length() < 2) return s;
        // rolling hash means we are hashing and adding char to it
        int prime = 31 , m = 1e9 + 7;
        long long int pnos = 31 ;
        
        
        // we can solve this by sliding window approach as we have to find maximum length of palindrome that starts at 0 and end at ind i so we have to add i+1th to end of string to our previous string so this will be like if we add ith char it will be plaidrome or not if it is then good to go but it not then break.
        
        
        // we are creating 2 hash forward and reverse hash so that if both are equal means that we have palidrome in forward hash we are addding character value (a-1) and multiplying it with i'th power of prime in reverse hash we are multiplying previous hash with prime and then adding character value to previous hash and 
        
        
        int ind = 0;
        long long int shash = s[0] - 'a' + 1;
        long long int rhash = s[0] - 'a' + 1;
        for(int i = 1;i<s.length();i++){
            // forward hash
            shash = shash + (s[i] - 'a' + 1)*pnos;
            shash = shash%m;
            // reverse hash
            rhash = rhash*prime + (s[i] - 'a' + 1);
            rhash = rhash%m;
            // updating power of prime
            pnos *= prime;
            pnos = pnos%m;
            if(shash == rhash){
                // till this index string is palindrome
                ind = i;
            }
        }
        // now take string from ind + 1 and reverse it and paste it to rear of given string
        string rev = s.substr(ind+1);
        reverse(rev.begin(),rev.end());
        return rev + s;
    }
};