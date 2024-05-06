import java.util.*;

public class MaxSlidingWindow{
    public static int[] maxSlidingWindow(int[] nums, int k){
        if(nums == null || k <= 0) return new int[0];
        
        int n = nums.length;
        int[] result = new int[n-k+1];
        Deque<Integer> deque = new ArrayDeque<>();
        
        int ri = 0;
        for(int i=0; i<nums.length; i++){
            while(!deque.isEmpty() && deque.peek() < i - k + 1){
                deque.poll();
            }
            
            while(!deque.isEmpty() && nums[deque.peekLast()] < nums[i]){
                deque.pollLast();
            }
            
            deque.offer(i);
            
            if(i>=k-1){
                result[ri++] = nums[deque.peek()];
            }
        }
        return result;
    }
    
    public static void main(String[] args){
        int[] nums = {1,3,-1,-3,5,3,6,7};
        int k = 3;
        int[] result = maxSlidingWindow(nums, k);
        for(int num : result){
            System.out.print(num + " ");
        }
    }
}