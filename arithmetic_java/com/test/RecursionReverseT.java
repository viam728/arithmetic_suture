import java.util.Scanner;
import java.util.Stack;

public class RecursionReverseT {
    public static void main(String[] args) {
        // RecursionReverse recursionReverse = new RecursionReverse(); //这里涉及static方法的使用,即static属于类本身,不属于其实例
        Stack<Integer> stack = new Stack<>();
        try (
        Scanner scanner = new Scanner(System.in)) {
            int num = scanner.nextInt();

            for (int i = 0; i < num; i++) {
                stack.push(scanner.nextInt());
            }
        }
        RecursionReverse.reverseStackElement(stack);
        System.out.printf(stack.toString());
    }
}
