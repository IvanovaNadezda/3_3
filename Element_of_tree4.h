//
// Created by inade on 27.05.2022.
//

#ifndef ELEMENT_OF_TREE4_H
#define ELEMENT_OF_TREE4_H
#include "Base_class.h"
class Element_of_tree4 : public Base_class {
public:

    void signal(string& message);

    void handler(string message);

    Element_of_tree4(Base_class* parent, string name);

};
#endif
