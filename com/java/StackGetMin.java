

import java.util.Stack;

public class StackGetMin {
    private Stack<Integer> stackData;
    private Stack<Integer> stackMin;

    public StackGetMin() {
        this.stackData = new Stack<>();
        this.stackMin = new Stack<>();
    }

    public  void push(int num){
        if(this.stackData.empty()){
            this.stackMin.push(num);
        } else if (num<=this.getMin()){
            this.stackMin.push(num);
        }
        this.stackData.push(num);
    }
    public int pop(){
        if (stackData == null) {
            throw new RuntimeException("Stack is empty");
        }
        int val = stackData.pop();

        if (val==this.getMin()){
            this.stackMin.pop();
        }
        return val;
    }

    public Integer getMin() {
        if (stackMin == null) {
            throw new RuntimeException("StackMin is empty");
        }

        return  this.stackMin.peek();
    }
}
