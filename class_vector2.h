// Идиома "защита включения"
#ifndef CLASS_VECTOR2_H_
#define CLASS_VECTOR2_H_

#include "namespace_math.h"

// Объявление типа: класс Vector2
class Vector2;

// Объявление объектов класса Vector2
extern Vector2 v2, *pv2;

// Определение типа: класс Vector2
class Vector2 { /*
 private: // далее - скрытые элементы класса */
  int x_, y_; // поля класса

 public: // далее - открытые элементы класса

  // Определения (встраиваемых) методов класса
  int get_x() const { return x_; } // метод-"мутатор" ("геттер")
  void set_x(int x) { x_ = x; } // метод-"мутатор" ("сеттер")

  // Объявления методов класса
  int get_y() const; // метод-"мутатор" ("геттер")
  void set_y(int y); // метод-"мутатор" ("сеттер")

  // Объявления встраиваемых методов класса
  inline double get_rad() const;
  inline double get_alpha() const;

  // Объявление конструктора с параметрами
  Vector2(int x = 0, int y = 0);

  // Объявления методов класса
  Vector2& add(const Vector2& arg);
  Vector2& operator += (const Vector2& arg);
  
  // Объявления ФУНКЦИЙ, дружественных классу
  friend Vector2& add(Vector2& arg1, const Vector2& arg2);
  friend Vector2& operator += (Vector2& arg1, const Vector2& arg2);
};

// Определение встраиваемых методов класса
inline double Vector2::get_rad() const { return Math::rad(x_, y_); }
inline double Vector2::get_alpha() const { return Math::alpha(x_, y_); }

// Объявление функции, возвращающей новый объект,
// равный векторной сумме двух ее аргументов
Vector2 sum(const Vector2& arg1, const Vector2& arg2);
Vector2 operator + (const Vector2& arg1, const Vector2& arg2);

// Подключение файла c ОБЪЯВЛЕНИЕМ классов ввода/вывода
#include <iosfwd>

// Оператор "побитовый сдвиг влево" (a << b), перегруженный для вывода
// на первый аргумент (объект потока вывода) второго аргумента (типа Vector2)
// и возвращаюший первый аргумент для работы цепочки операторов (a << b << c)
std::ostream& operator << (std::ostream& out, const Vector2& vector);

// ЗАДАНИЕ. Реализовать операторы:

Vector2& operator *= (Vector2& arg1, int arg2);
Vector2 operator * (const Vector2& arg1, int arg2);
Vector2 operator * (int arg1, const Vector2& arg2);
int operator * (const Vector2& arg1, const Vector2& arg2);

// Идиома "защита включения"
#endif // CLASS_VECTOR2_H_
