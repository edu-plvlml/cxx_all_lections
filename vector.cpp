#include <cmath>

//------------------------------------------------------------------------------

// Объявление типа: структура Vector3
struct Vector3;

// Определение переменных типа Vector3
// Vector3 v3_x, v3_y, v3_z; // еще нельзя
// Vector3 *pv3 = new Vector3; // еще нельзя
Vector3 *pv3_0 = nullptr;

// Подключение файла с определением Vector3
#include "vector.h"

// Определение переменных типа Vector3
Vector3 v3_x = {1,0,0}, v3_y = {0,1,0}, v3_z = {0,0,1};
Vector3 *pv3 = new Vector3; // теперь можно

// Определения функций
void set_x(Vector3& vector_to, int x) { vector_to.x = x; }
void set_y(Vector3& vector_to, int y) { vector_to.y = y; }
void set_z(Vector3& vector_to, int z) { vector_to.z = z; }

//------------------------------------------------------------------------------

// Определения переменных из области Math
Math::Z Math::x0 = 0;
Math::Z Math::y0 = 0;

// Объявления имен
// using Math::Z; // не нужно
using Math::R;

// Определения функций из области Math
R Math::rad(Z x, Z y) {
  // Math::x0 и Math::y0
  return sqrt( double((x-x0)*(x-x0) + (y-y0)*(y-y0)) );
}

R Math::alpha(Z x, Z y) {
  // Math::x0 и Math::y0
  return atan2( double(y-y0), double(x-x0) );
}

//------------------------------------------------------------------------------

// Определения методов класса Vector2
double Vector2::get_rad() const { return Math::rad(x_, y_); }
double Vector2::get_alpha() const { return Math::alpha(x_, y_); }

// Определение конструктора с параметрами класса Vector2
Vector2::Vector2(int x, int y):
    x_(x), y_(y) { // список инициализации
  // x_ = x; y_ = y; // плохо
}

// Определение конструктора по умолчанию класса Vector2
Vector2::Vector2():
    x_(0), y_(0) {}

// Определение конструктора копирования класса Vector2
Vector2::Vector2(const Vector2& other):
    x_(other.x_), y_(other.y_) {}

// Определение объектов класса Vector2
Vector2* pv2_1 = new Vector2; // с вызовом конструктора по умолчанию
Vector2* pv2_2 = new Vector2(); // с вызовом конструктора по умолчанию
Vector2* pv2_3 = new Vector2(1,1); // с вызовом конструктора с параметрами
Vector2* pv2_4 = new Vector2(*pv2_3); // с вызовом конструктора копирования

Vector2 v2_1; // с вызовом конструктора по умолчанию
Vector2 v2_2(1,1); // с вызовом конструктора с параметрами
Vector2 v2_3 = v2_2; // с вызовом конструктора копирования
Vector2 v2_4(); // а это что?

