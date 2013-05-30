#include "Vector.h"

namespace Math {

    Vector::Vector(unsigned int size, Element value) {
        // TODO: 
    }

    /// Copy constructor.
	Vector::Vector(const Vector& vector) {
        // TODO: 
    }

	/// Destructor, releases allocated memory.
	Vector::~Vector() {
        // TODO: 
    }

	/// Destroys content of this instance and copies all data from the right one
	/// \param right	assigned Math::Vector
	/// \return Reference to this
	Vector& Vector::operator = (const Vector& right) {
        return *this;
    }

	/// Returns element at a given position.
	/// \param index	
	/// \return Reference to last element if index is invalid 
	Vector::Element Vector::operator [] (unsigned int index) const {
        // TODO: 
        return this->m_elements[index];
    }

	/// Returns reference to element at a given position.
	/// \param index	
	/// \return Reference to last element if index is invalid
	Vector::Element& Vector::operator [] (unsigned int index) {
        // TODO: 
        return this->m_elements[index];
    }

    // Vector + Vector
    Vector& Vector::operator + (Vector& vector) {
        // TODO: 
        return *this;
    }

    // Vector - Vector
    Vector& Vector::operator - (Vector& vector) {
        // TODO: 
        return *this;
    }
    // Vector * Vector (scalar product, element wise multiplication, then sum)
    Vector& Vector::operator * (Vector& vector) {
        // TODO: 
        return *this;
    }
    // Vector * Element
    Vector& Vector::operator * (Vector::Element vector) {
        // TODO: 
        return *this;
    }

    // std::ostream << Vector (output as formated text)
    std::ostream& operator << (std::ostream& left, const Vector& right) {
        // TODO: 
        return left;
    }
}