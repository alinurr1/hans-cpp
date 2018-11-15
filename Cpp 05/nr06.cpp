#include <fstream>
#include <iostream>
#include <random>

#include "listtest.h"
#include "vectortest.h"
#include "timer.h"

int main( int argc, char* argv [] )
{
   std::ifstream input ("text.txt", std::ifstream::binary);
   if(input){
     std::vector<std::string> inp = vectortest::readfile(input);
     std::cout << inp;
     std::cout << inp[0] << "\n";
     std::cout << inp[1] << "\n";
     std::cout << inp[2] << "\n";
     std::cout << inp[3] << "\n";
     std::cout << inp[4] << "\n";
     std::cout << inp[5] << "\n";
     std::cout << inp.size() << "\n";
   }
   return 0;

   #if 0
   std::vector<std::string >  vect = vectortest::randomstrings(10000, 50);
   std::vector< std::string > vect1 =vect;
   std::vector< std::string > vect2 =vect;
   std::list<std::string> lst = listtest::randomstrings(10000, 50);
   std::list<std::string> lst1 = lst;
   std::list<std::string> lst2 = lst;

   auto t1 = std::chrono::high_resolution_clock::now( );
   listtest::sort_move( lst );
   auto t2 = std::chrono::high_resolution_clock::now( );

   std::chrono::duration< double > d = ( t2 - t1 );

   std::cout << "sorting took " << d. count( ) << " seconds\n";

   auto t3 = std::chrono::high_resolution_clock::now( );
   listtest::sort_assign( lst1 );
   auto t4 = std::chrono::high_resolution_clock::now( );

   std::chrono::duration< double > d1 = ( t4 - t3 );

   std::cout << "sorting took " << d1. count( ) << " seconds\n";
   #endif
}
