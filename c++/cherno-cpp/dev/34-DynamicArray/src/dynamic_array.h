#pragma once
#include <cstdio>
#include <iterator>
#include <utility>
#include <vector>

template <typename Vector> class VectorIterator {
public:
    using value_type = typename Vector::value_type;
    using pointer_type = value_type*;
    using reference_type = value_type&;

public:
    VectorIterator(pointer_type ptr)
        : ptr(ptr)
    {
    }

    VectorIterator& operator++()
    {
        ptr++;
        return *this;
    }

    VectorIterator operator++(int)
    {
        VectorIterator iterator = *this;
        ++(*this);
        return iterator;
    }

    VectorIterator& operator--()
    {
        ptr--;
        return *this;
    }

    VectorIterator operator--(int)
    {
        VectorIterator iterator = *this;
        --(*this);
        return iterator;
    }

    reference_type operator[](int index) { return *(ptr + index); }

    pointer_type operator->() { return ptr; }

    reference_type operator*() { return *ptr; }

    bool operator==(const VectorIterator& other) const { return ptr == other.ptr; }
    bool operator!=(const VectorIterator& other) const { return !(*this == other); }

private:
    pointer_type ptr;
};

// FIXME: Double free error!

template <typename T> class DynamicArr {
public:
    using value_type = T;
    using iterator = VectorIterator<DynamicArr<T>>;

public:
    DynamicArr()
        : DynamicArr(2)
    {
    }

    DynamicArr(size_t cap)
        : cap { cap }
        , size { 0 }
    {
        arr = new T[cap];
    }

    void PushBack(const T& item)
    {
        if (IsFull())
            Resize(cap * 2);
        arr[size++] = item;
    }

    // NOTE: Once you enter function the rval turns into lval.
    //       Hence why we need to call std::move again to get rval.
    void PushBack(T&& item)
    {
        if (IsFull())
            Resize(cap * 2);
        arr[size++] = std::move(item);
    }

    template <typename... Args> T& EmplaceBack(Args&&... args)
    {
        if (IsFull())
            Resize(cap * 2);

        new (&arr[size++]) T(std::forward<Args>(args)...);
        return arr[size - 1];
    }

    void PopBack()

    {
        // NOTE: I would probably thrown an error here to avoid silent handling.
        if (!IsEmpty()) {
            size--;
            arr[size].~T();
        }
    }

    void Clear()
    {
        for (size_t i = 0; i < size; i++)
            arr[i].~T();
        size = 0;
    }

    const T& operator[](size_t index) const { return arr[index]; }
    T& operator[](size_t index) { return arr[index]; }

    size_t Size() const { return size; }

    iterator begin() { return iterator(arr); }
    iterator end() { return iterator(arr + size); }

    const iterator begin() const { return iterator(arr); }
    const iterator end() const { return iterator(arr + size); }

    ~DynamicArr()
    {
        Clear();
        delete[] arr;
    }

private:
    void Resize(size_t new_cap)
    {
        // T* new_arr = (T*)::operator new(new_cap * sizeof(T));
        T* new_arr = new T[new_cap]; // this will cause double free err

        // NOTE: Might be violating SRP.
        if (new_cap < size)
            size = new_cap;

        for (size_t i = 0; i < size; i++) {
            new_arr[i] = std::move(arr[i]);
        }

        // for (size_t i = 0; i < size; i++) {
        //     arr[i].~T();
        // }

        // ::operator delete(arr, cap * sizeof(T)); arg error...
        delete[] arr; // this will cause mem err
        cap = new_cap;
        arr = new_arr;
    };

    bool IsFull() { return cap == size; }
    bool IsEmpty() { return size == 0; }

    T* arr;
    size_t cap;
    size_t size;
};

template class DynamicArr<int>;
