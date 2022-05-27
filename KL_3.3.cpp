//
// Created by inade on 27.05.2022.
//

#include <stdlib.h>
#include <stdio.h>
#include "Application.h"
int main()
{
    Application* app = new Application(); //Создаем объкт класса Application
    app->built_tree_objs();//Строим иерархическое древо
    app->set_tree_connects();//Обрабатываем команды пользователя
    return app->exec(); // Выводим иерархическое древо на экран
}