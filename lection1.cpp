#include "lections.h"

#include <iostream>
using namespace std;

#include "namespace_math.h"
#include "struct_vector3.h"
#include "class_vector2.h"

void lection1() {
  v3.x = 3;
  cout << "v3.x == " << v3.x << endl;

  Vector3_set_y(&v3, 4);
  cout << "get_y(v3) == " << Vector3_get_y(&v3) << endl; // (*)

  // Инкапсуляция: внутренняя структура недоступна, ...
  // v2.x_ = 3; // поле скрыто
  // cout << "v2.x_ == " << v2.x_ << endl; // поле скрыто

  // ... доступен только интерфейс.
  v2.set_x(3);
  v2.set_y(4);
  cout << "v2.get_x() == " << v2.get_x() << endl; // (**)
  cout << "v2.get_y() == " << v2.get_y() << endl; // (**)

  cout << "v2.get_rad() == "   << v2.get_rad()   << endl;
  cout << "v2.get_alpha() == " << v2.get_alpha() << endl;
  // Внутренняя структура неизвестна - абстракция.

  Vector3 v3_y = {0,1,0}; // инициализация полей структуры
  cout << "get_y(v3_y) == " << Vector3_get_y(&v3_y) << endl; // см. (*)
  // в наши функции передается фактический аргумент типа структуры

  // Vector2 v2_y = {0,1}; // поля скрыты!
  Vector2 v2_y(0,1); // инициализация полей класса конструктором
  cout << "v2_y.get_y() == " << v2_y.get_y() << endl; // см. (**)
  // в метод передается вызвавший его объект как скрытый параметр
}
