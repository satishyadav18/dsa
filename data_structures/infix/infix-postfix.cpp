//infix to postfix


//Stack for infix
#include<iostream>
using namespace std;
#define max 100

class Stack{
    private:
        int top;
        int stack[max];
    public:
        Stack(){
            top = -1;
        }
        int isEmpty();
        int isFull();
        void push(char);
        void pop();
        void display();
        int peek();
};

int Stack::isEmpty(){
    return top == -1;
}
int Stack::isFull(){
    return top >= max-1;
}
void Stack::push(char val){
    if(isFull()){
        cout<<"Stack overflow"<<endl;
    }
    stack[++top] = val;
    return;
}

void Stack::pop(){
    if(isEmpty()){
        cout<<"Stack underflow"<<endl;
    }
    top --;
}

void Stack::display(){
    if(isEmpty()){
        cout<<"Stack is empty."<<endl;
    }
    cout<<"Stack elements are: "<<endl;
    for(int i=top;i>=0;i--){
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}

int Stack::peek(){
    if(isEmpty()){
        cout<<"Empty"<<endl;
        return -1;
    }
    return stack[top];
}
    


#include<iostream>
//#include<infixstack.cpp>
using namespace std;

char infix[100];
char postfix[100];

int precd(char ch){
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

int isAlphaNum(char ch){
    if(ch >= 'a' && ch <= 'z')
        return 1;
    if(ch >= 'A' && ch <='Z')
        return 1;
    if(ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

int isOperand(char ch){
    if(isAlphaNum(ch))
        return 1;
    else
        return 0;
}

void infixTopostfix(){
    int i = 0, j = 0;
    Stack s;
    bool flag = true;  // flag to check if the expression is balanced

    while(infix[i] != '\0'){
        char ch = infix[i];
        if(isOperand(ch)){
            postfix[j++] = ch;
        }
        else if(ch == '(')
            s.push(ch);
        else if(ch == ')'){
            while(s.peek() != '('){
                postfix[j++] = s.peek();
                s.pop();
            }
            s.pop();
        }
        else if(isOperator(ch)){
            while(!s.isEmpty() && s.peek() != '(' && precd(ch) <= precd(s.peek())){
                postfix[j++] = s.peek();
                s.pop();
            }
            s.push(ch);
        }
        else{
            flag = false;
            cout << " ERROR: INVALID INFIX EXPRESSION" << endl;
            break;
        }
        i++;
    }

    if(flag){
        while(!s.isEmpty()){
            postfix[j++] = s.peek();
            s.pop();
        }
        postfix[j++] = '\0';
    }
    else{
        cout << "ERROR: INVALID EXPRESSION" << endl;
    }

}

int evalPostfix(char postfix[]){
    int i, operand1, operand2, result;
    Stack s;

    for(i=0; postfix[i] != '\0'; i++){
        if(isOperand(postfix[i])){
            s.push(postfix[i] - '0'); //converting character into integer value
        }
        else{
            operand2 = s.peek();
            s.pop();
            operand1 = s.peek();
            s.pop();
            switch(postfix[i]){
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if(operand2 != 0){
                        result = operand1 / operand2;
                    }
                    else{
                        cout << "Error: Division by zero\n";
                        result = 0;
                        break;
                    }
            }
            s.push(result);
        }
    }
    result = s.peek();
    return result;
}

int main(){
    cout << "Enter en infix expression: ";
    cin >> infix;

    infixTopostfix();
    cout << "Postfix Expression : " << postfix << endl;

    int result = evalPostfix(postfix);
    cout << "The result is: " << result <<endl;

    return 0;
}