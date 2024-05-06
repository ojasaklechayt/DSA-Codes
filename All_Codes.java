// 1. **FibonacciMemoization**:

```java
import java.util.Scanner;

public class FibonacciMemoization {
    public static int fibonacci(int n) {
        int[] memo = new int[n + 1];
        return fibonacciHelper(n, memo);
    }

    private static int fibonacciHelper(int n, int[] memo) {
        if (n <= 1)
            return n;
        if (memo[n] == 0) {
            memo[n] = fibonacciHelper(n - 1, memo) + fibonacciHelper(n - 2, memo);
        }
        return memo[n];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the position of Fibonacci number: ");
        int n = scanner.nextInt();
        System.out.println("Fibonacci number at position " + n + ": " + fibonacci(n));
        scanner.close();
    }
}
```

// 2. **LongestCommonSubsequenceDP**:

```java
import java.util.Scanner;

public class LongestCommonSubsequenceDP {

    // Method to find the length of LCS using dynamic programming
    public static int lcs(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();

        // Create a 2D array to store intermediate results
        int[][] dp = new int[m + 1][n + 1];

        // Fill the dp array iteratively
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                // Base case: if either of the strings is empty, LCS is 0
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                // If the characters at current positions match, include them in LCS
                else if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        // Return the length of LCS from the bottom-right corner of the dp array
        return dp[m][n];
    }

    // Main method to test the implementation
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the first string:");
        String s1 = scanner.nextLine();
        System.out.println("Enter the second string:");
        String s2 = scanner.nextLine();
        System.out.println("Length of LCS: " + lcs(s1, s2));
        scanner.close();
    }
}
```

// 3. **LongestIncreasingSubsequenceMemoization**:

```java
import java.util.Arrays;
import java.util.Scanner;

public class LongestIncreasingSubsequenceMemoization {

    public static int lis(int[] nums) {
        int[] memo = new int[nums.length];
        Arrays.fill(memo, -1);
        return lisHelper(nums, -1, 0, memo);
    }

    private static int lisHelper(int[] nums, int prevIndex, int curIndex, int[] memo) {
        if (curIndex == nums.length) {
            return 0;
        }
        if (memo[curIndex] != -1) {
            return memo[curIndex];
        }
        int taken = 0;
        if (prevIndex == -1 || nums[curIndex] > nums[prevIndex]) {
            taken = 1 + lisHelper(nums, curIndex, curIndex + 1, memo);
        }
        int notTaken = lisHelper(nums, prevIndex, curIndex + 1, memo);
        memo[curIndex] = Math.max(taken, notTaken);
        return memo[curIndex];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        int[] nums = new int[n];

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        System.out.println("Length of Longest Increasing Subsequence: " + lis(nums));

        scanner.close();
    }
}
```

// 4. **LongestBitonicSubsequenceBruteForce**:

```java
import java.util.Scanner;

public class LongestBitonicSubsequenceBruteForce {

    public static int lbs(int[] nums) {
        int maxLength = 0;
        for (int i = 0; i < nums.length; i++) {
            maxLength = Math.max(maxLength, lbsHelper(nums, i, true) + lbsHelper(nums, i, false) - 1);
        }
        return maxLength;
    }

    private static int lbsHelper(int[] nums, int currentIndex, boolean increasing) {
        int maxLength = 0;
        for (int i = currentIndex + 1; i < nums.length; i++) {
            if (increasing && nums[i] > nums[currentIndex]) {
                maxLength = Math.max(maxLength, 1 + lbsHelper(nums, i, increasing));
            } else if (!increasing && nums[i] < nums[currentIndex]) {
                maxLength = Math.max(maxLength, 1 + lbsHelper(nums, i, increasing));
            }
        }
        return maxLength;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        int[] nums = new int[n];
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println("Length of Longest Bitonic Subsequence: " + lbs(nums));
        scanner.close();
    }
}
```

// 5. **LongestPalindromicSubsequenceRecursive**:

```java
import java.util.Scanner;

public class LongestPalindromicSubsequenceRecursive {

    public static int lps(String s) {
        return lpsHelper(s, 0, s.length() - 1);
    }

    private static int lpsHelper(String s, int start, int end) {
        if (start > end)
            return 0;
        if (start == end)
            return 1;
        if (s.charAt(start) == s.charAt(end))
            return 2 + lpsHelper(s, start + 1, end - 1);
        return Math.max(lpsHelper(s, start + 1, end), lpsHelper(s, start, end - 1));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a string:");
        String s = scanner.nextLine();
        System.out.println("Length of Longest Palindromic Subsequence: " + lps(s));
        scanner.close();
    }
}
```

// 6. **SubsetSumRecursive**:

```java
import java.util.Scanner;

public class SubsetSumRecursive {

    public static boolean subsetSum(int[] nums, int target) {
        return subsetSumHelper(nums, nums.length - 1, target);
    }

    private static boolean subsetSumHelper(int[] nums, int index, int target) {
        // Base cases
        if (target == 0) {
            return true; // Subset with sum 0 is always achievable
        }
        if (index < 0 || target < 0) {
            return false; // If we have exhausted all elements or target becomes negative
        }
        
        // If the current element is greater than the target, we skip it
        if (nums[index] > target) {
            return subsetSumHelper(nums, index - 1, target);
        }
        
        // Two possibilities:
        // 1. Include the current element and check if the subset sum is achievable
        // 2. Exclude the current element and check if the subset sum is achievable
        return subsetSumHelper(nums, index - 1, target - nums[index]) || subsetSumHelper(nums, index - 1, target);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        int[] nums = new int[n];
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.print("Enter the target sum: ");
        int target = scanner.nextInt();
        System.out.println("Subset with sum " + target + " found: " + subsetSum(nums, target));
        scanner.close();
    }
}
```

Continuing with the updates in the next message.

// 7. **KarayHeap**:

```java
import java.util.Scanner;

public class KarayHeap {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.print("Enter the value of k: ");
        int k = scanner.nextInt();

        buildheap(arr, n, k);

        System.out.println("Built heap: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }

        System.out.print("\nEnter the element to insert: ");
        int element = scanner.nextInt();
        insert(arr, n, k, element);
        n++;

        System.out.println("Heap after insertion of " + element + ": ");
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
        scanner.close();
    }

    public static void buildheap(int[] arr, int n, int k) {
        for (int i = (n - 1) / k; i >= 0; i--)
            restoredown(arr, n, i, k);
    }

    public static void insert(int[] arr, int n, int k, int elem) {
        arr[n - 1] = elem;
        restoreup(arr, n - 1, k);
    }

    public static int extractmax(int[] arr, int n, int k) {
        int max = arr[0];
        arr[0] = arr[n - 1];
        restoredown(arr, n - 1, 0, k);
        return max;
    }

    public static void restoredown(int[] arr, int len, int index, int k) {
        int[] child = new int[k + 1];
        while (true) {
            for (int i = 1; i <= k; i++)
                child[i] = (k * index + i) < len ? (k * index + i) : -1;

            int maxchild = -1, maxchildindex = 0;

            for (int i = 1; i <= k; i++) {
                if (child[i] != -1 && arr[child[i]] > maxchild) {
                    maxchildindex = child[i];
                    maxchild = arr[child[i]];
                }
            }

            if (maxchild == -1)
                break;

            if (arr[index] < arr[maxchildindex])
                swap(arr, index, maxchildindex);

            index = maxchildindex;
        }
    }

    public static void restoreup(int[] arr, int index, int k) {
        int parent = (index - 1) / k;
        while (parent >= 0) {
            if (arr[index] > arr[parent]) {
                swap(arr, index, parent);
                index = parent;
                parent = (index - 1) / k;
            } else {
                break;
            }
        }
    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
```

 // 8. **Boundary Traversal**:

```java
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

public class BoundaryTraversal {
    static Node root;

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
            System

.out.print(node.data + " ");
            printBoundaryLeft(node.right);
        }
        // Do nothing if it is a leaf node
    }

    // Function to print the right boundary of the binary tree
    void printBoundaryRight(Node node) {
        if (node == null)
            return;
        if (node.right != null) {
            // Printing non-leaf right child node's data
            printBoundaryRight(node.right);
            System.out.print(node.data + " ");
        } else if (node.left != null) {
            // If right child is null, print the left child node's data
            printBoundaryRight(node.left);
            System.out.print(node.data + " ");
        }
        // Do nothing if it is a leaf node
    }

    // Function to print the boundary traversal of the binary tree
    void printBoundary(Node node) {
        if (node == null)
            return;
        // Printing the root node's data
        System.out.print(node.data + " ");
        // Printing the left boundary (except the leaf node)
        printBoundaryLeft(node.left);
        // Printing the leaf nodes
        printLeaves(node.left);
        printLeaves(node.right);
        // Printing the right boundary (except the leaf node)
        printBoundaryRight(node.right);
    }

    public static void main(String args[]) {
        BoundaryTraversal tree = new BoundaryTraversal();
        Scanner scanner = new Scanner(System.in);
        root = buildTree(scanner);
        System.out.println("Boundary Traversal of binary tree:");
        tree.printBoundary(root);
        scanner.close();
    }
}
```

// 1. **Priority Queue using Doubly Linked List**:

```java
import java.util.Scanner;

class Node {
    int data;
    Node next, prev;

    public Node(int data) {
        this.data = data;
        this.next = this.prev = null;
    }
}

public class PriorityQueueDLL {
    Node head;

    public PriorityQueueDLL() {
        head = null;
    }

    public void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        if (data < head.data) {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
            return;
        }
        Node current = head;
        while (current.next != null && current.next.data <= data) {
            current = current.next;
        }
        newNode.next = current.next;
        if (current.next != null) {
            current.next.prev = newNode;
        }
        current.next = newNode;
        newNode.prev = current;
    }

    public int peek() {
        if (head != null) {
            return head.data;
        }
        return -1; // Or throw an exception
    }

    public int poll() {
        if (head != null) {
            int data = head.data;
            head = head.next;
            if (head != null) {
                head.prev = null;
            }
            return data;
        }
        return -1; // Or throw an exception
    }

    public boolean isEmpty() {
        return head == null;
    }

    public static void main(String[] args) {
        PriorityQueueDLL pq = new PriorityQueueDLL();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = scanner.nextInt();
        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            int data = scanner.nextInt();
            pq.insert(data);
        }
        System.out.println("Priority Queue:");
        while (!pq.isEmpty()) {
            System.out.print(pq.poll() + " ");
        }
        scanner.close();
    }
}
```

// 2. **Sort the bitonic Doubly Linked List**:

```java
import java.util.Scanner;

class Node {
    int data;
    Node prev, next;

    public Node(int data) {
        this.data = data;
        this.prev = this.next = null;
    }
}

public class SortBitonicDLL {
    public static Node merge(Node left, Node right) {
        if (left == null)
            return right;
        if (right == null)
            return left;

        if (left.data <= right.data) {
            left.next = merge(left.next, right);
            left.next.prev = left;
            left.prev = null;
            return left;
        } else {
            right.next = merge(left, right.next);
            right.next.prev = right;
            right.prev = null;
            return right;
        }
    }

    public static Node findMid(Node node) {
        Node fast = node, slow = node;
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }

    public static Node bitonicSort(Node head) {
        if (head == null || head.next == null)
            return head;

        Node mid = findMid(head);
        Node nextOfMid = mid.next;
        mid.next = null;

        Node left = bitonicSort(head);
        Node right = bitonicSort(nextOfMid);

        return merge(left, right);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = scanner.nextInt();
        System.out.println("Enter elements:");
        Node head = null;
        Node tail = null;
        for (int i = 0; i < n; i++) {
            int data = scanner.nextInt();
            Node newNode = new Node(data);
            if (head == null) {
                head = tail = newNode;
            } else {
                tail.next = newNode;
                newNode.prev = tail;
                tail = newNode;
            }
        }
        head = bitonicSort(head);
        System.out.println("Sorted Bitonic Doubly Linked List:");
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        scanner.close();
    }
}
```

// 3. **Max Sliding Window**:

```java
import java.util.*;

public class MaxSlidingWindow {
    public static int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0 || k <= 0)
            return new int[0];

        int n = nums.length;
        int[] result = new int[n - k + 1];
        Deque<Integer> deque = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            while (!deque.isEmpty() && deque.peekFirst() < i - k + 1)
                deque.pollFirst();

            while (!deque.isEmpty() && nums[deque.peekLast()] < nums[i])
                deque.pollLast();

            deque.offerLast(i);

            if (i >= k - 1)
                result[i - k + 1] = nums[deque.peekFirst()];
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = scanner.nextInt();
        System.out.println("Enter elements:");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.print("Enter window size: ");
        int k = scanner.nextInt();
        int[] result = maxSlidingWindow(nums, k);
        System.out.println("Maximums in sliding window:");
        for (int num : result) {
            System.out.print(num + " ");
        }
        scanner.close();
    }
}
```

// 4. **Merge Sort for Doubly Linked List**:

```java
import java.util.Scanner;

class Node {
    int data;
    Node prev, next;

    public Node(int data) {
        this.data = data;
        this.prev = this.next = null;
    }
}

public class MergeSortDLL {
    public Node getMiddle(Node head) {
        if (head == null)
            return head;

        Node slow = head, fast = head;

        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public Node merge(Node left, Node right) {
        if (left == null)
            return right;
        if (right == null)
            return left;

        if (left.data < right.data) {
            left.next = merge(left.next, right);
            left.next.prev = left;
            left

.prev = null;
            return left;
        } else {
            right.next = merge(left, right.next);
            right.next.prev = right;
            right.prev = null;
            return right;
        }
    }

    public Node mergeSort(Node head) {
        if (head == null || head.next == null)
            return head;

        Node middle = getMiddle(head);
        Node nextOfMiddle = middle.next;

        middle.next = null;

        Node left = mergeSort(head);
        Node right = mergeSort(nextOfMiddle);

        return merge(left, right);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = scanner.nextInt();
        System.out.println("Enter elements:");
        Node head = null;
        Node tail = null;
        for (int i = 0; i < n; i++) {
            int data = scanner.nextInt();
            Node newNode = new Node(data);
            if (head == null) {
                head = tail = newNode;
            } else {
                tail.next = newNode;
                newNode.prev = tail;
                tail = newNode;
            }
        }
        MergeSortDLL mergeSortDLL = new MergeSortDLL();
        head = mergeSortDLL.mergeSort(head);
        System.out.println("Sorted Doubly Linked List:");
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        scanner.close();
    }
}
```

// 5. **Sort without Extra Space**:

```java
import java.util.Scanner;

public class SortWithoutExtraSpace {
    public void sort(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            while (nums[i] != i + 1) {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = scanner.nextInt();
        System.out.println("Enter elements:");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        SortWithoutExtraSpace sortWithoutExtraSpace = new SortWithoutExtraSpace();
        sortWithoutExtraSpace.sort(nums);
        System.out.println("Sorted Array without Extra Space:");
        for (int num : nums) {
            System.out.print(num + " ");
        }
        scanner.close();
    }
}
```