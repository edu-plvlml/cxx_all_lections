#include "class_unit.h"

#include <cstring>
#include <utility>
#include <iostream>

// Инициализация переменных области UnitInfo
unsigned int UnitInfo::number = 0; // количество объектов класса Unit
unsigned int UnitInfo::max_index = 0; // индекс последнего объекта

// Инициализация статических полей класса Unit
unsigned int Unit::number = 0; // количество объектов класса Unit
unsigned int Unit::max_index = 0; // индекс последнего объекта

void Unit::set_name(const char* name) {
  // strcpy(name_, name); // плохо: вдруг недостаточно места?
  
  // delete[] name_; // плохо: вдруг дальше возникнет исключение?
  // name_ = new char[strlen(name)+1];
  
  char* temp = new char[strlen(name)+1];
  strcpy(temp, name);
  std::swap(name_, temp); // гарантируется отсутствие исключений
  // хорошо: строгая гарантия безопасности исключений
  delete[] temp;
}

Unit::Unit(const char* name /* = "Unit" */, int x /* = 0 */, int y /* = 0 */):
    index_(++max_index),
    position_(x, y),
    name_(new char[strlen(name)+1]) // Идиома RAII:
    // Resource Acquisition Is Initialization, или
    // получение ресурса есть (совпадает с) инициализация (-ей)
{
  strcpy(name_, name);
  std::clog << "Unit #" << index_ << " \"" << name_ << "\" " << "calls c-tor" << std::endl;
  ++number;
}

Unit::~Unit() {
  std::clog << "Unit #" << index_ << " \"" << name_ << "\" " << "calls d-tor" << std::endl;
  --number;
  delete[] name_; // Идиома RAII:
  // освобождение ресурса совпадает с удалением объекта
}

// Конструктор копирования
Unit::Unit(const Unit& other):
    index_(++max_index),
    position_(other.position_),
    // name_(other.name_) // простое копирование - плохо,
    // т.к. деструктор копии удалит ресурс оригинала
    name_(new char[strlen(other.name_)+1]) // см. ниже
{
  strcpy(name_, other.name_); // хорошо: глубокое копирование
  std::clog << "Unit #" << index_ << " \"" << name_ << "\" " << "calls copy c-tor" << std::endl;  
  ++number;
}

// Конструктор перемещения
Unit::Unit(Unit&& other): // other привязана к pr-value или x-value,
    // т.е. это объект временный или истекающего времени жизни
    index_(++max_index),
    position_(other.position_),
    name_(other.name_) // простое копирование - правильно
{
  other.name_ = nullptr; // оригинал больше не владеет ресурсом
  // т.о., деструктор оригинала не удалит ресурс копии
  std::clog << "Unit #" << index_ << " \"" << name_ << "\" " << "calls move c-tor" << std::endl;
  ++number;
}

void swap(Unit& unit1, Unit& unit2) noexcept {
  std::swap(unit1.position_, unit2.position_);
  std::swap(unit1.name_, unit2.name_);
}

// Оператор копирующего присваивания
Unit& Unit::operator=(const Unit& other) {
  // Идиома "copy and swap"
  Unit temp(other); // может возникнуть исключение
  swap(temp, *this); // гарантируется отсутствие исключений
  // хорошо: строгая гарантия безопасности исключений
  return *this;
} // вызывается деструктор temp, удалающий прежние ресурсы this

// Оператор перемещающего присваивания
Unit& Unit::operator=(Unit&& other) { // other привязана к pr-value или x-value,
  // т.е. это объект временный или истекающего времени жизни
  swap(other, *this);
  return *this;
} // скоро вызовется деструктор other, удаляя прежние ресурсы this


// Универсальный оператор присваивания
// Unit& Unit::operator=(Unit other) { // other передается по значению,
//   // при этом вызывается копирующий или перемещающий конструктор;
//   // возможно также исключение копирования (copy elision)
//   swap(other, *this);
//   return *this;
// } // вызывается деструктор other, удаляющий прежние ресурсы this
