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

TEST_CASE("Checks if the 'setter'(putOne) properly change values of itemCount","putOne()"){
    Pallet pallet1("Korean Fried Chicken", 10, 10);
    Pallet pallet2("Buldak Carbonara", 25, 0);
    REQUIRE(pallet1.reallocateEmptyPallet("Normal Fried Chicken", 5) == false);
    REQUIRE(pallet2.reallocateEmptyPallet("Buldak Normal", 30) == true);
    REQUIRE(pallet2.getItemName() == "Buldak Normal");
    REQUIRE(pallet2.getRemainingSpace() == 30);
};

TEST_CASE()