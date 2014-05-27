#include "lections.h"

#include <cstdio>
#include <iostream>
using namespace std;

#include "class_unit.h"

Unit make_unit(const char* name) {
  Unit temp(name);
  return temp; // возможна NRVO,
  // хотя должен вызываться конструктор копирования
}

void lection3() {
  // freopen("log.txt", "wt", stderr); // перенаправление потока stderr в файл
  // глобальный объект std::cout осуществляет буферизованный вывод в поток stdout
  // глобальный объект std::cerr осуществляет небуферизованный вывод в поток stderr;
  // глобальный объект std::clog осуществляет буферизованный вывод в поток stderr
  
  Unit u, *pu = new Unit;
  cout << u.get_number() << endl; // вызов статического метода
  cout << pu->get_number() << endl; // вызов статического метода
  cout << Unit::get_number() << endl; // вызов статического метода!
  // статическим методам не передается ссылка на текущий объект

  pu->~Unit(); // явный вызов деструктора без освобождения памяти
  new(pu) Unit(); // явный ВЫЗОВ КОНСТРУКТОРА без выделения памяти:
  // для создания объекта используется ранее выделенная память
  delete pu; // освобождение памяти из-под объекта с вызовом деструктора

  u.~Unit(); // явный вызов деструктора без освобождения памяти
  new(&u) Unit(); // явный вызов конструктора без выделения памяти

  // ---------------------------------------------------------------------------
  clog << "-----------------------------------------------------------" << endl;
  // ---------------------------------------------------------------------------
  
  Unit* tomato = new Unit("Tomato");
  cout << (void*) tomato->get_name() << ": " << tomato->get_name() << endl;
  // выводится адрес строки с именем и само имя

  Unit tomato2 = *tomato; // вызывается конструктор копирования
  cout << (void*) tomato2.get_name() << ": " << tomato2.get_name() << endl;
  // выводится адрес копии строки с именем и то же самое имя

  Unit tomato3 = make_unit("Fresh tomato"); // возможно исключение копирования,
  // хотя должен вызываться конструктор перемещения
  
  Unit tomato4 = std::move(*tomato); // вызывается конструктор перемещения
  cout << (void*) tomato->get_name() << endl;
  // выводится нулевой адрес - исходная строка с именем перемещена

  delete tomato;
  cout << (void*) tomato4.get_name() << ": " << tomato4.get_name() << endl;
  // выводится адрес исходной строки с именем и само имя
  
  // ---------------------------------------------------------------------------
  clog << "-----------------------------------------------------------" << endl;
  // ---------------------------------------------------------------------------

  Unit student1("Vasya");
  Unit student2("Fedya");
  Unit student3("Sigismund");

  student1 = tomato2; // вызывается оператор копирующего присваивания
  student2 = std::move(tomato3); // вызывается оператор перемещающего присваивания
  student3 = make_unit("Rotten tomato"); // вызывается оператор перемещающего присваивания

  // ---------------------------------------------------------------------------
  clog << "-----------------------------------------------------------" << endl;
  // ---------------------------------------------------------------------------

} // неявное удаление объектов со стека с вызовом деструкторов
