// Task 3: You are developing a calculator application in C++ that needs to handle arithmetic expressions
// entered by the user. The expressions can include the basic arithmetic operators (+, -, *, /) as well as
// parentheses to group operations. How would you convert the infix expression a+b*(c^d-e)^(f+g*h)-i
// to postfix notation.
// Use the class of stack created in Task 01 ( Lab Tasks).

#include <iostream>
#include <string>

using namespace std;

class Stack {
    char data[200];
    int topIndex;
public:
    Stack(): topIndex(-1) {}
    void push(char c) { if (topIndex < 199) data[++topIndex] = c; }
    char pop() { return (topIndex >= 0) ? data[topIndex--] : '\0'; }
    char top() const { return (topIndex >= 0) ? data[topIndex] : '\0'; }
    bool empty() const { return topIndex == -1; }
};

int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPostfix(const string& exp) {
    Stack st;
    string output;
    for (char c : exp) {
        if (isalnum(static_cast<unsigned char>(c))) {
            output.push_back(c);
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') output.push_back(st.pop());
            if (!st.empty() && st.top() == '(') st.pop();
        } else if (isOperator(c)) {
            while (!st.empty() && st.top() != '(' &&
                  (prec(st.top()) > prec(c) || (prec(st.top()) == prec(c) && c != '^'))) {
                output.push_back(st.pop());
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        if (st.top() != '(') output.push_back(st.pop());
        else st.pop();
    }
    return output;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(infix) << endl;
    return 0;
}