
class Solution {
 public:
    bool isValid(string str) {

        stack<char> s;

        for(int i = 0; i < str.size(); i++) {

            char ch = str[i];

            // Opening brackets
            if(ch == '(' || ch == '[' || ch == '{') {
                s.push(ch);
            }
            else {
                // Stack empty hai
                if(s.empty()) {
                    return false;
                }
                char top = s.top();

                // Matching check
                if((top == '(' && ch == ')') ||
                   (top == '[' && ch == ']') ||
                   (top == '{' && ch == '}')) {
                    s.pop();
                }
                else {
                    return false;
                }
            }
        }

        return s.empty();
    }
};