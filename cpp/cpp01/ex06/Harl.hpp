#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl 
{
  private:
    void debug( void );
    void info( void );
    void warning( void ); 
    void error( void );
  
  public:
    void complain( std::string level );
    Harl(void);
    ~Harl(void);
    Harl& operator=(const Harl& other);
    Harl(const Harl& other);
};

#endif