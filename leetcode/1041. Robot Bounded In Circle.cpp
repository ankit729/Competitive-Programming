// On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

// "G": go straight 1 unit;
// "L": turn 90 degrees to the left;
// "R": turn 90 degress to the right.
// The robot performs the instructions given in order, and repeats them forever.

// Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

// Example 1:

// Input: "GGLLGG"
// Output: true
// Explanation: 
// The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
// When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
// Example 2:

// Input: "GG"
// Output: false
// Explanation: 
// The robot moves north indefinitely.
// Example 3:

// Input: "GL"
// Output: true
// Explanation: 
// The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 

// Note:

// 1 <= instructions.length <= 100
// instructions[i] is in {'G', 'L', 'R'}

class Solution {
public:
    bool isRobotBounded(string s) {
        int dir=0,x=0,y=0;
        int i=0;
        while(s[i]!=NULL){
            isRobotBoundedHelper(s[i],x,y,dir);
            i++;
        }
        return !(dir==0) || (x==0 && y==0);
    }
private:
    void isRobotBoundedHelper(char c, int& x, int& y, int& dir) {
        if(c=='G'){
            switch(dir){
                case 0:y++;break;
                case 1:x++;break;
                case 2:y--;break;
                case 3:x--;break;
            }
        }
        else if(c=='L'){
            dir--;
            if(dir==-1)
                dir+=4;
        }
        else{
            dir++;
            if(dir==4)
                dir-=4;
        }
    }
};
