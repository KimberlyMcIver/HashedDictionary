#pragma once

#include "DictionaryInterface.h"
#include "HashedEntry.h"
#include <exception>
#include <unordered_map>
#include <vector>


#define DEFAULT_SIZE 101

/**
 *
 * This Hash table is of fixed max size 101 - which is a prime number (why?)
 */
template<class KeyType, class ItemType>
class HashedDictionary : public DictionaryInterface<KeyType, ItemType> {
private:
    HashedEntry<KeyType, ItemType> **hashTable;  // Array of pointers to entries

   // HashedEntry<KeyType, ItemType> *entrytoAddPtr;

    int itemCount;
    int hashTableSize; //Default value should be assigned to 101

    //ItemType itemStored;


    int getHashIndex(const KeyType &itemKey) const;

    void destroyDictionary();

public:
    HashedEntry<KeyType, ItemType> *entrytoAddPtr;

    virtual ~HashedDictionary();

    HashedDictionary();

    bool isEmpty() const override;

    int getNumberOfItems() const override;

    bool add(const KeyType &searchKey, const ItemType &newItem) override;

    bool remove(const KeyType &searchKey) override;

    void clear() override;

    ItemType getItem(const KeyType &searchKey) const override;

    bool contains(const KeyType &searchKey) const override;

    void traverse(void (*visit)(ItemType &)) const override;

    std::vector<ItemType> toVector() const override;

    HashedEntry<KeyType, ItemType> &operator[](KeyType key);



};

/**
 * DO NOT MODIFY THESE
 */
template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType &key) const {
    //DO NOT MODIFY
    return static_cast<int>(key % hashTableSize);
}

template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
        : itemCount(0), hashTableSize(DEFAULT_SIZE) {
    //DO NOT MODIFY
    hashTable = new HashedEntry<KeyType, ItemType> *[DEFAULT_SIZE];
    for (int i = 0; i < DEFAULT_SIZE; i++)
        hashTable[i] = nullptr;
}


template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::~HashedDictionary() {
    //DO NOT MODIFY
    destroyDictionary();
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::clear() {
    //DO NOT MODIFY
    destroyDictionary();
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::traverse(void (*visit)(ItemType &)) const {
    //DO NOT MODIFY
    for (int index = 0; index < hashTableSize; index++) {
        HashedEntry<KeyType, ItemType> *chainPtr = hashTable[index];
        while (chainPtr != nullptr) {
            ItemType currentItem = chainPtr->getItem();
            visit(currentItem);
            chainPtr = chainPtr->getNext();
        }
    }
}

template<class KeyType, class ItemType>
std::vector<ItemType> HashedDictionary<KeyType, ItemType>::toVector() const {
    //DO NOT MODIFY
    std::vector<ItemType> returnVector;
    for (int index = 0; index < hashTableSize; index++) {
        HashedEntry<KeyType, ItemType> *chainPtr = hashTable[index];
        while (chainPtr != nullptr) {
            ItemType currentItem = chainPtr->getItem();
            returnVector.push_back(currentItem);
            chainPtr = chainPtr->getNext();
        }
    }
    return returnVector;
};


template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType> &HashedDictionary<KeyType, ItemType>::operator[](KeyType searchKey) {
    //DO NOT MODIFY
    int itemHashIndex = getHashIndex(searchKey);
    HashedEntry<KeyType, ItemType> *chainPtr = hashTable[itemHashIndex];

    // Short circuit evaluation is important here
    while ((chainPtr != nullptr) && (searchKey != chainPtr->getKey())) {
        chainPtr = chainPtr->getNext();
    } // end while

    if (chainPtr == nullptr)
        throw std::exception();

    return *chainPtr;
}

/**
 * DO NOT MODIFY THE ABOVE
 */

/**
 * TODO IMPLEMENT THE REQUIRED BELOW
 */

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::destroyDictionary() {
    //TODO

    hashTable = new HashedEntry<KeyType, ItemType> *[DEFAULT_SIZE];
    itemCount = 0;

}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const {
   /* if(hashTableSize == 0)
        return true;
        */
    if(itemCount == 0){
        return true;
    }

        return false;
} // end of isEmpty

template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems() const {
    //TODO
    return itemCount;
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem) {
    //TODO
    // create entry to add to dictionary
//    std::cout << "Beginning to find " << searchKey << std::endl;
    int itemHashIndex = getHashIndex(searchKey);
//    std::cout << "Index found: " << itemHashIndex << std::endl;

    /*
    if(itemHashIndex > hashTableSize)
    {
        std::cout << "Index " << itemHashIndex << " beyond " << hashTableSize;
        //int newIndexFoo = itemHashIndex%hashTableSize;
        itemHashIndex = 0;
        //itemHashIndex = itemHashIndex%hashTableSize;
        std::cout << "Truncated to " << itemHashIndex << std::endl;
    }*/

//    std::cout << "Attepting to add..." << std::endl;



    //add the entry to the chain at itemHashIndex
    if (hashTable[itemHashIndex] == nullptr )
    {
//        std::cout << "Creating new" << std::endl;
//        std::cout << "creating new item at index " << itemHashIndex << std::endl;
        HashedEntry<KeyType, ItemType> *newEntry = new HashedEntry<KeyType, ItemType>(itemHashIndex, newItem);
//        std::cout << "Item Created: " << newEntry->getItem() << ":" << newEntry->getKey() << std::endl;
        hashTable[itemHashIndex] = newEntry;
        itemCount++;

    }

    else
    {
//        std::cout << "replacing item at index " << itemHashIndex << std::endl;
        //entrytoAddPtr->setNext (hashTable[itemHashIndex]);
        HashedEntry<KeyType, ItemType> *replaceEntry = new HashedEntry<KeyType, ItemType>(itemHashIndex, newItem);
        replaceEntry->setNext(hashTable[itemHashIndex]);

        hashTable[itemHashIndex] = replaceEntry; //->setItem(newItem);// = entrytoAddPtr;
//        std::cout << "Done" << std::endl;
    }

    return true;
}



template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType &searchKey) {

    /*
            // TODO
    return true;
*/

    for (int i = 0; i < hashTableSize; i++) {


//        std::cout << "RUNNING" << std::endl;
        HashedEntry<KeyType, ItemType> *chainPtr = hashTable[i];
        if (chainPtr == nullptr) {
//            std::cout << "CHAIN POINTER IS NOT INITIALIZED" << std::endl;
        }
        else {
            //std::cout << "Chain pointer found at index " << i << std::endl;
            while (chainPtr != nullptr) {
                ItemType currentItem = chainPtr->getItem();
                //std::cout << "Current item: " << currentItem << std::endl;
                //(*hashTable)->visit(currentItem);
                chainPtr = chainPtr->getNext();
            }

            //ItemType currentItem = chainPtr->getItem();
            //KeyType currentKey = chainPtr->getKey();
            //std::cout << "Current item: " << currentItem << std::endl;
            //something in here is crashing
            //std::cout << i << ":" << hashTable[i]->getKey() << " : " << hashTable[i]->getItem() << std::endl;
            //std::cout << hashTable[i]->getItem() << std::endl;

            if(hashTable[i] != nullptr)
            {
                if (hashTable[i]->getKey() == searchKey) {

                    HashedEntry<KeyType, ItemType> *prior = nullptr;
                    HashedEntry<KeyType, ItemType> *toRemove = hashTable[i];
                    while(toRemove->getNext() != nullptr)
                    {
//                        std::cout << "Stepping back..." << std::endl;
                        prior = toRemove;
                        toRemove = toRemove->getNext();
                    }
                    if(prior == nullptr) //then it was the first item in that chain, drop the chain
                    {
                        hashTable[i] = nullptr;
                    }
                    else {
//                        std::cout << std::endl << "Removing..." << hashTable[i]->getItem() << std::endl;

                        prior->setNext(nullptr);
                        toRemove = nullptr;
//                    hashTable[i] = NULL;
                    }
                    itemCount--;
                    return true;
                }
            }
        }
    }

    return false;

}


template<class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType &searchKey) const {


    //TODO
    if(itemCount == 0)
    {
        throw std::exception();
    }
    //entrytoAddPtr = item;
    // return "k"; // item;
    // itemStored entrytoAddPtr;
    //return itemStored;
    /*
     *
   for (int index = 0; index < hashTableSize; index++) {
        HashedEntry<KeyType, ItemType> *chainPtr = hashTable[index];
        while (chainPtr != nullptr) {
            ItemType currentItem = chainPtr->getItem();
            visit(currentItem);
            chainPtr = chainPtr->getNext();
        }
    }

     *
     */

    //std::cout << "Items stored: " << itemCount << " table size: " << hashTableSize << std::endl;


    //itemcount is always 1 for some reason
    for (int i = 0; i < hashTableSize; i++) {


//        std::cout << "RUNNING" << std::endl;
        HashedEntry<KeyType, ItemType> *chainPtr = hashTable[i];
        if(chainPtr == nullptr) {
//            std::cout << "CHAIN POINTER IS NOT INITIALIZED" << std::endl;
        }
        else {
            //std::cout << "Chain pointer found at index " << i << std::endl;
            while (chainPtr != nullptr) {
                ItemType currentItem = chainPtr->getItem();
                //std::cout << "Current item: " << currentItem << std::endl;
                //(*hashTable)->visit(currentItem);
                chainPtr = chainPtr->getNext();
            }

            //ItemType currentItem = chainPtr->getItem();
            //KeyType currentKey = chainPtr->getKey();
            //std::cout << "Current item: " << currentItem << std::endl;
            //something in here is crashing
            //std::cout << i << ":" << hashTable[i]->getKey() << " : " << hashTable[i]->getItem() << std::endl;
            //std::cout << hashTable[i]->getItem() << std::endl;


            if (hashTable[i]->getKey() == searchKey) {
                std::cout << "Found item at index " << i << std::endl;
                return hashTable[i]->getItem();
            }
        }
//        std::cout << "RAN" << std::endl;

    }

    std::cout << "NOT FOUND " << std::endl;
    throw std::exception();
    return "NOT FOUND";
   // {
     //   throw exception();
    //}

}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType &searchKey) const {
    //TODO

    //itemcount is always 1 for some reason
    for (int i = 0; i < hashTableSize; i++) {


//        std::cout << "RUNNING" << std::endl;
        HashedEntry<KeyType, ItemType> *chainPtr = hashTable[i];
        if(chainPtr == nullptr) {
//            std::cout << "CHAIN POINTER IS NOT INITIALIZED" << std::endl;
        }
        else {
            //std::cout << "Chain pointer found at index " << i << std::endl;
            while (chainPtr != nullptr) {
                ItemType currentItem = chainPtr->getItem();
                //std::cout << "Current item: " << currentItem << std::endl;
                //(*hashTable)->visit(currentItem);
                chainPtr = chainPtr->getNext();
            }

            //ItemType currentItem = chainPtr->getItem();
            //KeyType currentKey = chainPtr->getKey();
            //std::cout << "Current item: " << currentItem << std::endl;
            //something in here is crashing
            //std::cout << i << ":" << hashTable[i]->getKey() << " : " << hashTable[i]->getItem() << std::endl;
            //std::cout << hashTable[i]->getItem() << std::endl;


            if (hashTable[i]->getKey() == searchKey) {
                return true;
            }
        }
//        std::cout << "RAN" << std::endl;

    }


    return false;
}

