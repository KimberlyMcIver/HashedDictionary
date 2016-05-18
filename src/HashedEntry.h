#pragma  once


#include "Entry.h"

template<class KeyType, class ItemType>
class HashedEntry : public Entry<KeyType, ItemType> {
private:
    HashedEntry<KeyType, ItemType> *nextPtr;
    KeyType searchKey;
    ItemType item;



public:
    ItemType getItem();
    KeyType getKey();
    void setItem(ItemType newItem);

    HashedEntry(); //done

    HashedEntry(KeyType searchKey, ItemType newEntry); // done


    HashedEntry(KeyType searchKey, ItemType newEntry,
                HashedEntry<KeyType, ItemType> *nextEntryPtr); //done

    //void setNext(HashedEntry<KeyType, ItemType> *nextEntryPtr); //implement

    //HashedEntry<KeyType, ItemType> *getNext() const; //implement



   HashedEntry *getNext() const {
        return nextPtr;
    }

    void operator=(const ItemType&); //done

    void setNext(HashedEntry *nextEntryPtr) {
        HashedEntry::nextPtr = nextEntryPtr;
    }
};






template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry()
{
    nextPtr = nullptr;
}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(KeyType itemKey, ItemType newEntry)
{
//    std::cout << "CREATING A NEW HASHED ENTRY WITH VALUE: " << newEntry << std::endl;
    item = newEntry;
    searchKey = itemKey;
    nextPtr = nullptr;
}
//HashedEntry<KeyType, ItemType>::HashedEntry(KeyType itemKey, ItemType newEntry) : item(newEntry), searchKey(itemKey) { }

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(KeyType itemKey, ItemType newEntry, HashedEntry<KeyType, ItemType> *newEntryPtr)
{
    item = newEntry;
    searchKey = itemKey;
    nextPtr = newEntryPtr;
}
//HashedEntry<KeyType, ItemType>::HashedEntry(KeyType itemKey, ItemType newEntry, HashedEntry<KeyType, ItemType> *newEntryPtr) : item(newEntry), searchKey(itemKey), nextPtr(newEntryPtr) { };

template<class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::operator=(const ItemType& newItem)
{
    //DO
    this->setItem(newItem);
}


template<class KeyType, class ItemType>
KeyType HashedEntry<KeyType, ItemType>::getKey()
{
    return searchKey;
}

template<class KeyType, class ItemType>
ItemType HashedEntry<KeyType, ItemType>::getItem()
{
    return item;
}

template<class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::setItem(ItemType newItem) {
    item = newItem;
}

/*
template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::getNext() const {
return nextPtr;
}
 */


/*template<class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::setNext(HashedEntry<KeyType, ItemType> *nextEntryPtr) {

    nextPtr = nextEntryPtr;
}
*/





;




