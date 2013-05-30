#include "arraylist.hpp"

namespace Collections {

    ArrayList::ArrayList() {
        initArrayList(8);
    }

    ArrayList::ArrayList(const ICollection& list) {
		initArrayList(list.getNumElements());
        auto it = list.getIterator();
        while(it->current()) {
            this->insert(*(it->current()));
            it->next();
        }
    }

    ArrayList::~ArrayList() {
        for (unsigned i = 0; i < m_numElements ; ++i)
            delete elements[i];
        delete[] elements;
    }

    void ArrayList::insert(const IElement& newElement) {
        // Array is full - double the size
        if (m_numElements == capacity)
            resize(capacity << 1);
        elements[m_numElements++] = newElement.clone();
    }

	IElement* ArrayList::get(unsigned int index) const {
        return index < m_numElements  ? elements[index] : nullptr;
    }

	void ArrayList::set(const IElement& newElement, unsigned int index) {
        if (index >= m_numElements)
            return;
		if (elements[index] != nullptr)
			delete elements[index];
        elements[index] = newElement.clone();
    }

    void ArrayList::reserve(unsigned int reservation) {
        // Enough memory
        if (m_numElements + reservation <= capacity)
            return;

        resize(m_numElements + reservation);
    }

    void ArrayList::initArrayList(unsigned int size) {
        this->capacity = size;
        this->elements = new IElement*[capacity];
    }

    void ArrayList::resize(unsigned int newSize) {
        IElement** tmp = new IElement*[newSize];
        for(int i = 0; i < m_numElements; ++i) {
            tmp[i] = elements[i];
        }
        delete[] elements;
        elements = tmp;
        capacity = newSize;
    }

    ICollection::IIterator* ArrayList::getIterator() const {
        return new ArrayList::ListIterator(elements, m_numElements);
    }

    IElement*  ArrayList::ListIterator::next() {
        ++index;
        return current();
    }

	/// \brief Access the current element without changing the iterator
	///
	IElement* ArrayList::ListIterator::current() const {
        return index < size ? tmp_elements[index] : nullptr;
    }
};