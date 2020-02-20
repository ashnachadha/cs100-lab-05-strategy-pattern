#ifndef __BUBBLESORT_HPP__
#define __BUBBLESORT_HPP__

#include "container.hpp"
#include "sort.hpp"

class BubbleSort : Sort() {

	public:
		/* Constructors */
		BubbleSort() : Sort() {}

		/* Pure Virtual Functions */
		virtual void sort(Container* container) {
			int i, j, flag = 1;
			for(i = 1; (i <= container->size()) && flag; i++)
			{
				flag = 0;
				for(j = 0; j < container->size() - 1; j++)
				{
					if(container->at(j+1)->evaluate() > container->at(j)->evaluate())
					{
						container->swap(j, j+1);
						flag = 1;
					}
				}
			}
		}			
};

#endif //__BUBBLESORT_HPP__
