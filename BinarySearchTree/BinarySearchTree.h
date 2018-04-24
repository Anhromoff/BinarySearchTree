#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <stdio.h>

// Structure of the tree element
struct node 
{
	int value; // just a number
	node* left_node; // pointer to the left subtree
	node* right_node; // pointer to the right subtree
};

// Insertion an element with value v to the tree
node* InsertTree(node* current_node, int v)
{
	// if there is no node
	if (!current_node) 
	{
		current_node = new node; // creating a new node
		current_node->value = v; // put value to it

		// there are no children yet, so pointers must be null
		current_node->left_node = 0; 
		current_node->right_node = 0;
		return current_node;
	}
	else
	{
		// go deeper to the left subtree
		if (v< current_node->value) 
			current_node->left_node=InsertTree(current_node->left_node, v); 
		// go deeper to the right subtree
		else 
			current_node->right_node=InsertTree(current_node->right_node, v);// если заданное значение больше или равно значения текущего узла, то рекурсивно обрабатываем узел правого поддерева
		return current_node;
	}
}

// Console tree visualisation
void PrintTree(node* current_node) 
{
	static int level = 0; // means depth of the current node
	level++; // level down
	if (current_node)
	{
		PrintTree(current_node->right_node); // print begins with right node
		for (int i = 0; i<level; i++) printf("   "); // printing spaces
		printf("\\__%d\n", current_node->value); // printing value
		PrintTree(current_node->left_node); // go to the left subtree
	}
	level--; // level up
}

// Searching for the node with min value in subtree
node* prev_node;
node* FindMin(node* current_node)
{
	if (current_node->right_node)
	{
		prev_node = current_node;
		FindMin(current_node->right_node);
	}
	else
	{
		prev_node->right_node = 0;
		return current_node;
	}
}

// deleting element vith value v from tree
node* DeleteFromTree(node* current_node, int v)
{
	// element not found
	if (!current_node)
	{
		printf("not found");
		return 0;
	}
	if (current_node)
	{
		// searching for the node with value v
		if (v<current_node->value) current_node->left_node =DeleteFromTree(current_node->left_node, v);
		else if (v>current_node->value) current_node->right_node =DeleteFromTree(current_node->right_node, v);

		// If we got here, it means that the node was found

		// If node has only one child, we replace the node by the child
		else if ((!current_node->right_node) && (current_node->left_node)) // left child case
		{
			delete current_node;
			return current_node->left_node;
		}
		else if ((!current_node->left_node) && (current_node->right_node)) // right child case
		{
			delete current_node;
			return current_node->right_node;
		}
		// If node has no children, we simply delete it
		else if ((!current_node->right_node) && (!current_node->left_node)) 
		{
			delete current_node;
			return 0;
		}
		// If node has 2 children, we find node with minimum value and replace the node by it
		else
		{
			node* min = FindMin(current_node);
			current_node->value = min->value;
			delete min;
			return current_node;
		}
		return current_node;
	}
}

#endif
