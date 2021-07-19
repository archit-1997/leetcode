/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

  public TreeNode increasingBST(TreeNode root) {
    if (root == null) return root;
    List<Integer> nodeList = new ArrayList();
    //store the inorder traversal
    TreeNode tmp = new TreeNode(0);
    tmp = root;
    inorder(tmp, nodeList);

    TreeNode ans = new TreeNode(0);
    TreeNode cur = new TreeNode(0);
    cur = ans;

    for (int num : nodeList) {
      cur.right = new TreeNode(num);
      cur = cur.right;
    }

    return ans.right;
  }

  public void inorder(TreeNode root, List<Integer> nodeList) {
    if (root == null) return;
    inorder(root.left, nodeList);
    nodeList.add(root.val);
    inorder(root.right, nodeList);
  }
}
