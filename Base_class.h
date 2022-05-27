//
// Created by inade on 27.05.2022.
//

#ifndef BASE_CLASS_H
#define BASE_CLASS_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Base_class;
typedef void (Base_class::* TYPE_SIGNAL)(string&);
typedef void (Base_class::* TYPE_HANDLER)(string);
#define SIGNAL(signal)((TYPE_SIGNAL)(&signal))
#define HANDLER(handler)((TYPE_HANDLER)(&handler))
class Base_class {
private:
    struct o_sh {
        TYPE_SIGNAL p_signal;
        Base_class* p_cl_base;
        TYPE_HANDLER p_handler;
    };
    vector<o_sh*> connects;
    string obj_name;
    Base_class* ptr_head_obj;
    int condition;
    vector <Base_class*> child_objs;
public:
    int class_number = 0;
    Base_class(Base_class* ptr_head_obj, string obj_name);

    void set_obj_name(string name);

    string get_obj_name();



    void change_head_obj(Base_class* bs_class);
    Base_class* get_head_obj();
    void print_child_objs(int level);
    void print_child_objsConditions(int level);
    Base_class* getObjByName(string name);
    void add_child_obj(Base_class* child_obj);
    unsigned int get_count_child();
    void set_condition(int condition);
    int get_condition();
    Base_class* getObjByURL(string url);
    TYPE_HANDLER getHandler();
    TYPE_SIGNAL getSignal();
    int get_class_number();
    void set_connect(TYPE_SIGNAL p_signal, Base_class* p_object,
                     TYPE_HANDLER p_ob_handler);

    void delete_connect(TYPE_SIGNAL p_signal, Base_class*
    p_object, TYPE_HANDLER p_ob_handler);

    void emit_signal(TYPE_SIGNAL p_signal, string&
    s_command);

    string Get_Abs_URL();

    void SetReadyALL();


};
#endif
