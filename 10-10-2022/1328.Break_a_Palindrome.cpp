class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n<=1)return "";    //if size is 1 , then it is always a palindrome
        for(int i=0;i<n/2;++i){
            if(palindrome[i]!='a'){  //replace the first non 'a' character
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome.pop_back(); 
        palindrome+='b';
        return palindrome;
    }
};