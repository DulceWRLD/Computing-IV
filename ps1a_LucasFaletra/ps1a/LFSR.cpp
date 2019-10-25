/*****************
Lucas Faletra
ps1a
*****************/
#include "LFSR.hpp"
#include <iostream>
#include <string>
using namespace std;

LFSR::LFSR(string seed, int t){
  this->bits = seed;
  this->size = seed.length();
  this->tap = this->size - t - 1;
}

int LFSR::step(){
  //first check if the tap is a valid index. Return -1 if it is not
  if(this->tap > this->size || this->tap < 0)
    {
      
      return -1;
    }
  int x, y, z;
  int i = 0;
  x = this->bits.at(0) - 48; //x is bit furthest to the left
  y = this->bits.at(this->tap) - 48; //y is the tap bit
  z = x ^ y;                 //XOR operation to get new rightmost bit
  while(i < this->size - 1)
    {
      this->bits.at(i) = this->bits.at(i+1); //shift all the bits to the left
      i++;
    }
  this->bits.at(this->size - 1) = z + 48;  //change the final bit to the result
  //of the XOR operation above

  return z;
}

int LFSR::generate(int k){
  //check if tap is a valid index. Return -1 if it is out of bounds
  if(this->tap > this->size || this->tap < 0)
    {
      return -1;
    }
  int count = 0;
  int i;
  for(i = 0; i < k; i++)
    {
      count *= 2;
      count += this->step();
    }
  return count;
}

ostream& operator << (ostream& out, LFSR lfsr){
  int n, i;
  for(i = lfsr.size - 1; i >= 0; i--)
    {
      n *= 2;
      n += lfsr.bits.at(i) - 48;
    }
  out << "Current value of register is: " << lfsr.bits << ' ' << n << endl;
  return out;
}

