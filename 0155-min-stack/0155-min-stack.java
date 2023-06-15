class MinStack {
    Stack<Integer> stack;
    Stack<Integer> minS;

    public MinStack() {
        stack = new Stack<>();
        minS = new Stack<>();
    }

    public void push(int x) {

        if (stack.isEmpty()) {
            stack.push(x);
            minS.push(x);
        } else {
            stack.push(x);
            if (x <= minS.peek()) minS.push(x);
        }
    }

    public void pop() {
        int sp = stack.peek();
        int mp = minS.peek();
        if (sp == mp) {
            stack.pop();
            minS.pop();
        } else {
            stack.pop();
        }


    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return minS.peek();
    }
}



