//
// Created by inade on 27.05.2022.
//

#include "Base_class.h"
#include "Application.h"
#include "Element_of_tree2.h"
#include "Element_of_tree3.h"
#include "Element_of_tree4.h"
#include "Element_of_tree5.h"
#include "Element_of_tree6.h"


Base_class::Base_class(Base_class* ptr_head_obj = NULL, string obj_name =
"Base_object") { //Параметрический конструктор
    this->ptr_head_obj = ptr_head_obj;
    this->obj_name = obj_name;
}

void Base_class::set_obj_name(string name) { //Установить имя объекета
    this->obj_name = name;
}
string Base_class::get_obj_name() { // Получить имя объекта
    return this->obj_name;
}

void Base_class::change_head_obj(Base_class* bs_class) { // Изменить указатель на головной объект
    this->ptr_head_obj = bs_class;
}


Base_class* Base_class::get_head_obj() { // Получить указатель на головной 	объект
    return this->ptr_head_obj;
}


void Base_class::print_child_objs(int level) {// Вывести на экран дочерние классы
    cout << endl;
    for (int j = 0; j < level; j++) {
        cout << " ";
    }
    cout << this->obj_name;
    if (this->get_count_child() != 0) {
        for (int i = 0; i < this->get_count_child(); i++) {
            child_objs[i]->print_child_objs(level + 1);
        }
    }

}


void Base_class::print_child_objsConditions(int level) { // Вывести на экран дочерние классы
    cout << "\n";
    for (int j = 0; j < level; j++) {
        cout << " ";
    }
    cout << obj_name;

    if (this->get_condition() != 0) {
        cout << " is ready";
    }
    else {
        cout << " is not ready";
    }
    if (this->get_count_child() != 0) {
        for (int i = 0; i < this->get_count_child(); i++) {
            child_objs[i]->print_child_objsConditions(level + 1);
        }
    }

}


Base_class* Base_class::getObjByName(string name) {//Поиск объекта по имени
    if (this->obj_name == name) {
        return this;
    }
    else {
        for (int i = 0; i < this->get_count_child(); i++) {
            Base_class* base = child_objs[i]->getObjByName(name);
            if (base != NULL) {
                return base;
            }
        }
        return nullptr;
    }
}


void Base_class::add_child_obj(Base_class* child_obj) { //Добавить дочерний класс в массив
    child_objs.push_back(child_obj);
}


unsigned int Base_class::get_count_child() { // Получить кол-во дочерних классов
    return child_objs.size();
}



void Base_class::set_condition(int condition) {//Установить состояние
    Base_class* base = this->get_head_obj();
    if (condition != 0) {//Если хотим включить объект, проверяем включены ли вышестоящие
        while (base != NULL) {
            if (base->get_condition() == 0) {
                this->condition = 0;
                return;
            }
            base = base->get_head_obj();
        }
        this->condition = condition;
    }
    else {//Если хотим выключить, выключаем этот объект и все нижестоящие
        for (int i = 0; i < this->get_count_child(); i++) {
            this->child_objs[i]->set_condition(0);
        }
        this->condition = 0;
    }
}


int Base_class::get_condition() { //Получение состояния объекта
    return condition;
}

Base_class* Base_class::getObjByURL(string url) { //Получение указателя на объект по заданному пути
    if (url == "/") {
        return this;
    }
    Base_class* found_obj;//Найденный объект
    string main_coord = "";//Главный объект
    string coord_for_check = ""; //Путь от главного объекта к искомому
    bool check_first_elem = true;

    // Разделяем на главный объект и путь от этого объекта к искомому
    for (int i = 0; i < url.length(); i++) {
        if (url[i] == '/' && main_coord == "") {
            continue;
        }
        else if (url[i] != '/' && check_first_elem) {
            main_coord += url[i];

        }
        else if (url[i] == '/') {
            check_first_elem = false;
            coord_for_check += url[i];
        }
        else {
            coord_for_check += url[i];
        }
    }

    //Производим поиск объекта по пути
    for (int i = 0; i < this->get_count_child(); i++) {

        //Ищем среди дочерних объектов текущего объект с подходящим именем
        if (this->child_objs[i]->get_obj_name() == main_coord) {
            //Если поиск окончен возвращаем указатель
            if (coord_for_check == "") {
                return this->child_objs[i];
            }
                //Поиск не закончен
            else {
                found_obj = this->child_objs[i] -> getObjByURL(coord_for_check);
                if (found_obj != nullptr) {
                    return found_obj;
                }
            }

        }
    }
    return nullptr;

}
//Установка связи между объектами
void Base_class::set_connect(TYPE_SIGNAL p_signal, Base_class* p_object,
                             TYPE_HANDLER p_ob_handler) {
    o_sh* p_value;
    for (unsigned int i = 0; i < connects.size(); i++) {
        if (connects[i]->p_signal == p_signal && connects[i]->p_cl_base
                                                 == p_object && connects[i]->p_handler == p_ob_handler) {
            return;
        }
    }
    p_value = new o_sh();
    p_value->p_signal = p_signal;
    p_value->p_cl_base = p_object;
    p_value->p_handler = p_ob_handler;
    connects.push_back(p_value);

}
//Удаление связи между объектами
void Base_class::delete_connect(TYPE_SIGNAL p_signal, Base_class* p_object,
                                TYPE_HANDLER p_ob_handler) {
    for (unsigned int i = 0; i < connects.size(); i++) {
        if (connects[i]->p_signal == p_signal && connects[i]->p_cl_base
                                                 == p_object && connects[i]->p_handler == p_ob_handler) {
            connects.erase(connects.begin() + i);
            return;
        }
    }
}
//Рассылка сигналов
void Base_class::emit_signal(TYPE_SIGNAL p_signal, string& s_command) {
    TYPE_HANDLER p_handler;
    if (this->get_condition() == 0) {
        return;
    }
    (this->*p_signal)(s_command);
    for (unsigned int i = 0; i < connects.size(); i++) {
        if (connects[i]->p_signal == p_signal) {
            p_handler = connects[i]->p_handler;
            Base_class* obj = connects[i]->p_cl_base;
            if (obj->get_condition() != 0) {
                (obj->*p_handler)(s_command);
            }
        }
    }
}
//Получение абсолютного пути до объекта
string Base_class::Get_Abs_URL() {
    if (this->get_head_obj() == NULL) {
        return "/";
    }
    string url = "";
    Base_class* obj = this;
    while (obj->get_head_obj() != NULL) {
        url = "/" + obj->get_obj_name() + url;
        obj = obj->get_head_obj();
    }
    return url;
}
//Получение указателя на метод обработчика
TYPE_HANDLER Base_class::getHandler() {
    switch (this->get_class_number()) {
        case 1:
            return HANDLER(Application::handler);
            break;
        case 2:
            return HANDLER(Element_of_tree2::handler);
            break;
        case 3:
            return HANDLER(Element_of_tree3::handler);
            break;
        case 4:
            return HANDLER(Element_of_tree4::handler);
            break;
        case 5:
            return HANDLER(Element_of_tree5::handler);
            break;
        case 6:
            return HANDLER(Element_of_tree6::handler);
            break;
        default:return HANDLER(Application::handler);

    }
}
//Получение указателя на метод сигнала
TYPE_SIGNAL Base_class::getSignal() {
    switch (this->get_class_number()) {
        case 1:
            return SIGNAL(Application::signal);
        case 2:
            return SIGNAL(Element_of_tree2::signal);
        case 3:
            return SIGNAL(Element_of_tree3::signal);
        case 4:
            return SIGNAL(Element_of_tree4::signal);
        case 5:
            return SIGNAL(Element_of_tree5::signal);
        case 6:
            return SIGNAL(Element_of_tree6::signal);
        default:return SIGNAL(Application::signal);

    }
}
//Установка готовности у каждого объекта
void Base_class::SetReadyALL() {
    Base_class* obj = this;
    obj->set_condition(1);
    for (int i = 0; i < this->child_objs.size(); i++) {
        obj = this->child_objs[i];
        obj->set_condition(1);
        obj->SetReadyALL();
    }
}
//Получение номера класса
int Base_class::get_class_number() {
    return this->class_number;
}