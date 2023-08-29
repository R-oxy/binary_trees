#include "binary_trees.h"

/**
 * _binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	left_height = _binary_tree_height(tree->left);
	right_height = _binary_tree_height(tree->right);

	return (MAX(left_height, right_height) + 1);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: input tree
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_binary_tree_height(tree));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);
	left_height = (tree->left)
		? (int)binary_tree_height(tree->left)
		: -1;
	right_height = (tree->right)
		? (int)binary_tree_height(tree->right)
		: -1;

	return (left_height - right_height);
}
