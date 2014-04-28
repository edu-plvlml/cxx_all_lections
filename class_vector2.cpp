// Объявление типа: класс Vector2
class Vector2;

// Определение объектов класса Vector2
// Vector2 v2, *pv2 = new Vector2; // еще нельзя

// Подключение файла с определением типа Vector2
#include "class_vector2.h"

// Определение объектов класса Vector2
Vector2 v2, *pv2 = new Vector2; // теперь можно

// Определение конструктора с параметрами
Vector2::Vector2(int x /* = 1 */, int y /* = 1 */)
    // Список инициализации
    : x_(x), y_(y) { // правильно: конструктор инициализирует поля
  // Присваивание значений полям
  // x_ = x; y_ = y; // плохо: поля уже инициализированы
}

// Определение метода класса Vector2
int Vector2::get_y(/* const Vector3& vector_from */) const {
  // const Vector* this = &vector_from;
  return this->y_;
}

// Определение метода класса Vector2
void Vector2::set_y(/* Vector3& vector_to, */ int y) {
  // Vector* this = &vector_to;
  this->y_ = y;
}
