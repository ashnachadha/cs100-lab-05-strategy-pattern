#ifndef __LISTCONTAINER_TEST_HPP__
#define __LISTCONTAINER_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.hpp"
#include "listContainer.hpp"

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

#endif //__LISTCONTAINER_TEST_HPP__

