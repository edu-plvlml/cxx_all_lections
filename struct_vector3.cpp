struct Vector3; // объявление типа: структура Vector3

// Определение переменных типа Vector3
// Vector3 v3_x, v3_y, v3_z; // размещать в памяти еще нельзя
// Vector3 *pv3 = new Vector3; // выделять память еще нельзя
Vector3 *pv3_0 = nullptr; // создавать указатели можно

// Подключение файла с определением типа Vector3
#include "struct_vector3.h"

// Определение переменных типа Vector3
Vector3 v3_x = {1,0,0}, v3_y = {0,1,0}, v3_z = {0,0,1};
Vector3 *pv3 = new Vector3; // теперь можно

// Определения функций
void set_x(Vector3& vector_to, int x) { vector_to.x = x; }
void set_y(Vector3& vector_to, int y) { vector_to.y = y; }
void set_z(Vector3& vector_to, int z) { vector_to.z = z; }
