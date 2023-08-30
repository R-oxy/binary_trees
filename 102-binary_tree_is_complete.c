#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * is_complete - Checks if a binary tree is complete recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @index: The index of the current node in the array representation.
 * @size: The total number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
_Bool is_complete(const binary_tree_t *tree,
			 unsigned int index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, size) &&
		is_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t size = binary_tree_size(tree);

	return (is_complete(tree, 0, size));
}
