//
// Created by inade on 27.05.2022.
//

#include "Application.h"
#include "Base_class.h"
Application::Application(Base_class* parent, string name) :
        Base_class(parent, name) {}
void Application::built_tree_objs() {
    cin >> parent_name;
    this->set_obj_name(parent_name);
    while (true) {

        cin >> url;
        if (url == "еndtrее") {
            break;
        }

        cin >> child_name >> class_number;


        if (url == "/") {
            parent = this;
        }

        else {

            parent = this->getObjByURL(url);

            if (parent == nullptr) {
                cout << "Object tree";
                this->print_child_objs(0);
                cout << "\nThe head object " << url << " is not found";
                exit(0);

            }
        }
        switch (class_number) {
            case 11:
                parent->add_child_obj(new Element_of_tree2(parent,
                                                           child_name));
                break;
            case 12:
                parent->add_child_obj(new Element_of_tree3(parent,
                                                           child_name));
                break;
            case 13:
                parent->add_child_obj(new Element_of_tree4(parent,
                                                           child_name));
                break;
            case 14:
                parent->add_child_obj(new Element_of_tree5(parent,
                                                           child_name));
                break;
            case 15:
                parent->add_child_obj(new Element_of_tree6(parent,
                                                           child_name));
                break;
        }

    }


}
void Application::set_tree_connects() {
    string url1;
    string url2;
    Base_class* obj1, * obj2;
    cin >> url1;

    while (url1 != "end_of_connections") {
        cin >> url2;
        if (url1 == "/") {
            url1=url2;
        }
        else {
            obj1 = this->getObjByURL(url1);
        }
        if (url2 == "/") {
            obj2 = this;
        }
        else {
            obj2 = this->getObjByURL(url2);
        }

        obj1->set_connect(obj1->getSignal(), obj2, obj2 -> getHandler());
        cin >> url1;
    }
}
void Application::set_tree_condition() {
    string name;
    int cond;
    Base_class* b;
    while (cin) {
        cin >> name;
        cin >> cond;
        this->getObjByName(name)->set_condition(cond);
    }
}


void Application::tree_connect_commands() {
    Base_class* start_obj, * end_obj;
    string end_url, message = "";
    char cond;
    string com, com_url;
    cin >> com;
    while (com != "ЕND") {
        cin >> com_url;
        if (com == "EMIT") {
            getline(cin, message);
            if (message[message.length() - 1] == ' ') {
                message = message.substr(0, message.length() -
                                            3);
            }
            start_obj = this->getObjByURL(com_url);
            if (start_obj == NULL) {
                cout << "\nObject " << com_url << " not found";
            }
            else {
                start_obj->emit_signal(start_obj->getSignal(),
                                       message);
            }
        }
        else if (com == "SET_CONNECT") {
            cin >> end_url;
            start_obj = this->getObjByURL(com_url);
            end_obj = this->getObjByURL(end_url);
            if (start_obj == NULL) {
                cout << "\nObject " << com_url << " not found";
            }
            else if (end_obj == NULL) {
                cout << "\nHandler object " << end_url << " not found";
            }
            else {
                start_obj->set_connect(start_obj->getSignal(),
                                       end_obj, end_obj->getHandler());
            }
        }
        else if (com == "DЕLЕTЕ_CONNЕCT") {
            cin >> end_url;
            start_obj = this->getObjByURL(com_url);
            end_obj = this->getObjByURL(com_url);
            if (start_obj == NULL) {
                cout << "\nObject " << com_url << " not found";
            }
            else if (end_obj == NULL) {
                cout << "\nHandler object " << com_url << " not found";
            }
            else {
                start_obj->delete_connect(start_obj -> getSignal(), end_obj, end_obj->getHandler());
            }
        }

        else if (com == "SЕT_CONDITIОN") {
            cin >> cond;
            start_obj = this->getObjByURL(com_url);
            if (start_obj == nullptr) {
                cout << "\nObject " << com_url << " not found";
            }
        }
        cin >> com;

    }
}
void Application::tree_commands() {
    Base_class* current_obj = this, * found_obj = nullptr;
    string com, com_url;
    cin >> com;
    while (com != "END") {
        cin >> com_url;
        if (com == "SET") {
            if (com_url.substr(0, 2) == "//") {
                found_obj = this -> getObjByName(com_url.substr(2));
            }
            else {
                found_obj = current_obj->getObjByURL(com_url);
            }
            if (found_obj == nullptr) {
                cout << "Object is not found: " <<	current_obj->get_obj_name() << " " << com_url;
            }
            else {
                current_obj = found_obj;
                cout << "Object is set: " << current_obj -> get_obj_name();

            }

        }
        else {

            if (com_url == ".") {
                cout << com_url << " Object name: " <<
                     current_obj->get_obj_name();
            }
            else if (com_url == "/") {
                cout << com_url << " Object name: " <<
                     this->get_obj_name();
            }
            else {
                if (com_url.substr(0, 2) == "//") {
                    found_obj = this -> getObjByName(com_url.substr(2));
                }
                else {
                    found_obj = current_obj -> getObjByURL(com_url);
                }
                if (found_obj == nullptr) {
                    cout << com_url << " Object is not found";
                }
                else {
                    cout << com_url << " Object name: " << found_obj->get_obj_name();
                }
            }
        }
        cin >> com;
    }

}
void Application::signal(string& message) {
    cout << "\nSignal from " << this->Get_Abs_URL();
    message += " (class: 1)";
}
void Application::handler(string message) {
    cout << "\nSignal to " << this->Get_Abs_URL() << " Text: " << message;
}
int Application::exec() {
    cout << "Object tree";
    this->print_child_objs(0);
    this->SetReadyALL();
    this->tree_connect_commands();
    return 0;
}