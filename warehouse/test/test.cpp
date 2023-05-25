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