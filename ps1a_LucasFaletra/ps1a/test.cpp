/****************
Lucas Faletra
ps1a
***************/
#include <iostream>
#include <string>
#include "LFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo){

  LFSR l("00111", 2);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);

  LFSR l2("00111", 2);
  BOOST_REQUIRE(l2.generate(8) == 198);
}

BOOST_AUTO_TEST_CASE(initAt32Bits)
{
  //initialize a 32 bit LFSR with tap of 24
  //Perform a series of steps and check each return value
  LFSR test("00011100011100011100011100011100", 24);
  BOOST_REQUIRE(test.step() == 0);
  BOOST_REQUIRE(test.step() == 0);
  BOOST_REQUIRE(test.step() == 1);
  BOOST_REQUIRE(test.step() == 0);
  BOOST_REQUIRE(test.step() == 0);
  BOOST_REQUIRE(test.step() == 1);
  BOOST_REQUIRE(test.step() == 0);
  BOOST_REQUIRE(test.step() == 0);
  BOOST_REQUIRE(test.step() == 1);
  BOOST_REQUIRE(test.step() == 0);


  //call generate function on a 32 bit seed with tap of 30
  LFSR test2("00011100011100011100011100011100", 30);
  BOOST_REQUIRE(test2.generate(7) == 18);

}

BOOST_AUTO_TEST_CASE(tapOutOfBounds){
  /*this test checks that each function interperets the tap as out of bounds

 The if statement at the beginning of my step and generate functions perform
 no operations and returns -1 if the tap is not a valid index for the seed*/
  
  LFSR test("1010101", 32);//seed length is 7 bits, so 32 is not a valid tap value
  BOOST_REQUIRE(test.step() == -1);
  BOOST_REQUIRE(test.step() == -1);
  BOOST_REQUIRE(test.generate(2) == -1);
  
  LFSR test2("1010101", -12);//a negative tap value cannot be used
  BOOST_REQUIRE(test2.step() == -1);
  BOOST_REQUIRE(test2.step() == -1);
  BOOST_REQUIRE(test2.generate(3) == -1);
  


}
