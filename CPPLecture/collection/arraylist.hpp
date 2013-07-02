#pragma once

#include "collection.hpp"

namespace Collections {
	// TODO: Dynamical template array class: ArrayList
	//  - implement interface
	//  - reserve
	//  - constructor
	//	- constructor from other collection
	//	- operator[]
	template<typename T> class ArrayList: public ICollection<T> {
	public:

        ArrayList() {
            m_numElements = 0;
            capacity = 16;
            array = new T[capacity];
        }

        ArrayList(ICollection& collection) {
            m_numElements = 0;
            capacity = collection.getNumElements() * 2;
            array = new T[capacity];

	        auto it = collection.getIterator();
	        while(it->current())
	        {
                insert(*(it->current()));
		        it->next();
	        }
        }

		virtual ~ArrayList() {
            delete[] array;
		}

		void resize( unsigned int numInstances ) {
            T* newArray = new T[numInstances];
            for (unsigned int i = 0; i < m_numElements ; ++i) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
            capacity = numInstances;
		}

		virtual void insert( const T& newElement ) override {
            if (m_numElements == capacity)
                resize(capacity * 2);
            array[m_numElements++] = newElement;
		}

        T& ArrayList::operator[](unsigned int const index) {
            return array[index];
        }

		class Iterator: public ICollection<T>::IIterator {
		public:
			Iterator( T* first, int numElements ) : 
				m_array( numElements ? first : nullptr ), m_remaining( numElements )		{}

			virtual T* next() override {
				if( m_remaining > 1 )
				{
					--m_remaining;
					return ++m_array;
				}
				m_remaining = 0;
				m_array = nullptr;
				return nullptr;
			}

			/// \brief Access the current element without changing the iterator
			///
			virtual T* current() const override {
				return m_array;
			}

			virtual ~Iterator() override	{}
		private:
			T* m_array;
			int m_remaining;
		};

		virtual std::shared_ptr<typename ICollection<T>::IIterator> getIterator() const override {
            return std::make_shared<Iterator>(array, m_numElements);
		}

	private:
        T* array;
        unsigned int capacity;
	};
};