#include <iostream>
#include <vector>
#include <algorithm> 
#include "doctest.h"
#include "sources/MagicalContainer.hpp"
using namespace std;
using namespace ariel;

TEST_SUITE("Magical Container class tests") {
    
    TEST_CASE("test for add element and size method") {
        MagicalContainer MC;
        MC.addElement(7);
        MC.addElement(4);
        MC.addElement(6);
        MC.addElement(22);
        MC.addElement(11);
        CHECK(MC.size() == 5);
    }
    TEST_CASE("test the get and the set function") {
        MagicalContainer MC;
        MC.addElement(7);
        MC.addElement(4);
        MC.addElement(6);
        MC.addElement(22);
        MC.addElement(11);
        CHECK(MC.getelem()[0] == 7);
        CHECK(MC.getelem()[1] == 4);
        CHECK(MC.getelem()[2] == 6);
        CHECK(MC.getelem()[3] == 22);
        CHECK(MC.getelem()[4] == 11);
        vector<int> elem {2};
        MC.setelem(elem);
        CHECK(MC.getelem()[0] == 2);
        CHECK(MC.size() == 1);
    }
    TEST_CASE("test remove element method") {
        MagicalContainer MC;
        MC.addElement(7);
        MC.addElement(4);
        MC.addElement(6);
        CHECK_NOTHROW(MC.removeElement(7));
        CHECK_NOTHROW(MC.removeElement(4));
        CHECK(MC.size() == 1);
        //should throw exception
        CHECK_THROWS(MC.removeElement(4));
    }
}

TEST_SUITE("Ascending Iterator class tests") {
    MagicalContainer container;

    TEST_CASE("Test for Duplicates") {
        MagicalContainer MC;
        MC.addElement(7);
        MC.addElement(7);
        CHECK(MC.size() == 2);
        MagicalContainer::AscendingIterator ascIter(container);
        CHECK(*(ascIter.begin()) == 7);
        ++ascIter;
        CHECK(*(ascIter.begin()) == 7);
    }

    TEST_CASE("Iterator Invalidation Test") {
        MagicalContainer MC;
        MC.addElement(7);
        MagicalContainer::AscendingIterator ascIter(container);
        MC.addElement(6);
        CHECK_THROWS(ascIter.begin()); // assumes your implementation throws if the iterator is invalidated
    }

    TEST_CASE("Tests for Large Inputs") {
        MagicalContainer MC;
        for(int i = 0; i < 10000; ++i) {
            MC.addElement(i);
        }
        CHECK(MC.size() == 10000);
    }

    TEST_CASE("Tests for Different Orderings") {
        MagicalContainer MC;
        MC.addElement(7);
        MC.addElement(4);
        MagicalContainer::AscendingIterator ascIter(container);
        CHECK(*(ascIter.begin()) == 4);
    }

    TEST_CASE("Invalid Operation Tests") {
        MagicalContainer MC;
        MC.addElement(7);
        MagicalContainer::AscendingIterator ascIter(container);
        CHECK_THROWS(++ascIter.end()); // assuming that iterator throws when you try to increment end
    }


  
    TEST_CASE("test for the <, >, != ,== operators") {
        container.addElement(7);
        container.addElement(4);
        container.addElement(6);
        container.addElement(22);
        container.addElement(11);
        MagicalContainer::AscendingIterator ascIter(container);
        auto b = ascIter.begin();
        auto e = ascIter.end();
        CHECK(*b > *e);
        CHECK(*b < *e);
        CHECK(*b !=* e);
        CHECK_FALSE(*b == *e);
    }
    TEST_CASE("test for the ++ operator") {
        container.addElement(7);
        container.addElement(4);
        container.addElement(6);
        container.addElement(22);
        MagicalContainer::AscendingIterator ascIter(container);
        auto b = ascIter.begin();
        CHECK_EQ(*b, 4);
        CHECK_NOTHROW(++b);
        CHECK_EQ(*b, 6);
        CHECK_NOTHROW(++b);
        CHECK_EQ(*b, 7);
        CHECK_THROWS(++b);
        CHECK_EQ(*b, 22);
        CHECK_THROWS(++b);
    }
}
TEST_SUITE("SideCross Iterator iterator class tests") {
    MagicalContainer container;
    TEST_CASE("Test for Duplicates") {
        MagicalContainer MC;
        MC.addElement(7);
        MC.addElement(7);
        CHECK(MC.size() == 2);
        MagicalContainer::PrimeIterator ascIter(container);
        CHECK(*(ascIter.begin()) == 7);
        ++ascIter;
        CHECK(*(ascIter.begin()) == 7);
    }

    TEST_CASE("Iterator Invalidation Test") {
        MagicalContainer MC;
        MC.addElement(7);
        MagicalContainer::PrimeIterator ascIter(container);
        MC.addElement(6);
        CHECK_THROWS(ascIter.begin()); // assumes your implementation throws if the iterator is invalidated
    }

    TEST_CASE("Tests for Large Inputs") {
        MagicalContainer MC;
        for(int i = 0; i < 10000; ++i) {
            MC.addElement(i);
        }
        CHECK(MC.size() == 10000);
    }

    TEST_CASE("Tests for Different Orderings") {
        MagicalContainer MC;
        MC.addElement(7);
        MC.addElement(4);
        MagicalContainer::PrimeIterator ascIter(container);
        CHECK(*(ascIter.begin()) == 4);
    }

    TEST_CASE("Invalid Operation Tests") {
        MagicalContainer MC;
        MC.addElement(7);
        MagicalContainer::PrimeIterator ascIter(container);
        CHECK_THROWS(++ascIter.end()); // assuming that iterator throws when you try to increment end
    }




    TEST_CASE("test begin end methods with <, >, !=") {
        container.addElement(7);
        container.addElement(4);
        container.addElement(6);
        container.addElement(22);
        container.addElement(11);
        MagicalContainer::SideCrossIterator ascIter(container);
        auto b = ascIter.begin();
        auto e = ascIter.end();
        CHECK_FALSE(*b <*e);
        CHECK(*b > *e);
        CHECK(*b != *e);
        CHECK_FALSE(*b == *e);
    }
    TEST_CASE("test begin end methods with *,++") {
        container.addElement(7);
        container.addElement(4);
        container.addElement(6);
        container.addElement(22);
        MagicalContainer::SideCrossIterator ascIter(container);
        auto b = ascIter.begin();
        CHECK_EQ(*b, 4);
        CHECK_NOTHROW(++b);
        CHECK_EQ(*b, 22);
        CHECK_NOTHROW(++b);
        CHECK_EQ(*b,6 );
        CHECK_THROWS(++b);
        CHECK_EQ(*b, 7);
        CHECK_THROWS(++b);
    }
}
TEST_SUITE("Prime Iterator iterator class tests") {
    MagicalContainer container;
        TEST_CASE("Test for Duplicates") {
        MagicalContainer MC;
        MC.addElement(7);
        MC.addElement(7);
        CHECK(MC.size() == 2);
        MagicalContainer::SideCrossIterator ascIter(container);
        CHECK(*(ascIter.begin()) == 7);
        ++ascIter;
        CHECK(*(ascIter.begin()) == 7);
    }

    TEST_CASE("Iterator Invalidation Test") {
        MagicalContainer MC;
        MC.addElement(7);
        MagicalContainer::SideCrossIterator ascIter(container);
        MC.addElement(6);
        CHECK_THROWS(ascIter.begin()); // assumes your implementation throws if the iterator is invalidated
    }

    TEST_CASE("Tests for Large Inputs") {
        MagicalContainer MC;
        for(int i = 0; i < 10000; ++i) {
            MC.addElement(i);
        }
        CHECK(MC.size() == 10000);
    }

    TEST_CASE("Tests for Different Orderings") {
        MagicalContainer MC;
        MC.addElement(7);
        MC.addElement(4);
        MagicalContainer::SideCrossIterator ascIter(container);
        CHECK(*(ascIter.begin()) == 4);
    }

    TEST_CASE("Invalid Operation Tests") {
        MagicalContainer MC;
        MC.addElement(7);
        MagicalContainer::SideCrossIterator ascIter(container);
        CHECK_THROWS(++ascIter.end()); // assuming that iterator throws when you try to increment end
    }

 


  
        TEST_CASE("test begin end methods with <, >, !=") {
        container.addElement(7);
        container.addElement(4);
        container.addElement(6);
        container.addElement(11);
        MagicalContainer::PrimeIterator ascIter(container);
        auto b = ascIter.begin();
        auto e = ascIter.end();
        CHECK(*b <*e);
        CHECK_FALSE(*b > *e);
        CHECK(*b != *e);
        CHECK_FALSE(*b == *e);
    }
    TEST_CASE("test begin end methods with *,++") {
        container.addElement(7);
        container.addElement(4);
        container.addElement(6);
        container.addElement(11);
        MagicalContainer::PrimeIterator ascIter(container);
        auto b = ascIter.begin();
        CHECK_EQ(*b, 7);
        CHECK_NOTHROW(++b);
        CHECK_EQ(*b, 11);
    }
}




