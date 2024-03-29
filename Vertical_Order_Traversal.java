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
}

class Node {
    TreeNode node;
    int row;
    int col;

    public Node(TreeNode _node, int _row, int _col) {
        node = _node;
        row = _row;
        col = _col;
    }
}

public class Main {
    public List<List<Integer>> verticalOrderTraversal(TreeNode root) {
        TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new TreeMap<>();
        Queue<Node> q = new LinkedList<>();
        if (root != null) {
            q.offer(new Node(root, 0, 0));
        }
        while (!q.isEmpty()) {
            Node node = q.poll();
            TreeNode treeNode = node.node;
            int x = node.row;
            int y = node.col;

            if (!map.containsKey(x)) {
                map.put(x, new TreeMap<>());
            }

            if (!map.get(x).containsKey(y)) {
                map.get(x).put(y, new PriorityQueue<>());
            }
            map.get(x).get(y).offer(treeNode.val);

            if (treeNode.left != null) {
                q.offer(new Node(treeNode.left, x - 1, y + 1));
            }

            if (treeNode.right != null) {
                q.offer(new Node(treeNode.right, x + 1, y + 1));
            }
        }

        List<List<Integer>> list = new ArrayList<>();
        for (TreeMap<Integer, PriorityQueue<Integer>> ys : map.values()) {
            list.add(new ArrayList<>());
            for (PriorityQueue<Integer> nodes : ys.values()) {
                while (!nodes.isEmpty()) {
                    list.get(list.size() - 1).add(nodes.poll());
                }
            }
        }
        return list;
    }

    // Method to construct a binary tree from user input
    public TreeNode constructTreeFromInput(Scanner scanner) {
        System.out.print("Enter the value for the root node (-1 for null): ");
        int rootValue = scanner.nextInt();
        if (rootValue == -1) {
            return null;
        }
        TreeNode root = new TreeNode(rootValue);

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();

            System.out.print("Enter the value for the left child of " + current.val + " (-1 for null): ");
            int leftValue = scanner.nextInt();
            if (leftValue != -1) {
                current.left = new TreeNode(leftValue);
                queue.add(current.left);
            }

            System.out.print("Enter the value for the right child of " + current.val + " (-1 for null): ");
            int rightValue = scanner.nextInt();
            if (rightValue != -1) {
                current.right = new TreeNode(rightValue);
                queue.add(current.right);
            }
        }

        return root;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Main solution = new Main();
        
        // Construct the binary tree from user input
        TreeNode root = solution.constructTreeFromInput(scanner);

        // Perform vertical order traversal
        List<List<Integer>> result = solution.verticalOrderTraversal(root);

        // Print the vertical order traversal
        System.out.println("Vertical Order Traversal:");
        for (List<Integer> list : result) {
            System.out.println(list);
        }

        scanner.close();
    }
}
