#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
    string expression;
    TPostfix postfix;
    double res;

    setlocale(LC_ALL, "Russian");

    cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
    postfix.ToPostfix();
    cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;

    res = postfix.Calculate();
    cout << "Результат вычисления: " << res << endl;

    return 0;
}
