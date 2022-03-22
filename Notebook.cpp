#include "Notebook.hpp"
#include <string>
#include <iostream>
#include "Direction.hpp"
using namespace std;
using namespace ariel;

Notebook::Notebook(){

}

void Notebook::write(unsigned int page, unsigned int row, unsigned int col, Direction , string str){
    cout << " " << endl;
}

string Notebook::read(unsigned int page, unsigned int row, unsigned int col, Direction , unsigned int num){
    return "";
}

void Notebook::erase(unsigned int page, unsigned int row, unsigned int col, Direction , unsigned int num){
}

void Notebook::show(unsigned int page){
}

