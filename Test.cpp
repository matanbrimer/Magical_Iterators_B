#include "doctest.h"
#include "sources/MagicalContainer.hpp"


#include<iostream>
using namespace std;
using namespace ariel;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

TEST_CASE("MagicalContainer") {
    
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(17));

   // CHECK_EQ(*container.getElement().begin(),17);

    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(25));
    CHECK_NOTHROW(container.addElement(9));
    CHECK_NOTHROW(container.addElement(3));
int arr[] ={17,2,25,9,3};
int i =0;
   for (auto it :(container).getElement()) {
       CHECK_EQ(it,arr[i]);
       i++;
    }
   // CHECK_EQ(*container.getElement().end(),3);
    CHECK_EQ(container.size(),5);

    container.removeElement(3);
    
    CHECK_EQ(*container.getElement().end(),9);
   
}
TEST_CASE("check AscendingIterator sort") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::AscendingIterator ascIter(container);
    int arr[5]= {0};
    int i =0;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it,i++) {
       arr[i] =*it;
    }
    CHECK_EQ( arr[0], 2);
    CHECK_EQ( arr[1], 3);
    CHECK_EQ( arr[2],9);
    CHECK_EQ( arr[3], 17);
    CHECK_EQ( arr[4], 25);
    //add to container and check if add to ascIter
    container.addElement(7);
    int size=0;
   for (auto it = ascIter.begin(); it != ascIter.end(); ++it,i++) {
       size++;
    }
    CHECK_EQ(size, 6);


}
TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::SideCrossIterator SidIter(container);
    int arr[5]= {0};
    int i =0;
    for (auto it = SidIter.begin(); it != SidIter.end(); ++it,i++) {
       arr[0] =*it;
    }// 2 25 3 17 9
    CHECK_EQ( arr[0], 2);
    CHECK_EQ( arr[1], 25);
    CHECK_EQ( arr[2], 3);
    CHECK_EQ( arr[3], 17);
    CHECK_EQ( arr[4], 9);


}

TEST_CASE("PrimeIterator") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::SideCrossIterator ascIter(container);
    int arr[5]= {0};
    int i =0;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it,i++) {
       arr[0] =*it;
    }
    CHECK_EQ( arr[0], 2);
    CHECK_EQ( arr[1], 3);
    CHECK_EQ( arr[2],17);



}