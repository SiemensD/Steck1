
#include <iostream>
#include <stack>

using namespace std;

bool balanced(const string& s) 
{
    stack<char> stack;
    for (char c : s) 
    {
        switch (c) 
        {

        case '(': stack.push(')'); break;
        case '[': stack.push(']'); break;
        case '{': stack.push('}'); break;
        case '<': stack.push('>'); break;

        case ')':
        case ']':
        case '}':
        case '>':
            if (stack.empty() || stack.top() != c) {
                return false;
            }
            stack.pop();
            break;
        default:
            break;
        }
    }
    return stack.empty();
}

void test(const string& s)
{
    cout << '"' << s << "\" " << (balanced(s) ? "yes" : "no") << endl;
}

int main() {
   
    test("({x-y-z}*[x+2y]-(z+4x))");
    test("([x-y-z}*[x+2y)-{z+4x)]");
   
}