#pragma once
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "include/catch.hpp"
#include "../src/include/warehouse.hpp"

// Find all tests in test*.cpp in test/
TEST_CASE("Checks if the constructor correctly assigns values and if getters fetch the correct data","The constructor and getter"){
    Employee employee1("Bob", false);
    Employee employee2("Bobbie", true);

    REQUIRE(employee1.getName() == "Bob");
    REQUIRE(employee2.getName() == "Bobbie");
    REQUIRE(employee1.getForkliftCertificate() == false);
    REQUIRE(employee2.getForkliftCertificate() == true);
    REQUIRE(employee1.getBusy() == false);
    REQUIRE(employee2.getBusy() == false);
};

TEST_CASE("Checks if the setters correctly reassign values","The setters"){
    Employee employee1("Finn", false);
    Employee employee2("Gerda", true);
    employee1.setBusy(true);
    employee1.setForkliftCertificate(true);
    REQUIRE(employee1.getBusy() == true);
    REQUIRE(employee1.getForkliftCertificate() == true);
    REQUIRE(employee1.getBusy() == true);
};

TEST_CASE("Checks whether the default constructor correctly assigns the default values","The default constructor"){
    Pallet pallet1 = Pallet();
    REQUIRE(pallet1.getItemName() == "");
    REQUIRE(pallet1.getItemCount() == 0);
    REQUIRE(pallet1.getRemainingSpace() == 0);
};

TEST_CASE("Checks whether the constructors correctly assigns the values","The constructor"){
    Pallet pallet1("Korean Fried Chicken", 10, 10);
    Pallet pallet2("Buldak Carbonara", 25, 0);
    REQUIRE(pallet1.getItemName() == "Korean Fried Chicken");
    REQUIRE(pallet1.getItemCount() == 10);
    REQUIRE(pallet1.getRemainingSpace() == 0);
};

TEST_CASE("Checks if the icontainer functions of Pallet work","Icontainer functions Pallet"){
    Pallet pallet1("Korean Fried Chicken", 10, 10);
    Pallet pallet2("Buldak Carbonara", 25, 0);
    REQUIRE(pallet1.isEmpty() == false);
    REQUIRE(pallet1.isFull() == true);
    REQUIRE(pallet2.isEmpty() == true);
    REQUIRE(pallet2.isFull() == false);
};

TEST_CASE("Checks if the 'setter'(takeOne) properly change values of itemCount","takeOne()"){
    Pallet pallet1("Korean Fried Chicken", 10, 10);
    Pallet pallet2("Buldak Carbonara", 25, 0);
    REQUIRE(pallet1.takeOne() == true);
    REQUIRE(pallet1.getItemCount() == 9);
    REQUIRE(pallet2.takeOne() == false);
};

TEST_CASE("Checks if the 'setter'(putOne) properly change values of itemCount","putOne()"){
    Pallet pallet1("Korean Fried Chicken", 10, 10);
    Pallet pallet2("Buldak Carbonara", 25, 0);
    REQUIRE(pallet1.putOne() == false);
    REQUIRE(pallet2.putOne() == true);
    REQUIRE(pallet2.getItemCount() == 1);
};

TEST_CASE("Checks if the reallocation of an empty pallet works or not","reallocateEmptyPallet()"){
    Pallet pallet1("Korean Fried Chicken", 10, 10);
    Pallet pallet2("Buldak Carbonara", 25, 0);
    REQUIRE(pallet1.reallocateEmptyPallet("Normal Fried Chicken", 5) == false);
    REQUIRE(pallet2.reallocateEmptyPallet("Buldak Normal", 30) == true);
    REQUIRE(pallet2.getItemName() == "Buldak Normal");
    REQUIRE(pallet2.getRemainingSpace() == 30);
};

TEST_CASE("Checks if the icontainer functions of Shelf work(isEmpty())","Icontainer isEmpty() function Shelf"){
    Shelf shelf1 = Shelf();
    Pallet pallet1("Books", 100, 0);
    Pallet pallet2("Books", 100, 0);
    Pallet pallet3("Books", 100, 0);
    Pallet pallet4("Books", 100, 0);
    shelf1.pallets[0] = pallet1;
    shelf1.pallets[1] = pallet2;
    shelf1.pallets[2] = pallet3;
    shelf1.pallets[3] = pallet4;
    Shelf shelf2 = Shelf();
    Pallet pallet5("Books", 100, 1);
    Pallet pallet6("Books", 100, 0);
    Pallet pallet7("Books", 100, 0);
    Pallet pallet8("Books", 100, 0);
    shelf2.pallets[0] = pallet5;
    shelf2.pallets[1] = pallet6;
    shelf2.pallets[2] = pallet7;
    shelf2.pallets[3] = pallet8;
    REQUIRE(shelf1.isEmpty() == true);
    REQUIRE(shelf2.isEmpty() == false);
};

TEST_CASE("Checks if the icontainer functions of Shelf work(isFull())","Icontainer isFull() function Shelf"){
    Shelf shelf1 = Shelf();
    Pallet pallet1("Books", 100, 100);
    Pallet pallet2("Books", 100, 100);
    Pallet pallet3("Books", 100, 100);
    Pallet pallet4("Books", 100, 100);
    shelf1.pallets[0] = pallet1;
    shelf1.pallets[1] = pallet2;
    shelf1.pallets[2] = pallet3;
    shelf1.pallets[3] = pallet4;
    Shelf shelf2 = Shelf();
    Pallet pallet5("Books", 100, 1);
    Pallet pallet6("Books", 100, 0);
    Pallet pallet7("Books", 100, 0);
    Pallet pallet8("Books", 100, 0);
    shelf2.pallets[0] = pallet5;
    shelf2.pallets[1] = pallet6;
    shelf2.pallets[2] = pallet7;
    shelf2.pallets[3] = pallet8;
    REQUIRE(shelf1.isFull() == true);
    REQUIRE(shelf2.isFull() == false);
};

TEST_CASE("Checks whether the function correctly detects which pallet index is the most full","checkMostFullPallet()"){
    Shelf shelf1 = Shelf();
    Pallet pallet1("Books", 100, 100);
    Pallet pallet2("Books", 100, 9);
    Pallet pallet3("Books", 100, 0);
    Pallet pallet4("Books", 100, 100);
    shelf1.pallets[0] = pallet1;
    shelf1.pallets[1] = pallet2;
    shelf1.pallets[2] = pallet3;
    shelf1.pallets[3] = pallet4;
    Shelf shelf2 = Shelf();
    Pallet pallet5("Books", 100, 0);
    Pallet pallet6("Books", 100, 8);
    Pallet pallet7("Books", 100, 1);
    Pallet pallet8("Books", 100, 9);
    shelf2.pallets[0] = pallet5;
    shelf2.pallets[1] = pallet6;
    shelf2.pallets[2] = pallet7;
    shelf2.pallets[3] = pallet8;
    REQUIRE(shelf1.checkLeastFullPallet(0) == 2);
    REQUIRE(shelf2.checkLeastFullPallet(1) == 0);
};

bool operator==(Pallet lhs, Pallet rhs){
    return lhs.getItemCount() == rhs.getItemCount() && lhs.getItemName() == rhs.getItemName() && lhs.getRemainingSpace() == rhs.getRemainingSpace();
}

bool operator==(Shelf lhs, Shelf rhs){
    bool equal = true;
    for (int i = 0; i < lhs.palletSize; i++){
        if (!(lhs.pallets[i] == rhs.pallets[i])){
            equal = false;
            break;
        }
    };
    return equal;
};

TEST_CASE("Checks whether the function correctly swaps pallets","swapPallet()"){
    Shelf shelf1 = Shelf();
    Pallet pallet1("Books", 100, 100);
    Pallet pallet2("Books", 100, 9);
    Pallet pallet3("Books", 100, 3);
    Pallet pallet4("Books", 100, 10);
    shelf1.pallets[0] = pallet1;
    shelf1.pallets[1] = pallet2;
    shelf1.pallets[2] = pallet3;
    shelf1.pallets[3] = pallet4;
    Shelf shelf2 = Shelf();
    shelf2.pallets[0] = pallet3;
    shelf2.pallets[1] = pallet4;
    shelf2.pallets[2] = pallet1;
    shelf2.pallets[3] = pallet2;
    shelf1.swapPallet(1,3);
    shelf1.swapPallet(2,4);
    REQUIRE(shelf1 == shelf2);
};

TEST_CASE("Checks whether pickItems correctly removes item from wanted item", "pickItems()"){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    Pallet pallet1("Books", 100, 1);
    Pallet pallet2("Books", 100, 9);
    Pallet pallet3("Books", 100, 3);
    Pallet pallet4("Books", 100, 10);
    shelf1.pallets[0] = pallet1;
    shelf1.pallets[1] = pallet2;
    shelf1.pallets[2] = pallet3;
    shelf1.pallets[3] = pallet4;
    // resulting shelf after pickItems()
    Shelf shelf2 = Shelf();
    Pallet pallet5("Books", 100, 0);
    Pallet pallet6("Books", 100, 1);
    Pallet pallet7("Books", 100, 3);
    Pallet pallet8("Books", 100, 10);
    shelf2.pallets[0] = pallet5;
    shelf2.pallets[1] = pallet6;
    shelf2.pallets[2] = pallet7;
    shelf2.pallets[3] = pallet8;
    // shelf with nothing
    Shelf shelf3 = Shelf();
    Pallet pallet9("yes", 100, 0);
    Pallet pallet10("yes", 100, 0);
    Pallet pallet11("yes", 100, 0);
    Pallet pallet12("yes", 100, 0);
    shelf3.pallets[0] = pallet9;
    shelf3.pallets[1] = pallet10;
    shelf3.pallets[2] = pallet11;
    shelf3.pallets[3] = pallet12;
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);
    warehouse.addShelf(shelf3);
    REQUIRE(warehouse.pickItems("Books", 9) == true);
    REQUIRE(shelf1 == shelf2);
    REQUIRE(warehouse.pickItems("yes", 4) == false);
    REQUIRE(warehouse.pickItems("dslfkj", 3) == false);
}