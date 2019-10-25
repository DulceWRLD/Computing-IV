/****************************
Copyright Lucas Faletra 2019
**************************/
//#include "RingBuffer.hpp"
#include "GuitarString.hpp"
#include <vector>
#include <cmath>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <stdint.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>


GuitarString::GuitarString(double frequency) {
  this->RB = new RingBuffer(ceil(frequency));
}

GuitarString::GuitarString(std::vector<sf::Int16> init) {
  this->samples = init;
  this->RB = new RingBuffer(init.size());
  int i = 0;
  for(i = 0; i < init.size(); i++)
    this->RB->enqueue(int16_t(init[i]));
  //take last sample vector, load buffer
  this->buffer.loadFromSamples(&(this->samples[0]), this->samples.size(), 2, 44100);
  
  this->sounds.setBuffer(this->buffer);
}

void GuitarString::pluck() {
  //fill rb with random values

  //check if RB is full already
  //if full, empty the whole thing

  if(RB->isFull())
    {
      while(!(RB->isEmpty()))
	{
	  RB->dequeue();
	}
    }
  
  int i = 0;
  // n is random number being pushed into RingBuffer
  int16_t n;          

  // seed rand with time for truly random number
  srand(time(0));
  
  for(i = RB->size(); i < RB->cap(); i++)
    {
      n = ((rand() % 64000) - 32000);
      //n = i;
      this->RB->enqueue(n);
    }

 
}

void GuitarString::tic() {
  //do the average function
  int16_t a, b, c;
  //take first and second elements and perform karplus-strong operation
  a = this->RB->dequeue();
  b = this->RB->peek();
  c = int16_t(0.996 * ((a + b) * 0.50));//decay was 0.996 with 0.5
  this->RB->enqueue(c);
  this->n_tics++;
}

sf::Int16 GuitarString::sample() {
  return sf::Int16(this->RB->peek());
}

int GuitarString::time_() {
  return this->n_tics;
}

sf::Sound GuitarString::get_sound(){
  return this->sounds;
}

std::vector<sf::Int16> GuitarString::make_samples() {
  std::vector<sf::Int16> temp;
  this->pluck();
  int i = 0;
  for(i = 0; i < 44100 * 8; i++)
    {
      this->tic();
      this->samples.push_back(this->sample());
    }

  temp = this->samples;
  return temp;
}



