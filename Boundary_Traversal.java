import java.util.*;

class Node {
    int data;
    Node left, right;

    // Node constructor
    public Node(int data) {
        this.data = data;
        left = right = null;
    }
}

public class Main {
    static Node root;
    private List<Integer> path1 = new ArrayList<>();
    private List<Integer> path2 = new ArrayList<>();

    // Function to build the binary tree
    static Node buildTree(Scanner scanner) {
        Queue<Node> q = new LinkedList<>();
        System.out.print("Enter root value (N for null): ");
        String val = scanner.next();
        if (val.equals("N"))
            return null;
        Node root = new Node(Integer.parseInt(val));
        q.add(root);
        while (!q.isEmpty()) {
            Node temp = q.poll();
            // Prompting for left child value
            System.out.print("Enter left child value of " + temp.data + " (N for null): ");
            val = scanner.next();
            if (!val.equals("N")) {
                // Creating left child node and adding to the queue
                temp.left = new Node(Integer.parseInt(val));
                q.add(temp.left);
            }
            // Prompting for right child value
            System.out.print("Enter right child value of " + temp.data + " (N for null): ");
            val = scanner.next();
            if (!val.equals("N")) {
                // Creating right child node and adding to the queue
                temp.right = new Node(Integer.parseInt(val));
                q.add(temp.right);
            }
        }
        return root;
    }

    // Function to print the leaves of the binary tree
    void printLeaves(Node node) {
        if (node == null)
            return;
        printLeaves(node.left);
        if (node.left == null && node.right == null) {
            // Printing leaf node's data
            System.out.print(node.data + " ");
        }
        printLeaves(node.right);
    }

    // Function to print the left boundary of the binary tree
    void printBoundaryLeft(Node node) {
        if (node == null)
            return;
        if (node.left != null) {
            // Printing non-leaf left child node's data
            System.out.print(node.data + " ");
            printBoundaryLeft(node.left);
        } else if (node.right != null) {
            // If left child is null, print the right child node's data
            System.out.print(node.data + " ");
            printBoundaryLeft(node.right);
        }
    }

    // Function to print the right boundary of the binary tree
    void printBoundaryRight(Node node) {
        if (node == null)
            return;
        if (node.right != null) {
            // Printing non-leaf right child node's data in reverse order
            printBoundaryRight(node.right);
            System.out.print(node.data + " ");
        } else if (node.left != null) {
            // If right child is null, print the left child node's data in reverse order
            printBoundaryRight(node.left);
            System.out.print(node.data + " ");
        }
    }

    // Function to print the boundary of the binary tree
    void printBoundary(Node node) {
        if (node == null)
            return;
        // Print root node's data
        System.out.print(node.data + " ");
        // Print the left boundary
        printBoundaryLeft(node.left);
        // Print leaf nodes in left subtree
        printLeaves(node.left);
        // Print leaf nodes in right subtree
        printLeaves(node.right);
        // Print the right boundary
        printBoundaryRight(node.right);
    }

    // Main method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main obj = new Main();
        root = buildTree(scanner); // Build the binary tree
        obj.printBoundary(root);  // Print the boundary of the binary tree
        scanner.close();
    }
}
