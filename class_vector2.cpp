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
int Vector2::get_y(/* const Vector2& vector_from */) const {
  // const Vector2* this = &vector_from;
  return this->y_;
}

// Определение метода класса Vector2
void Vector2::set_y(/* Vector2& vector_to, */ int y) {
  // Vector2* this = &vector_to;
  this->y_ = y;
}

// Функция, возвращающая новый объект,
// равный векторной сумме двух ее аргументов
Vector2 sum(const Vector2& arg1, const Vector2& arg2) {
  Vector2 res(arg1.get_x() + arg2.get_x(),
              arg1.get_y() + arg2.get_y());
  return res; // возможна NRVO
}

// Оператор "a + b", возвращающий новый объект,
// равный векторной сумме аргументов a и b
Vector2 operator + (const Vector2& arg1, const Vector2& arg2) {
  // скопировано тело функции sum
  Vector2 res(arg1.get_x() + arg2.get_x(),
              arg1.get_y() + arg2.get_y());
  return res; // возможна NRVO
}

// Функция, возвращающая сам первый аргумент,
// увеличенный на значение второго аргумента
Vector2& add(Vector2& arg1, const Vector2& arg2) {
  arg1.set_x(arg1.get_x() + arg2.get_x());
  arg1.y_ += arg2.y_; // если бы поле не было скрыто
  return arg1;
}

// Оператор "a += b", возвращающий сам аргумент a,
// увеличенный на значение аргумента b
Vector2& operator += (Vector2& arg1, const Vector2& arg2) {
  // скопировано тело функции add
  arg1.set_x(arg1.get_x() + arg2.get_x());
  arg1.y_ += arg2.y_; // если бы поле не было скрыто
  return arg1;
}

// Метод класса, возвращающий текущий объект,
// увеличенный на значение аргумента
Vector2& Vector2::add(/* Vector2& vector_to, */ const Vector2& arg) {
  // Vector2* this = &vector_to;
  this->x_ += arg.x_;
  this->y_ += arg.y_;
  return *this;
}

// Оператор класса, возвращающий текущий объект,
// увеличенный на значение аргумента
Vector2& Vector2::operator+=(/* Vector2& vector_to, */ const Vector2& arg) {
  // Vector2* this = &vector_to;
  // скопировано тело метода Vector2::add
  this->x_ += arg.x_;
  this->y_ += arg.y_;
  return *this;
}
