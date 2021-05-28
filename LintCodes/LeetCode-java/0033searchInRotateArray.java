class Solution {
	private int maxIdx;
	private int minIdx;
	private int length;
	private int translate(int idx) {
		int id = idx + minIdx;
		return id < length ? id : id - length;
	}

    private void findPivot(int[] nums) {
		length = nums.length;
    	if (nums.length <= 1 || nums[0] < nums[nums.length - 1]) {
    	    minIdx = 0;
    	    maxIdx = nums.length - 1;
		}
    	int left = 0, right = nums.length - 1;
    	while (left < right) {
    		int mid = (right + left) / 2;
    		if (nums[mid] > nums[mid + 1]) {
    			maxIdx = mid;
    			minIdx = mid + 1;
			}
    		if (nums[left] < nums[mid]) {
    			left = mid;
			}
    		else {
    			right = mid;
			}
		}
	}
	public int search(int[] nums, int target) {
	    if (nums.length == 0) {
	    	return -1;
		}
	    if (nums.length == 1) {
	    	return nums[0] == target ? 0 : -1;
		}

	    findPivot(nums);
	    int left = 0;
	    int right = nums.length - 1;
	    while (left < right) {
	        if (right - left < 2) {
	        	left = translate(left);
	        	right = translate(right);
	        	if (nums[left] == target)
	        		return left;
	        	if (nums[right] == target)
	        		return right;
	        	return -1;
			}
	    	int mid = translate((left + right) / 2);
	    	if (nums[mid] == target) {
	    		return mid;
			}
	    	if (nums[mid] < target) {
	    		left = (right + left) / 2;
			}
	    	else {
				right = (right + left) / 2;
			}
		}
	    return -1;
	}
}

