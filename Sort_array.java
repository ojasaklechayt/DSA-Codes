import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input number of elements to add
        System.out.print("Enter the number of elements: ");
        int numElements = scanner.nextInt();

        // Input elements
        System.out.println("Enter the elements:");
        int[] elements = new int[numElements];
        for (int i = 0; i < numElements; i++) {
            elements[i] = scanner.nextInt();
        }

        // Sorting the array
        Arrays.sort(elements);

        // Printing all elements of the sorted array
        System.out.println("All elements sorted:");
        for (int element : elements) {
            System.out.println(element);
        }

        scanner.close();
    }
}
