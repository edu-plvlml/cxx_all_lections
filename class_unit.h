#ifndef CLASS_UNIT_H_
#define CLASS_UNIT_H_

namespace UnitInfo {

extern unsigned int number; // количество объектов класса Unit
extern unsigned int max_index; // индекс последнего объекта
// плохо: отсутствует инкапсуляция (ВОПРОС: как исправить?)

}

class Unit {
 private:
  unsigned int index; // индекс текущего объекта
  
 public:
  unsigned int get_index() { return index; }  

  // using namespace UnitInfo; // нельзя
  // using UnitInfo::max_index; // нельзя
  
  Unit():
      index(++max_index)
  {
    // ++UnitInfo::number; // плохо: внешняя область
    ++Unit::number; // хорошо: собственная область
  }

  ~Unit() {
    --number;
  }
  
 private:

  // Статические поля - общие для всех объектов данного класса
  static unsigned int number; // количество объектов данного класса
  static unsigned int max_index; // индекс последнего объекта
  // хорошо: статические поля инкапсулированы

 public:

  // Статические методы - для работы только со статическими полями
  static unsigned int get_number() { return number; }
  static unsigned int get_max_index() { return max_index; }
};


#endif // CLASS_UNIT_H_










