/*****************
Lucas Faletra
ps1a
****************/
#include <string>
#include <iostream>
using namespace std;
class LFSR{
public:
  LFSR(string seed, int t);

  int step();

  int generate(int k);

  friend ostream& operator << (ostream& out, LFSR lfsr);

private:

  string bits;
  int tap;
  int size;
};

  
