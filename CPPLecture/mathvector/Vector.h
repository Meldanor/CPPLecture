#pragma once
#pragma once

#include <memory>

namespace Math
{
	class Vector
	{
	public:
		/// Vector number-type.
		typedef float Element;
		
		/// Create empty from size, filled with a given value.
		/// \param size		vectors size
		/// \param value	value applied to all elements
		explicit Vector(unsigned int size, Element value = 0);

		/// Copy constructor.
		Vector(const Vector& vector);

		/// Destructor, releases allocated memory.
		~Vector();

		/// Returns number of elements
		unsigned int getNumElements() const { return m_size; }
		
		/// Destroys content of this instance and copies all data from the right one
		/// \param right	assigned Math::Vector
		/// \return Reference to this
		Vector& operator = (const Vector& right);

		/// Returns element at a given position.
		/// \param index	
		/// \return Reference to last element if index is invalid 
		Element operator [] (unsigned int index) const;

		/// Returns reference to element at a given position.
		/// \param index	
		/// \return Reference to last element if index is invalid
		Element& operator [] (unsigned int index);

        // Vector + Vector
        Vector& operator + (Vector& vector);
        // Vector - Vector
        Vector& operator - (Vector& vector);
        // Vector * Vector (scalar product, element wise multiplication, then sum)
        Vector& operator * (Vector& vector);
        // Vector * Element
        Vector& operator * (Element vector);
	private:
		/// intern element array
		std::unique_ptr<Element[]> m_elements;

		/// number of elements
		unsigned int m_size;
	};

    // Element * Vector
    inline Vector operator * (Vector::Element left, Vector& right) { return right * left; }

    // std::ostream << Vector (output as formated text)
    inline std::ostream& operator<< (std::ostream& out, const Vector& right);
}
