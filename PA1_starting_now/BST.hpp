#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>
#include <typeinfo>

/* Samantha Stone A12861099
 * Yasmine Nassar A12772835
 */

template<typename Data>
class BST {


public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
      This is inlined because it is trivial.
   */
  BST() : root(nullptr), isize(0) {}


  /** Default destructor.
      Delete every node in this BST.
  */
  ~BST();

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return a pair where the first element is an iterator 
   *  pointing to either the newly inserted element or the element 
   *  that was already in the BST, and the second element is true if the 
   *  element was newly inserted or false if it was already in the BST.
   * 
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=)  
   */
  std::pair<iterator, bool> insert(const Data& item);


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=).  For the reasoning
   *  behind this, see the assignment writeup.
   */
  iterator find(const Data& item) const;

  
  /** Return the number of items currently in the BST.
   */ 
  unsigned int size() const;
  
  /** Return the height of the BST.
      height of a tree starts with root at height 0
   */ 
  unsigned int height() const;

  unsigned int heightHelper(BSTNode<Data> * node) const;

  /** Return true if the BST is empty, else false.
   */ 
  bool empty() const;

  /** Return an iterator pointing to the first (smallest) item in the BST.
   */ 
  iterator begin() const;

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const;


private:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;
  
  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** Find the first element of the BST
   * Helper function for the begin method above.
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root);

  /** do a postorder traversal, deleting nodes
   */
  static void deleteAll(BSTNode<Data>* n);
 };


// ********** Function definitions ****************


/** Default destructor.
    Delete every node in this BST.
*/
template <typename Data>
BST<Data>::~BST() {
  deleteAll(root);
}


/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return a pair where the first element is an iterator pointing to either the newly inserted
 *  element or the element that was already in the BST, and the second element is true if the 
 *  element was newly inserted or false if it was already in the BST.
 * 
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  
 */

template <typename Data>
std::pair<BSTIterator<Data>, bool> BST<Data>::insert(const Data& item) {
  
  
  //check if the tree is empty without using ==
  if (empty()){
	//add item as a new node to the tree
	BSTNode<Data> * ptr = new BSTNode<Data>(item); 
	//set the root to the node  
	root = ptr; 
	BSTIterator<Data> itr (ptr);  
	isize++;
	return std::pair<BSTIterator<Data>,bool>(itr, true);
  }
  //if the item already exists, we just need an iterator pointing to it
  BSTIterator<Data> itemItr= find(item);
  if(itemItr!=end()){
	return std::pair<BSTIterator<Data>,bool>(itemItr, false);
  }
  //the item does not exist in the tree so we need to put it in and return true
  else{
	//BSTNode<Data> insert_node = new BSTNode<Data>(item);
	BSTNode<Data> * insert_node_ptr = new BSTNode<Data>(item);
	BSTNode<Data> * node = root;
	//BSTIterator <Data> new_itr (nullptr);
        while (node != NULL){
		if(item < node->data){
			if(node->left != NULL){
				node = node->left;
			}
			//insert it if the child is not there
			else{
				node->left = insert_node_ptr;
				(node->left)->parent = node;
				BSTIterator <Data> new_itr(node->left);
				isize++;
        			return std::pair<BSTIterator<Data>, bool>(new_itr, true);
				
			}
		}
		else if (node->data < item){
			if(node->right != NULL){	
				node = node->right;
			}
			else{
				node->right = insert_node_ptr;
				(node->right)->parent = node;
				BSTIterator <Data> new_itr(node->right);
				isize++;
			        return std::pair<BSTIterator<Data>, bool>(new_itr, true);
			}
		}
	}
   }	
   return std::pair<BSTIterator<Data>, bool>(NULL, NULL);

}


/** Find a Data item in the BST.
 *  Return an iterator pointing to the item, or pointing past
 *  the last node in the BST if not found.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */

template <typename Data>
BSTIterator<Data> BST<Data>::find(const Data& item) const
{
  BSTNode<Data> * node = root;
  //make sure there is a node to compare to
  while(node != NULL){
	if(item < node->data){
		//traverse left
		node = node->left;
	}
	else if (node->data < item){
		//traverse right
		node = node->right;
	}
	//here the data and node are equal-- we found it!
	else{
		BSTIterator<Data> iter(node);
		return iter;
	}
  }
  //handle case where element is not found; return null iter 
  
  return BSTIterator<Data>(nullptr); 

}

  
/** Return the number of items currently in the BST.
 */ 
template <typename Data>
unsigned int BST<Data>::size() const
{
  return isize;
}

/** Return the height of the BST.
 */
template <typename Data> 
unsigned int BST<Data>::height() const
{
  int height;
  //if the tree has only one node (a root) or none , then the height is 0
  if(empty() || size()== 1){
  	height = 0;
  }
  //else, find the height of the tree
  else{
  	height = heightHelper(this->root);		
  }
  return height;
}

/** Helper for height method
 */
template <typename Data>
unsigned int BST<Data>::heightHelper(BSTNode<Data>* node) const
{	
  //get the left and right children
  BSTNode<Data>* leftO = node->left;
  BSTNode<Data>* rightO = node->right;
  int Ltotal=0;
  int Rtotal=0;
  //see if left exists, add 1 to the total height on the left side
  if (leftO){
	Ltotal= 1+ heightHelper(leftO);
  }
  //see if right exists, add 1 to the total height on the right side
  if (rightO){
	Rtotal=1+ heightHelper(rightO);
  }
  //whichever branch is largest is the height we return
  if (Rtotal<Ltotal){
	return Ltotal;
  }
  if (Ltotal<Rtotal){
	return Rtotal;
  }
  //if both heights are the same, we return one of them
  return Ltotal;
}
  
   
   

/** Return true if the BST is empty, else false.
 */ 
template <typename Data>
bool BST<Data>::empty() const
{
  //if there are no nodes
  if (isize<1){
	return true;
  }
  return false;
}

/** Return an iterator pointing to the first (smallest) item in the BST.
 */ 
template <typename Data>
BSTIterator<Data> BST<Data>::begin() const
{
  return BSTIterator<Data>(first(root));
}

/** Return an iterator pointing past the last item in the BST.
 */
template <typename Data>
BSTIterator<Data> BST<Data>::end() const
{
  return BSTIterator<Data>(nullptr);
}

/** Find the first element of the BST
 * Helper function for the begin method above.
 */ 
template <typename Data>
BSTNode<Data>* BST<Data>::first(BSTNode<Data>* root)
{
  BSTNode<Data>* node = root;
  //traverse to the left until you are at the left most (smallest)
  while (node->left){
  	node = node->left;
  }
  return node;
}

/** do a postorder traversal, deleting nodes
 */
template <typename Data>
void BST<Data>::deleteAll(BSTNode<Data>* n)
{
	BSTNode<Data> * curr = n;
	//traverse left and delete everything
	if(curr->left){
		deleteAll(curr->left);
		curr->left = nullptr;
	}  
	//traverse right and delete everything
	if(curr->right){
		deleteAll(curr->right);
		curr->right = nullptr;
	}
	
	//delete the current node
	if(curr->right == NULL && curr->left == NULL){
		delete curr;
	}
}



#endif //BST_HPP
