#include "binary_trees.h"

/**
 * is_bst - Helper function
 * @tree: Pointer to the root node of the tree to check
 * @prev: Pointer to the previously visited node
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, const binary_tree_t **prev)
{
	if (tree == NULL)
		return (1);

	if (!is_bst(tree->left, prev))
		return (0);

	if (*prev != NULL && (*prev)->n >= tree->n)
		return (0);

	*prev = tree;

	return (is_bst(tree->right, prev));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	const binary_tree_t *prev = NULL;

	return (is_bst(tree, &prev));
}
