class Solution {
private:
    int merge(int low, int mid, int high, vector<int>& arr){
        int ans = 0;
        int i=low;
        int j=mid+1;
        vector<int>temp;

        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)arr[i] > 2LL * arr[j])
                j++;

            ans += j - (mid + 1);
        }
         i= low;
         j = mid+1;
        
        while(i<=mid && j<=high){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else {
                temp.push_back(arr[j]);
                j++;
            }
        }
        
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int i=low;i<=high;i++){
            arr[i] = temp[i-low];
        }
        
        return ans;
    }
    
    int mergeSort(int low,int high, vector<int>& arr){
        int cnt = 0;
        if(low >= high) return cnt;
        
        int mid = (high+low)/2;
        cnt += mergeSort(low,mid,arr);
        cnt += mergeSort(mid+1,high,arr);
        
        cnt += merge(low,mid,high,arr);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(0,n-1,nums);
    }
};