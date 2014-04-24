#include <cmath>

// Подключение файла с определением области Math
#include "namespace_math.h"

// Определения переменных из области Math
Math::Z Math::x0 = 0, Math::y0 = 0;

// Определение функции из области Math
Math::R Math::alpha(Math::Z x, Math::Z y) {
  return atan2( double(y-y0), double(x-x0) );
}

using Math::R; // объявление имени R

// Определение функции из области Math
R Math::rad(Z x, Z y) { // имя Z и так видимо
  // Имена x0 и y0 и так видимы
  return sqrt( double((x-x0)*(x-x0) + (y-y0)*(y-y0)) );
}

// Определение ДРУГОЙ функции из глобальной области
R rad(Math::Z x, Math::Z y) { // имя Z не видимо
  // Имена x0 и y0 не видимы
  return sqrt( double((x-Math::x0)*(x-Math::x0) +
                      (y-Math::y0)*(y-Math::y0)) );
}
