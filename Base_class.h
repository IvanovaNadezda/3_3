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
        TYPE_SIGNAL p_signal; //указатель на метод сигнала
        Base_class* p_cl_base;//указатель на целевой объект
        TYPE_HANDLER p_handler;//Указатель на метод обработчика
    };
    vector<o_sh*> connects;
    string obj_name; //Имя объекта
    Base_class* ptr_head_obj; //Указатель на головной объект
    int condition;
    vector <Base_class*> child_objs;// Массив указателей на дочерние объекты
public:
    int class_number = 0;
    Base_class(Base_class* ptr_head_obj, string obj_name);
    //Параметрический конструктор

    void set_obj_name(string name); //Установить имя объекета

    string get_obj_name(); // Получить имя объекта



    void change_head_obj(Base_class* bs_class); // Изменить указатель на головной объект



    Base_class* get_head_obj(); // Получить указатель на головнойобъект



    void print_child_objs(int level);// Вывести на экран дочерние классы



    void print_child_objsConditions(int level); // Вывести на экран дочерние классы




    Base_class* getObjByName(string name);//Поиск объекта по имени



    void add_child_obj(Base_class* child_obj); //Добавить дочерний класс в массив



    unsigned int get_count_child(); // Получить кол-во дочерних классов



    void set_condition(int condition); //Установить состояние и отключить все нижестоящие




    int get_condition(); //Получение состояния объекта
    Base_class* getObjByURL(string url); //Получение указателя на объект по заданному пути

    TYPE_HANDLER getHandler();// Получение указателя на обработчик

    TYPE_SIGNAL getSignal();//Получение указателя на метод сигнала


    int get_class_number();//Получение номера класса объекта
    void set_connect(TYPE_SIGNAL p_signal, Base_class* p_object,
                     TYPE_HANDLER p_ob_handler); //Добавление связи между объектами

    void delete_connect(TYPE_SIGNAL p_signal, Base_class*
    p_object, TYPE_HANDLER p_ob_handler); //Удаление связи между объектами

    void emit_signal(TYPE_SIGNAL p_signal, string&
    s_command); //Рассылает сигналы

    string Get_Abs_URL();//Определить абсолютный путь до объекта

    void SetReadyALL();//Установить состояние готовности у всех объектов


};
#endif
