import java.util.*;

class Node {
    int data;
    Node left, right;

    public Node(int data) {
        this.data = data;
        left = right = null;
    }
}

public class Main {
    static Node root;
    private List<Integer> path1 = new ArrayList<>();
    private List<Integer> path2 = new ArrayList<>();

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
            System.out.print("Enter left child value of " + temp.data + " (N for null): ");
            val = scanner.next();
            if (!val.equals("N")) {
                temp.left = new Node(Integer.parseInt(val));
                q.add(temp.left);
            }
            System.out.print("Enter right child value of " + temp.data + " (N for null): ");
            val = scanner.next();
            if (!val.equals("N")) {
                temp.right = new Node(Integer.parseInt(val));
                q.add(temp.right);
            }
        }
        return root;
    }

    void printLeaves(Node node) {
        if (node == null)
            return;
        printLeaves(node.left);
        if (node.left == null && node.right == null) {
            System.out.print(node.data + " ");
        }
        printLeaves(node.right);
    }

    void printBoundaryLeft(Node node) {
        if (node == null)
            return;
        if (node.left != null) {
            System.out.print(node.data + " ");
            printBoundaryLeft(node.left);
        } else if (node.right != null) {
            System.out.print(node.data + " ");
            printBoundaryLeft(node.right);
        }
    }

    void printBoundaryRight(Node node) {
        if (node == null)
            return;
        if (node.right != null) {
            printBoundaryRight(node.right);
            System.out.print(node.data + " ");
        } else if (node.left != null) {
            printBoundaryRight(node.left);
            System.out.print(node.data + " ");
        }
    }

    void printBoundary(Node node) {
        if (node == null)
            return;
        System.out.print(node.data + " ");
        printBoundaryLeft(node.left);
        printLeaves(node.left);
        printLeaves(node.right);
        printBoundaryRight(node.right);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main obj = new Main();
        root = buildTree(scanner);
        obj.printBoundary(root);
        scanner.close();
    }
}
