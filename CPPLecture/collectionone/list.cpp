#include "list.hpp"

namespace Collections {

    bool SingleLinkedList::isEmpty() {
        return this->node == nullptr;
    }

    void SingleLinkedList::insert( const IElement& newElement ) {
        if (this->isEmpty()) {
            this->node = new Node(newElement);
        }
        else {
            Node* node = this->node;
            while (node->next != nullptr) {
                node = node->next;
            }
            node->next = new Node(newElement);

        }
    }

    ICollection::IIterator* SingleLinkedList::getIterator() const {
        return nullptr;
    }

}