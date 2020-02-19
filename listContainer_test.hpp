#ifndef __LISTCONTAINER_TEST_HPP__
#define __LISTCONTAINER_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.hpp"
#include "listContainer.hpp"
#include "selectionSort.hpp"


TEST(listContainerTest, AddOpToList) {
    Op* zero = new Op(0);
    ListContainer* list = new ListContainer();
    list->add_element(zero);
    
    ASSERT_EQ(list->size(), 1);
    EXPECT_EQ(list->at(0)->evaluate(), 0);
}

TEST(listContainerTest, AddOtherBasesToList) {
    Op* three = new Op(3);
    Add* add = new Add(three, three);
    
    ListContainer* list = new ListContainer();
    list->add_element(add);
    
    ASSERT_EQ(list->size(), 1);
    EXPECT_EQ(list->at(0)->evaluate(), 6);
}

TEST(listContainerTest, AddMultipleBasesToList) {
    Op* three = new Op(3);
    Add* add = new Add(three, three);
    
    ListContainer* list = new ListContainer();
    list->add_element(three);
    list->add_element(add);
    
    ASSERT_EQ(list->size(), 2);
    EXPECT_EQ(list->at(0)->evaluate(), 3);
    EXPECT_EQ(list->at(1)->evaluate(), 6);
}

TEST(listContainerTest, PrintOpFromList) {
    Op* zero = new Op(0);
    ListContainer* list = new ListContainer();
    list->add_element(zero);
    
    list->print();
}

TEST(listContainerTest, PrintMultipleOpFromList) {
    Op* zero = new Op(0);
    Op* five = new Op(5);
    ListContainer* list = new ListContainer();
    list->add_element(zero);
    list->add_element(five);

    list->print();
}

TEST(listContainerTest, PrintMultipleBaseFromList) {
    Op* zero = new Op(0);
    Op* five = new Op(5);
    Op* two = new Op(2);
    Base* add = new Add(five, two);
    Base* pow = new Pow(five, zero);
    ListContainer* list = new ListContainer();
    list->add_element(zero);
    list->add_element(five);
    list->add_element(add);
    list->add_element(pow);

    list->print();
}


TEST(listContainerTest, SwapList) {
    Op* three = new Op(3);
    Add* add = new Add(three, three);

    ListContainer* list = new ListContainer();
    list->add_element(three);
    list->add_element(add);

    ASSERT_EQ(list->size(), 2);
    EXPECT_EQ(list->at(0)->evaluate(), 3);
    EXPECT_EQ(list->at(1)->evaluate(), 6);

    list->swap(0, 1);

    ASSERT_EQ(list->size(), 2);
    EXPECT_EQ(list->at(0)->evaluate(), 6);
    EXPECT_EQ(list->at(1)->evaluate(), 3);
}


TEST(listContainerTest, SizeList) {
    Op* three = new Op(3);
    Add* add = new Add(three, three);

    ListContainer* list = new ListContainer();
    list->add_element(three);
    list->add_element(add);
    list->add_element(three);
    list->add_element(add);

    ASSERT_EQ(list->size(), 4);
    EXPECT_EQ(list->size(), 4);
}

TEST(selectionSortTest, SortListContainer){
    Op* five = new Op(5);
    Op* two = new Op(2);
    Op* three = new Op(3);

    SelectionSort* sorter = new SelectionSort();
    ListContainer* list = new ListContainer(sorter);

    list->add_element(five);
    list->add_element(two);
    list->add_element(three);

    ASSERT_EQ(list->size(), 3);
    EXPECT_EQ(list->at(0)->evaluate(), 5);
    EXPECT_EQ(list->at(1)->evaluate(), 2);
    EXPECT_EQ(list->at(2)->evaluate(), 3);
 
    list->sort();

    ASSERT_EQ(list->size(), 3);
    EXPECT_EQ(list->at(0)->evaluate(), 2);
    EXPECT_EQ(list->at(1)->evaluate(), 3);
    EXPECT_EQ(list->at(2)->evaluate(), 5);
}

/*
TEST(bubbleSortTest, SortListContainer){
    Op* five = new Op(5);
    Op* two = new Op(2);
    Op* three = new Op(3);

    BubbleSort* sorter = new BubbleSort();
    ListContainer* list = new ListContainer(sorter);

    list->add_element(five);
    list->add_element(two);
    list->add_element(three);

    ASSERT_EQ(list->size(), 3);
    EXPECT_EQ(list->at(0)->evaluate(), 5);
    EXPECT_EQ(list->at(1)->evaluate(), 2);
    EXPECT_EQ(list->at(2)->evaluate(), 3);

    list->sort();

    ASSERT_EQ(list->size(), 3);
    EXPECT_EQ(list->at(0)->evaluate(), 2);
    EXPECT_EQ(list->at(1)->evaluate(), 3);
    EXPECT_EQ(list->at(2)->evaluate(), 5);
}
*/

#endif //__LISTCONTAINER_TEST_HPP__

