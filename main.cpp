//
// Created by ZhugeKongan on 2022/7/25.
//

#include <iostream>
#include "Complier.h"

int main() {

    Complier::OnGetComplier().OnSetInFiles("../sourcefiles/test_file.lisp");
    Complier::OnGetComplier().OnSetOutFiles("../targetfiles/main.c");


    Complier::OnGetComplier().Init();
    Complier::OnGetComplier().run();

    return 0;
}
