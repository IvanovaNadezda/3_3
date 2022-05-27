//
// Created by inade on 27.05.2022.
//

#ifndef ELEMENT_OF_TREE6_H
#define ELEMENT_OF_TREE6_H
#include "Base_class.h"
class Element_of_tree6 : public Base_class {
public:

    void signal(string& message);

    void handler(string message);

    Element_of_tree6(Base_class* parent, string name);

};
#endif
