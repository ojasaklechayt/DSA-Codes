// Bellman Ford

import java.util.*;

class Main {
    static class CreateGraph {
        class CreateEdge {
            int src, dest, weight;

            CreateEdge(int src, int dest, int weight) {
                this.src = src;
                this.dest = dest;
                this.weight = weight;
            }
        }

        int V, E;
        CreateEdge edge[];

        CreateGraph(int v, int e) {
            V = v;
            E = e;
            edge = new CreateEdge[e];
        }

        void BellmanFord(int src) {
            int dist[] = new int[V];
            for (int i = 0; i < V; ++i) {
                dist[i] = Integer.MAX_VALUE;
            }
            dist[src] = 0;
            for (int i = 1; i < V; ++i) {
                for (int j = 0; j < E; ++j) {
                    int u = edge[j].src;
                    int v = edge[j].dest;
                    int w = edge[j].weight;
                    if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }

            for (int j = 0; j < E; ++j) {
                int u = edge[j].src;
                int v = edge[j].dest;
                int w = edge[j].weight;
                if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v]) {
                    System.out.println("Graph contains negative weight cycle");
                    return;
                }
            }
            printSolution(dist);
        }

        void printSolution(int dist[]) {
            for (int i = 0; i < V; ++i) {
                System.out.println(i + "\t\t" + dist[i]);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of vertices: ");
        int V = scanner.nextInt();
        System.out.print("Enter the number of edges: ");
        int E = scanner.nextInt();
        
        CreateGraph graph = new CreateGraph(V, E);
        
        System.out.println("Enter edge details (source destination weight):");
        for (int i = 0; i < E; i++) {
            int src = scanner.nextInt();
            int dest = scanner.nextInt();
            int weight = scanner.nextInt();
            graph.edge[i] = graph.new CreateEdge(src, dest, weight);
        }
        
        System.out.print("Enter the source vertex: ");
        int sourceVertex = scanner.nextInt();
        
        graph.BellmanFord(sourceVertex);
        
        scanner.close();
    }
}


// BFS

import java.util.*;

public class Graph {
    private int V;
    private LinkedList<Integer> adj[];

    Graph(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i) {
            adj[i] = new LinkedList();
        }
    }

    void addEdge(int v, int w) {
        adj[v].add(w);
    }

    void BFS(int s) {
        boolean visited[] = new boolean[V];
        LinkedList<Integer> queue = new LinkedList();
        visited[s] = true;
        queue.add(s);
        while (queue.size() != 0) {
            s = queue.poll();
            System.out.print(s + " ");
            Iterator<Integer> i = adj[s].listIterator();
            while (i.hasNext()) {
                int n = i.next();
                if (!visited[n]) {
                    visited[n] = true;
                    queue.add(n);
                }
            }
        }
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        int V = scanner.nextInt();
        Graph g = new Graph(V);

        System.out.print("Enter the number of edges: ");
        int E = scanner.nextInt();

        System.out.println("Enter edge details (source destination):");
        for (int i = 0; i < E; i++) {
            int src = scanner.nextInt();
            int dest = scanner.nextInt();
            g.addEdge(src, dest);
        }

        System.out.print("Enter the starting vertex for BFS traversal: ");
        int startVertex = scanner.nextInt();

        g.BFS(startVertex);
        
        scanner.close();
    }
}


// Binomial Heap

import java.util.*;

class BinomialHeapNode {
    int key, degree;
    BinomialHeapNode parent;
    BinomialHeapNode sibling;
    BinomialHeapNode child;

    public BinomialHeapNode(int k) {
        key = k;
        degree = 0;
        parent = null;
        sibling = null;
        child = null;
    }

    public BinomialHeapNode reverse(BinomialHeapNode sibl) {
        BinomialHeapNode ret;
        if (sibling != null)
            ret = sibling.reverse(this);
        else
            ret = this;
        sibling = sibl;
        return ret;
    }

    public BinomialHeapNode findMinNode() {
        BinomialHeapNode x = this, y = this;
        int min = x.key;
        while (x != null) {
            if (x.key < min) {
                y = x;
                min = x.key;
            }
            x = x.sibling;
        }
        return y;
    }

    public BinomialHeapNode findANodeWithKey(int value) {
        BinomialHeapNode temp = this, node = null;
        while (temp != null) {
            if (temp.key == value) {
                node = temp;
                break;
            }
            if (temp.child == null)
                temp = temp.sibling;
            else {
                node = temp.child.findANodeWithKey(value);
                if (node == null)
                    temp = temp.sibling;
                else
                    break;
            }
        }
        return node;
    }

    public int getSize() {
        return (1 + ((child == null) ? 0 : child.getSize()) + ((sibling == null) ? 0 : sibling.getSize()));
    }
}

class BinomialHeap {
    private BinomialHeapNode Nodes;
    private int size;

    public BinomialHeap() {
        Nodes = null;
        size = 0;
    }

    public boolean isEmpty() {
        return Nodes == null;
    }

    public int getSize() {
        return size;
    }

    public void makeEmpty() {
        Nodes = null;
        size = 0;
    }

    public void insert(int value) {
        if (value > 0) {
            BinomialHeapNode temp = new BinomialHeapNode(value);
            if (Nodes == null) {
                Nodes = temp;
                size = 1;
            } else {
                unionNodes(temp);
                size++;
            }
        }
    }

    private void merge(BinomialHeapNode binHeap) {
        BinomialHeapNode temp1 = Nodes, temp2 = binHeap;
        while ((temp1 != null) && (temp2 != null)) {
            if (temp1.degree == temp2.degree) {
                BinomialHeapNode tmp = temp2;
                temp2 = temp2.sibling;
                tmp.sibling = temp1.sibling;
                temp1.sibling = tmp;
                temp1 = tmp.sibling;
            } else {
                if (temp1.degree < temp2.degree) {
                    if ((temp1.sibling == null) || (temp1.sibling.degree > temp2.degree)) {
                        BinomialHeapNode tmp = temp2;
                        temp2 = temp2.sibling;
                        tmp.sibling = temp1.sibling;
                        temp1.sibling = tmp;
                        temp1 = tmp.sibling;
                    } else
                        temp1 = temp1.sibling;
                } else {
                    BinomialHeapNode tmp = temp1;
                    temp1 = temp2;
                    temp2 = temp2.sibling;
                    temp1.sibling = tmp;
                    if (tmp == Nodes)
                        Nodes = temp1;
                }
            }
        }
        if (temp1 == null) {
            temp1 = Nodes;
            while (temp1.sibling != null)
                temp1 = temp1.sibling;
            temp1.sibling = temp2;
        }
    }

    private void unionNodes(BinomialHeapNode binHeap) {
        merge(binHeap);
        BinomialHeapNode prevTemp = null, temp = Nodes, nextTemp = Nodes.sibling;
        while (nextTemp != null) {
            if ((temp.degree != nextTemp.degree) || ((nextTemp.sibling != null) && (nextTemp.sibling.degree == temp.degree))) {
                prevTemp = temp;
                temp = nextTemp;
            } else {
                if (temp.key <= nextTemp.key) {
                    temp.sibling = nextTemp.sibling;
                    nextTemp.parent = temp;
                    nextTemp.sibling = temp.child;
                    temp.child = nextTemp;
                    temp.degree++;
                } else {
                    if (prevTemp == null)
                        Nodes = nextTemp;
                    else
                        prevTemp.sibling = nextTemp;
                    temp.parent = nextTemp;
                    temp.sibling = nextTemp.child;
                    nextTemp.child = temp;
                    nextTemp.degree++;
                    temp = nextTemp;
                }
            }
            nextTemp = temp.sibling;
        }
    }

    public int findMinimum() {
        return Nodes.findMinNode().key;
    }

    public void delete(int value) {
        if ((Nodes != null) && (Nodes.findANodeWithKey(value) != null)) {
            decreaseKeyValue(value, findMinimum() - 1);
            extractMin();
        }
    }

    public void decreaseKeyValue(int old_value, int new_value) {
        BinomialHeapNode temp = Nodes.findANodeWithKey(old_value);
        if (temp == null)
            return;
        temp.key = new_value;
        BinomialHeapNode tempParent = temp.parent;
        while ((tempParent != null) && (temp.key < tempParent.key)) {
            int z = temp.key;
            temp.key = tempParent.key;
            tempParent.key = z;
            temp = tempParent;
            tempParent = tempParent.parent;
        }
    }

    public int extractMin() {
        if (Nodes == null)
            return -1;
        BinomialHeapNode temp = Nodes, prevTemp = null;
        BinomialHeapNode minNode = Nodes.findMinNode();
        while (temp.key != minNode.key) {
            prevTemp = temp;
            temp = temp.sibling;
        }
        if (prevTemp == null)
            Nodes = temp.sibling;
        else
            prevTemp.sibling = temp.sibling;
        temp = temp.child;
        BinomialHeapNode fakeNode = temp;
        while (temp != null) {
            temp.parent = null;
            temp = temp.sibling;
        }
        if ((Nodes == null) && (fakeNode == null))
            size = 0;
        else {
            if ((Nodes == null) && (fakeNode != null)) {
                Nodes = fakeNode.reverse(null);
                size = Nodes.getSize();
            } else {
                if ((Nodes != null) && (fakeNode == null))
                    size = Nodes.getSize();
                else {
                    unionNodes(fakeNode.reverse(null));
                    size = Nodes.getSize();
                }
            }
        }
        return minNode.key;
    }

    public void displayHeap() {
        System.out.print("\nHeap : ");
        displayHeap(Nodes);
        System.out.println("\n");
    }

    private void displayHeap(BinomialHeapNode r) {
        if (r != null) {
            displayHeap(r.child);
            System.out.print(r.key + " ");
            displayHeap(r.sibling);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        BinomialHeap binHeap = new BinomialHeap();
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements to insert: ");
        int n = scanner.nextInt();

        System.out.println("Enter the elements to insert into the heap:");
        for (int i = 0; i < n; i++) {
            int element = scanner.nextInt();
            binHeap.insert(element);
        }

        System.out.println("Size: " + binHeap.getSize());
        binHeap.displayHeap();

        System.out.print("Enter the element to delete: ");
        int elementToDelete = scanner.nextInt();
        binHeap.delete(elementToDelete);

        System.out.println("Size after deletion: " + binHeap.getSize());
        binHeap.displayHeap();

        System.out.println("Is the heap empty? " + binHeap.isEmpty());

        binHeap.makeEmpty();
        System.out.println("Is the heap empty after clearing? " + binHeap.isEmpty());

        scanner.close();
    }
}


// Boundary Traversal

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


// DFS

import java.util.*;

class Graph {
    private LinkedList<Integer> adjLists[];
    private boolean visited[];

    Graph(int vertices) {
        adjLists = new LinkedList[vertices];
        visited = new boolean[vertices];
        for (int i = 0; i < vertices; i++) {
            adjLists[i] = new LinkedList<>();
        }
    }

    void addEdge(int src, int dest) {
        adjLists[src].add(dest);
    }

    void DFS(int vertex) {
        visited[vertex] = true;
        System.out.print(vertex + " ");
        Iterator<Integer> ite = adjLists[vertex].listIterator();
        while (ite.hasNext()) {
            int adj = ite.next();
            if (!visited[adj]) {
                DFS(adj);
            }
        }
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        int V = scanner.nextInt();
        Graph g = new Graph(V);

        System.out.print("Enter the number of edges: ");
        int E = scanner.nextInt();

        System.out.println("Enter edge details (source destination):");
        for (int i = 0; i < E; i++) {
            int src = scanner.nextInt();
            int dest = scanner.nextInt();
            g.addEdge(src, dest);
        }

        System.out.print("Enter the starting vertex for DFS traversal: ");
        int startVertex = scanner.nextInt();

        g.DFS(startVertex);

        scanner.close();
    }
}


// Dial's Algorithm 

import java.util.*;

class Graph {
    private int V;
    private List<List<Node>> adj;

    public Graph(int V) {
        this.V = V;
        adj = new ArrayList<>(V);
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
    }

    public void addEdge(int source, int destination, int weight) {
        Node node = new Node(destination, weight);
        adj.get(source).add(node);
    }

    public void dijkstra(int startVertex) {
        int[] distance = new int[V];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[startVertex] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>(V, Comparator.comparingInt(node -> node.weight));
        pq.add(new Node(startVertex, 0));
        while (!pq.isEmpty()) {
            int currentVertex = pq.poll().vertex;
            for (Node neighbor : adj.get(currentVertex)) {
                int newDist = distance[currentVertex] + neighbor.weight;
                if (newDist < distance[neighbor.vertex]) {
                    distance[neighbor.vertex] = newDist;
                    pq.add(new Node(neighbor.vertex, newDist));
                }
            }
        }
        for (int i = 0; i < V; i++) {
            System.out.println(i + "\t" + distance[i]);
        }
    }

    static class Node {
        int vertex;
        int weight;

        public Node(int vertex, int weight) {
            this.vertex = vertex;
            this.weight = weight;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of vertices: ");
        int V = scanner.nextInt();
        System.out.print("Enter the number of edges: ");
        int E = scanner.nextInt();
        Graph graph = new Graph(V);

        System.out.println("Enter edge details (source destination weight):");
        for (int i = 0; i < E; i++) {
            int source = scanner.nextInt();
            int destination = scanner.nextInt();
            int weight = scanner.nextInt();
            graph.addEdge(source, destination, weight);
        }

        System.out.print("Enter the starting vertex for Dijkstra's algorithm: ");
        int source = scanner.nextInt();

        graph.dijkstra(source);

        scanner.close();
    }
}


// Heap Sort

import java.util.Scanner;

class HeapSort {
    static void heapify(int a[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && a[left] > a[largest])
            largest = left;
        if (right < n && a[right] > a[largest])
            largest = right;
        if (largest != i) {
            int temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
            heapify(a, n, largest);
        }
    }

    static void heapSort(int a[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(a, n, i);

        for (int i = n - 1; i >= 0; i--) {
            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;

            heapify(a, i, 0);
        }
    }

    static void printArr(int a[], int n) {
        for (int i = 0; i < n; ++i)
            System.out.print(a[i] + " ");
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        
        int a[] = new int[n];
        
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        scanner.close();

        System.out.println("Original Array:");
        printArr(a, n);

        heapSort(a, n);

        System.out.println("\nSorted Array:");
        printArr(a, n);
    }
}

// K Aray

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int capacity = 100;
        int[] arr = new int[capacity];
        System.out.println("Enter the number of elements in the array (up to 100):");
        int n = scanner.nextInt();
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println("Enter the value of k for the k-ary heap:");
        int k = scanner.nextInt();
        buildHeap(arr, n, k);
        System.out.println("Built Heap: ");
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
        System.out.println("Enter the element to insert into the heap:");
        int element = scanner.nextInt();
        insert(arr, n, k, element);
        n++;
        System.out.println("Heap after insertion of " + element + ": ");
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
        System.out.println("Extracted max is " + extractMax(arr, n, k));
        n--;
        System.out.println("\n\nHeap after extract max: ");
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
        
        scanner.close();
    }

    public static void buildHeap(int[] arr, int n, int k) {
        for (int i = (n - 1) / k; i >= 0; i--)
            restoreDown(arr, n, i, k);
    }

    public static void insert(int[] arr, int n, int k, int elem) {
        arr[n - 1] = elem;
        restoreUp(arr, n - 1, k);
    }

    public static int extractMax(int[] arr, int n, int k) {
        int max = arr[0];
        arr[0] = arr[n - 1];
        restoreDown(arr, n - 1, 0, k);
        return max;
    }

    public static void restoreDown(int[] arr, int len, int index, int k) {
        int[] child = new int[k + 1];
        while (true) {
            for (int i = 1; i <= k; i++)
                child[i] = (k * index + i) < len ? (k * index + i) : -1;
            int maxChild = -1, maxChildIndex = 0;
            for (int i = 1; i <= k; i++) {
                if (child[i] != -1 && arr[child[i]] > maxChild) {
                    maxChildIndex = child[i];
                    maxChild = arr[child[i]];
                }
            }
            if (maxChild == -1)
                break;
            if (arr[index] < arr[maxChildIndex])
                swap(arr, index, maxChildIndex);
            index = maxChildIndex;
        }
    }

    public static void restoreUp(int[] arr, int index, int k) {
        int parent = (index - 1) / k;
        while (parent >= 0) {
            if (arr[index] > arr[parent]) {
                swap(arr, index, parent);
                index = parent;
                parent = (index - 1) / k;
            } else
                break;
        }
    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}


// Recover the Binary Tree

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


// Vertical Order Traversal

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


// Views of Tree

import java.util.*;

class Node {
    int data, hd;
    Node left, right;

    public Node(int data) {
        this.data = data;
        left = right = null;
        this.hd = Integer.MAX_VALUE;
    }
}

public class Main {
    static Node root;
    private List<Integer> path1 = new ArrayList<>();
    private List<Integer> path2 = new ArrayList<>();

    static Node build(String s[]) {
        if (s[0].equals("N") || s.length == 0) {
            return null;
        }
        Node root = new Node(Integer.parseInt(s[0]));
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        int i = 1;
        while (!q.isEmpty() && i < s.length) {
            Node curr = q.poll();
            String cval = s[i];
            if (!cval.equals("N")) {
                int h = Integer.parseInt(cval);
                curr.left = new Node(h);
                q.add(curr.left);
            }
            i++;
            if (i >= s.length)
                break;
            cval = s[i];
            if (!cval.equals("N")) {
                int h = Integer.parseInt(cval);
                curr.right = new Node(h);
                q.add(curr.right);
            }
            i++;
        }
        return root;
    }

    void rightView(Node root) {
        if (root == null) {
            return;
        }
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node curr = q.peek();
                q.remove();
                if (i == n - 1) {
                    System.out.print(curr.data + " ");
                }
                if (curr.left != null) {
                    q.add(curr.left);
                }
                if (curr.right != null) {
                    q.add(curr.right);
                }
            }
        }
    }

    void leftView(Node root) {
        if (root == null)
            return;
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int n = queue.size();
            for (int i = 1; i <= n; i++) {
                Node temp = queue.poll();
                if (i == 1) {
                    System.out.print(temp.data + " ");
                }
                if (temp.left != null)
                    queue.add(temp.left);
                if (temp.right != null)
                    queue.add(temp.right);
            }
        }
    }

    static class QueueObj {
        Node node;
        int hd;

        QueueObj(Node node, int hd) {
            this.node = node;
            this.hd = hd;
        }
    }

    static void topView(Node root) {
        if (root == null) {
            return;
        }
        Queue<QueueObj> q = new LinkedList<>();
        Map<Integer, Integer> map = new HashMap<>();
        int min = 0;
        int max = 0;
        q.add(new QueueObj(root, 0));
        while (!q.isEmpty()) {
            QueueObj curr = q.poll();
            if (!map.containsKey(curr.hd)) {
                map.put(curr.hd, curr.node.data);
            }
            if (curr.node.left != null) {
                min = Math.min(min, curr.hd - 1);
                q.add(new QueueObj(curr.node.left, curr.hd - 1));
            }
            if (curr.node.right != null) {
                max = Math.max(max, curr.hd + 1);
                q.add(new QueueObj(curr.node.right, curr.hd + 1));
            }
        }
        for (; min <= max; min++) {
            System.out.print(map.get(min) + " ");
        }
    }

    static void bottomView(Node root) {
        if (root == null)
            return;
        int hd = 0;
        Map<Integer, Integer> map = new TreeMap<>();
        Queue<Node> queue = new LinkedList<>();
        root.hd = hd;
        queue.add(root);
        while (!queue.isEmpty()) {
            Node temp = queue.remove();
            hd = temp.hd;
            map.put(hd, temp.data);
            if (temp.left != null) {
                temp.left.hd = hd - 1;
                queue.add(temp.left);
            }
            if (temp.right != null) {
                temp.right.hd = hd + 1;
                queue.add(temp.right);
            }
        }
        for (Map.Entry<Integer, Integer> me : map.entrySet()) {
            System.out.print(me.getValue() + " ");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i;
        Main ob = new Main();
        String s[] = sc.nextLine().split(" ");
        root = build(s);
        ob.rightView(root);
        System.out.println();
        ob.leftView(root);
        System.out.println();
        topView(root);
        System.out.println();
        bottomView(root);
    }
}


// Winner Algorithms

import java.util.*;

public class WinnerTree {
    private int[] tree;
    private int[] players;

    public WinnerTree(int[] players) {
        this.players = players;
        int n = players.length;
        int treeSize = 1;
        while (treeSize < n) {
            treeSize *= 2;
        }
        tree = new int[2 * treeSize - 1];
        Arrays.fill(tree, -1);
        for (int i = 0; i < n; i++) {
            tree[treeSize - 1 + i] = i;
        }
        build(0, 0, treeSize - 1);
    }

    private void build(int node, int left, int right) {
        if (left == right) return;
        int mid = (left + right) / 2;
        build(2 * node + 1, left, mid);
        build(2 * node + 2, mid + 1, right);
        tree[node] = players[tree[2 * node + 1]] <= players[tree[2 * node + 2]] ? tree[2 * node + 1] : tree[2 * node + 2];
    }

    public int getWinner() {
        return tree[0];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of players: ");
        int numPlayers = scanner.nextInt();
        int[] players = new int[numPlayers];

        System.out.println("Enter the scores of players:");
        for (int i = 0; i < numPlayers; i++) {
            players[i] = scanner.nextInt();
        }

        WinnerTree winnerTree = new WinnerTree(players);
        int winnerIndex = winnerTree.getWinner();
        System.out.println("The player with the highest score is at index: " + winnerIndex);
        System.out.println("The score of the winning player is: " + players[winnerIndex]);

        scanner.close();
    }
}
