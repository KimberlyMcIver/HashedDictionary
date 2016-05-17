#include <iostream>
#include <map>
#include "Entry.h"
#include "HashedEntry.h"

#include "HashedDictionary.h"

using namespace std;

//This function can be passed into the traverse()
void display1(string &anItem) {
    cout << "Displaying item - " << anItem << endl;
}

void dictionaryTestFromText() {

    cout << "Running example \"test\" code from the Text book\n";
    DictionaryInterface<int, string> *testDictionary = new HashedDictionary<int, string>();

    testDictionary->add(60, "F");
    testDictionary->add(70, "G");
    testDictionary->add(40, "D");
    testDictionary->add(80, "H");
    testDictionary->add(30, "C");
    testDictionary->add(50, "E");
    testDictionary->add(10, "A");
    testDictionary->add(20, "B");

    cout << "Traversing data items in sorted search-key order:\n";
    testDictionary->traverse(display1);

    testDictionary->remove(10);
    testDictionary->remove(80);
    testDictionary->remove(40);

    cout << "\nAfter Removing 10/A, 40/D & 80/H, traverse data items in sorted search-key order:\n";
    testDictionary->traverse(display1);

    cout << "\nTrying to remove 40/D again\n";
    if (testDictionary->remove(40))
        cout << "Removed second 40 :-(\n\n";
    else
        cout << "Could not remove second 40 :-)\n\n";

    cout << "Getting key/item 20/B: " << testDictionary->getItem(20) << endl;

    cout << "Getting key/item 70/G: " << testDictionary->getItem(70) << endl;

    cout << "Getting key/item 50/E: " << testDictionary->getItem(50) << endl;

    cout << "Contains key/item 80/H: " << testDictionary->contains(80) << endl;

    cout << "Contains key/item 00/??: " << testDictionary->contains(00) << endl;

    testDictionary->clear();

    cout << "\nTrying to traverse after clear\n";
    testDictionary->traverse(display1);
    cout << "If nothing displayed, that is good!\n";

    if (testDictionary->remove(20))
        cout << "Removed 20 from an empty dictionary :-(\n\n";
    else
        cout << "Could not remove 20 from an empty dictionary :-)\n\n";
}


void runHashedEntryExamples() {

    cout << "Running simple examples using Basic Entry and Hashed Entry\n";
    Entry<int, string> e1(1, "data1");
    Entry<int, string> e2(2, "data2");

    cout << e1.getItem() << endl;
    cout << e1.getKey() << endl;


    HashedEntry<int, string> he1(3, "data3");
    cout << he1.getItem() << endl;
    cout << he1.getKey() << endl;
}

void runOurDictionaryStuff() {

    cout << "---- ADDITIONAL TESTING ----- \n";
    auto dict1 = new HashedDictionary<int, string>();
    try {
            dict1->getItem(10);

    }
    catch(int e)
    {
        std::cout << "Caught exception when trying to get an item from an empty dictionary.  This is good! :-)" << std::endl;
    }

    cout << "Adding \"apple\" to index 10, banana to 20, and carrot to 30" << endl;
    dict1->add(10, "apple");
    dict1->add(20, "banana");
    dict1->add(30, "carrot");

//    cout << "Checking for item at 10 (apple)" << endl;
    cout << "Is anything in index 10? (expect 1 for true):  " << dict1->contains(10);
    cout << '\n';
    cout << "What's in index 10? (expect apple): " << dict1->getItem(10);

    //either this should return an array with 11 possible items (size of 11)
    HashedDictionary<int, string> *castedPointer = dynamic_cast<HashedDictionary<int, string> *>(dict1);
    cout << '\n';
    //or all of the 10s below here should be 9s
    cout << "Checking index 10 via dynamic cast of pointer (expect apple): " << castedPointer->getItem(10);

    //additionally, we can not set an object value to a string
    //(*castedPointer)[10] = "40";


    cout << '\n';
//    cout << castedPointer->getItem(10);
    HashedDictionary<int, string> dictObject;

    std::cout << "Attempting to replace [10] apple with alligator and [20] banana with bear..." << std::endl;
    dictObject.add(10, "alligator");
    dictObject.add(20, "bear");

    cout << "Checking index 10 (expect alligator): " << dictObject.getItem(10);
//    dictObject[10] = "40";
    cout << '\n';
    cout <<"Checking index 20 (expect banana): " << dictObject.getItem(20);
    std::cout << std::endl;
    cout << "---- ADDITIONAL TESTING COMPLETE ----- \n";

}

int main() {

    //Uncomment the below to test stuff out.
    runHashedEntryExamples();
    dictionaryTestFromText();
    runOurDictionaryStuff();

    return 0;
}