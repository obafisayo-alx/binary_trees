#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_node, *temp_node;

	if (parent == NULL)
		return (NULL);
	left_node = malloc(sizeof(binary_tree_t));
	if (left_node == NULL)
		return (NULL);
	left_node->right = NULL;
	left_node->n = value;
	left_node->parent = parent;
	if (parent->left == NULL)
	{
		parent->left = left_node;
		left_node->left = NULL;
	} else {
		temp_node = parent->left;
		parent->left = left_node;
		left_node->left = temp_node;
		temp_node->parent = left_node;
	}
	return left_node;
}
