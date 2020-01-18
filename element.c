/***********
 * Sara Spagnoletto
 * 556693885
 * 01
 * ass06
 ***********/

#include <stdlib.h>
#include "element.h"
#include "genericBinTree.h"

// struct of alement has a key and value
struct Element {
    int key;
    int value;
};

/******************
 * Function Name: init_element
 * Input: int key, int value
 * Output: Element*
 * Function Operation: initialyzes the element
 ******************/
Element* init_element (int key, int value) {
    // allocating memory for an element
    Element* current = (Element*)malloc(sizeof(Element));
    // assigning the key and the value
    current->key = key;
    current->value = value;
    return current;
}

/******************
 * Function Name: return_value
 * Input: Element* current
 * Output: int
 * Function Operation: returns the value of an element
 ******************/
int return_value (Element* current) {
    return current->value;
}

/******************
 * Function Name: allocate_element
 * Output: Ptr
 * Function Operation: allocate element
 ******************/
Ptr allocate_element() {
    return malloc(sizeof(Element));
}

/******************
 * Function Name: destroy element
 * Input: Ptr p
 * Function Operation: frees allocated mememory of a Ptr
 ******************/
void destroy_element(Ptr p) {
    free(p);
}

/******************
 * Function Name: copy_element
 * Input: Ptr p1, Ptr p2
 * Function Operation: copies p2 into p1
 ******************/
void copy_element(Ptr p1, Ptr p2) {
    Element* i1 = (Element*) p1;
    Element* i2 = (Element*) p2;
    
    int* value1ptr = &(i1->value);
    int* key1ptr = &(i1->key);
    int* value2ptr = &(i2->value);
    int* key2ptr = &(i2->key);
    
    *value1ptr = *value2ptr;
    *key1ptr = *key2ptr;
}

/******************
 * Function Name: compare_element
 * Output: int
 * Input: Ptr p1, Ptr p2
 * Function Operation: checks which one is bigger
 ******************/
int compare_element(Ptr p1, Ptr p2) {
    Element* i1 = (Element*) p1;
    Element* i2 = (Element*) p2;
    
    if (i1->key == i2->key) {
        return 0;
    }
    
    int* key1ptr = &(i1->key);
    int* key2ptr = &(i2->key);
    
    // if the return is bigger than 0, means that p1 is bigger than p2, and viceversa
    return (*key1ptr - *key2ptr);
}

/******************
 * Function Name: print_element
 * Input: Ptr p
 * Function Operation: prints one element 
 ******************/
void print_element(Ptr p) {
    Element* i = (Element*) p;
    int* value1ptr = &(i->value);
    int* key1ptr = &(i->key);
    printf("[%d:%d]", *key1ptr, *value1ptr);
}
   


