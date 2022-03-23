#include <string>
#include <iostream>
#include "Direction.hpp"

using namespace std;

namespace ariel {
    class Notebook {
    public:
        Notebook();

        void write(int page, int row, int col, Direction, string str);
        string read(int page, int row, int col, Direction, int num);
        void erase(int page, int row, int col, Direction, int num);
        void show(int page);

    };
};

