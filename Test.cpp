#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Good input"){
    Notebook notebook;

    notebook.write(0, 0, 0, Direction::Horizontal, "Hello, good morning!");
    notebook.write(0, 1, 0, Direction::Horizontal, "Hello");
    notebook.write(0, 2, 0, Direction::Horizontal, "my");
    notebook.write(0, 3, 0, Direction::Horizontal, "name");
    notebook.write(0, 4, 0, Direction::Horizontal, "is");
    notebook.write(0, 5, 0, Direction::Horizontal, "Roni");


    CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 20) == "Hello, good morning!");
    CHECK(notebook.read(0, 1, 0, Direction::Horizontal, 5) == "Hello");
    CHECK(notebook.read(0, 2, 0, Direction::Horizontal, 2) == "my");
    CHECK(notebook.read(0, 3, 0, Direction::Horizontal, 4) == "name");
    CHECK(notebook.read(0, 4, 0, Direction::Horizontal, 2) == "is");
    CHECK(notebook.read(0, 5, 0, Direction::Horizontal, 4) == "roni");

    notebook.write(0, 6, 0, Direction::Horizontal, "is");
    notebook.erase(0, 6, 0, Direction::Horizontal, 2);
    CHECK(notebook.read(0, 5, 0, Direction::Horizontal, 2) == "~~");

    notebook.write(1, 0, 0, Direction::Horizontal, "Sunday");
    notebook.write(1, 0, 0, Direction::Horizontal, "Monday");
    notebook.write(1, 1, 0, Direction::Horizontal, "Tuesday");
    notebook.write(1, 2, 0, Direction::Horizontal, "Wednesday");
    notebook.write(1, 3, 0, Direction::Horizontal, "Thursday");
    notebook.write(1, 4, 0, Direction::Horizontal, "Friday");
    notebook.write(1, 5, 0, Direction::Horizontal, "Saturday");


    CHECK(notebook.read(1, 0, 0, Direction::Horizontal, 6) == "Sunday");
    CHECK(notebook.read(1, 1, 0, Direction::Horizontal, 6) == "Monday");
    CHECK(notebook.read(1, 2, 0, Direction::Horizontal, 7) == "Tuesday");
    CHECK(notebook.read(1, 3, 0, Direction::Horizontal, 9) == "Wednesday");
    CHECK(notebook.read(1, 4, 0, Direction::Horizontal, 8) == "Thursday");
    CHECK(notebook.read(1, 5, 0, Direction::Horizontal, 6) == "Friday");
    CHECK(notebook.read(1, 5, 0, Direction::Horizontal, 8) == "Saturday");


}


TEST_CASE("Bad input"){
    Notebook notebook;

    //this test will fail because the col number is bigger than the row len
    CHECK_THROWS(notebook.read(1, 0, 105, Direction::Horizontal, 5));

    //this test will fail because we try to write more than 100 chars
    CHECK_THROWS(notebook.write(2, 1, 0, Direction::Horizontal, "abcdefghijk abcdefghijk "
                                                                 "abcdefghijk abcdefghijk abcdefghijk abcdefghijk "
                                                                 "abcdefghijk abcdefghijk abcdefghijk abcdefghijk "));

    //this test will fail because we try to write 20 chars from col 95, and we have only 100 chars each col
    CHECK_THROWS(notebook.write(0, 0, 95, Direction::Horizontal, "Hello, good morning!"));

    //this test will fail because we try to write 20 chars from col 81, and we have only 100 chars each col
    CHECK_THROWS(notebook.write(0, 0, 81, Direction::Horizontal, "Hello, good morning!"));

    //this test will fail because we try to erase 110 chars, and we have only 100 chars each col
    CHECK_THROWS(notebook.erase(0, 0, 0, Direction::Horizontal, 110));

    //this test will fail because we try to erase 30 chars from col 80, and we have only 100 chars each col
    CHECK_THROWS(notebook.erase(0, 0, 80, Direction::Horizontal, 30));

    //this test will fail because we try to erase 15 chars from col 90, and we have only 100 chars each col
    CHECK_THROWS(notebook.erase(0, 0, 90, Direction::Horizontal, 15));

    //this test will fail because we try to erase 2 chars from col 99, and we have only 100 chars each col
    CHECK_THROWS(notebook.erase(0, 0, 99, Direction::Horizontal, 2));

    //this test will fail because I try to write twice in the same page, row and col
    notebook.write(2, 2, 10, Direction::Horizontal, "Hello");
    CHECK_THROWS(notebook.write(2, 2, 10, Direction::Horizontal, "Hello"));

    //this test will fail because I try to write in the same page, row and col that I erase from
    notebook.erase(2, 2, 10, Direction::Horizontal, 5);
    CHECK_THROWS(notebook.write(2, 2, 10, Direction::Horizontal, "Hello"));

    //this test will fail because we try to write '~'
    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Horizontal, "Ari~el"));

    //this test will fail because we try to write in negative page number
    CHECK_THROWS(notebook.write(-2, 0, 0, Direction::Horizontal, "Ariel"));

    //this test will fail because we try to write in negative row number
    CHECK_THROWS(notebook.write(0, -5, 0, Direction::Horizontal, "University"));

    //this test will fail because we try to write in negative col number
    CHECK_THROWS(notebook.write(0, 0, -9, Direction::Horizontal, "Barak"));

    //this test will fail because we try to write in negative row and col number
    CHECK_THROWS(notebook.write(0, -2, -1, Direction::Horizontal, "Shahar"));

    //this test will fail because we try to write in negative page and col number
    CHECK_THROWS(notebook.write(-9, 0, -5, Direction::Horizontal, "Daniel"));

    //this test will fail because we try to write in negative row and page number
    CHECK_THROWS(notebook.write(-2, -3, 0, Direction::Horizontal, "Anton"));

    //this test will fail because we try to write in negative page, row and col number
    CHECK_THROWS(notebook.write(-3, -2, -1, Direction::Horizontal, "Roni"));

}