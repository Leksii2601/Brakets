#include <iostream>
#include <stack>
#include <string>
#include <Windows.h>
using namespace std;
bool AreBracketsBalanced(const std::string& str) {
    std::stack<char> stack;

    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.empty())
                return false;

            char openBracket = stack.top();
            stack.pop();
            if ((openBracket == '(' && ch != ')') ||
                (openBracket == '{' && ch != '}') ||
                (openBracket == '[' && ch != ']')) {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
	
    string input;
    cout << "Введіть рядок з дужками: ";
    cin >> input;
    bool result = AreBracketsBalanced(input);
    cout << (result ? "Дужки розставлені правильно" : "Дужки розставлені неправильно") << std::endl;
    return 0;
}