#include "Vector.h"

#include <iostream>
using namespace std;

namespace Math {

    Vector::Vector(unsigned int size, Element value) {
        m_elements.reset(new Element[size]);
        for (unsigned int i = 0 ; i < size; ++i)
            m_elements[i] = value;
		m_size = size;
    }

    /// Copy constructor.
	Vector::Vector(const Vector& vector) {
        m_elements.reset(new Element[vector.getNumElements()]);
        for (unsigned int i = 0 ; i < vector.getNumElements(); ++i)
            m_elements[i] = vector.m_elements[i];
		m_size = vector.getNumElements();
    }

	/// Destructor, releases allocated memory.
	Vector::~Vector() {
        m_elements.release();
    }

	/// Destroys content of this instance and copies all data from the right one
	/// \param right	assigned Math::Vector
	/// \return Reference to this
	Vector& Vector::operator = (const Vector& right) {
        m_elements.reset(new Element[right.getNumElements()]);
        for (unsigned int i = 0 ; i < right.getNumElements(); ++i)
            m_elements[i] = right.m_elements[i];
        return *this;
    }

	/// Returns element at a given position.
	/// \param index	
	/// \return Reference to last element if index is invalid 
	Vector::Element Vector::operator [] (unsigned int index) const {
        return this->m_elements[index];
    }

	/// Returns reference to element at a given position.
	/// \param index	
	/// \return Reference to last element if index is invalid
	Vector::Element& Vector::operator [] (unsigned int index) {
        return this->m_elements[index];
    }

    // Vector + Vector
    Vector& Vector::operator + (Vector& vector) {
        // Error - different length
        if (this->getNumElements() != vector.getNumElements())
            return *this;

        // Add components of vector
        for (unsigned int i = 0 ; i < this->getNumElements() ; ++i)
            this->m_elements[i] += vector.m_elements[i];

        return *this;
    }

    // Vector - Vector
    Vector& Vector::operator - (Vector& vector) {
        // Error - different length
        if (this->getNumElements() != vector.getNumElements())
            return *this;

        // Add components of vector
        for (unsigned int i = 0 ; i < this->getNumElements() ; ++i)
            this->m_elements[i] -= vector.m_elements[i];

        return *this;
    }

    // Vector * Vector (scalar product, element wise multiplication, then sum)
    Vector::Element Vector::operator * (Vector& vector) {
        // error
        if (this->getNumElements() != vector.getNumElements())
            return 0;
		Element sum = 0.0f;
		for (unsigned int i = 0 ; i < vector.getNumElements(); ++i) 
			sum += m_elements[i] * vector[i];
		return sum;
    }

    // Vector * Element
    Vector& Vector::operator * (Vector::Element scalar) {
        // Multiply components with the scalar
        for (unsigned int i = 0 ; i < this->getNumElements() ; ++i)
            this->m_elements[i] *= scalar;

        return *this;
    }

    // std::ostream << Vector (output as formated text)
    ostream& operator<< (ostream& left, const Vector& right) {
        left << "(";
        for (unsigned int i = 0 ; i < right.getNumElements() -1 ; ++i) {
            left << right[i] << ", ";
        }
        if (right.getNumElements() > 0)
            return left << right[right.getNumElements() - 1] << ")";
        else
            return left;
    }
}