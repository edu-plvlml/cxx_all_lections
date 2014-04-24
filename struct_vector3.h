// Идиома "защита включения"
#ifndef STRUCT_VECTOR3_H_
#define STRUCT_VECTOR3_H_

// Объявление типа: структура Vector3
struct Vector3;

// Объявление переменных типа Vector3
extern Vector3 v3, *pv3, *pv3_0;

// Определение типа: структура Vector3
struct Vector3 {
  int x, y, z; // поля структуры
};

// Определения встраиваемых функций
inline int get_x(const Vector3& vector_from) { return vector_from.x; }
inline int get_y(const Vector3& vector_from) { return vector_from.y; }
inline int get_z(const Vector3& vector_from) { return vector_from.z; }

// Объявления функций
void set_x(Vector3& vector_to, int x);
void set_y(Vector3& vector_to, int y);
void set_z(Vector3& vector_to, int z);

// Идиома "защита включения"
#endif // STRUCT_VECTOR3_H_
