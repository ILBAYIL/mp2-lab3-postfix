#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix) {
    ASSERT_NO_THROW(TPostfix p);
}

TEST(TPostfix, can_set_infix_expression) {
    TPostfix p;
    ASSERT_NO_THROW(p.SetInfix("a + b * c"));
    EXPECT_EQ(p.GetInfix(), "a + b * c");
}

TEST(TPostfix, can_get_infix_expression) {
    TPostfix p;
    p.SetInfix("a + b");
    EXPECT_EQ(p.GetInfix(), "a + b");  // Проверяем, что инфиксное выражение установлено корректно
}

TEST(TPostfix, can_convert_infix_to_postfix) {
    TPostfix p;
    p.SetInfix("a + b * c");
    p.ToPostfix();  // Преобразуем инфиксное выражение в постфиксное
    EXPECT_EQ(p.GetPostfix(), "abc*+");  // Проверяем, что постфиксное выражение корректное
}

TEST(TPostfix, can_handle_invalid_character_in_infix_expression) {
    TPostfix p;
    ASSERT_THROW(p.SetInfix("a + b # c"), std::invalid_argument);  // Проверка на недопустимый символ
}

TEST(TPostfix, can_calculate_simple_postfix_expression) {
    TPostfix p;
    p.SetInfix("a + b");
    p.ToPostfix();
    // В данном примере предполагаем, что все переменные равны 1.0, поэтому результат должен быть 2.0
    ASSERT_DOUBLE_EQ(p.Calculate(), 2.0);
}

TEST(TPostfix, can_handle_empty_infix_expression) {
    TPostfix p;
    p.SetInfix("");
    ASSERT_NO_THROW(p.ToPostfix());  // Преобразование пустого выражения в постфиксное должно пройти без ошибок
    EXPECT_EQ(p.GetPostfix(), "");  // Пустое выражение в постфиксной форме тоже должно быть пустым
}
