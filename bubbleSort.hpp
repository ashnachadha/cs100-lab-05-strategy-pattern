#ifndef __BUBBLESORT_HPP__
#define __BUBBLESORT_HPP__

#include "container.hpp"
#include "sort.hpp"

class BubbleSort : public Sort {

	public:
		/* Constructors */
		BubbleSort() : Sort() {}

		/* Pure Virtual Functions */
		virtual void sort(Container* container) {
			
            for (unsigned i = 0; i + 1 < container->size(); ++i) {
                for (unsigned j = 0; j + i + 1 < container->size(); ++j) {
                    if (container->at(j)->evaluate() > container->at(j+1)->evaluate()) {
                        container->swap(j, j+1);
                    }
                }
            }
            
		}			
};

#endif //__BUBBLESORT_HPP__
