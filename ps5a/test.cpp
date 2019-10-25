// Copyright 2015 fredm@cs.uml.edu for 91.204 Computing IV
// Wed Mar 25 06:32:17 2015

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include <stdint.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "RingBuffer.hpp"

BOOST_AUTO_TEST_CASE(RingBuffercontructor) {
	// normal constructor
	BOOST_REQUIRE_NO_THROW(RingBuffer RB(100));

	// this should fail
	BOOST_REQUIRE_THROW(RingBuffer RB2(0), std::exception);
	BOOST_REQUIRE_THROW(RingBuffer RB3(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RBenque_dequeue) {
	RingBuffer rb(100);

	rb.enqueue(2);
	rb.enqueue(1);
	rb.enqueue(0);

	BOOST_REQUIRE(rb.dequeue() == 2);
	BOOST_REQUIRE(rb.dequeue() == 1);
	BOOST_REQUIRE(rb.dequeue() == 0);

	BOOST_REQUIRE_THROW(rb.dequeue(), std::runtime_error);
}



BOOST_AUTO_TEST_CASE(Test_Constructor_Exceptions) {
  BOOST_REQUIRE_THROW(RingBuffer RB1(-1), std::invalid_argument);
  BOOST_REQUIRE_THROW(RingBuffer RB2(0), std::invalid_argument);

  BOOST_REQUIRE_NO_THROW(RingBuffer RB3(1000));
}

BOOST_AUTO_TEST_CASE(Test_enqueue_exceptions) {

  //putting 4 items into a buffer with capacity 3 should fail
  RingBuffer RB(3);
  RB.enqueue(2);
  RB.enqueue(4);
  RB.enqueue(6);
  BOOST_REQUIRE_THROW(RB.enqueue(8), std::runtime_error);

  //putting 10 items into a buffer with capacity 10 should work
  RingBuffer RB2(10);
  for(int i = 0; i < 10; i++)
    BOOST_REQUIRE_NO_THROW(RB2.enqueue(i * 20));
}

BOOST_AUTO_TEST_CASE(Test_dequeue_exceptions) {
  RingBuffer RB(10);
  BOOST_REQUIRE_THROW(RB.dequeue(), std::runtime_error);
  RB.enqueue(12);
  BOOST_REQUIRE_NO_THROW(RB.dequeue());
}

BOOST_AUTO_TEST_CASE(Test_peek_exceptions) {
  RingBuffer RB(100);
  BOOST_REQUIRE_THROW(RB.peek(), std::runtime_error);

  RB.enqueue(16);
  BOOST_REQUIRE_NO_THROW(RB.peek());
}

BOOST_AUTO_TEST_CASE(Test_size_accessor) {
  RingBuffer RB(20);
  BOOST_REQUIRE(RB.size() == 0);

  //push an integer i into the buffer. size should be 1, 2, 3 etc.
  for(int i = 0; i < 20; i++) {
    RB.enqueue(i);
    BOOST_REQUIRE(RB.size() == i + 1);
  }

}

BOOST_AUTO_TEST_CASE(Test_isEmpty) {
  RingBuffer RB(10);
  BOOST_REQUIRE(RB.isEmpty() == true);
  RB.enqueue(1);
  BOOST_REQUIRE(RB.isEmpty() == false);
}

BOOST_AUTO_TEST_CASE(Test_isFull) {
  RingBuffer RB(10);
  BOOST_REQUIRE(RB.isFull() == false);
  for(int i = 0; i < 10; i++) {
    RB.enqueue(i);
  }
  BOOST_REQUIRE(RB.isFull() == true);
}


  

