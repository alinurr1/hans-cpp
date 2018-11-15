#include <iostream>
#include <fstream> 
#include <stdexcept>
#include <list>
#include <map> 
#include <unordered_map> 
#include <vector> 
#include <sstream>
#include "string.h"

int main( int argc, char* argv [ ] )
{
   std::cout << "Lab 4" << "\n";
   string sw1 = "Alinur";
   string sw2 = "hallo";
   std::swap( sw1, sw2 );
   std::cout << ( sw1 + ", " + sw2 ) << "\n";

   std::cout << string( "this is a string" ) << "\n";
   sw2 = ( sw1 + "!" );
   std::cout << "Greater operator is being tested: " << "\n";
   std::cout << "===============\n";
   string zz = "zz";
   std::cout << "before:\n";
   string max = greater( greater( "aa", string( "b" ) + string( "c" )),    greater( zz, string( "cc" )));
   std::cout << "after:\n";
   std::cout << "max = " << max << "\n";
}


