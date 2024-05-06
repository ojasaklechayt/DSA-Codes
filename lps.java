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
        String s = "bbbab";
        System.out.println("Length of Longest Palindromic Subsequence: " + lps(s));
    }
}
