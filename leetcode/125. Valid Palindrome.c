// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Note: For the purpose of this problem, we define empty string as valid palindrome.

// Example 1:

// Input: "A man, a plan, a canal: Panama"
// Output: true
// Example 2:

// Input: "race a car"
// Output: false

bool isPalindrome(char * s){
    int n=strlen(s);
    int l=0,h=n-1;
    while(l<h){
        while(l<h&&!((s[l]>='a'&&s[l]<='z')||(s[l]>='A'&&s[l]<='Z')||(s[l]>='0'&&s[l]<='9')))
            l++;
        while(l<h&&!((s[h]>='a'&&s[h]<='z')||(s[h]>='A'&&s[h]<='Z')||(s[h]>='0'&&s[h]<='9')))
            h--;
        if(tolower(s[l++])!=tolower(s[h--]))
            return false;
    }
    return true;
}
