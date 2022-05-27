//
// Created by inade on 27.05.2022.
//

#include "Element_of_tree4.h"
Element_of_tree4::Element_of_tree4(Base_class* parent, string name) :
        Base_class(parent, name) {
    this->class_number = 4;
}
void Element_of_tree4::signal(string& message) {
    cout << "\nSignal from " << this->Get_Abs_URL();
    message += " (class: 4)";
}

void Element_of_tree4::handler(string message) {
    cout << "\nSignal to " << this->Get_Abs_URL() << " Text: " << message;
}