#include "Vector.h"
#include <ostream>

namespace Math
{
    	/// Create empty from size, filled with a given value.
		/// \param size		vectors size
		/// \param value	value applied to all elements
        Vector::Vector(unsigned int size, Vector::Element value) : m_size(size) {
            this->m_elements.reset(new Element[m_size]);
            for (unsigned int i = 0 ; i< m_size ; ++i)
                m_elements[i] = value;
        }

		/// Copy constructor.
        Vector::Vector(const Vector& vector) : m_size(vector.getNumElements()) {
            m_elements.reset(new Element[m_size]);
            for (unsigned int i = 0; i < m_size; ++i) {
                m_elements[i] = vector.m_elements[i];
            }
        }
		
		/// Destroys content of this instance and copies all data from the right one
		/// \param right	assigned Math::Vector
		/// \return Reference to this
		Vector& Vector::operator = (const Vector& right) {
            this->m_elements.reset(right.m_elements.get());
            this->m_size = right.m_size;
            return *this;
        }

		/// Returns element at a given position.
		/// \param index	
		/// \return Reference to last element if index is invalid 
		Vector::Element Vector::operator [] (unsigned int index) const {
            return m_elements[index];
        }

		/// Returns reference to element at a given position.
		/// \param index	
		/// \return Reference to last element if index is invalid
		Vector::Element& Vector::operator [] (unsigned int index) {
            return m_elements[index];
        }

		// TODO: Insert additional Operators (here or global where necessary)
		// -> Use const wherever possible and useful!
		// -> Where possible use methods in favor of global functions!
		//
		// Vector + Vector
        Vector Vector::operator +(const Vector& right) {
            const Vector& max = getMax(*this, right);
            const Vector& min = getMin(*this, right);
            Vector tmp(max.getNumElements());
            for (unsigned int i = 0 ; i < min.getNumElements(); ++i)
                tmp[i] = this->m_elements[i] + right[i];
            return tmp;
        }

		// Vector - Vector
        Vector Vector::operator -(const Vector& right) {
            const Vector& max = getMax(*this, right);
            const Vector& min = getMin(*this, right);
            Vector tmp(max.getNumElements());
            for (unsigned int i = 0 ; i < min.getNumElements(); ++i)
                tmp[i] = this->m_elements[i] - right[i];
            return tmp;
        }

		// Vector * Element
        Vector Vector::operator *(const Element& right) {
            Vector tmp(*this);
            for (unsigned int i = 0 ; i < tmp.getNumElements(); ++i)
                tmp[i] *= right;
            return tmp;
        }

		// Vector * Vector (scalar product, element wise multiplication, then sum)
        Vector::Element Vector::operator *(const Vector& right) {
            Element sum = 0;
            const Vector& max = getMax(*this, right);
            const Vector& min = getMin(*this, right);
            unsigned int i = 0;
            for (i = 0 ; i < min.getNumElements() ; ++i)
                sum += (min[i] * max[i]);
            for (; i < max.getNumElements() ; ++i)
                sum += max[i];
            return sum;
        }

        const Vector& Vector::getMin(const Vector &v1, const Vector& v2) const {
            return v1.m_size < v2.m_size ? v1 : v2;
        }

        const Vector& Vector::getMax(const Vector& v1, const Vector& v2) const {
            return v1.m_size > v2.m_size ? v1 : v2;
        }

        // std::ostream << Vector (output as formated text)
        std::ostream& operator<<(std::ostream& left, const Vector& right) {
            left << "Vector(" << right.getNumElements() << "): ";
            for (unsigned int i = 0 ; i < right.getNumElements(); ++i)
                left << right[i] << ' ';

            return left;
        }
}