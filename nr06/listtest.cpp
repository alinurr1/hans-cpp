#include "listtest.h"

#include <random>
#include <chrono>
#include <algorithm>

std::list<std::string>
listtest::randomstrings( size_t nr, size_t s ){
  static std::default_random_engine gen(
     std::chrono::system_clock::now( ). time_since_epoch( ). count( ) );

  static std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345689";
  static std::uniform_int_distribution<int> distr( 0, alphabet. size( ) - 1 );

  std::list< std::string > res;

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

std::list<std::string> readfile( std::istream& input){
  std::list<std::string> out;
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

void listtest::sort_assign( std::list< std::string > & v ){
    for (std::list<std::string>::iterator j = v.begin(); j != v.end(); ++j)
        for (std::list<std::string>::iterator i = v.begin(); i != j; ++i){
            if (*i > *j){
                std::string str = *j;
                (*i) = (*j);
                *j = str;
            }
        }
}


void listtest::sort_move( std::list< std::string > & v ){
    for (std::list<std::string>::iterator j = v.begin(); j != v.end(); ++j){
        for (std::list<std::string>::iterator i = v.begin(); i != j; ++i){
            if (*i > *j)
                std::swap(*i, *j);
        }
    }
}

std::ostream&operator << ( std::ostream&out , const std::list< std::string> &list ){
  std::string in = "{";
  std::string end = "}";
  std::string comma = ", ";
  if(list.size() > 1){
    std::list<std::string>::const_iterator i;
    for(i = list.begin(); i != list.end(); i++){
      in += *i + comma;
    }
    in += end;
    out << in << "\n";
    return out;
  }else if(list.size() == 1){
    std::string e = list.front();
    in += e;
    in += end;
    out << in << "\n";
    return out;
  }else{
    out << "List is empty" << "\n";
    return out;
  }
}
