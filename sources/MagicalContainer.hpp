#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

namespace ariel {

class MagicalContainer {
private:
    std::vector<int> elements;

public:
    void addElement(int elem);
    void removeElement(int elem);
    std::vector<int> getElement();
    int size();
    bool isPrime(int n); // Helper function for prime checking
    
    class AscendingIterator {
    private:
        MagicalContainer* container;
        int index;

    public:
        AscendingIterator begin();
        AscendingIterator end();
        AscendingIterator(MagicalContainer* container, int index);
        AscendingIterator(const AscendingIterator& other); // Copy constructor
        AscendingIterator(AscendingIterator&& other) noexcept; //  Move constructor
        AscendingIterator(MagicalContainer& container);
        AscendingIterator& operator++();
        bool operator==(const AscendingIterator& iter) const;
        bool operator!=(const AscendingIterator& iter) const;
        bool operator>(const AscendingIterator& iter) const;
        bool operator<(const AscendingIterator& iter) const;
        AscendingIterator& operator<<(int steps);
        AscendingIterator& operator>>(int steps);
        AscendingIterator& operator=(const AscendingIterator& other); // Copy assignment
         AscendingIterator& operator=(AscendingIterator&& other) noexcept;// Move assignment
         ~AscendingIterator();

        int operator*() const;
        void sort(MagicalContainer* container);
    };

    class SideCrossIterator {
    private:
        MagicalContainer* container;
        int index;
        int direction;  

    public:
        SideCrossIterator begin();
        SideCrossIterator end();
        SideCrossIterator();
        SideCrossIterator(MagicalContainer* container, int index, int direction);
        SideCrossIterator(MagicalContainer& container);
        SideCrossIterator(const SideCrossIterator& other); // Copy constructor
        SideCrossIterator(SideCrossIterator&& other) noexcept; //  Move constructor
        SideCrossIterator& operator++();
        bool operator==(const SideCrossIterator& iter) const;
        bool operator!=(const SideCrossIterator& iter) const;
        bool operator>(const SideCrossIterator& iter) const;
        bool operator<(const SideCrossIterator& iter) const;
        SideCrossIterator& operator<<(int steps);
        SideCrossIterator& operator>>(int steps);
        int operator*() const;
        void sort(MagicalContainer* container);
        MagicalContainer getContainer();
        SideCrossIterator& operator=(const SideCrossIterator& other);
         SideCrossIterator& operator=(SideCrossIterator&& other) noexcept;// Move assignment
         ~SideCrossIterator();
    };

    class PrimeIterator {
    private:
        MagicalContainer* container;
        int index;
        std::vector<int> elementsP;
        int index2;

    public:
        PrimeIterator();
        PrimeIterator(MagicalContainer* container, int index,int,std::vector<int>);
        PrimeIterator(MagicalContainer& container);
        PrimeIterator(const PrimeIterator& other); // Copy constructor
        PrimeIterator(PrimeIterator&& other) noexcept; //  Move constructor
        PrimeIterator& operator++();
        bool operator==(const PrimeIterator& iter) const;
        bool operator!=(const PrimeIterator& iter) const;
        bool operator>(const PrimeIterator& iter) const;
        bool operator<(const PrimeIterator& iter) const;
        PrimeIterator& operator<<(int steps);
        PrimeIterator& operator>>(int steps);
        int operator*() ;
        void addC(MagicalContainer* container);
        MagicalContainer getContainer();
         std::vector<int> getelementsP();
        void setValueToContainer(int value);
        PrimeIterator begin();
        PrimeIterator end();
        void setindex(int);
        PrimeIterator& operator=(const PrimeIterator& other);
        PrimeIterator& operator=(PrimeIterator&& other) noexcept;// Move assignment
        ~PrimeIterator();
        void setindex2(int num);
    };
};

} 

#endif
