import java.util.Scanner;

public class QueueByStackT {
    public static void main(String[] args) {
        QueueByStack queueByStack = new QueueByStack();
        try (Scanner scanner = new Scanner(System.in)) {
            int val = 0;
            int inp = scanner.nextInt();
            while (inp>0){
                val = scanner.nextInt();
                queueByStack.add(val);
                inp --;
            }
            System.out.println(String.valueOf(queueByStack.peek()));
            System.out.println(String.valueOf(queueByStack.poll()));
            System.out.println(String.valueOf(queueByStack.peek()));

        }
    }
}
