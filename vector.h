// Идиома "защита подключения"
#ifndef VECTOR_H_
#define VECTOR_H_

//------------------------------------------------------------------------------

// Объявить область невозможно
// namespace Math;

// Определение области Math
namespace Math {
typedef int Z; // переименование типа
typedef double R; // переименование типа
}

// Расширение области Math
namespace Math {
extern Z x0, y0; // объявление переменныx типа Z
R rad(Z x, Z y), alpha(Z x, Z y); // объявление функций
}

//------------------------------------------------------------------------------

// Объявление типа: структура Vector3
struct Vector3;

// Объявление переменных типа Vector3
extern Vector3 v3_x, v3_y, v3_z, *pv3, *pv3_0;

// Определение типа: структура Vector3
struct Vector3 {
  Math::Z x, y, z; // поля структуры
};

// Определения встраиваемых функций
inline int get_x(const Vector3& vector_from) { return vector_from.x; }
inline int get_y(const Vector3& vector_from) { return vector_from.y; }
inline int get_z(const Vector3& vector_from) { return vector_from.z; }

// Объявления функций
void set_x(Vector3& vector_to, int x);
void set_y(Vector3& vector_to, int y);
void set_z(Vector3& vector_to, int z);

//------------------------------------------------------------------------------

// Объявление типа: класс Vector2
class Vector2;

// Объявление объектов класса Vector2
extern Vector2 v2_1, v2_2, v2_3, *pv2_1, *pv2_2, *pv2_3, *pv2_4;

// Определение типа: класс Vector2
class Vector2 { /*
 private: // Скрытые элементы класса */
  Math::Z x_, y_; // поля класса

 public: // Открытые элементы класса

  // Определения (встраиваемые) методов класса
  int get_x() const { return x_; } // метод-"мутатор" ("геттер")
  void set_x(int x) { x_ = x; } // метод-"мутатор" ("сеттер")

  // Объявления встраиваемых методов класса
  inline int get_y() const; // метод-"мутатор" ("геттер")
  inline void set_y(int y); // метод-"мутатор" ("сеттер")

  // Объявления методов класса
  double get_rad() const;
  double get_alpha() const;

  // Объявление конструктора с параметрами
  Vector2(int x, int y);

  // Объявление конструктора по умолчанию
  Vector2();

  // Объявление конструктора копирования
  Vector2(const Vector2& other);
};

// Определения встраиваемых методов класса
inline int Vector2::get_y(/* const Vector3& vector_from */) const {
  // const Vector* this = &vector_from;
  return this->y_;
}

inline void Vector2::set_y(/* Vector3& vector_to, */ int y) {
  // Vector* this = &vector_to;
  this->y_ = y;
}

//------------------------------------------------------------------------------

// Идиома "защита подключения"
#endif // VECTOR_H_



