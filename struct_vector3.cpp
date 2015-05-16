struct Vector3; // объявление типа: структура Vector3

// Определение переменных типа Vector3
// Vector3 v3_x, v3_y, v3_z; // размещать в памяти еще нельзя
// Vector3 *pv3 = new Vector3; // выделять память еще нельзя
Vector3 *pv3_0 = nullptr; // создавать указатели можно

// Подключение файла с определением типа Vector3
#include "struct_vector3.h"

// Определение переменных типа Vector3
Vector3 v3, *pv3 = new Vector3; // теперь можно

// Определения функций
void Vector3_set_x(Vector3* vector_to, int x) { vector_to->x = x; }
void Vector3_set_y(Vector3* vector_to, int y) { vector_to->y = y; }
void Vector3_set_z(Vector3* vector_to, int z) { vector_to->z = z; }
