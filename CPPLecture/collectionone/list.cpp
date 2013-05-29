#include "list.hpp"

namespace Collections
{
	SingleLinkedList::~SingleLinkedList()
	{
		while( m_first )
		{
			ListEntry* next = m_first->next;
			delete m_first;
			m_first = next;
		}
	}

    SingleLinkedList::SingleLinkedList(const ICollection& list) {
        auto it = list.getIterator();
        while(it->current()) {
            this->insert(*(it->current()));
            it->next();
        }
    }

	// Inserts elements at the front of the list.
	void SingleLinkedList::insert( const IElement& newElement )
	{
		++m_numElements;
		m_first = new ListEntry( m_first, newElement.clone() );
	}

	IElement* SingleLinkedList::ListIterator::next()
	{
		if( m_current )
		{
			m_current = m_current->next;
			return m_current ? m_current->data : nullptr;
		}
		return nullptr;
	}

	IElement* SingleLinkedList::ListIterator::current() const
	{
		return m_current ? m_current->data : nullptr;
	}
    
	// Creates a one-time iterator.
	ICollection::IIterator* SingleLinkedList::getIterator() const
	{
		return new ListIterator( m_first );
	}
};