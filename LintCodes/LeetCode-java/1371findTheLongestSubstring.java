import java.util.*;

class Solution {
	public int findTheLongestSubstring(String s) {
		int maxLength = 0;
		int[] firstStat = new int[32];
		for (int i = 0; i < 32; ++i) {
			firstStat[i] = -1;
		}
		firstStat[0] = 0;
		int status = 0;
		HashMap<Character, Integer> dict = new HashMap<>();
		dict.put('a', 0);
		dict.put('e', 1);
		dict.put('o', 2);
		dict.put('i', 3);
		dict.put('u', 4);
		
		for (int i = 0; i < s.length(); ++i)
		{
			if (dict.containsKey(s.charAt(i))) {
				status ^= 1 << dict.get(s.charAt(i));
			}
			if (firstStat[status] >= 0) {
				maxLength = Math.max(maxLength, i + 1 - firstStat[status]);
			}
			else {
				firstStat[status] = i + 1;
			}
		}
		
		return maxLength;
    }
}