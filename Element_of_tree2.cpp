//
// Created by inade on 27.05.2022.
//

#include "Element_of_tree2.h"
Element_of_tree2::Element_of_tree2(Base_class* parent, string name) :Base_class(parent, name) {this->class_number = 2;} // Обращение к конструктору класса Base_class
//Метод сигнала
void Element_of_tree2::signal(string& message) {
    cout << "\nSignal from " << this->Get_Abs_URL();
    message += " (class: 2)";
}
//Метод обработчика
void Element_of_tree2::handler(string message) {
    cout << "\nSignal to " << this->Get_Abs_URL() << " Text: " << message;
}