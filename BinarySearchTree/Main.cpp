#include "BinarySearchTree.h"

int main()
{
	int n;
	int v;
	char x = 'x';
	node* tree = 0;
	printf("[p] - print tree, [d] - deleting from tree, [i] - inserting to tree, [e] - exit\n");
	while (x != 'e')
	{
		printf("enter command: ");
		scanf_s("%c", &x);
		
		if (x == 'p')
		{
			if (!tree) printf("The tree is empty!\n");
			else PrintTree(tree);
		}
		else if (x == 'd')
		{
			if (!tree) printf("The tree is empty!\n");
			else
			{
				printf("Enter the value: ");
				scanf_s("%d", &v);
				tree=DeleteFromTree(tree, v);
			}
		}
		else if (x == 'i')
		{
			printf("Enter the value: ");
			scanf_s("%d", &v);
			tree=InsertTree(tree, v);
			printf("Node has been inserted successfully!\n");
		}
	}
	return 0;
}
