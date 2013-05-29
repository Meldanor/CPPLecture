#pragma once

#include "collection.hpp"

namespace Collections {
	class ArrayList: public ICollection {
	public:
        ArrayList(); 
        ~ArrayList();
        ArrayList(const ICollection& list);

        void insert(const IElement& newElement) override;
        
		/// \brief Creates a one-time iterator.
		///
		IIterator* getIterator() const override;

		/// \brief Gets an element by index
		/// \param index	Arrayindex of the inquired element. Will check validity only in debug-mode!
		/// \return Inquired element or nullptr
		IElement* get(unsigned int index) const;

		/// \brief Sets an element by index.
		/// \remarks Will delete the old element
		/// \param index	Arrayindex of the array element that will be overwritten. Will check validity only in debug-mode!
		void set(const IElement& newElement, unsigned int index);

		/// \brief Reserves memory for a given number of elements.
		/// \details This method preserves all previous inserted data. It can
		///		be used to resize the array.
		/// \remarks If the list is already bigger, this function will do nothing
		void reserve(unsigned int reservation);

    private:
        IElement** elements;
        int capacity;

        void resize(unsigned int newSize);
        void initArrayList(unsigned int size);

        class ListIterator: public IIterator {
            
		public:
            ListIterator(IElement** elements, unsigned int size) : index(0), tmp_elements(elements), size(size) {}

			/// \brief Goes to the next element in the collection.
			/// \return The next/new element or nullptr at the end.
			 IElement* next() override;

			/// \brief Access the current element without changing the iterator
			///
			IElement* current() const override;
        private:
            unsigned int index;
            IElement** tmp_elements;
            unsigned int size;
		};
	};
};