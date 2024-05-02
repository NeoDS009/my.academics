#include <iostream>

/*
  You must seed the random number generator with the current
  time in main(), before any calls to random(); use the 
  following call:  srand( (unsigned)time( NULL ) );
*/

int random(int max)
{
  return(rand() % max);
}
