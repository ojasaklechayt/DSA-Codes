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
