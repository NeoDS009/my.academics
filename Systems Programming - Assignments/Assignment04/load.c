#include "defs.h"


/*
  Function: loadResData
  Purpose: Load sample reservation data into the given restaurant structure.
  Parameters:
    in: RestaurantType* r - pointer to the restaurant structure
    out: None
    in/out: None
    return: None
*/
void loadResData(RestaurantType* r) {
  createResv(r, 100,  2023, 12,  3, 14, 30);
  createResv(r, 1002, 2023, 14,  3, 14, 30);
  createResv(r, 1002, 2023, 12, 32, 14, 30);

  createResv(r, 1001, 2023, 12, 9, 17, 30);
  createResv(r, 1005, 2023, 12, 9, 19, 0);
  createResv(r, 1002, 2023, 12, 9, 19, 0);
  createResv(r, 1003, 2023, 12, 9, 19, 0);
  createResv(r, 1004, 2023, 12, 9, 19, 0);

  createResv(r, 1006, 2023, 12, 9, 19, 30);
  createResv(r, 1006, 2023, 12, 9, 18, 30);
  createResv(r, 1006, 2023, 12, 9, 18, 30);
  createResv(r, 1001, 2023, 12, 9, 20, 30);
  createResv(r, 1004, 2023, 12, 9, 20, 0);
  createResv(r, 1002, 2023, 12, 9, 21, 0);

  createResv(r, 1004, 2023, 12, 8, 20, 45);
  createResv(r, 1003, 2023, 12, 8, 19, 45);
  createResv(r, 1006, 2023, 12, 8, 18, 0);
  createResv(r, 1004, 2023, 12, 8, 20, 0);
  createResv(r, 1004, 2023, 12, 8, 20, 15);
  createResv(r, 1003, 2023, 12, 8, 20, 15);
  createResv(r, 1004, 2023, 12, 8, 21, 0);
  createResv(r, 1001, 2023, 12, 8, 20, 30);
  createResv(r, 1001, 2023, 12, 8, 19, 15);
  createResv(r, 1006, 2023, 12, 8, 19, 15);
  createResv(r, 1001, 2023, 12, 8, 19, 0);
}


/*
  Function: loadPatronData
  Purpose: Load sample patron data into the given restaurant structure.
  Parameters:
    in: RestaurantType* r - pointer to the restaurant structure
    out: None
    in/out: None
    return: None
*/
void loadPatronData(RestaurantType* r) {
  addPatron(&r->patrons, "Juliet");
  addPatron(&r->patrons, "Sayid");
  addPatron(&r->patrons, "Jack");
  addPatron(&r->patrons, "Kate");
  addPatron(&r->patrons, "James");
  addPatron(&r->patrons, "Hugo");
}
