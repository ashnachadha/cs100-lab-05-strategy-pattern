#ifndef __SELECTIONSORT_HPP__
#define __SELECTIONSORT_HPP__

#include "container.hpp"
#include "sort.hpp"

class SelectionSort : public Sort {

public:
    /* Constructors */
    SelectionSort() : Sort() {}
    
    /* Pure Virtual Functions */
    virtual void sort(Container* container) {
        
        int minIndex;
        
        for (unsigned i = 0; i + 1 < container->size(); ++i) {
            
            minIndex = i;
            
            for (unsigned j = i + 1; j < container->size(); ++j) {
                
                if (container->at(j)->evaluate() < container->at(minIndex)->evaluate()) {
                    minIndex = j;
                }
                
            }
            
            container->swap(minIndex, i);
            
        }
        
        
        
    }
};

#endif //__SELECTIONSORT_HPP__

