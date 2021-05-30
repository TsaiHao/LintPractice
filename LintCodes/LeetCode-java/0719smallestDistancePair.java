import java.util.*;

class Solution {
	public int countSmaller(int[] nums, int dis)
	{
		int cnt = 0;
		int left = 0; 
		for (int right = 0; right < nums.length; ++right)
		{
			while (nums[right] - nums[left] > dis) {
				++left;
			}
			cnt += right - left;
		}
		return cnt;
	}
    public int smallestDistancePair(int[] nums, int k) {
    	Arrays.sort(nums);
    	int minDis = 0, maxDis = nums[nums.length - 1] - nums[0];
    	
    	while (minDis < maxDis)
    	{
    		int mid = (maxDis + minDis) / 2;
    		if (countSmaller(nums, mid) < k) {
    			minDis = mid + 1;
    		}
    		else {
    			maxDis = mid;
    		}
    	}
    	return minDis;
    }
}