/***********
 * Sara Spagnoletto
 * 556693885
 * 01
 * ass06
 ***********/

#ifndef ELEMENT_H
#define ELEMENT_H
#include "genericBinTree.h"
#include <stdio.h>

//typedef stuct
typedef struct Element Element;

// declarations of all funcionations used in element.c 
Element* init_element (int key, int value);
int return_value (Element*);
Ptr allocate_element(void);
void destroy_element(Ptr p);
void copy_element(Ptr p1, Ptr p2);
int compare_element(Ptr p1, Ptr p2);
void print_element(Ptr p);

#endif /* element_h */
