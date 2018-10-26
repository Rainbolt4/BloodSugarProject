// Node.cpp
// tom bailey   1050  31 jan 2011
// Definitions of the Node class methods
// Modified for use in blood sugar project by Dominic Rainbolt 
// 10/10/2018

#include "Node.h"


Node::Node(int entry)
	: entry_(entry), next_(NULL)
{
	cout << "Node( " << entry_ << ", " << next_ <<
		" ) created at " << this << endl;
}

Node::Node(int entry, Node * next)
	: entry_(entry), next_(next)
{
	cout << "Node( " << entry_ << ", " << next_ <<
		" ) created at " << this << endl;
}

Node::~Node()
{
	cout << "Node( " << entry_ << ", " << next_ <<
		" ) at " << this << " destroyed" << endl;
}