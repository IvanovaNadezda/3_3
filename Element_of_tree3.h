//
// Created by inade on 27.05.2022.
//

#ifndef ELEMENT_OF_TREE3_H
#define ELEMENT_OF_TREE3_H
#include "Base_class.h"
class Element_of_tree3 : public Base_class {
public:
    //Метод сигнала
    void signal(string& message);
    //Обработчик
    void handler(string message);
    //Конструктор
    Element_of_tree3(Base_class * parent, string name);

};
#endif
