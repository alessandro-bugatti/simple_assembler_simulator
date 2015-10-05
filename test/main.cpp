#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "assembly_error.h"
#include "computer.h"
#include "instruction.h"
#include "loadil.h"
#include "loadih.h"
#include "instructionsfactory.h"

TEST_CASE( "LoadiL", "[instruction][load]" ) {
    Computer c(10000);

    SECTION( "Wrong numbers of parameters" ) {
        REQUIRE_THROWS_AS(LoadiL(&c,string("R1")),assembly_error);
        REQUIRE_THROWS_AS(LoadiL(&c,string("R1 R2 R3")),assembly_error);
    }
    SECTION( "Wrong first parameter" ) {
        REQUIRE_THROWS_AS(LoadiL(&c,string("RH 0x256")),assembly_error);
        REQUIRE_THROWS_AS(LoadiL(&c,string("A2 0x256")),assembly_error);
        REQUIRE_THROWS_AS(LoadiL(&c,string("12 0x256")),assembly_error);
    }
    SECTION( "Wrong second parameter" ) {
        REQUIRE_THROWS_AS(LoadiL(&c,string("R1 Ax256")),assembly_error);
        REQUIRE_THROWS_AS(LoadiL(&c,string("R1 AA256")),assembly_error);
        REQUIRE_THROWS_AS(LoadiL(&c,string("R1 0xKL")),assembly_error);
    }
    SECTION( "Correct parameters" ) {
        REQUIRE_NOTHROW(LoadiL(&c,string("R1 0x11")));
        REQUIRE_NOTHROW(LoadiL(&c,string("R2 0x100")));
        REQUIRE_NOTHROW(LoadiL(&c,string("RA 0xFF")));
    }
    SECTION( "Execution"){
        REQUIRE_NOTHROW(LoadiH(&c,string("R1 0x01")).execute());
        REQUIRE(c.getRegisterValue("R1") == 0x0100);
        REQUIRE_NOTHROW(LoadiL(&c,string("R1 0x01")).execute());
        REQUIRE(c.getRegisterValue("R1") == 0x0101);
        REQUIRE_NOTHROW(LoadiH(&c,string("RA 0x1F")).execute());
        REQUIRE(c.getRegisterValue("RA") == 0x1F00);
    }
}

TEST_CASE( "InstructionFactory", "[instruction][factory]" ) {
    Computer c(10000);
    InstructionsFactory *factory;
    SECTION( "Istructions are not correct" ) {
        REQUIRE_THROWS_AS(factory->CreateInstruction(&c,"LOADbL R1 0x34"),assembly_error);
        REQUIRE_THROWS_AS(factory->CreateInstruction(&c,"LOADiL R1 0x34  0x34"),assembly_error);
    }
    SECTION( "Istructions are correct" ) {
        REQUIRE_NOTHROW(factory->CreateInstruction(&c,"LOADiL R1 0x34"));
        REQUIRE_NOTHROW(factory->CreateInstruction(&c,"LOADiH R1 0x34"));
    }
}

