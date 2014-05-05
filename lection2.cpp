#include "lections.h"

#include <iostream>
using namespace std;

#include "namespace_math.h"
#include "struct_vector3.h"
#include "class_vector2.h"

void lection2() {
  Vector2 a(1,1), b(2,2), c;  

  c = sum(a, b);
  cout << c.get_x() << ' ' << c.get_y() << endl;

  c = a + b;
  cout << c.get_x() << ' ' << c.get_y() << endl;

  c = operator+(a, b);
  cout << c.get_x() << ' ' << c.get_y() << endl;

  // c += a; // ошибка: метод или дружественная функция?
  // cout << c.get_x() << ' ' << c.get_y() << endl;

  operator+=(c, a);
  cout << c.get_x() << ' ' << c.get_y() << endl;

  c.operator+=(a);
  cout << c.get_x() << ' ' << c.get_y() << endl;
}
