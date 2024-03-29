import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
    
    // Method to construct a binary tree from user input
    public static TreeNode constructTreeFromInput(Scanner scanner) {
        System.out.print("Enter the value for the root node: ");
        int rootValue = scanner.nextInt();
        TreeNode root = new TreeNode(rootValue);

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();

            System.out.print("Enter the value for the left child of " + current.val + " (Enter -1 for null): ");
            int leftValue = scanner.nextInt();
            if (leftValue != -1) {
                current.left = new TreeNode(leftValue);
                queue.add(current.left);
            }

            System.out.print("Enter the value for the right child of " + current.val + " (Enter -1 for null): ");
            int rightValue = scanner.nextInt();
            if (rightValue != -1) {
                current.right = new TreeNode(rightValue);
                queue.add(current.right);
            }
        }

        return root;
    }
}

class Solution {
    public void recoverTree(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode current = root;
        TreeNode lastProcessed = null;
        TreeNode[] swapped = new TreeNode[2];
        while (!stack.isEmpty() || current != null) {
            while (current != null) {
                stack.push(current);
                current = current.left;
            }
            current = stack.pop();
            if (lastProcessed != null && lastProcessed.val > current.val) {
                if (swapped[0] == null) {
                    swapped[0] = lastProcessed;
                    swapped[1] = current;
                } else {
                    swapped[1] = current;
                    break;
                }
            }
            lastProcessed = current;
            current = current.right;
        }
        int temp = swapped[0].val;
        swapped[0].val = swapped[1].val;
        swapped[1].val = temp;
    }

    public void printInorder(TreeNode node) {
        if (node == null) {
            return;
        }
        printInorder(node.left);
        System.out.print(" " + node.val);
        printInorder(node.right);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Construct the binary tree from user input
        TreeNode root = TreeNode.constructTreeFromInput(scanner);
        
        // Create an instance of the Solution class
        Solution solution = new Solution();
        
        // Recover the tree
        solution.recoverTree(root);

        // Print the inorder traversal of the recovered tree
        System.out.println("Inorder traversal of the recovered tree:");
        solution.printInorder(root);

        scanner.close();
    }
}
