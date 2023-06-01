#include "MagicalContainer.hpp"

namespace ariel
{

    // Default constructor
    MagicalContainer::MagicalContainer() {}
    // // Copy constructor
    // MagicalContainer::MagicalContainer(const MagicalContainer &other): elements(other.elements) {}
    // //move constructor
    // MagicalContainer::MagicalContainer(MagicalContainer &&other) noexcept: elements(std::move(other.elements)) {}
    // // Move assignment operator
    // MagicalContainer &MagicalContainer ::operator=(MagicalContainer &&other) noexcept
    // {
    //     if (this != &other)
    //     {
    //         elements = other.elements;
    //     }
    //     return *this;
    // }
    // Destructor
    MagicalContainer::~MagicalContainer() {}

    // Move assignment operator
    // MagicalContainer &MagicalContainer ::operator=(MagicalContainer &&other) noexcept
    // {
    //     if (this != &other)
    //     {
    //         elements = std::move(other.elements);
    //         other.elements.clear();
    //     }
    //     return *this;
    // }


    // Add element
    void MagicalContainer::addElement(int element)
    {
        elements.push_back(element);
    }

    // Remove element
    void MagicalContainer::removeElement(int element)
    {
        auto it = std::find(elements.begin(), elements.end(), element);
        if (it != elements.end())
        {
            elements.erase(it);
        }
    }
    // set container
    void MagicalContainer::setelem(vector<int> &elem)
    {
        elements = elem;
    }
    // get container
    vector<int> &MagicalContainer::getelem()
    {
        return elements;
    }

    // Size of the container
    int MagicalContainer::size() const
    {
        return elements.size();
    }
    // AscendingIterator
    MagicalContainer::AscendingIterator::AscendingIterator(): container(nullptr), index(0) {}
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &container) : container(&container), index(0) {}


    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container), index(other.index)
    {
    }

    MagicalContainer::AscendingIterator::~AscendingIterator()
    {
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {

        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++()
    {
        if (index < container->elements.size())
            ++index;
        return *this;
    }

    // Dereference operator
    int MagicalContainer::AscendingIterator::operator*() const
    {
        if(index < static_cast<int>(container->elements.size())){
            return container->elements[static_cast<std::vector<int>::size_type>(index)];
        } else {
            throw std::out_of_range("Iterator out of bounds");
        }
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return this->index == other.index && this->container == other.container;
    }
    
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {

        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {

        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {

        return false;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {

        this->index = 0;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        this->index = container->size();
        return *this;
    }

    // SideCrossIterator
    MagicalContainer::SideCrossIterator::SideCrossIterator(): container(nullptr), index(0) {}
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container) : container(&container), index(0) {}


    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(other.container), index(other.index)
    {
    }

    MagicalContainer::SideCrossIterator::~SideCrossIterator()
    {
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {

        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++()
    {
        if (index < container->elements.size())
            ++index;
        return *this;
    }

    // Dereference operator
    int MagicalContainer::SideCrossIterator::operator*() const
    {
        if(index < static_cast<int>(container->elements.size())){
            return container->elements[static_cast<std::vector<int>::size_type>(index)];
        } else {
            throw std::out_of_range("Iterator out of bounds");
        }
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return this->index == other.index && this->container == other.container;
    }
    
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {

        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {

        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {

        return false;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {

        this->index = 0;
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        this->index = container->size();
        return *this;
    }
    // PrimeIterator
    MagicalContainer::PrimeIterator::PrimeIterator(): container(nullptr), index(0) {}
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container) : container(&container), index(0) {}


    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container), index(other.index)
    {
    }

    MagicalContainer::PrimeIterator::~PrimeIterator()
    {
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {

        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++()
    {
        if (index < container->elements.size())
            ++index;
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*() const
    {
        if(index < static_cast<int>(container->elements.size())){
            return container->elements[static_cast<std::vector<int>::size_type>(index)];
        } else {
            throw std::out_of_range("Iterator out of bounds");
        }
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return this->index == other.index && this->container == other.container;
    }
    
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {

        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {

        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {

        return false;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {

        this->index = 0;
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        this->index = container->size();
        return *this;
    } 
}
