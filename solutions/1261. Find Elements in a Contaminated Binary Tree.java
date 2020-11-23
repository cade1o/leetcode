/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class FindElements {
​
   TreeNode root;
​
public FindElements(TreeNode root) {
    this.root = root;
}
​
public boolean find(int target) {
    return dfs(root, binSerialize(target + 1), 1);
}
​
public boolean dfs(TreeNode root, String str, int pos){
    if(root == null)    return false;
    if(pos == str.length()) return true;
    return str.charAt(pos) == '0'? dfs(root.left, str, pos+1) : dfs(root.right, str, pos+1);
}
​
public String binSerialize(int num){
    StringBuilder sb = new StringBuilder();
    while(num > 0){
        sb.insert(0, num & 1);
        num /= 2;
    }
    return sb.toString();
}
}
​
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */
​
