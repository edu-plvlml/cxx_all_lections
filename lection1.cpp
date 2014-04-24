#include "lections.h"

#include <iostream>
using namespace std;

#include "namespace_math.h"
#include "struct_vector3.h"
#include "class_vector2.h"

void lection1() {
  v3.x = 3;
  cout << "v3.x == " << v3.x << endl;

  set_y(v3, 4);
  cout << "get_y(v3) == " << get_y(v3) << endl;

  // Инкапсуляция: внутренняя структура недоступна, ...
  // v2.x_ = 3; // поле скрыто
  // cout << "v2.x_ == " << v2.x_ << endl; // поле скрыто

  // ... доступен только интерфейс.
  v2.set_x(3);
  v2.set_y(4);
  cout << "v2.get_x() == " << v2.get_x() << endl;
  cout << "v2.get_y() == " << v2.get_y() << endl;

  cout << "v2.get_rad() == " << v2.get_rad() << endl;
  cout << "v2.get_alpha() == " << v2.get_alpha() << endl;
  // Внутренняя структура неизвестна - абстракция.

  Vector3 v3_x = {1,0,0};
  cout << "get_x(v3_x) == " << get_x(v3_x) << endl;
  cout << "get_x(v3) == " << get_x(v3) << endl;

  Vector2 v2_x /* = {1,0}; // поля скрыты! */;
  cout << "v2_x.get_x() == " << v2_x.get_x() << endl;
  cout << "v2.get_x() == " << v2.get_x() << endl;

  // Как инициализировать объект конкретными значениями?
  // Как метод узнает, какой конкретно объект его вызвал?
}
