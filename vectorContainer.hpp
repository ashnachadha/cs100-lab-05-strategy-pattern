#ifndef __VECTORCONTAINER_HPP__
#define __VECTORCONTAINER_HPP__

#include<iostream>
#include<vector>
#include<exception>

#include "sort.hpp"
#include "base.hpp"
#include "container.hpp"

using namespace std;

class VectorContainer : public Container {

	protected:
		Sort* sort_function;
	private:
		vector<Base*> myVector;
	public:
		/* Constructors */
		VectorContainer() : Container() {sort_function = nullptr;}
		VectorContainer(Sort* function) : Container() { sort_function = function; }

		/*Non Virtual Functions */
		void set_sort_function(Sort* s) {
			sort_function = s;
		}
		
		/* Virtual Functions */
		//push the top pointer of the tree into container
		virtual void add_element(Base* element)
		{
			myVector.push_back(element);	
		}
		
		//iterate through trees and output the expressions
		virtual void print()
		{
			for(int i = 0; i < myVector.size(); i++)
			{
				cout << myVector.at(i)->stringify() << endl;
			}
		}
		
		//calls on the previously set sorting algorithm. checks if sort_function is not null, throw exception if otherwise
		virtual void sort()
		{
			try {
                            if (sort_function == nullptr) {
                               throw 1;
                            }
                        sort_function->sort(this);
                        }
                        catch(...) {cout << "Exeption trown: sort_function is null" << endl;}
		}

		//switch tree locations
		virtual void swap(int i, int j)
		{
			Base* temp = myVector.at(i);
			myVector.at(i) = myVector.at(j);
			myVector.at(j) = temp;
		}

		//return container size
		virtual Base* at(int i)
		{
			return myVector.at(i);
		}

		virtual int size()
		{
			return myVector.size();
		}
};

#endif //__VECTORCONTAINER_HPP__
