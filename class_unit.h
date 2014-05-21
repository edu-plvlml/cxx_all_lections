#ifndef CLASS_UNIT_H_
#define CLASS_UNIT_H_

#include "class_vector2.h"

class Unit;

namespace UnitInfo {

extern unsigned int number; // количество объектов класса Unit
extern unsigned int max_index; // индекс последнего объекта
// плохо: отсутствует инкапсуляция (ВОПРОС: как исправить?)

}

class Unit {
 private:
  unsigned int index_; // индекс текущего объекта

 public:
  unsigned int get_index() { return index_; }

  // using UnitInfo::max_index; // нельзя: объявление чего?
  // using namespace UnitInfo; // нельзя: нет поиска имен

  // Unit():
  //     index_(++UnitInfo::max_index) // нежелательно: внешняя область
  // {
  //   ++UnitInfo::number;
  // }

  // ~Unit() {
  //   --UnitInfo::number;
  // }

 private:
  // Статические поля - общие для всех объектов данного класса
  static unsigned int number; // количество объектов данного класса
  static unsigned int max_index; // индекс последнего объекта
  // хорошо: статические поля инкапсулированы

 public:
  // Статические методы - для работы только со статическими полями
  static unsigned int get_number() { return number; }
  static unsigned int get_max_index() { return max_index; }

  // Unit():
  //     index_(++max_index) // хорошо: собственная область
  // {
  //   ++number;
  // }

  // ~Unit() {
  //   --number;
  // }

 private:
  // Композиция - объект одного класса является полем другого класса
  Vector2 position_;

 public:
  Vector2 get_position() { return position_; }

  // Делегирование реализации методов класса методам его полей
  void set_x(int x) { position_.set_x(x); }
  void set_y(int y) { position_.set_y(y); }
  // Композиция и делегирование устанавливают между классами отношение
  // "реализован посредством": Unit реализован посредством (использует) Vector2

 private:
  char* name_;

 public:
  const char* get_name() const { return name_; }
  void set_name(const char* name);

  Unit(const char* name = "Unit", int x = 0, int y = 0);
  ~Unit();

  // Конструктор копирования
  Unit(const Unit& other);

  // Конструктор перемещения
  Unit(Unit&& other);

  // Дружественная функция обмена
  friend void swap(Unit& unit1, Unit& unit2) noexcept;

  // Оператор копирующего присваивания
  Unit& operator = (const Unit& other);

  // Оператор перемещающего присваивания
  Unit& operator = (Unit&& other);
};

#endif // CLASS_UNIT_H_
