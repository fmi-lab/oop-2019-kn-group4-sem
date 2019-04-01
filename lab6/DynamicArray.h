#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <ostream>
template <typename Item>
class DynamicArray
{
    public:
        DynamicArray() {
            this->items = nullptr;
            this->size = 0;
        }
        DynamicArray(DynamicArray<Item> const& other) {
            this->copy(other);
        }
        DynamicArray& operator=(DynamicArray<Item> const& other);
        ~DynamicArray();

        void add(Item const& x) {
            Item* updated = new Item[this->size + 1];
            for (unsigned i = 0; i < this->size; i++) {
                updated[i] = this->items[i];
            }
            updated[this->size] = x;
            delete [] this->items;
            this->items = updated;
            this->size++;
        }

        Item get(unsigned index) const {
            if (index >= this->size) {
                std::cerr << "Bad index" << std::endl;
            }
            return this->items[index];
        }

        void set(unsigned index, Item const& x) {
            if (index >= this->size) {
                std::cerr << "Bad Index" << std::endl;
            }
            this->items[index] = x;
        }

        Item const& operator[](unsigned index) const {
            std::cout << "Const operator[]" << std::endl;
            return this->items[index];
        }

        Item& operator[](unsigned index) {
            std::cout << "Non-Const operator[]" << std::endl;
            return this->items[index];
        }

        friend std::ostream& operator<<(std::ostream& out, DynamicArray<Item> const& arr) {
            for (unsigned i = 0; i < arr.size; i++) {
                out << arr[i] << ", ";
            }
            return out;
        }
    protected:

    private:
            Item *items;
            unsigned size;
            void copy(DynamicArray<Item> const& other) {
                this->items = new Item[other.size];
                for(unsigned i = 0; i < other.size; i++) {
                    this->items[i] = other.items[i];
                }
                this->size = other.size;
            }
};

template <typename Item>
DynamicArray<Item>& DynamicArray<Item>::operator=(DynamicArray<Item> const& other) {
    if (this != &other) {
        delete [] this->items;
        this->copy(other);
    }
    return *this;
}

template <typename Item>
DynamicArray<Item>::~DynamicArray()
{
    delete[] this->items;
}
#endif // DYNAMICARRAY_H
