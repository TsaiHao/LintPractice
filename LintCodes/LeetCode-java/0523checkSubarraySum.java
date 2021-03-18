import java.util.*;

class Solution {
	private boolean checkTwoZeros(int[] nums)
	{
		boolean flag = false;
		for (int i = 0; i <  nums.length; ++i)
		{
			if (nums[i] == 0) {
				if (flag) {
					return true;
				}
				flag = true;
			}
			else {
				flag = false;
			}
		}
		return false;
	}
    public boolean checkSubarraySum(int[] nums, int k) {
    	if (nums.length <= 1) {
    		return false;
    	}
    	if (k == 0) {
    		if (checkTwoZeros(nums)) {
    			return true;
    		}
    		return false;
    	}
    	HashMap<Integer, Integer> record = new HashMap<Integer, Integer>();
    	record.put(0, -1);
    	k = Math.abs(k);
    	int prev = 0;
    	for (int i = 0; i < nums.length; ++i)
    	{
    		int res = (nums[i] + prev) % k;
    		prev = res;
    		if (record.containsKey(res)) {
    			if (record.get(res) != i - 1) {
    				return true;
    			}
    		}
    		else {
    			record.put(res, i);
    		}
    	}
    	return false;
    }
}