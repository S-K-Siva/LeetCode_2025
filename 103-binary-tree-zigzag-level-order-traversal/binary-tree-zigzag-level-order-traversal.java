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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root == null){
            return new ArrayList<>();
        }
        boolean leftToRight = true;
        Queue<TreeNode> que = new LinkedList<>();
        que.offer(root);
        List<List<Integer>> result = new ArrayList<>();

        while(!que.isEmpty()){
            int queSize = que.size();
            List<Integer> row = new LinkedList<>();
            for(int i = 0;i<queSize;i++){
                TreeNode current;
                current = que.poll();
                if(current == null) continue;
                if(leftToRight){
                    row.addLast(current.val);
                }else{
                    row.addFirst(current.val);
                }

                if(current.left != null){
                    que.offer(current.left);
                }
                if(current.right != null){
                    que.offer(current.right);
                }
            }
            leftToRight = !leftToRight;
            result.add(row);
        }
        return result;
    }
}