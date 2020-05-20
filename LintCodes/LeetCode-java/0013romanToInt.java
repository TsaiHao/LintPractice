import java.util.*;

class Solution {
	public int romanToInt(String s) {
		HashMap<Character, Integer> digits = new HashMap<>();
		digits.put('I', 1);
		digits.put('V', 5);
		digits.put('X', 10);
		digits.put('L', 50);
		digits.put('C', 100);
		digits.put('D', 500);
		digits.put('M', 1000);
		
		int num = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			num += digits.get(s.charAt(i));
			if (i < s.length() - 1)
			{
				if (digits.get(s.charAt(i + 1)) > digits.get(s.charAt(i))) {
					num -= 2 * digits.get(s.charAt(i));
				}
			}
		}
		return num;
    }
}