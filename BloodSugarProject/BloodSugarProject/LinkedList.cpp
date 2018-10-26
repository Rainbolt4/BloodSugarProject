// LinkedList.cpp

// tom bailey   0745  5 oct 2010
// updated for use in the Blood Sugar project by Dominic Rainbolt 10/23/2018
// Definition of methods for the List class.

#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL), last_(NULL)
{
}



List::List(const List & other)
	: first_(clone(other.first_))
{
	size = other.size;
	sum = other.sum;
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
		size = other.size;
		sum = other.sum;
	}

	return *this;
}

bool List::operator==(const List &rhs) {
	/*if(size() == 0 && rhs.size() == 0){return true;}//both empty
	if(size() != rhs.size()){return false;}//sizes not the same

	Node * lptr = this->next_;
	Node * rptr = rhs->next_;
	Double lEntry = lptr->entry_;
	Double rEntry = rptr->entry_;
	while (lptr != NULL && rptr != NULL)
	{
	if(lEntry != rEntry){
	return false;
	}
	lptr = lptr->next_;
	rptr = rptr->next_;
	lEntry = lptr->entry_;
	rEntry = rptr->entry_;
	}
	*/
	return true;
}


bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
	sum = sum + x;
	size += 1;
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	sum = sum - item;
	size--;
	delete tempPtr;
	return item;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}
//insert as last function for assignment


void List::insertAsLast(double x)
{

	Node * firstnode = new Node(x, first_);
	Node* newn = new Node(x);
	if (firstnode->next_ == NULL) {
		insertAsFirst(x);
	}
	else {
		while (firstnode->next_ != NULL) {
			firstnode = firstnode->next_;
		}
		firstnode->next_ = newn;
		newn->next_ = NULL;
		newn->entry_ = x;
		sum = sum + x;
		size += 1;
	}
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}

//Function definition to return the size of the list.
int List::getSize() {
	return size;
}
// Function definitio to return the sum of the List.
double List::getSum() {
	return sum;
}