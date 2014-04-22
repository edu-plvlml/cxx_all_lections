#include <iostream>
using namespace std;

#include "vector.h"

int main(int argc, char* argv[]) {
  cout << v3_x.x << endl;
  cout << pv3->y << endl;
  cout << get_x(v3_x) << endl;
  cout << get_y(*pv3) << endl;

  // Демонстрация инкапсуляции
  // cout << v2_2.x_ << endl; // нет доступа
  // cout < pv2_2->y_ << endl; // нет доступа
  cout << v2_3.get_x() << endl;
  cout << pv2_4->get_y() << endl;

  // Демонстрация абстракции
  cout << v2_3.get_rad() << endl;
  cout << pv2_4->get_alpha() << endl;

  return 0;
}
