import leetcode.TreeNode;

import java.util.*;

class Solution {
    private int maxDepthHelper(TreeNode root, int dep, int maxdep)
    {
        if (root == null) {
            return dep;
        }
        ++dep;
        if (dep > maxdep) {
            maxdep = dep;
        }
        int left = maxDepthHelper(root.left, dep, maxdep);
        maxdep = (maxdep > left ? maxdep : left);
        int right = maxDepthHelper(root.right, dep, maxdep);
        return (maxdep > right ? maxdep : right);
    }
    public int maxDepth(TreeNode root) {
        return maxDepthHelper(root, 0, 1);
    }
}