// Write a function that reverses a string. The input string is given as an array of characters char[].

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// You may assume all the characters consist of printable ascii characters.

void reverseString(char* s, int n){
    int l=0,h=n-1;
    while(l<h){
        char c=s[l];
        s[l++]=s[h];
        s[h--]=c;
    }
    return s;
}
