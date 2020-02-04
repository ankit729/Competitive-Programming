// Given a positive integer num, write a function which returns True if num is a perfect square else False.

// Note: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: 16
// Output: true
// Example 2:

// Input: 14
// Output: false

bool isPerfectSquare(int num){
    int l=1;
    while(num>0){
        num-=l;
        l+=2;
    }
    return (num==0);
}
