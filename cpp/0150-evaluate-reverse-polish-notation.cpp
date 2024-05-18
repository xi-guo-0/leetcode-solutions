class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        stk.push(0);
        for (auto token : tokens) {
            if (!is_operator(token)) {
                stk.push(stoi(token));
            } else {
                char op = token[0];
                int y = stk.top();
                stk.pop();
                int x = stk.top();
                stk.pop();
                if (op == '+')      x += y;
                else if (op == '-') x -= y;
                else if (op == '*') x *= y;
                else                x /= y;
                
                stk.push(x);
            }
        }
        return stk.top();
    }
    
private:
    bool is_operator(const string &op) {
        return op.size() == 1 && string("+-*/").find(op) != string::npos;
    }
};
