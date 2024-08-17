#ifndef ITERATOR_H
#define ITERATOR_H
#include<vector>
/*
 * Iterator is a behavioral design pattern that lets you traverse elements of a collection without exposing its
 * underlying representation (list, stack, tree, etc.).
 */

//Iterator interface
template<typename T>
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() = 0;
    virtual T next() = 0;
};

template<typename T>
class VectorIterator final : public Iterator<T> {
private:
    std::vector<T>& data;
    size_t position;
public:
    explicit VectorIterator(std::vector<T>& vec) : data{vec} , position{0} {}
    bool hasNext() override {
        return position < data.size();
    }

    T next() override {
        return data[position++];
    }

};


//Aggregate(Collection) Interface
template<typename T>
class Collection {
public:
    virtual ~Collection() = default;
    virtual Iterator<T>* createIterator() = 0;
};

template<typename T>
class MyVector final : public Collection<T> {
private:
    std::vector<T> data;
public:
    void add(T element) {
        data.emplace_back(element);
    }

    Iterator<T>* createIterator() override {
        return new VectorIterator<T>(data);
    }
};



#endif //ITERATOR_H
