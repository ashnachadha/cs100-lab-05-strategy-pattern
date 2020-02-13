#ifndef __LISTCONTAINER_HPP__
#define __LISTCONTAINER_HPP__

#include <iostream>
#include <list>

#include "sort.hpp"
#include "base.hpp"
#include "container.hpp"

using namespace std;

class Sort;
class Base;

class ListContainer {
protected:
    Sort* sort_function;
    
private:
    list<Base*> table;
    
public:
    /* Constructors */
    ListContainer() : sort_function(nullptr) { };
    ListContainer(Sort* function) : sort_function(function) { };
    
    /* Non Virtual Functions */
    void set_sort_function(Sort* sort_function) { // set the type of sorting algorithm
        this sort_function = sort_function;
    }
    /* Pure Virtual Functions */
    // push the top pointer of the tree into container
    virtual void add_element(Base* element) {
        table.push_back(element);
    }
    // iterate through trees and output the expressions (use stringify())
    virtual void print() {
        //(std::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
        for (list<Base*>::iterator i = table.begin(); i != table.end(); ++i) {
            cout << (*i)->stringify();
            cout << endl;
        }
    }
    // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
    virtual void sort() {
        sort_function->sort(this);
    }
    
    /* Essentially the only functions needed to sort */
    //switch tree locations
    virtual void swap(int i, int j) {
        list<Base*>::iterator it = table.begin();
        for (unsigned x = 0; x < i; ++x) {
            ++it;
        }
        list<Base*>::iterator jit = table.begin();
        for (unsigned x = 0; x < j; ++x) {
            ++jit;
        }
        
        Base* temp = *it;
        it = jit;
        *jit = temp;
    }
    // get top ptr of tree at index i
    virtual Base* at(int i) {
        list<Base*>::iterator it = table.begin();
        
        for (unsigned j = 0; j < i; ++j) {
            ++it;
        }
        
        return *it;
    }
    // return container size
    virtual int size() {
        return table.size();
    }
};

#endif //__LISTCONTAINER_HPP__

