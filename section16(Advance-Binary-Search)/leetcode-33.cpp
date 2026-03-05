// 33. Search in Rotated Sorted Array

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size() - 1;
    while(s <= e){
        int mid = s + (e - s)/2;
        if(nums[mid] == target)
            return mid;
        if(nums[s] <= nums[mid]){  
            if(target >= nums[s] && target < nums[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        else{  
            if(target > nums[mid] && target <= nums[e])
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>nums[i];
    int target;
    cout<<"Enter target: ";
    cin>>target;
    cout<<"Index: "<<search(nums,target);
}