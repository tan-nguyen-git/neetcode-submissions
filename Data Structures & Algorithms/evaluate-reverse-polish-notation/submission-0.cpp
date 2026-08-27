class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(const string& str: tokens){
            if(str == "+"){
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                s.push(first + second);
            }
            else if(str == "-"){
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                s.push(second - first);

            }
            else if(str == "*"){ 
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                s.push(second * first);

        
            }
            else if(str == "/"){
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                s.push(second / first);

            }
            else{
                s.push(std::stoi(str));
            }
        }
        return s.top();
        
    }
};
