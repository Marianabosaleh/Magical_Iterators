#pragma once
#include <vector>
#include <iostream>
using namespace std;

namespace ariel
{
    class MagicalContainer
    {
        std::vector<int> elements;

    public:
        // Default constructor
        MagicalContainer();
        //Copy constructor
        // MagicalContainer(const MagicalContainer &other);
        // // Move constructor
        // MagicalContainer(MagicalContainer&& other) noexcept;
        // // Move assignment operator
        // MagicalContainer& operator=(MagicalContainer&& other) noexcept;
        // // Assignment operator
        // MagicalContainer &operator=(const MagicalContainer &other);
        // destructor
        ~MagicalContainer();
        // Add element
        void addElement(int element);
        //get the element
        std::vector<int>& getelem();
        //set element 
        void setelem(vector<int>& elem);
        // Remove element
        void removeElement(int element);
        // Size of the container
        int size() const;
        // iterators class
        class AscendingIterator
        {
            const MagicalContainer *container;
            int index=0;

        public:
            // Default constructor
            AscendingIterator();

            // Constructor with parameters
            AscendingIterator(const MagicalContainer &container);

            // Copy constructor
            AscendingIterator(const AscendingIterator& other);

            // Destructor
            ~AscendingIterator();

            // Assignment operator
            AscendingIterator& operator=(const AscendingIterator& other);

            // Pre-increment operator
            AscendingIterator operator++();

            // Dereference operator
            int operator*() const;

            // Equality comparison
            bool operator==(const AscendingIterator& other) const;

            // Inequality comparison
            bool operator!=(const AscendingIterator& other) const;

            // GT, LT comparison operators
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
                
            AscendingIterator begin();
            AscendingIterator end();
        };
        class SideCrossIterator
        {
            const MagicalContainer *container;
            int index=0;

        public:
            // Default constructor
            SideCrossIterator();

            // Constructor with parameters
            SideCrossIterator(const MagicalContainer &container);

            // Copy constructor
            SideCrossIterator(const SideCrossIterator& other);

            // Destructor
            ~SideCrossIterator();

            // Assignment operator
            SideCrossIterator& operator=(const SideCrossIterator& other);

            // Pre-increment operator
            SideCrossIterator operator++();

            // Dereference operator
            int operator*() const;

            // Equality comparison
            bool operator==(const SideCrossIterator& other) const;

            // Inequality comparison
            bool operator!=(const SideCrossIterator& other) const;

            // GT, LT comparison operators
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
                
            SideCrossIterator begin();
            SideCrossIterator end();
        };
        class PrimeIterator
        {
            const MagicalContainer *container;
            int index=0;

        public:
            // Default constructor
            PrimeIterator();

            // Constructor with parameters
            PrimeIterator(const MagicalContainer &container);

            // Copy constructor
            PrimeIterator(const PrimeIterator& other);

            // Destructor
            ~PrimeIterator();

            // Assignment operator
            PrimeIterator& operator=(const PrimeIterator& other);

            // Pre-increment operator
            PrimeIterator operator++();

            // Dereference operator
            int operator*() const;

            // Equality comparison
            bool operator==(const PrimeIterator& other) const;

            // Inequality comparison
            bool operator!=(const PrimeIterator& other) const;

            // GT, LT comparison operators
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
                
            PrimeIterator begin();
            PrimeIterator end();
        };
        

    };
}
