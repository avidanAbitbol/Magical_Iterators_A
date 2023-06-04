#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <iostream>
#include <vector>
using namespace ariel;
using namespace std;

TEST_CASE("Check container initialization") {
    MagicalContainer container;
    CHECK(container.size() == 0);
}

TEST_CASE("Add element to container") {
    MagicalContainer container;
    container.addElement(1);
    CHECK(container.size() == 1);
}

TEST_CASE("Check size after adding multiple elements") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    CHECK(container.size() == 3);
}

TEST_CASE("Remove existing element from container") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.removeElement(1);
    CHECK(container.size() == 1);
}

TEST_CASE("Remove non-existing element from container") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.removeElement(3);
    CHECK(container.size() == 2);
}

TEST_CASE("AscendingIterator should iterate in correct order") {
    MagicalContainer container;
    container.addElement(3);
    container.addElement(1);
    container.addElement(2);
    MagicalContainer::AscendingIterator ascIter(container);
    std::vector<int> expected = {1, 2, 3};
    std::vector<int> actual;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        actual.push_back(*it);
    }
    CHECK(actual == expected);
}

TEST_CASE("SideCrossIterator should iterate in side cross order") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::SideCrossIterator crossIter(container);
    std::vector<int> expected = {2, 25, 3, 17, 9}; // Change if your side cross order is different.
    std::vector<int> actual;
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        actual.push_back(*it);
    }
    CHECK(actual == expected);
}

TEST_CASE("PrimeIterator should iterate over prime numbers only") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::PrimeIterator primeIter(container);
    std::vector<int> expected = {2, 3, 17}; // Change if your prime iteration order is different.
    std::vector<int> actual;
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        actual.push_back(*it);
    }
    CHECK(actual == expected);
}

TEST_CASE("Check size of container after removing all elements") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.removeElement(1);
    container.removeElement(2);
    CHECK(container.size() == 0);
}

TEST_CASE("Adding a duplicate element should not affect the size") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(1);
    CHECK(container.size() == 1);
}
TEST_CASE("Check container size when adding negative numbers.") {
    MagicalContainer container;
    container.addElement(-1);
    CHECK(container.size() == 1);
}

TEST_CASE("Check container size when adding zero.") {
    MagicalContainer container;
    container.addElement(0);
    CHECK(container.size() == 1);
}

TEST_CASE("Removing a negative number or zero should not affect the size.") {
    MagicalContainer container;
    container.addElement(1);
    container.removeElement(0);
    container.removeElement(-1);
    CHECK(container.size() == 1);
}

TEST_CASE("Check correct order with AscendingIterator when negative numbers are present.") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(-1);
    container.addElement(0);
    MagicalContainer::AscendingIterator ascIter(container);
    std::vector<int> expected = {-1, 0, 1};
    std::vector<int> actual;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        actual.push_back(*it);
    }
    CHECK(actual == expected);
}


TEST_CASE("PrimeIterator should not yield negative numbers.") {
    MagicalContainer container;
    container.addElement(-1);
    container.addElement(-2);
    container.addElement(-3);
    container.addElement(2);
    container.addElement(3);
    MagicalContainer::PrimeIterator primeIter(container);
    std::vector<int> expected = {2, 3};
    std::vector<int> actual;
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        actual.push_back(*it);
    }
    CHECK(actual == expected);
}

TEST_CASE("Add elements and check if size increases properly.") {
    MagicalContainer container;
    container.addElement(1);
    CHECK(container.size() == 1);
    container.addElement(2);
    CHECK(container.size() == 2);
}

TEST_CASE("Remove elements and check if size decreases properly.") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    CHECK(container.size() == 2);
    container.removeElement(1);
    CHECK(container.size() == 1);
}
TEST_CASE("Add elements and check order with AscendingIterator.") {
    MagicalContainer container;
    container.addElement(3);
    container.addElement(1);
    container.addElement(2);
    MagicalContainer::AscendingIterator ascIter(container);
    std::vector<int> expected = {1, 2, 3};
    std::vector<int> actual;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        actual.push_back(*it);
    }
    CHECK(actual == expected);
}



TEST_CASE("Add elements and check PrimeIterator only yields primes.") {
    MagicalContainer container;
    container.addElement(4);
    container.addElement(2);
    container.addElement(3);
    MagicalContainer::PrimeIterator primeIter(container);
    std::vector<int> expected = {2, 3};
    std::vector<int> actual;
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        actual.push_back(*it);
    }
    CHECK(actual == expected);
}

TEST_CASE("Add same element multiple times, then remove it once, should still exist in the container.") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(1);
    container.removeElement(1);
    CHECK(container.size() == 1);
}

TEST_CASE("Check order of AscendingIterator with duplicate elements.") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(1);
    MagicalContainer::AscendingIterator ascIter(container);
    std::vector<int> expected = {1, 1, 2};
    std::vector<int> actual;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        actual.push_back(*it);
    }
    CHECK(actual == expected);
}


TEST_CASE("Check PrimeIterator with duplicate primes.") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(2);
    MagicalContainer::PrimeIterator primeIter(container);
    std::vector<int> expected = {2, 2, 3};
    std::vector<int> actual;
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        actual.push_back(*it);
    }
    CHECK(actual == expected);
}

TEST_CASE("Add elements then clear container, size should be zero.") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.removeElement(1);
    container.removeElement(2);
    CHECK(container.size() == 0);
}

TEST_CASE("Add elements then clear container, AscendingIterator should yield no elements.") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    for(int i = 0; i < 2; i++) {
        container.removeElement(i);
    }
    MagicalContainer::AscendingIterator ascIter(container);
    CHECK(ascIter.begin() == ascIter.end());
}


TEST_CASE("Add elements then clear container, PrimeIterator should yield no elements.") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    for(int i = 0; i < 2; i++) {
        container.removeElement(i);
    }    MagicalContainer::PrimeIterator primeIter(container);
    CHECK(primeIter.begin() == primeIter.end());
}

TEST_CASE("Add elements, clear container, add more elements, iterators should yield correct results.") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    for(int i = 0; i < 2; i++) {
        container.removeElement(i);
    }
    container.addElement(3);
    container.addElement(4);
    MagicalContainer::AscendingIterator ascIter(container);
    std::vector<int> expected = {3, 4};
    std::vector<int> actual;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        actual.push_back(*it);
    }
    CHECK(actual == expected);
}

TEST_CASE("Add elements, clear container, add more elements, size should be correct.") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    for(int i = 0; i < 2; i++) {
        container.removeElement(i);
    }
    container.addElement(3);
    container.addElement(4);
    CHECK(container.size() == 2);
}

TEST_CASE("Add elements, clear container, add more elements, AscendingIterator should yield correct results.") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(1);
    for(int i = 0; i < 2; i++) {
        container.removeElement(i);
    }
    container.addElement(4);
    container.addElement(3);
    MagicalContainer::AscendingIterator ascIter(container);
    std::vector<int> expected = {3, 4};
    std::vector<int> actual;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        actual.push_back(*it);
    }
    CHECK(actual == expected);
}


TEST_CASE("Add elements, clear container, add more elements, PrimeIterator should yield correct results.") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    for(int i = 0; i < 2; i++) {
        container.removeElement(i);
    }
    container.addElement(4);
    container.addElement(5);
    MagicalContainer::PrimeIterator primeIter(container);
    std::vector<int> expected = {5};
    std::vector<int> actual;
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        actual.push_back(*it);
    }
    CHECK(actual == expected);
}
TEST_CASE("check for throws in many cases") {
    MagicalContainer container;
    // This is just an example, replace with actual conditions/methods that should throw.
    CHECK_THROWS_AS(container.addElement(-1), std::invalid_argument);
    CHECK_THROWS_AS(container.removeElement(10), std::out_of_range);
    CHECK_THROWS_AS(container.removeElement(10), std::out_of_range);

}

TEST_CASE("check for not throws in many cases") {
    MagicalContainer container;
    // Again, replace these with actual conditions/methods that should not throw.
    CHECK_NOTHROW(container.addElement(1));
    CHECK_NOTHROW(container.removeElement(1));
}
