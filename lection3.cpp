#include "lections.h"

#include <iostream>
using namespace std;

#include "namespace_math.h"
#include "struct_vector3.h"
#include "class_vector2.h"
#include "class_unit.h"

void lection3() {
  Unit u, *pu = new Unit;
  cout << u.get_number() << endl; // вызов статического метода
  cout << pu->get_number() << endl; // вызов статического метода
  cout << Unit::get_number() << endl; // вызов статического метода!
  // статическим методам не передается ссылка на текущий объект
}
