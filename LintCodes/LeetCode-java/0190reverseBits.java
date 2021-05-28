import java.util.*;

class leetcode {
	public static void main(String[] args)  {
		Solution s = new Solution();
		System.out.println(s.reverseBits(43261596));
	}
}
class Solution {
	public int reverseBits(int n) {
		int res = 0;
	    int maskRight = 1;
	    int maskLeft = 1 << 31;
	    for (int i = 0; i < 32; ++i) {
	    	res |= ((maskRight & n) == 0 ? 0 : maskLeft);
	    	maskRight <<= 1;
	    	maskLeft >>>= 1;
		}
	    return res;
    }
}