#include "binary_trees.h"

/**
 * create_avl - recursive function that builds an AVL tree from an array
 * @left: leftmost index of the part of the array to be parse
 * @right: rightmost index of the part of the array to be parse
 * @root: root node
 * @array: the array
 * Return: poiner to AVL's root node
 */
avl_t *create_avl(int left, int right, avl_t *root, int *array)
{
	int idx;
	avl_t *new;
	
	if (left > right)
		return (NULL);
	idx = left + (right - left) / 2;
	new = malloc(sizeof(avl_t));
	if (new == NULL)
		return (NULL);
	new->n = array[idx];
	new->parent = root;
	new->left = create_avl(left, idx - 1, new, array);
	new->right = create_avl(idx + 1, right, new, array);
	return (new);
}
/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 * @array: the array
 * @size: the array's size
 * Return: a pointer to the root node of the created tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array == NULL)
		return (NULL);
	return create_avl(0, size - 1, root, array);
}
