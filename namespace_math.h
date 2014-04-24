// Идиома "защита включения"
#ifndef NAMESPACE_MATH_H_
#define NAMESPACE_MATH_H_

// namespace Math; // объявлять область нельзя

namespace Math { // определение области Math

typedef int Z; // переименование типа
typedef double R; // переименование типа

}

namespace Math { // расширение области Math

// Имена Z и R видимы
extern Z x0, y0, z0; // объявление переменныx
R rad(Z x, Z y); // объявление функции
R alpha(Z x, Z y); // объявление функции

}

// Идиома "защита включения"
#endif // NAMESPACE_MATH_H_
