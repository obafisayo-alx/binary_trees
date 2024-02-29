#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to inset the right-child in
 * @value: the value to store in the new node
 * 
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_node, *temp_node;

	if (parent == NULL)
		return (NULL);
	right_node = malloc(sizeof(binary_tree_t));
	if (right_node == NULL)
		return (NULL);
	right_node->left = NULL;
	right_node->n = value;
	right_node->parent = parent;
	if (parent->right != NULL)
	{
		temp_node = parent->right;
		parent->right = right_node;
		right_node->right = temp_node;
		temp_node->parent = right_node;
	}
	else
	{
		parent->right = right_node;
		right_node->right = NULL;
	}
	return (right_node);
}
