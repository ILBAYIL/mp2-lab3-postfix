#include "postfix.h"
#include <cctype>
#include <stdexcept>
#include <stack>
#include <sstream>

using namespace std;

// Конструктор
TPostfix::TPostfix() : infix(""), postfix("") {}

// Установка инфиксного выражения
void TPostfix::SetInfix(const string& expr)
{
    for (char c : expr) {
        if (!IsValidCharacter(c) && !isspace(c)) {
            throw invalid_argument("Invalid character in expression.");
        }
    }
    infix = expr;
}

// Получение инфиксного выражения
string TPostfix::GetInfix() const
{
    return infix;
}

// Получение постфиксного выражения
string TPostfix::GetPostfix() const
{
    return postfix;
}

// Преобразование инфиксного выражения в постфиксное
void TPostfix::ToPostfix()
{
    stack<char> operators;  // Стек для операторов
    stringstream result;  // Постфиксное выражение

    for (char c : infix) {
        if (isalnum(c)) {  // Если символ - операнд (буква или цифра)
            result << c;
        }
        else if (IsOperator(c)) {  // Если символ - оператор
            while (!operators.empty() && Precedence(operators.top()) >= Precedence(c)) {
                result << operators.top();
                operators.pop();
            }
            operators.push(c);
        }
        else if (c == '(') {  // Открывающая скобка
            operators.push(c);
        }
        else if (c == ')') {  // Закрывающая скобка
            while (!operators.empty() && operators.top() != '(') {
                result << operators.top();
                operators.pop();
            }
            if (operators.empty() || operators.top() != '(') {
                throw invalid_argument("Mismatched parentheses.");
            }
            operators.pop();
        }
    }

    // Снимаем все операторы с оставшегося стека
    while (!operators.empty()) {
        result << operators.top();
        operators.pop();
    }

    postfix = result.str();
}

// Вычисление результата постфиксного выражения
double TPostfix::Calculate()
{
    stack<double> operands;  // Стек для операндов

    for (char c : postfix) {
        if (isalnum(c)) {  // Если символ - операнд
            operands.push(1.0);  // Для простоты предполагаем, что переменные равны 1.0
        }
        else if (IsOperator(c)) {  // Если символ - оператор
            if (operands.size() < 2) {
                throw invalid_argument("Not enough operands.");
            }
            double b = operands.top(); operands.pop();
            double a = operands.top(); operands.pop();
            switch (c) {
            case '+': operands.push(a + b); break;
            case '-': operands.push(a - b); break;
            case '*': operands.push(a * b); break;
            case '/':
                if (b == 0) {
                    throw invalid_argument("Division by zero.");
                }
                operands.push(a / b);
                break;
            default:
                throw invalid_argument("Unknown operator.");
            }
        }
    }

    if (operands.size() != 1) {
        throw invalid_argument("Invalid postfix expression.");
    }

    return operands.top();  // Возвращаем результат
}

// Проверка, является ли символ допустимым (операндом или оператором)
bool TPostfix::IsValidCharacter(char c)
{
    return isalnum(c) || IsOperator(c) || c == '(' || c == ')';
}

// Проверка, является ли символ оператором
bool TPostfix::IsOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Определение приоритета оператора
int TPostfix::Precedence(char c)
{
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;  // Для не-операторов
}
