class Solution {
public:
    vector<int> ans;

    void mergeSort(vector<pair<int,int>>& arr, int left, int right){

        if(left>=right)
            return;

        int mid=(left+right)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        vector<pair<int,int>> temp;

        int i=left;
        int j=mid+1;

        int smaller=0;

        while(i<=mid && j<=right){

            if(arr[j].first < arr[i].first){

                smaller++;
                temp.push_back(arr[j++]);

            }
            else{

                ans[arr[i].second]+=smaller;
                temp.push_back(arr[i++]);
            }
        }

        while(i<=mid){

            ans[arr[i].second]+=smaller;
            temp.push_back(arr[i++]);
        }

        while(j<=right)
            temp.push_back(arr[j++]);

        for(int k=left;k<=right;k++)
            arr[k]=temp[k-left];
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n=nums.size();

        ans.assign(n,0);

        vector<pair<int,int>> arr;

        for(int i=0;i<n;i++)
            arr.push_back({nums[i],i});

        mergeSort(arr,0,n-1);

        return ans;
    }
};