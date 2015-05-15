// Объявление типа: класс Vector2
class Vector2;

// Определение объектов класса Vector2
// Vector2 v2, *pv2 = new Vector2; // еще нельзя

// Подключение файла с определением типа Vector2
#include "class_vector2.h"

// Определение объектов класса Vector2
Vector2 v2, *pv2 = new Vector2; // теперь можно

// Определение метода класса Vector2
int Vector2::get_y(/* const Vector2& vector_from */) const {
  // const Vector2* this = &vector_from;
  return this->y_;
}

// Определение метода класса Vector2
void Vector2::set_y(/* Vector2& vector_to, */ int y) {
  // Vector2* this = &vector_to;
  this->y_ = y;
}

// Определение конструктора с параметрами
Vector2::Vector2(int x /* = 0 */, int y /* = 0 */)
    // Список инициализации
    : x_(x), y_(y) { // правильно: конструктор инициализирует поля
  // Присваивание значений полям
  // x_ = x; y_ = y; // плохо: поля уже инициализированы
}
