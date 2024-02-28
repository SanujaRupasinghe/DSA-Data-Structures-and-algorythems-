public class Recursion {
    public static void main(String[] args) {
        int n = 6;
        System.out.println(fibonacci(n));
    }

    //to find fibonacci
    private static long fibonacci(int n) {
        if (n <= 1) {
            return n;
        }
        long fib = fibonacci(n - 1) + fibonacci(n - 2);
        return fib;
    }
}
