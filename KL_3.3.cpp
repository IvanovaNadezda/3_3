//
// Created by inade on 27.05.2022.
//

#include <stdlib.h>
#include <stdio.h>
#include "Application.h"
int main()
{
    Application* app = new Application();
    app->built_tree_objs();
    app->set_tree_connects();
    return app->exec();
}