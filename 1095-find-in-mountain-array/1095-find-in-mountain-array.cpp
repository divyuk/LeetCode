/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int peakIndexInMountainArray(MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 0, high = n-1, mid = 0;
        while(low<high){
            mid = low + (high-low)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1) ) low = mid+1;
            else high = mid;
        }
        return low; // high
    }
    
    int binarySearch(MountainArray &mountainArr, int low, int high, int target){

        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) < target ) low = mid+1;
            else high = mid -1;

        }
        return -1;
    }
    
    int reversebinarySeach(MountainArray &mountainArr, int low, int high, int target){
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) < target ) high = mid -1;
            else low = mid+1;

        }
        return -1;
    }
    
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peakIdx = peakIndexInMountainArray(mountainArr);
        
        int resultIdx= binarySearch(mountainArr, 0, peakIdx, target);
        if(resultIdx == -1) 
            resultIdx = reversebinarySeach(mountainArr, peakIdx+1 , n-1 , target);
        
        return resultIdx;
        

    }
};