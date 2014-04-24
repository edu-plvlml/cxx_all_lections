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
};

// Определение встраиваемых методов класса
inline double Vector2::get_rad() const { return Math::rad(x_, y_); }
inline double Vector2::get_alpha() const { return Math::alpha(x_, y_); }

// Идиома "защита включения"
#endif // CLASS_VECTOR2_H_
