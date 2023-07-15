
import java.util.Stack;

public class QueueByStack {
    private final Stack<Integer> stackPush;
    private final Stack<Integer> stackPop;
    public QueueByStack(){
        this.stackPush = new Stack<>();
        this.stackPop = new Stack<>();

    }

    private void push_to_pop(){
        if (stackPop.empty()){
            while (!stackPush.empty()){
                stackPop.push(stackPush.pop());
            }
        }
    }

    public void add(int inp){
        stackPush.push(inp);
        push_to_pop();
    }
    public int poll(){
        if (stackPush.empty()&&stackPop.empty()) {
            throw new RuntimeException("Queue is empty");
        }
        push_to_pop();
        return stackPop.pop();
    }
    public int peek(){
        if (stackPush.empty()&&stackPop.empty()) {
            throw new RuntimeException("Queue is empty");
        }
        push_to_pop();
        return stackPop.pop();
    }
}
