#include "vectortest.h"

#include <random>
#include <chrono>
#include <algorithm>

std::vector< std::string >
vectortest::randomstrings( size_t nr, size_t s )
{
   static std::default_random_engine gen(
      std::chrono::system_clock::now( ). time_since_epoch( ). count( ) );

   static std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345689";
   static std::uniform_int_distribution<int> distr( 0, alphabet. size( ) - 1 );

   std::vector< std::string > res;

   for( size_t i = 0; i < nr; ++ i )
   {
      std::string rand;
      for( size_t j = 0; j < s; ++ j )
      {
         rand. push_back( alphabet[ distr( gen ) ] );
      }

      res. push_back( std::move( rand ));
   }
   return res;
}

std::vector<std::string>vectortest::readfile( std::istream& input ){
  std::vector<std::string> out;
  while(!input.eof()){
    int c = input.get();
    bool go = input.good();
    std::string str;
    if(go== true && isalpha(c)){
      while(go == true && isalpha(c)){
        str += c;
        c = input.get();
        go = input.good();
      }
      out.push_back(str);
    }
  }
  return out;
}


void vectortest::sort_assign( std::vector< std::string> & v ){
for( size_t j = 0; j < v. size( ); ++ j )
  for( size_t i = 0; i < j; ++ i ){
    if( v[i] > v[j] ){
      std::string s = v[i];
      v[i] = v[j];
      v[j] = s;
    }
  }
}

void vectortest::sort_move( std::vector< std::string > &v ){
for( size_t j = 0; j < v. size( ); ++ j ){
  for( size_t i = 0; i < j; ++ i ){
    if( v[i] > v[j] ) std::swap( v[i], v[j] );
    }
  }
}

void vectortest::sort_std( std::vector< std::string > & v){
  std::sort( v. begin( ), v. end( ));
}

std::ostream&operator << ( std::ostream& out, const std::vector< std::string > & vect ){
  std::string in = "{";
  std::string end = "}";
  std::string comma = ", ";
  int size = vect.size();
  if(size > 1){
    for(int i = 0; i < size; ++i){
	     if(i != size - 1){
	        std::string temp = vect[i];
          in += temp + comma;
	     }else{
          std::string temp = vect[i];
          in += temp;
       }
     }
    in += end;
    out << in << "\n";
    return out;
  }else if(size == 1){
    std::string temp = vect[0];
    in += temp;
    in += end;
    out << in << "\n";
    return out;
  }else{
    out << "Vector is empty" << "\n";
    return out;
  }
}
