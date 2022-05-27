//
// Created by inade on 27.05.2022.
//

#include "Element_of_tree3.h"
Element_of_tree3::Element_of_tree3(Base_class* parent, string name) :
        Base_class(parent, name) {
    this->class_number = 3;
}
void Element_of_tree3::signal(string& message) {
    cout << "\nSignal from " << this->Get_Abs_URL();
    message += " (class: 3)";
}
void Element_of_tree3::handler(string message) {
    cout << "\nSignal to " << this->Get_Abs_URL() << " Text: " << message;
}