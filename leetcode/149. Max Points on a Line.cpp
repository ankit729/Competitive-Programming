// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

// Example 1:

// Input: [[1,1],[2,2],[3,3]]
// Output: 3
// Explanation:
// ^
// |
// |        o
// |     o
// |  o  
// +------------->
// 0  1  2  3  4
// Example 2:

// Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4
// Explanation:
// ^
// |
// |  o
// |     o        o
// |        o
// |  o        o
// +------------------->
// 0  1  2  3  4  5  6
// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size(),ans=0;
        sort(points.begin(),points.end());
        for(int i=0;i<n;++i){
            int same=1,hv=0;
            while(i+1<n && points[i]==points[i+1])
                same++,i++;
            int j=i+1;
            while(j<n && points[i][0]==points[j][0])
                hv++,j++;
            ans=max(ans,same+hv);
            map<pair<int,int>,int> slope;
            for(hv=0;j<n;++j){
                if(points[i][1]==points[j][1])
                    hv++;
                else{
                    int x=points[i][0]-points[j][0],y=points[i][1]-points[j][1];
                    int g=gcd(abs(x),abs(y));
                    x/=g,y/=g;
                    if(y<0)
                        x=-x,y=-y;
                    slope[{x,y}]++;
                }
            }
            ans=max(ans,same+hv);
            for(auto& x:slope)
                ans=max(ans,same+x.second);
        }
        return ans;
    }
};
