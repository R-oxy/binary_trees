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
 * print_level - Print nodes at a specific level
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each node
 * @level: Level of the tree to print
 */
void print_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL || func == NULL)
		return;

	if (level == 0)
	{
		func(tree->n);
	}
	else if (level > 0)
	{
		print_level(tree->left, func, level - 1);
		print_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	size_t height = binary_tree_height(tree);

	for (size_t level = 0; level <= height; level++)
	{
		print_level(tree, func, level);
	}
}
