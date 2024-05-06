import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
        
        System.out.print("Enter the number of elements: ");
        int numElements = scanner.nextInt();
        
        System.out.println("Enter the elements: ");
        for(int i=0; i<numElements; i++){
            int element = scanner.nextInt();
            priorityQueue.add(element);
        }
        
        System.out.println("All elements in the priority queue: ");
        for(Integer element: priorityQueue){
            System.out.println(element);
        }
        
        System.out.println("Removing elements from the priority queue: ");
        while(!priorityQueue.isEmpty()){
            System.out.println("Removing: " + priorityQueue.remove());
        }
        
        scanner.close();
    }
}