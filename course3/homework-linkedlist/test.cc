#include <cassert>
#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>

#include "linkedlist.h"

template<typename ListType>
void ListTest() {

    ListType testList;
    assert(testList.empty());
    assert(testList.size() == 0);

    testList.push_front(123);
    assert(!testList.empty());
    assert(testList.size() == 1);

    testList.push_front(124);
    assert(testList.size() == 2);

    testList.push_front(125);
    assert(testList.size() == 3);

    testList.pop_front();
    assert(testList.size() == 2);

    testList.pop_front();
    assert(testList.size() == 1);

    testList.pop_front();
    assert(testList.empty());
    assert(testList.size() == 0);

    ListType testList2 = {1, 3, 5, 7};
    assert(testList2.size() == 4);

    assert(testList2.front() == 1);
    testList2.pop_front();

    assert(testList2.front() == 3);
    testList2.pop_front();

    assert(testList2.front() == 5);
    testList2.pop_front();

    assert(testList2.front() == 7);
    testList2.pop_front();

    testList2 = {123, 124, 125, 126, 127, 128, 129, 130};
    assert(testList2.size() == 8);

    testList2.erase(testList2.begin());
    assert(testList2.size() == 7);
    assert(testList2.front() == 124);

    testList2.erase(++++testList2.begin());
    assert(testList2.size() == 6);
    assert(testList2.front() == 124);

    testList2.pop_front();
    assert(testList2.front() == 125);

    testList2.pop_front();
    assert(testList2.front() == 127);

    testList2.pop_front();
    assert(testList2.front() == 128);

    testList2.pop_front();
    assert(testList2.front() == 129);

    testList2.pop_front();
    assert(testList2.front() == 130);

    testList2 = {"mau", "dav"};
    std::cout << "size: " << testList2.size() << std::endl;
    std::cout << "front: " << testList2.front() << std::endl;
    assert(testList2.size() == 2);

    testList2 = {1,2,3,4,5};

    assert(std::accumulate(testList2.begin(), testList2.end(), 0) == 15);

    std::copy(testList.begin(), testList.end(), std::front_inserter(testList2));

//    testList2 = {3,5,1,2,4};
//    assert(std::fill(testList2.begin(), testList2.end(), 10));
//
//    testList2 = {3,5,1,2,4};
//    assert(std::min(testList2) == 1);
//

}

int main() {
    std::cout << "list" << std::endl; 

    std::cout << "testing std::list" << std::endl;
    ListTest<std::list<int>>();

    std::cout << "testing mau::list" << std::endl;
    ListTest<mau::list<int>>();

    return 0;
}