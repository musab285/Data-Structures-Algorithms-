// Task 4: Consider you have an expression x=12+13-5(0.5+0.5) +1 which results to 20. Implement a
// stack-based implementation to solve this question via linked lists (linked lists can be single or double)
// and the resulted output must be at the top of the stack. Note that the x and the equal sign must be
// present in the stack and when inserting the top value (20 result) all the values must be present in the
// stack (You can pop and push them accordingly)

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <cmath>

using namespace std;

struct Node {
    string val;
    Node* next;
    Node(const string& v, Node* n = nullptr): val(v), next(n) {}
};

struct Stack {
    Node* head = nullptr;
    void push(const string& s) { head = new Node(s, head); }
    string pop() { if(!head) return ""; Node* t = head; string v = t->val; head = head->next; delete t; return v; }
    string top() const { return head ? head->val : ""; }
    bool empty() const { return head == nullptr; }
    void print() const {
        Node* cur = head;
        while(cur) {
            cout << cur->val << endl;
            cur = cur->next;
        }
    }
};

vector<string> tokenize(const string& s) {
    vector<string> toks;
    string num;
    auto pushNum = [&](){
        if(!num.empty()){ toks.push_back(num); num.clear(); }
    };
    for(size_t i=0;i<s.size();++i){
        char c = s[i];
        if(isdigit(c) || c=='.'){ num.push_back(c); }
        else {
            pushNum();
            if(isspace(c)) continue;
            if(c=='(') {
                if(!toks.empty()){
                    string prev = toks.back();
                    if(!prev.empty() && (isdigit(prev.back()) || prev==")")) toks.push_back("*");
                }
                toks.push_back("(");
            } else {
                string t(1,c);
                toks.push_back(t);
            }
        }
    }
    pushNum();
    return toks;
}

int prec(const string& op){
    if(op=="+"||op=="-") return 1;
    if(op=="*"||op=="/") return 2;
    return 0;
}

bool isOp(const string& s){ return s=="+"||s=="-"||s=="*"||s=="/"; }

vector<string> toRPN(const vector<string>& toks){
    vector<string> out;
    vector<string> ops;
    for(auto& t: toks){
        if(t.empty()) continue;
        if(isdigit(t[0]) || (t.size()>1 && t[0]=='.') || (t.size()>1 && t[0]=='-' && isdigit(t[1]))) out.push_back(t);
        else if(isOp(t)){
            while(!ops.empty() && isOp(ops.back()) && prec(ops.back())>=prec(t)){
                out.push_back(ops.back()); ops.pop_back();
            }
            ops.push_back(t);
        } else if(t=="(") ops.push_back(t);
        else if(t==")"){
            while(!ops.empty() && ops.back()!="("){ out.push_back(ops.back()); ops.pop_back(); }
            if(!ops.empty() && ops.back()=="(") ops.pop_back();
        } else out.push_back(t);
    }
    while(!ops.empty()){ out.push_back(ops.back()); ops.pop_back(); }
    return out;
}

double evalRPN(const vector<string>& rpn){
    vector<double> st;
    for(auto& t: rpn){
        if(isOp(t)){
            if(st.size()<2) return 0;
            double b = st.back(); st.pop_back();
            double a = st.back(); st.pop_back();
            if(t=="+") st.push_back(a+b);
            else if(t=="-") st.push_back(a-b);
            else if(t=="*") st.push_back(a*b);
            else if(t=="/") st.push_back(a/b);
        } else {
            st.push_back(stod(t));
        }
    }
    return st.empty() ? 0 : st.back();
}

string formatDouble(double v){
    double iv;
    if(modf(v, &iv)==0.0) {
        long long vi = static_cast<long long>(iv);
        return to_string(vi);
    }
    ostringstream oss;
    oss << v;
    return oss.str();
}

int main(){
    string expr = "x=12+13-5(0.5+0.5)+1";
    size_t eq = expr.find('=');
    string lhs = expr.substr(0, eq);
    string rhs = expr.substr(eq+1);
    for(char& c: lhs) if(isspace(c)) c = '\0';
    Stack st;
    st.push("x");
    st.push("=");
    vector<string> toks = tokenize(rhs);
    for(auto& t: toks) st.push(t);
    vector<string> rpn = toRPN(toks);
    double result = evalRPN(rpn);
    st.push(formatDouble(result));
    st.print();
    return 0;
}