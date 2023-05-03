//#include <iostream>
//#include <stack>
//#include <string>
//#include <cmath>
//using namespace std;
//
//
//bool isDigit(char c) {
//    return (c >= '0' && c <= '9') || c == '.';
//}
//
//
//bool isLeftParen(char c) {
//    return c == '(';
//}
//
//
//bool isRightParen(char c) {
//    return c == ')';
//}
//
//
//bool isOperator(char c) {
//    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
//}
//
//
//int comparePriority(char op1, char op2) {
//    if (op1 == '^') {
//        if (op2 == '^') {
//            return 0;
//        }
//        else {
//            return 1;
//        }
//    }
//    if (op1 == '*' || op1 == '/') {
//        if (op2 == '^') {
//            return -1;
//        }
//        else if (op2 == '*' || op2 == '/') {
//            return 0;
//        }
//        else {
//            return 1;
//        }
//    }
//    if (op1 == '+' || op1 == '-') {
//        if (op2 == '+' || op2 == '-') {
//            return 0;
//        }
//        else {
//            return -1;
//        }
//    }
//}
//
//
//double calculate(double num1, double num2, char op) {
//    switch (op) {
//    case '+': 
//        return num1 + num2;
//    case '-': 
//        return num1 - num2;
//    case '*': 
//        return num1 * num2;
//    case '/': 
//        return num1 / num2;
//    case '^': 
//        return pow(num1, num2);
//    default: 
//        return 0;
//    }
//}
//
//
//double evaluate(string expression) {
//    stack<double> numbers; 
//    stack<char> operators; 
//    for (int i = 0; i < expression.length(); i++) {
//        char c = expression[i];
//        if (isDigit(c)) { 
//            double num = 0;
//            int dot = -1; 
//            while (i < expression.length() && (isDigit(c))) { 
//                if (c == '.') dot = 0; 
//                else {
//                    num = num * 10 + (c - '0'); 
//                    if (dot >= 0) dot++; 
//                }
//                i++;
//                c = expression[i]; 
//            }
//            i--; 
//            if (dot > 0) num /= pow(10, dot); 
//            numbers.push(num); 
//        }
//        else if (isLeftParen(c)) { 
//            operators.push(c); 
//        }
//        else if (isRightParen(c)) { 
//            while (!operators.empty() && !isLeftParen(operators.top())) { 
//                double num2 = numbers.top(); 
//                numbers.pop();
//                double num1 = numbers.top(); 
//                numbers.pop();
//                char op = operators.top(); 
//                operators.pop();
//                numbers.push(calculate(num1, num2, op));
//            }
//            if (!operators.empty()) operators.pop(); 
//        }
//        else if (isOperator(c)) { 
//            while (!operators.empty() && !isLeftParen(operators.top()) && comparePriority(c, operators.top()) <= 0) {
//                double num2 = numbers.top(); 
//                numbers.pop();
//                double num1 = numbers.top(); 
//                numbers.pop();
//                char op = operators.top(); 
//                operators.pop();
//                numbers.push(calculate(num1, num2, op));
//            }
//            operators.push(c); 
//        }
//    }
//    while (!operators.empty()) { 
//        double num2 = numbers.top(); numbers.pop();
//        double num1 = numbers.top(); numbers.pop();
//        char op = operators.top(); operators.pop();
//        numbers.push(calculate(num1, num2, op));
//    }
//    return numbers.top(); 
//}
//
//int main() {
//    string expression = "5 * (3 + 4)";
//    cout << evaluate(expression) << endl;
//    return 0;
//}