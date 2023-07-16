import java.util.Stack;

public class RecursionReverse {
    public static int catchLastElement(Stack<Integer> stack){
        int val=stack.pop();
        if (stack.empty()) {
            return val;
        }else {
            int last = catchLastElement(stack);
            stack.push(val);
            return last;
        }
        
    }
    public static void reverseStackElement(Stack<Integer> stack){
        if (stack.empty()) {
            return;
        }
        int top = catchLastElement(stack);
        reverseStackElement(stack);
        stack.push(top);
    }
}