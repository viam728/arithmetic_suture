import java.util.Scanner;

public class TStackToQueue {
    public static void main(String[] args) {
        QueueByStack queueByStack = new QueueByStack();
        Scanner scanner = new Scanner(System.in);
        int val = 0;
        int inp = scanner.nextInt();
        while (inp>=0){
            scanner.nextInt(val);
            queueByStack.add(val);
            inp --;
        }
    }
}
