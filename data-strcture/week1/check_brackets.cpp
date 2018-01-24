#include <iostream>
#include <stack>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::stack;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    string text;
    getline(cin, text);
   
    stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        Bracket bra(next, position);
        

        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(bra); 
            // Process opening bracket, write your code here

        }

        if (next == ')' || next == ']' || next == '}') {
            if (opening_brackets_stack.empty()) {
                cout<<position+1<<endl;
                return 0;
            }

            bra = opening_brackets_stack.top();
            if ((bra.type == '(' && next == ')') || \
                (bra.type == '[' && next == ']') || \
                (bra.type == '{' && next == '}')) {
                opening_brackets_stack.pop();
            }

            else {
                cout<<position+1<<endl;
                return 0;
            }
            // Process closing bracket, write your code here
        }
    }

    if (opening_brackets_stack.empty()) {
        cout<<"Success"<<endl;
    }

    else {
        cout<<opening_brackets_stack.size() + 1<<endl;
    }
    // Printing answer, write your code here

    return 0;
}
