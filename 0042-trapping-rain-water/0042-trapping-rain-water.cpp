class Solution
{
public:
    int trap(vector<int> &height){
        int n = height.size();
        int l = 0;
        int r = n-1;
        int leftmax = 0, rightmax = 0;
        int ans = 0;

        while(l<r){
            if(height[l] <= height[r]){
                if(leftmax > height[l]){
                    // in this case water can be stored
                    ans += leftmax - height[l];
                }
                else leftmax = height[l];
                l++;
            }
            else{
                if(rightmax > height[r]){
                    // in this case water to be stored
                    ans += rightmax - height[r];
                }
                else rightmax = height[r];
                r--;
            }
        }

        return ans;
    }
};