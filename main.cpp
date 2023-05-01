#include <iostream>
#include <fstream>
#include <vector>
#include "assert.h"
#include "class.h"
#include "story.h"
#include "Replacing.h"
#include "rezClass.cpp"
#include "Replacing.cpp"
#include "Story.cpp"
using namespace std;
int main(){
    Editor a(7,Editor::Operation::DELETE,"popopo");
    Editor b(7,Editor::Operation::DELETE,"pop");
    Editor c(5,Editor::Operation::INSERT,"fds");
    Replacing d(6,Editor::Operation::REPLACING,"my","no");
    Story story1;
    story1.push_back(&a);
    story1.push_back(&b);
    story1.push_back(&c);
    story1.push_back(&d);
    story1.setText("hello my gues");
    cout<<story1.getText()<<endl;
    story1.back();
    cout<<story1.getText()<<endl;
//hello my gues
//hello no gues
//
//substr = my
//newsub = no
//position = 6
//    Story story1;
//    story1.readFile("file.txt");
//    Editor a(7,Editor::Operation::DELETE,"popopo");
//    story1.push_back(a);
//
//    Editor b(7,Editor::Operation::DELETE,"pop");
//    Story story2;
//    story2.readFile("file.txt");
//    story2.push_back(b);
////Проверка функции проверки двух коллекций на равенство
//    int c = story1.check(&story2);
//    assert(c == 0);
////Функция последовательного и пронумерованного вывода элементов коллекции на экран
//    get(story1);
//
////Проверка конструктора копирования
//    Story story3(story1);
//    int p = story1.check(&story3);
//    assert(p == 1);
////изменение конструктора копирования и снова проверка
//    story3.push_back(b);
//    int e = story1.check(&story3);
//    assert(e == 0);
////Проверка метода добавления и удаления объектов
//    assert(story1.getCount() == 5);
//    story1.push_back(b);
//    assert(story1.getCount() == 6);
//    story1.pop();
//    assert(story1.getCount() == 5);
////Проверка метода полного удаления
//    story1.allDel();
//    assert(story1.getCount() == 0);
//// Метод доступа к элементам вывод всех эдементов на экран
//    story2.getStory();
//
//    story2.writeFile("newfile.txt");
//    Story story4;
//    story4.readFile("newfile.txt");
//    int d = story2.check(&story4);
////    story4 и story2 не будут равны, так как у нас стек, чтобы сделать их равными, нужно записывать в файл с конца, но у нас однонаправленный список, это невозможно
//    assert(d == 0);
//    cout<<"correct!\n";
    return 0;
}