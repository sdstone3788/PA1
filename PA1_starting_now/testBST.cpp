#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2017
 * Based on code by Christine Alvarado
 * Samantha Stone A12861099
 * Yasmine Nassar A12772835
 */
int main() {

    /* Create an STL vector of some ints */
    /*test*/
    vector<int> v;
    v.push_back(3); //3
    v.push_back(4); //4
    v.push_back(1); //1
    v.push_back(10); //100
    v.push_back(-33); //-33
	
    /* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */

    
    // Test the template version of the BST  with ints 
    BST<int> btemp;
    for (int item : v) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }

    // Now test finding the elements we just put in
    for (int item: v) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }



    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(v.begin(),v.end());

    cout << "traversal using iterator..." << endl;
    auto vit = v.begin();
    auto ven = v.end();
    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en = btemp.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp.begin();
    for(; vit != ven; ++vit) {
        if(! (it != en) ) {
            cout << *it << "," << *vit 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
    }

    cout << "success!" << endl;

    // ADD MORE TESTS HERE.  You might also want to change what is input
    // into the vector v.
    //
    //

    // TEST TWO: large integers and weird numbers
    vector<int> v2;
    v2.push_back(1000);
    v2.push_back(-384297);
    v2.push_back(45);
    v2.push_back(202);
    v2.push_back(-39);
    v2.push_back(-2);
    v2.push_back(8392704);
    v2.push_back(0);
    v2.push_back(-873437);

 
    // Test the template version of the BST  with ints 
    BST<int> btemp2;
    for (int item2 : v2) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item2 << " into the int template-based BST...";
        auto p2 = btemp2.insert(item2);
        if (*(p2.first) != item2) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item2 << " but got " << *(p2.first) << endl;
            return -1;
        }
        if (!p2.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p2.second << endl;
            return -1;
        }
        cout << "success" << endl;
              
    }

    // Now test finding the elements we just put in
    for (int item2: v2) {
        cout << "Finding " << item2 << "...." << endl;
        BSTIterator<int> foundIt2 = btemp2.find(item2);
        if (*(foundIt2) != item2) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item2 << " but found iterator pointing to " << *(foundIt2) 
                 << endl;
            return -1;
        }
        cout << "success " << endl;
    }



    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(v2.begin(),v2.end());

    cout << "traversal using iterator..." << endl;
    auto vit2 = v2.begin();
    auto ven2 = v2.end();
    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en2 = btemp2.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it2 = btemp2.begin();
    for(; vit2 != ven2; ++vit2) {
        if(! (it2 != en2) ) {
            cout << *it2 << "," << *vit2 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it2 << endl;
        if(*it2 != *vit2) {
            cout << *it2 << "," << *vit2 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it2;
    }

    cout << "success on weird numbers test traversal!" << endl;

    //TEST THREE: strings
    vector<string> v3;
    v3.push_back("Yasmine is weird");
    v3.push_back("Samantha is cooler");
    v3.push_back("Tacos");
    v3.push_back("Chicken");
    v3.push_back("Doggies");
    v3.push_back("Moooooo");
    v3.push_back("Cow cow cow");

    // Test the template version of the BST  with stringss 
    BST<string> btemp3;
    for (string item3 : v3) {
        // The auto type here is the pair of BSTIterator<string>, bool
        cout << "Inserting " << item3 << " Into the string template-based BST...";
        auto p3 = btemp3.insert(item3);
        if (*(p3.first) != item3) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item3 << " but got " << *(p3.first) << endl;
            return -1;
        }
        if (!p3.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p3.second << endl;
            return -1;
        }
        cout << "success" << endl;
              
    }

    // Now test finding the elements we just put in
    for (string item3: v3) {
        cout << "Finding " << item3 << "...." << endl;
        BSTIterator<string> foundIt3 = btemp3.find(item3);
        if (*(foundIt3) != item3) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item3 << " but found iterator pointing to " << *(foundIt3) 
                 << endl;
            return -1;
        }
        cout << "success " << endl;
    }



    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(v3.begin(),v3.end());

    cout << "traversal using iterator..." << endl;
    auto vit3 = v3.begin();
    auto ven3 = v3.end();
    // This is equivalent to BSTIterator<string> en = btemp.end();
    auto en3 = btemp3.end();

    //This is equivalent to BST<string>::iterator it = btemp.begin();
    auto it3 = btemp3.begin();
    for(; vit3 != ven3; ++vit3) {
        if(! (it3 != en3) ) {
            cout << *it3 << "," << *vit3 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it3 << endl;
        if(*it3 != *vit3) {
            cout << *it3 << "," << *vit3 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it3;
    }

    cout << "success on strings test traversal!" << endl;



    cout << "All tests passed!" << endl;
    return 0;
}
