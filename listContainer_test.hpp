#ifndef __LISTCONTAINER_TEST_HPP__
#define __LISTCONTAINER_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "listContainer.hpp"

TEST(listContainerTest, AddOpToList) {
    Op* zero = new Op(0);
    ListContainer* list = new ListContainer();
    list.add_element(zero);
    
    ASSERT_EQ(list->size(), 1);
    EXPECT_EQ(list->at(0)->evaluate(), 0);
}


#endif //__LISTCONTAINER_TEST_HPP__

