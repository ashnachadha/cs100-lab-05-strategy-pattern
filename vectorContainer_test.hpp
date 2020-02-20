#ifndef __VECTORCONTAINER_TEST_HPP__
#define __VECTORCONTAINER_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "vectorContainer.hpp"
#include "bubbleSort.hpp"
#include "selectionSort.hpp"

TEST(vectorContainerTest, AddOpToVector) {
	Op* zero = new Op(0);
	VectorContainer* vector = new VectorContainer();
	vector->add_element(zero);
	
	ASSERT_EQ(vector->size(), 1);
	EXPECT_EQ(vector->at(0)->evaluate(), 0);
}

TEST(vectorContainerTest, AddOtherBasesToVector) {
	Op* two = new Op(2);
	Add* add = new Add(two, two);

	VectorContainer* vector = new VectorContainer();
	vector->add_element(add);

	ASSERT_EQ(vector->size(), 1);
	EXPECT_EQ(vector->at(0)->evaluate(), 4);
}

TEST(vectorContainerTest, AddMultipleBasesToVector) {
	Op* two = new Op(2);
	Add* add = new Add(two, two);
	
	VectorContainer* vector = new VectorContainer();
	vector->add_element(two);
	vector->add_element(add);

	ASSERT_EQ(vector->size(), 2);
	EXPECT_EQ(vector->at(0)->evaluate(), 2);
	EXPECT_EQ(vector->at(1)->evaluate(), 4);
}

TEST(vectorContainerTest, PrintOpFromVector) {
	Op* zero = new Op(0);
	VectorContainer* vector = new VectorContainer();
	vector->add_element(zero);

	vector->print();
}

TEST(vectorContainerTest, PrintMultipleBasesFromVector) {
	Op* zero = new Op(0);
	Op* four = new Op(4);
	Op* three = new Op(3);

	Base* add = new Add(four, three);
	Base* div = new Div(zero, add);

	VectorContaienr* vector = new VectorContainer();
	vector->add_element(zero);
	vector->add_element(four);
	vector->add_element(add);
	vector->add_element(div);

	vector->print();
}

TEST(vectorContainerTest, SwapVector) {
	Op* three = new Op(3);
	Add* add = new Add(three, three);

	VectorContainer* vector = new VectorContainer();
	vector->add_element(three);
	vector->add_element(add);

	ASSERT_EQ(vector->size(), 2);
	EXPECT_EQ(vector->at(0)->evaluate(), 3);
	EXPECT_EQ(vector->at(1)->evaluate(), 6);

	vector->swap(0,1);
	
	ASSERT_EQ(vector->size(), 2);
	EXPECT_EQ(vector->at(0)->evaluate(), 6);
	EXPECT_EQ(vector->at(0)->evaluate(), 3);
}

TEST(vectorContainerTest, SizeList) {
	Op* three = new Op(3);
	Add* add = new Add(three, three);

	VectorContainer* vector = new VectorContainer();
	vector->add_element(three);
	vector->add_element(add);
	vector->add_element(three);
	vector->add_element(add);

	ASSERT_EQ(vector->size(), 4);
	EXPECT_EQ(vector->size(), 4);
}

TEST(vectorContainerTest, SortException) {
	VectorContainer* vector = new VectorContainer();
	vector->sort();
}

TEST(bubbleSortTest, SortOpBaseVectorContainer) {
	Op* five = new Op(5);
	Op* two = new Op(2);
	Op* three = new Op(3);

	BubbleSort* sorter = new BubbleSort();
	VectorContainer* vector = new VectorContainer(sorter);

	vector->add_element(five);
	vector->add_element(two);
	vector->add_element(three);

	ASSERT_EQ(vector->size(), 3);
	EXPECT_EQ(vector->at(0)->evaluate(), 5);
	EXPECT_EQ(vector->at(1)->evalute(), 2);
	EXPECT_EQ(vector->at(2)->evaluate(), 3);

	vector->sort();

	ASSERT_EQ(vector->size(), 3);
	EXPECT_EQ(vector->at(0)->evaluate(), 2);
	EXPECT_EQ(vector->at(1)->evalute(), 3);
        EXPECT_EQ(vector->at(2)->evaluate(), 5);
}

TEST(bubbleSortTest, SetSortOpBaseVectorContainer) {
	Op* five = new Op(5);
        Op* two = new Op(2);
        Op* three = new Op(3);

        BubbleSort* sorter = new BubbleSort();
        VectorContainer* vector = new VectorContainer(sorter);
	vector->set_sort_function(sorter);

	vector->add_element(five);
	vector->add_element(two);
	vector->add_element(three);

	ASSERT_EQ(vector->size(), 3);
        EXPECT_EQ(vector->at(0)->evaluate(), 5);
        EXPECT_EQ(vector->at(1)->evalute(), 2);
        EXPECT_EQ(vector->at(2)->evaluate(), 3);

        vector->sort();

        ASSERT_EQ(vector->size(), 3);
        EXPECT_EQ(vector->at(0)->evaluate(), 2);
        EXPECT_EQ(vector->at(1)->evalute(), 3);
        EXPECT_EQ(vector->at(2)->evaluate(), 5);
}

TEST(bubbleSortTest, SortVectorMultipleBaseContainer) {
	srand(523);
	
	Base* four = new Op(4);
   	Base* two = new Op(2);
    	Base* rand = new Rand();
    	Base* add = new Add(four, two);
    	Base* sub = new Sub(four, two);
    	Base* mult = new Mult(four, two);
    	Base* div = new Div(four, two);
    	Base* pow = new Pow(four, two);

    	BubbleSort* sorter = new BubbleSort();
    	VectorContainer* vector = new VectorContainer(sorter);

	vector->add_element(four);
	vector->add_element(two);
	vector->add_element(rand);
	vector->add_element(add);
	vector->add_element(sub);
	vector->add_element(mult);
	vector->add_element(div);
	vector->add_element(pow);
	
	ASSERT_EQ(vector->size(), 8);
	EXPECT_EQ(vector->at(0)->evaluate(), 4);
    	EXPECT_EQ(vector->at(1)->evaluate(), 2);
    	EXPECT_EQ(vector->at(2)->evaluate(), 55);
    	EXPECT_EQ(vector->at(3)->evaluate(), 6);
    	EXPECT_EQ(vector->at(4)->evaluate(), 2);
    	EXPECT_EQ(vector->at(5)->evaluate(), 8);
    	EXPECT_EQ(vector->at(6)->evaluate(), 2);
    	EXPECT_EQ(vector->at(7)->evaluate(), 16);

	vector->sort();

	ASSERT_EQ(vector->size(), 8);
	EXPECT_EQ(vector->at(0)->evaluate(), 2);
    	EXPECT_EQ(vector->at(1)->evaluate(), 2);
    	EXPECT_EQ(vector->at(2)->evaluate(), 2);
    	EXPECT_EQ(vector->at(3)->evaluate(), 4);
    	EXPECT_EQ(vector->at(4)->evaluate(), 6);
    	EXPECT_EQ(vector->at(5)->evaluate(), 8);
    	EXPECT_EQ(vector->at(6)->evaluate(), 16);
    	EXPECT_EQ(vector->at(7)->evaluate(), 55);
}

TEST(selectionSortTest, SortOpBaseVectorContainer) {
    	Op* five = new Op(5);
    	Op* two = new Op(2);
    	Op* three = new Op(3);

    	SelectionSort* sorter = new SelectionSort();
    	VectorContainer* vector = new VectorContainer(sorter);

    	vector->add_element(five);
    	vector->add_element(two);
    	vector->add_element(three);

    	ASSERT_EQ(vector->size(), 3);
    	EXPECT_EQ(vector->at(0)->evaluate(), 5);
    	EXPECT_EQ(vector->at(1)->evaluate(), 2);
    	EXPECT_EQ(vector->at(2)->evaluate(), 3);
 
    	vector->sort();
	
    	ASSERT_EQ(vector->size(), 3);
    	EXPECT_EQ(vector->at(0)->evaluate(), 2);
    	EXPECT_EQ(vector->at(1)->evaluate(), 3);
    	EXPECT_EQ(vector->at(2)->evaluate(), 5);
}

TEST(selectionSortTest, SetSortOpBaseVectorContainer) {
    	Op* five = new Op(5);
    	Op* two = new Op(2);
    	Op* three = new Op(3);
    
    	VectorContainer* vector = new VectorContainer();
    	SelectionSort* sorter = new SelectionSort();
    	vector->set_sort_function(sorter);

    	vector->add_element(five);
    	vector->add_element(two);
    	vector->add_element(three);
	
    	ASSERT_EQ(vector->size(), 3);
    	EXPECT_EQ(vector->at(0)->evaluate(), 5);
    	EXPECT_EQ(vector->at(1)->evaluate(), 2);
    	EXPECT_EQ(vector->at(2)->evaluate(), 3);

    	vector->sort();

    	ASSERT_EQ(vector->size(), 3);
    	EXPECT_EQ(vector->at(0)->evaluate(), 2);
    	EXPECT_EQ(vector->at(1)->evaluate(), 3);
    	EXPECT_EQ(vector->at(2)->evaluate(), 5);
}



TEST(selectionSortTest, SortVectorMutipleBaseContainer){
    	srand(523);    

    	Base* four = new Op(4);
    	Base* two = new Op(2);
    	Base* rand = new Rand();
    	Base* add = new Add(four, two);
    	Base* sub = new Sub(four, two);
    	Base* mult = new Mult(four, two);
    	Base* div = new Div(four, two);
    	Base* pow = new Pow(four, two);

    	SelectionSort* sorter = new SelectionSort();
    	VectorContainer* vector = new VectorContainer(sorter);

    	vector->add_element(four);
    	vector->add_element(two);
    	vector->add_element(rand);
    	vector->add_element(add);
    	vector->add_element(sub);
    	vector->add_element(mult);
    	vector->add_element(div);
    	vector->add_element(pow);

    	ASSERT_EQ(vector->size(), 8);
    	EXPECT_EQ(vector->at(0)->evaluate(), 4);
    	EXPECT_EQ(vector->at(1)->evaluate(), 2);
    	EXPECT_EQ(vector->at(2)->evaluate(), 55);
    	EXPECT_EQ(vector->at(3)->evaluate(), 6);
    	EXPECT_EQ(vector->at(4)->evaluate(), 2);
    	EXPECT_EQ(vector->at(5)->evaluate(), 8);
    	EXPECT_EQ(vector->at(6)->evaluate(), 2);
    	EXPECT_EQ(vector->at(7)->evaluate(), 16);
	
    	vector->sort();

    	ASSERT_EQ(vector->size(), 8);
    	EXPECT_EQ(vector->at(0)->evaluate(), 2);
    	EXPECT_EQ(vector->at(1)->evaluate(), 2);
    	EXPECT_EQ(vector->at(2)->evaluate(), 2);
    	EXPECT_EQ(vector->at(3)->evaluate(), 4);
    	EXPECT_EQ(vector->at(4)->evaluate(), 6);
    	EXPECT_EQ(vector->at(5)->evaluate(), 8);
    	EXPECT_EQ(vector->at(6)->evaluate(), 16);
    	EXPECT_EQ(vector->at(7)->evaluate(), 55);
}

#endif //__VECTORCONTAINER_TEST_HPP__		
