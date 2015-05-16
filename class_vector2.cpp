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

// Метод класса, возвращающий текущий объект,
// увеличенный на значение аргумента
Vector2& Vector2::add(/* Vector2& vector_to, */ const Vector2& arg) {
  // Vector2* this = &vector_to;
  this->x_ += arg.x_;
  this->y_ += arg.y_;
  return *this;
}

// Оператор "сложение с присваиванием" (a += b) как метод класса,
// возвращающий текущий объект, увеличенный на значение аргумента
Vector2& Vector2::operator+=(/* Vector2& vector_to, */ const Vector2& arg) {
  // Vector2* this = &vector_to;
  // скопировано тело метода Vector2::add
  this->x_ += arg.x_;
  this->y_ += arg.y_;
  return *this;
}

// Функция, возвращающая первый аргумент,
// увеличенный на значение второго аргумента
Vector2& add(Vector2& arg1, const Vector2& arg2) {
  arg1.set_x(arg1.get_x() + arg2.get_x()); // надо бы так
  arg1.y_ += arg2.y_; // можно, т.к. функция дружественная
  return arg1;
}

// Оператор "сложение с присваиванием" (a += b) как функция,
// возвращающая аргумент 1, увеличенный на значение аргумента 2
Vector2& operator += (Vector2& arg1, const Vector2& arg2) {
  // скопировано тело функции add
  arg1.set_x(arg1.get_x() + arg2.get_x()); // надо бы так
  arg1.y_ += arg2.y_; // можно, т.к. функция дружественная
  return arg1;
}

// Функция, возвращающая новый объект,
// равный векторной сумме двух ее аргументов
Vector2 sum(const Vector2& arg1, const Vector2& arg2) {
  Vector2 res = arg1; // результут есть копия первого, ...
  res.add(arg2); // ... увеличенная на значение второго
  return res; // возможна NRVO
}

// Оператор "бинарный плюс" (a + b) как функция, возвращающая
// новый объект, равный векторной сумме двух ее аргументов
Vector2 operator + (const Vector2& arg1, const Vector2& arg2) {
  // скопировано тело функции sum
  Vector2 res = arg1; // результут есть копия первого, ...
  res.add(arg2); // ... увеличенная на значение второго
  return res; // возможна NRVO
}

// Подключение файла c ОПРЕДЕЛЕНИЕМ классов ввода/вывода
#include <iostream>

// Оператор "побитовый сдвиг влево" (a << b), перегруженный для вывода
// на первый аргумент (объект потока вывода) второго аргумента (типа Vector2)
// и возвращаюший первый аргумент для работы цепочки операторов (a << b << c)
std::ostream& operator << (std::ostream& out, const Vector2& vector) {
  out << '(' << vector.get_x() << ", " << vector.get_y() << ')';
  return out;
}
