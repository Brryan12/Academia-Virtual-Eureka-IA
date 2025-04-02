#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

template <typename Datatype>
class List
{
private:

    /// @brief Node of the list
    struct Node
    {
        /// @brief Data stored in the node
        Datatype* data;

        /// @brief Pointer to the next node
        Node* next;

        /// @brief Constructor of the Node class
        /// @param data Data to be stored in the node
        /// @param next Pointer to the next node
        Node(Datatype* data, Node* next) : data(data), next(next) {}
    };

    /// @brief Pointer to the first node of the list
    Node* first;

    /// @brief Pointer to the current node of the list   
    Node* current;
public:
    /// @brief Constructor of the List class
    List() : first(nullptr), current(nullptr) {}

    /// @brief Destructor of the List class
    virtual ~List();

    /// @brief Method to insert an element into the list
    /// @param data Data to be inserted into the list
    /// @return false if the element already exists, true if it was inserted successfully
    bool insert(Datatype* data);

    /// @brief Method to delete an element from the list
    /// @param id Identifier of the element to be deleted
    /// @return false if the element does not exist, true if it was deleted successfully
    bool remove(std::string id);

    /// @brief Method to search for an element in the list
    /// @param id Identifier of the element to search for
    /// @return Pointer to the element if found, nullptr if not found
    Datatype* searchElement(std::string id);

    /// @brief Method to convert the list to a string
    /// @return String with the elements of the list
    std::string toString() const;

    /// @brief Method to check if the list is empty
    /// @return false if the list is not empty, true if the list is empty
    bool isEmpty() const { return first == nullptr; }

    /// @brief Method to return the first node of the list
    /// @return the first node of the list
    Node* getFirst() const { return first; }

    /// @brief Method to return the current node of the list
    /// @return the current node of the list
    Node* getCurrent() const { return current; }

    /// @brief Method to set the first node of the list
    /// @param first Pointer to the first node of the list
    void setFirst(Node* first) { this->first = first; }

    /// @brief Method to return the number of elements in the list
    int elementCount() const {
        int count = 0;
        Node* current = first;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    /// @brief Method to set the current node of the list
    /// @param current Pointer to the current node of the list
    void setCurrent(Node* current) { this->current = current; }

    /// @brief Method to save to file
    /// @param output Output stream
    bool saveToFile(std::ostream& output) const;
};

template<typename Datatype>
inline List<Datatype>::~List() {
    Node* current = first;
    while (current != nullptr) {
        Node* next = current->next; // Save the next node before deleting the current one
        delete current->data;       // Delete the data only if we are sure that List is the sole owner
        delete current;             // Delete the current node
        current = next;             // Move to the next node
    }
    first = nullptr; // Ensure that first is set to nullptr at the end
}

template<typename Datatype>
inline bool List<Datatype>::insert(Datatype* data)
{
    if (this->searchElement(data->getId()) != nullptr) {
        // If the element already exists, do not insert and return false
        return false;
    }
    current = new Node(data, nullptr);
    current->next = first;
    first = current;
    return true;
}

template<typename Datatype>
inline bool List<Datatype>::remove(std::string id) {
    current = first;
    Node* previous = nullptr;

    // empty list
    if (current == nullptr) {
        std::cout << "empty" << std::endl;
        return false;
    }

    // traverse list
    while (current != nullptr && current->data->getId() != id) {
        previous = current;
        current = current->next;
    }

    // node not found
    if (current == nullptr) {
        std::cout << "not found" << std::endl;
        return false;
    }

    // if the first node is to be deleted
    if (previous == nullptr) {
        first = current->next;
    }
    // if it is another node
    else {
        previous->next = current->next;
    }

    // free memory and avoid dangling references
    delete current;
    current = nullptr;

    return true;
}

template<typename Datatype>
inline Datatype* List<Datatype>::searchElement(std::string id)
{
    current = first;
    if (current == nullptr) {
        return nullptr;
    }
    while (current != nullptr && current->data->getId() != id) {
        current = current->next;
    }
    if (current == nullptr) {
        return nullptr;
    }
    return current->data;
}

template<typename Datatype>
inline std::string List<Datatype>::toString() const {
    std::stringstream ss;
    Node* current = first;
    while (current != nullptr) {
        ss << current->data->toString() << std::endl;
        current = current->next;
    }
    return ss.str();
}

// Method to save to file
template<typename Datatype>
bool List<Datatype>::saveToFile(std::ostream& output) const {
    Node* current = first;
    while (current != nullptr) {
        current->data->save(output);
        current = current->next;
    }

    return true;
}
