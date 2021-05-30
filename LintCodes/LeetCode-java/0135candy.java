import java.util.*;

class Solution {
    public int candy(int[] ratings) {
        int len = ratings.length;
        int[] left = new int[len];
        int[] right = new int[len];
        
        for (int i = 1; i < len; ++i) {
            if (ratings[i] > ratings[i -1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = len - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }

        int sum = len;
        for (int i = 0; i < len; ++i) {
            sum += (left[i] > right[i] ? left[i] : right[i]);
        }
        return sum;
    }
}