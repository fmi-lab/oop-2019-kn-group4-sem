#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <ostream>
template <typename Item>
class DynamicArray
{
    public:
        DynamicArray(int capacity = 10) {
            this->size = 0;
            this->capacity = capacity;
            this->items = new Item[this->capacity];
        }
        DynamicArray(DynamicArray<Item> const& other) {
            std::cout << "Copy constructor " << std::endl;
            this->copy(other);
        }
        DynamicArray& operator=(DynamicArray<Item> const& other);
        ~DynamicArray();

        void add(Item const& x) {
            if (this->size == this->capacity) {
                this->capacity *= 2;
                Item* newList = new Item[this->capacity];
                for (int i = 0; i < this->size; i++) {
                    newList[i]  = this->items[i];
                }
                delete [] this->items;
                this->items = newList;
            }
            this->items[this->size] = x;
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
            // std::cout << "Const operator[]" << std::endl;
            return this->items[index];
        }

        Item& operator[](unsigned index) {
            // std::cout << "Non-Const operator[]" << std::endl;
            return this->items[index];
        }

        friend std::ostream& operator<<(std::ostream& out, DynamicArray<Item> const& arr) {
            for (unsigned i = 0; i < arr.size; i++) {
                out << arr[i] << ", ";
            }
            return out;
        }

        template <typename R>
        DynamicArray<R> mapAll(R (*map)(Item )) const {
            std::cout << "Mapping all" << std::endl;
             DynamicArray<R> result(this->size);
             for (int i = 0; i < this->size; i++) {
                result.add(map(this->items[i]));
                std::cout << "Result[" << i << "] = " << result[i] << std::endl;
             }
             return result;
        }

        template <typename R>
        R reduce(R (*reducer)(R currentResult, Item nextItem), R initialValue) {
            R result = initialValue;
            for(int i = 0; i < this->size; i++) {
                result = reducer(result, items[i]);
            }
            return result;
        }

    protected:

    private:
            Item *items;
            unsigned size;
            unsigned capacity;

            void copy(DynamicArray<Item> const& other) {
                this->capacity = other.capacity;
                this->items = new Item[other.capacity];
                for(unsigned i = 0; i < other.size; i++) {
                    this->items[i] = other.items[i];
                }
                this->size = other.size;
            }

            DynamicArray<Item> multiplyBy2() const {
                 DynamicArray<Item> result(this->size);
                 for (int i = 0; i < this->size; i++) {
                    result[i] = this->items[i] * 2;
                 }
                 return result;
            }
};

template <typename Item>
DynamicArray<Item>& DynamicArray<Item>::operator=(DynamicArray<Item> const& other) {
    std::cout << "Operator=" << std::endl;
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
