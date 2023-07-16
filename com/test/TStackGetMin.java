import java.util.Scanner;

public class TStackGetMin {
    public static void main(String[] args) {
        StackGetMin stackGetMin = new StackGetMin();
        try (Scanner scanner = new Scanner(System.in)) {
            int num = scanner.nextInt();
            int val = 0;
            for (int i = 0; i < num; i++) {
                val = scanner.nextInt();
                stackGetMin.push(val);
            }
        }
        int min = stackGetMin.getMin();
        System.out.printf(String.valueOf(min));
    }
}
