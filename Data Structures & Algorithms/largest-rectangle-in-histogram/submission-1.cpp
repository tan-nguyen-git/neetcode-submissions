class Solution {
public:
    //first smaller bars encountered to the left and right of the current bar[]=
    int largestRectangleArea(vector<int>& heights){
        int n = heights.size();
        vector<int> left(n,0), right(n,0);
        stack<int> leftS, rightS;
        leftS.push(0);
        rightS.push(n-1);
        for(int i = 1; i < n; i++){
            while(!leftS.empty() && heights[leftS.top()] >= heights[i]){
                leftS.pop();
            }
            if(leftS.empty()) left[i] =  -i;
            else left[i] = leftS.top() - i +1;
            leftS.push(i);
        }
        for(int i = n -2; i >=0 ; i--){
            while(!rightS.empty() && heights[rightS.top()] >= heights[i]){
                rightS.pop();
            }
            if(rightS.empty()) right[i] =  n - i -1;
            else right[i] = rightS.top() -i -1 ;
            rightS.push(i);
        }
        for(auto a: left){
            cout<<a<<endl;
        }
         for(auto b: right){
            cout<<b<<endl;
        }
        int maxArea = 0;
        for(int i = 0 ; i< n ; i++){
            maxArea = max((right[i] - left[i]+1) * heights[i], maxArea);
        }
        return maxArea;
        
        
    }
};
