#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
int heap_height(heap_t *root)
{
	int left, right;

	if (root == NULL)
		return (0);
	left = heap_height(root->left);
	right = heap_height(root->right);
	return (left > right ? left + 1 : right + 1);	
}
heap_t *last_node(heap_t *root, int heigth)
{
	heap_t *left, *right;

	if (root == NULL)
		return (NULL);
	if (heigth == 1)
	{
		/*printf("%d ", root->n);*/
		return root;
	}		
	left = last_node(root->left, heigth - 1);
	right = last_node(root->right, heigth - 1);
	return (right == NULL ? left : right);	
}
/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: heap's root node
 * Return: the value of extracted node on success, 0 if not
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	int height;
	heap_t *node;
	/*printf("\n%d\n", height);*/
	if (root == NULL || *root == NULL)
		return (0);
	extracted_value = (*root)->n;
	height = heap_height(*root);
	node = last_node(*root, height);
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;
	(*root)->n = node->n;
	free(node);
	for(node = *root; node != NULL;)
	{
		if (node->right && node->left)
		{
			if(node->right->n > node->left->n && node->right->n > node->n)
			{
				swap(&node->right->n, &node->n);
				node = node->right;
			}
			else if(node->left->n > node->right->n && node->left->n > node->n)
			{
				swap(&node->left->n, &node->n);
				node = node->left;
			}
		}
		else if (node->right && node->right->n > node->n)
		{
			swap(&node->right->n, &node->n);
			node = node->right;
		}
		else if (node->left && node->left->n > node->n)
		{
			swap(&node->left->n, &node->n);
			node = node->left;
		}
		else
		{
			break;
		}
	}
	return(extracted_value);
}
