#include <string>
#include <iostream>
#include "Direction.hpp"

using namespace std;

namespace ariel {
    class Notebook {
    public:
        Notebook();

        void write(unsigned int page, unsigned int row, unsigned int col, Direction, string str);
        string read(unsigned int page, unsigned int row, unsigned int col, Direction, unsigned int num);
        void erase(unsigned int page, unsigned int row, unsigned int col, Direction, unsigned int num);
        void show(unsigned int page);

    };
};

