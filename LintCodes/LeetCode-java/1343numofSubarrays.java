import java.util.*;

class Solution {
	public int numOfSubarrays(int[] arr, int k, int threshold) {
		if (arr == null || arr.length < k) {
			return 0;
		}
		int n = 0;
		int sum = 0;
		final int thre = k * threshold;
		for (int i = 0; i < k; ++i) {
			sum += arr[i];
		}
		if (sum >= thre) {
			++n;
		}
		
		for (int i = k; i < arr.length; ++i)
		{
			sum += arr[i] - arr[i - k];
			if (sum >= thre) {
				++n;
			}
		}
		return n;
    }
}