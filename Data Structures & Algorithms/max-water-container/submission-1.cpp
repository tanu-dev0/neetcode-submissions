class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int maxarea=0;
        while(j>i){
        int carea=( j-i ) * ( min(heights[j],heights[i]) );
         maxarea=max(maxarea,carea);
         if(heights[j]>heights[i]){
            i++;
         } else j--;

        }
        return maxarea;

        
    }
};
