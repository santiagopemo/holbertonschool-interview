#include "binary_trees.h"

/**
 * is_bst - check if a tree is a binary search tree
 * @tree: root node
 * @min: min value of the tree
 * @max: max value of the tree
 * Return: 1 if it is a BST, otherwise 0
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min)
		return (0);
	if (tree->n > max)
		return (0);
	return (is_bst(tree->right, tree->n + 1, max) &&
			is_bst(tree->left, min, tree->n - 1));
}
/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: tree root
 * Return: If tree is NULL the function return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t r, l;

	if (tree == NULL)
		return (0);
	l = binary_tree_height(tree->left);
	r = binary_tree_height(tree->right);
	if (r > l)
		return (r + 1);
	return (l + 1);
}
/**
 * binary_tree_balance - function that measures the balance factor of a tree
 * @tree: binary tree root
 * Return: If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * overall_balance - check if a tree and all it's subtrees are balanced
 * @tree: pointer to root node
 * Return: 1 if is balanced, otherwise 0
 */
int overall_balance(const binary_tree_t *tree)
{
	int balance;

	if (tree == NULL)
		return (0);
	balance = binary_tree_balance(tree);
	if (balance >= -1 && balance <= 1)
		return (overall_balance(tree->left) || overall_balance(tree->right));
	return (balance);
}
/**
 * binary_tree_is_avl - Write a function that
 * checks if a binary tree is a valid AVL Tree
 * @tree: pointer to tree root
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int bst, balance;

	if (tree == NULL)
		return (0);
	bst = is_bst(tree, INT_MIN, INT_MAX);
	balance = binary_tree_balance(tree);
	if (bst == 1)
	{
		balance = overall_balance(tree);
		if (balance == 0)
			return (1);
	}
	return (0);
}
