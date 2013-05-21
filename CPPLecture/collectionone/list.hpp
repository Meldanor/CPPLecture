#pragma once

// QUESTION: can the following line be replaced with class
// ICollection predeclaration?
#include "collection.hpp"

namespace Collections {
    class SingleLinkedList : public ICollection {

    public:
        // Empty constructor
        SingleLinkedList() : ICollection() , node(nullptr) {}

        void insert( const IElement& newElement );

        bool isEmpty();

        IIterator* getIterator() const;

    private:

        class Node {
        public:
            Node* next;
            IElement* element;

            Node(const IElement& element) : element(element.clone()) {};
            Node(Node* next, const IElement& element) : next(next), element(element.clone()) {};
        };

        Node *node;
    };


}