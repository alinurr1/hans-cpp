#ifndef STRING_INCLUDED 
#define STRING_INCLUDED 1

#include <iostream> 
#include <cstring>

class string;
std::ostream& operator << ( std::ostream&, const string& );

struct string
{
   size_t len;
   char *p;

   using iterator = char* ;
   using const_iterator = const char* ;
   const_iterator begin( ) const { return p; }
   const_iterator end( ) const { return p + len; }
   iterator begin( ) { return p; }
   iterator end( ) { return p + len; }
 
   char operator [] ( size_t i ) const { 
      if( i >= len ) 
         throw std::runtime_error( "No such index"); 
      return p[i];
   }

   char& operator [] ( size_t i ) { 
      if( i >= len ) 
         throw std::runtime_error( "No such index"); 
      return p[i];
   }

   size_t size( ) const{ return len;}

   string( )
      : len{0},
        p{nullptr}
   {
	std::cout << "  Default constructor " << "\n";
   }

   string( const char* c )
      : len{ strlen(c) },
        p{ new char[ len ] }
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = c[i];
      std::cout << "  Char constructor for " << *this << "\n";
   }


   string( string&& s ) noexcept
      : len{ s. len },
        p{ s. p }
      {
        s.len = 0; 
        s.p = nullptr;
        std::cout << "  Moving constructor for " << *this << "\n";
      }

   string( const string& s )
      : len{ s. len },
        p{ new char[ len ] } 
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = s.p[i];

      std::cout << "  Copying constructor for " << *this << "\n";
   }


   const string& operator = ( string&& s ) noexcept
   {
      std::swap(p, s.p);
      std::swap(len, s.len);
      std::cout << " Moving assignment for " << *this << "\n";
      return *this;
   }


   string& operator = ( const string& s )
   {
      // Not only for efficiency, but also for assignment:
      if( len != s. len )
      {
         delete[] p;
         p = new char[ s. len ];
         len = s. len; 
      }
      for( size_t i = 0; i != len; ++ i )
         p[i] = s.p[i];

      std::cout << " copying assignment for " << *this << "\n";
      return *this;
   }

   ~string( )
   {
      std::cout << "Destructor for " << *this << "\n";
      delete[] p; 
   }

   string& operator += ( char c );

};

string& operator += ( string& s1, const string& s2 );

string operator + ( string s1, const string& s2 );

bool operator == ( const string& s1, const string& s2 );

bool operator < ( const string& s1, const string& s2 );

inline bool operator != ( const string& s1, const string& s2 ){return !(s1==s2);}

inline bool operator > ( const string& s1, const string& s2 ){return !(s1<s2);}

inline bool operator <= ( const string& s1, const string& s2 ){return((s1<s2) || (s1==s2));}

inline bool operator >= ( const string& s1, const string& s2 ){return((s1>s2) || (s1==s2));}

const string& greater( const string& s1, const string& s2 );

#endif


