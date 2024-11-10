#ifndef POSTFIX_H
#define POSTFIX_H

#include <string>
#include <stdexcept>

class TPostfix
{
public:
    TPostfix();  // Конструктор

    // Установка инфиксного выражения
    void SetInfix(const std::string& expr);

    // Получение инфиксного выражения
    std::string GetInfix() const;

    // Получение постфиксного выражения
    std::string GetPostfix() const;

    // Преобразование инфиксного выражения в постфиксное
    void ToPostfix();

    // Вычисление результата постфиксного выражения
    double Calculate();

private:
    std::string infix;   // Инфиксное выражение
    std::string postfix; // Постфиксное выражение

    // Проверка, является ли символ допустимым (операндом или оператором)
    bool IsValidCharacter(char c);

    // Проверка, является ли символ оператором
    bool IsOperator(char c);

    // Определение приоритета оператора
    int Precedence(char c);

};

#endif // POSTFIX_H
