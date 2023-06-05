#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

bool MagicalContainer::isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<int> MagicalContainer::getElement(){
    return elements;
}

void MagicalContainer::addElement(int elem) {
    elements.emplace_back(elem);
}

void MagicalContainer::removeElement(int elem) {
    bool t=true;
    for (auto it : elements) {
       if(it == elem){
            elements.erase( std::remove(elements.begin(), elements.end(), elem), elements.end());
            t=false;
       }
    }
 
    
    if(t)
        throw std::runtime_error("You cannot delete a number that does not exist in the container");
   
 
}





int MagicalContainer::size() {
    return elements.size();
}



void MagicalContainer::AscendingIterator::sort(MagicalContainer* container){
    std::sort( container->elements.begin(), container->elements.end());  
}


MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer* container, int index)
    : container(container), index(index) {
        
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(AscendingIterator&& other) noexcept {
    if (this != &other) {
        container = other.container;
        index = other.index;
    }
    return *this;
}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) {
    container = other.container;
    index = other.index;
}

MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator&& other) noexcept {
       container = other.container;
    index = other.index;
   // Invalidate the data members in 'other'
    other.container = nullptr;
    other.index = 0;
}


MagicalContainer::AscendingIterator::~AscendingIterator() {
}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
    : container(&container), index(0)
{
sort(&container);

}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    return AscendingIterator(container, 0);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    return AscendingIterator(container, container->size());
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) 
{
     if (this != &other) {
        if (container != other.container) {
            throw std::runtime_error("Iterators are pointing to different containers");
        }
        index = other.index;
    }
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    if(index == container->size()){
       throw runtime_error("no more index");
    }
        
    
    ++index;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& iter) const {
    return index == iter.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& iter) const {
    return index != iter.index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& iter) const {
    return index > iter.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& iter) const {
    return index < iter.index;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator<<(int steps) {
    index -= steps;
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator>>(int steps) {
    index += steps;
    return *this;
}

int MagicalContainer::AscendingIterator::operator*() const {
    unsigned long jhg=  static_cast<unsigned long>(index);
    return container->elements[jhg];
}


MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
    : container(&container), index(0) {
        sort(&container);
    }


MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(SideCrossIterator&& other) noexcept {
    if (this != &other) {
        container = other.container;
        index = other.index;
    }
    return *this;
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) {
    container = other.container;
    index = other.index;
}

MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator&& other) noexcept {
    container = other.container;
    index = other.index;
   // Invalidate the data members in 'other'
    other.container = nullptr;
    other.index = 0;
}


MagicalContainer::SideCrossIterator::~SideCrossIterator() {
    
}


void MagicalContainer::SideCrossIterator::sort(MagicalContainer* container){  
    std::sort( container->elements.begin(), container->elements.end());
    unsigned long size =(unsigned long)container->size();
    unsigned long i = 0;
    vector<int> elements2;
    int temp2;
   
        unsigned long  x=0,y=1;
          for(i=0;  i<size; i++){  
             if(i%2==0){
                  temp2 = container->elements.at(x);
                elements2.emplace_back(temp2);
   
                    x++;

                
            }else{
                temp2= container->elements.at(size - y);
                elements2.emplace_back(temp2);
                y++;   
            }

        }

     container->elements.swap(elements2);
 
}

MagicalContainer  MagicalContainer::SideCrossIterator::getContainer(){
    return *container;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) 
{
     if (this != &other) {
        if (container != other.container) {
            throw std::runtime_error("Iterators are pointing to different containers");
        }
        index = other.index;
    }
    return *this;
}


MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return SideCrossIterator(container, 0, 1);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    return SideCrossIterator(container, container->size(), 1);
}

MagicalContainer::SideCrossIterator::SideCrossIterator()
    : container(nullptr), index(0), direction(1) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer* container, int index, int direction)
    : container(container), index(index), direction(direction) {}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if(index == container->size()){
       throw runtime_error("no more index");
    }
    ++index;
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& iter) const {
    return index == iter.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& iter) const {
    return index != iter.index;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& iter) const {
    return index > iter.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& iter) const {
    return index < iter.index;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator<<(int steps) {
    index -= steps * direction;
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator>>(int steps) {
    index += steps * direction;
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    unsigned long jhg=  static_cast<unsigned long>(index);
    return container->elements[jhg];
}


MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
   : container(&container), index(0), index2(0) {
    if (container.getElement().empty()) {
        elementsP.clear();
        index = 0;
        index2 = 0;
    } else {
        addC(&container);
    }
        
    }

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(PrimeIterator&& other) noexcept {
    if (this != &other) {
        container = other.container;
        index = other.index;
        index2 = other.index2;
        elementsP = other.elementsP;
    }
    return *this;
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) {
    container = other.container;
    index = other.index;
}

MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator&& other) noexcept {
    container = other.container;
    index = other.index;
   // Invalidate the data members in 'other'
    other.container = nullptr;
    other.index = 0;
}

MagicalContainer::PrimeIterator::~PrimeIterator() {
    
}

void MagicalContainer::PrimeIterator::addC(MagicalContainer* container){
 
   std::sort( container->elements.begin(), container->elements.end());
    for(auto iter:container->getElement()){
        if(container->isPrime(iter)){
            elementsP.emplace_back(iter);
        }
    }
    if(elementsP.empty()){
        elementsP.clear();
    }
   

}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) 
{
     if (this != &other) {
        if (container != other.container) {
            throw std::runtime_error("Iterators are pointing to different containers");
        }
        index2 = other.index2;
        elementsP = other.elementsP;
        index=other.index;
        container = other.container;

    }
    return *this;
}

std::vector<int> MagicalContainer::PrimeIterator::getelementsP(){
    return elementsP;
}

MagicalContainer  MagicalContainer::PrimeIterator::getContainer(){
    return *container;
}

void  MagicalContainer::PrimeIterator::setValueToContainer(int num){
    container->addElement(num);
}

MagicalContainer::PrimeIterator::PrimeIterator()
    : container(nullptr), index(0), index2(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer* container, int index,int index2,std::vector<int> elem)
    : container(container), index(index),index2(index2),elementsP(elem)  {}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    if(index >= container->size()){
       throw runtime_error("no more index");
    }
    if(index2 == elementsP.size()){
        throw runtime_error("no more index");
    }
    ++index2;
    ++index;
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& iter) const {
    

    return index == iter.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& iter) const {
    return index != iter.index;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& iter) const {
    return index > iter.index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& iter) const {
    return index < iter.index;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator<<(int steps) {
    int count = 0;
    unsigned long jhg;
    while (count < steps) {
        --index;
        jhg=  static_cast<unsigned long>(index);
        if ( container->isPrime(container->elements[jhg]))
            ++count;
    }
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator>>(int steps) {
    int count = 0;
    unsigned long jhg;
    while (count < steps) {
        ++index;
        jhg=  static_cast<unsigned long>(index);
        if (container->isPrime(container->elements[jhg]))
            ++count;
    }
    return *this;
}

void MagicalContainer::PrimeIterator::setindex(int num){
    index =num;
}

void MagicalContainer::PrimeIterator::setindex2(int num){
    index =num;
}

int MagicalContainer::PrimeIterator::operator*()
{ 
    
    unsigned long jhg=  static_cast<unsigned long>(index2);
   
            return elementsP[jhg];
     
         
    
  throw std::runtime_error("ERROR");
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    return PrimeIterator(container, 0,0,elementsP);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    return PrimeIterator(container,elementsP.size(),elementsP.size(),elementsP);
}
