/***********
 * Sara Spagnoletto
 * 556693885
 * 01
 * ass06
 ***********/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"
#include "element.h"
#include "genericBinTree.h"

// struct of dictionary cointaning one root
struct Dictionary {
    BinTree* root;
};

// defining BinTreeFunctions
static const BinTreeFunctions element_funcs = {
    allocate_element,
    destroy_element,
    copy_element,
    compare_element,
    print_element,
};

/******************
 * Function Name: init_dictionary
 * Output: Dictionary*
 * Function Operation: initialyzes the dictionary
 ******************/
Dictionary* initDictionary() {
    // allocating memory for d
    Dictionary* d = (Dictionary*)malloc(sizeof(Dictionary));
    // checking if it failed to allocate
    if (d==NULL) {
        return NULL;
    }
    // creating a binTree and assigning to d->root 
    d->root = createBinTree(element_funcs);
    // checking if it failed to allocate
    if (d->root==NULL) {
        return NULL;
    }
    
    return d;
}

/******************
 * Function Name: destroyDictionary
 * Input: Dictionary* d
 * Function Operation: freeis allocated memory for a dictionary
 ******************/
void destroyDictionary(Dictionary* d) {
    destroyBinTree(d->root);
    free(d);
}

// returns size of dictionary
int sizeOfDictionary(Dictionary* d) {
    return sizeOfBinTree(d->root);
}

/******************
 * Function Name: putInDictionary
 * Input: Dictionary* d, int key, int value
 * Output: Result
 * Function Operation: put an element inside the dictionary
 ******************/
Result putInDictionary(Dictionary* d, int key, int value) {
    // creating a current element with key and value
    Element* current = init_element(key, value);
    // adding to the dictionary tree the current element
    Result result  = addToBinTree(d->root, current);
    // if it failed it means the element is already in
    if (result==FAILURE) {
        // taking out of the dictionary the key that is already in
        removeFromDictionary(d, key);
        // freeing the current element
        destroy_element(current);
        // and recalling the function now with a modified d
        return putInDictionary(d, key, value);
    }
    // freeing the current element
    destroy_element(current);
    
    return result;
}

/******************
 * Function Name: getFromDictionary
 * Input: Dictionary* d, int key
 * Output: int
 * Function Operation: gets the value assigned to a cartein key inside the dicitonary
 ******************/
int getFromDictionary(Dictionary* d, int key) {
    // initialyzes an element with key and value 0
    Element* find_element = init_element(key, 0);
    // looks in the dicionary tree for the root having that particular key
    BinTree* find_root = findInBinTree(d->root, find_element);
    // if it couldnt find in the dictionary a root like that
    if (find_root==NULL) {
        // frees the element and returns 0
        destroy_element(find_element);
        return 0;
    }
    // freeing the element used to find
    destroy_element(find_element);
    // creating another new element and setting it equale to the element taken from the find_root
    Element* new_element = createCopyOfValueInRoot(find_root);
    // assinging the value of the new_element to an int value
    int value =  return_value(new_element);
    // detroying also the secondo element (new_element) allocated before
    destroy_element(new_element);
    
    // and returning the value we have found
    return value;
}

/******************
 * Function Name: removeFromDictionary
 * Input: Dictionary* d, int key
 * Output: Result
 * Function Operation: removes an element from the dictionary
 ******************/
Result removeFromDictionary(Dictionary* d, int key) {
    // first looks for the value of that particular key
    int value = getFromDictionary(d, key);
    // initializing an element with that key and value
    Element* current = init_element(key, value);
    // removes from dictionary the current element
    Result result = removeFromBinTree(&(d->root), current);
    // frees the memory allocated for current
    destroy_element(current);
    return result;
}

/******************
 * Function Name: printDictionary
 * Input: Dictionary* d
 * Function Operation: prints the dicitonary
 ******************/
void printDictionary(Dictionary* d) {
    // printing parenthesys, element, and parenthesys again
    printf ("{");
    printInOrder(d->root);
    printf ("}");
}



/******************
* Function Name: createDictionaryFromArrays
* Input:int keys[], int values[], int size
* Output: Dictionary*
* Function Operation: creates a dictionary from an array of keys and values
******************/
Dictionary* createDictionaryFromArrays(int keys[], int values[], int size) {
    // allocating space for an array of elements
    Ptr* arr = malloc(size * sizeof(Element*));
    for (int i=0; i<size; i++) {
        arr[i] = (init_element(keys[i], values[i]));
    }
    // allocating space for a dictionary
    Dictionary* d = (Dictionary*)malloc(sizeof(Dictionary));
    // checking if it failed to allocate
    if (d==NULL) {
        return NULL;
    }
    // setting d->root
    d->root = createBinTree(element_funcs);
    
    // adding to the dictionary the arr elements
    for (int i=0; i<size; i++) {
        putInDictionary(d, keys[i], values[i]);
    }
    
    // freeing all allocated memory for the elements
    for (int i=0; i<size; i++) {
        destroy_element(arr[i]);
    }
    // freeing the arr
    free(arr);

    return d;
}







