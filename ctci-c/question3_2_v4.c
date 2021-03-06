/*
3.1 
How would you design a stack which, in addition to push and pop, also has a
function min which returns the minimum element? Push, pop and min should all
operate in 0(1) time.
*/

/*
SImilar to approach used in the array version with having a new separate min linked list/stack.
Extra space used for min stack while some space saved on only pushing min when value<=min.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
	int data;
	struct node *next;
};
struct node *minNode = NULL;

struct node * newNode(int val) {
	struct node *new = NULL;
	new = (struct node *)malloc(sizeof(struct node));
	if (new) {
		new->data = val;
		new->next = NULL;
	}
	else {
		printf("Error in allocating memory for new node");
	}

	return new;
}

int topStack(struct node *head) {
	printf("Top of stack: \n");
	if (head) {
		return head->data;
	}
	else {
		printf("Stack empty\n");
		return false;
	}
}

bool pushStack(struct node **head, int val) {
	printf("Pushing value: %d in stack: \n",val);
	struct node *curr = NULL, *minTemp = NULL;
	curr = newNode(val);
	if ((*head) == NULL) {
		minNode = newNode(val);
		curr->next = NULL;
		(*head) = curr;
	}
	else {
		//if (minNode) {
			if (val <= topStack(minNode)) {
				minTemp = newNode(val);
				minTemp->next = minNode;
				minNode = minTemp;
			}
		//}
		//else {
		//	minNode = newNode(val);
		//}
		curr->next = (*head);
		(*head) = curr;
	}
	return true;
}

int popStack(struct node **head) {
	printf("Popping stack: \n");
	int val;
	struct node *temp = NULL, *minTemp = NULL;

	if ((*head) == NULL) {
		printf("Stack empty\n");
		return false;
	}
	else {
		temp = (*head);
		val = temp->data;
		if (val == topStack(minNode)) {
			minTemp = minNode;
			minNode = minNode->next;
			free(minTemp);
		}
		(*head) = (*head)->next;
		free(temp);
		return val;
	}
}

int minStack() {
	printf("Finding min in stack: ");
	if (minNode == NULL) {
		printf("Stack empty\n");
		return false;
	}
	else {
		return minNode->data;
	}
}

void printStack(struct node *head) {
	printf("Printing stack: ");

	if (head != NULL) {
		printf("\n");
		while (head != NULL) {
			printf("Value: %d, Curr: %p, Next: %p\n",head->data,head,head->next);
			head = head->next;
		}
	}
	else {
		printf("Stack empty\n");
	}
}

void freeStack(struct node *head) {
	struct node *temp;
	printf("Freeing stack: ");

	if (head != NULL) {
		printf("\n");
		while (head != NULL) {
			temp = head;
			printf("Value: %d, Curr: %p, Next: %p\n",temp->data,temp,temp->next);
			head = head->next;
			free(temp);
		}
	}
	else {
		printf("Stack empty\n");
	}
}

int main(int argc, char *argv[]) {
	/*
	printf("Argument count: %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("Argument vector values:%s at %p memory\n", argv[i], argv[i]);
		for (char *j=argv[i]; *j!='\0'; j++) {
			printf("Another way to print argument vector values: "
                               "%c at %p memory\n", *j, j);
		}
	}
	*/
	struct node *stack = NULL;

	pushStack(&stack, 10);
	printf("Min: %d\n",minStack());
	pushStack(&stack, 10);
	printf("Min: %d\n",minStack());
	pushStack(&stack, 10);
	printf("Min: %d\n",minStack());
	//pushStack(&stack, 19);
	//printf("Min: %d\n",minStack());
	//pushStack(&stack, 32);
	//printf("Min: %d\n",minStack());
	printStack(stack);
	printStack(minNode);
	popStack(&stack);
	printf("Min: %d\n",minStack());
	popStack(&stack);
	printf("Min: %d\n",minStack());
	//popStack(&stack);
	//printf("Min: %d\n",minStack());
	printStack(stack);
	printStack(minNode);
	pushStack(&stack, 15);
	printf("Min: %d\n",minStack());
	pushStack(&stack, 14);
	printf("Min: %d\n",minStack());
	pushStack(&stack, 13);
	printf("Min: %d\n",minStack());
	pushStack(&stack, 12);
	printf("Min: %d\n",minStack());
	pushStack(&stack, 11);
	printf("Min: %d\n",minStack());
	pushStack(&stack, 1);
	printf("Min: %d\n",minStack());
	printStack(stack);
	printStack(minNode);
	popStack(&stack);
	printf("Min: %d\n",minStack());
	popStack(&stack);
	printf("Min: %d\n",minStack());
	popStack(&stack);
	printf("Min: %d\n",minStack());
	printStack(stack);
	printStack(minNode);

	freeStack(stack);
	freeStack(minNode);
	return 0;
}
