// Doubly linked list Abstract Data Type
// 

#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h>

typedef struct node_type
{
   	int data;
   	struct node_type *next;
   	struct node_type *prev;
} node;
typedef node *list; 
list head, prev_node, current;

void main()
{
    list temp = NULL;
    int action_key = 0;
	do {
	    printf("\nEnter 0: Create, 1: InsertAtBegin, 2: InsertAtEnd, 3: InsertMiddle, 4: DeleteAtBegin, 5: DeleteAtEnd, 6: DeleteMiddle, 7: Print, 8: Size, 9: Is Empty, 10: Exit \n");
		scanf("%d", &action_key);
		switch(action_key){
		    case 0:
			    create();
				break;
			case 1:
				insert_at_begin();
				break;
			case 2:
				insert_at_end();
				break;
			case 3:
				//insert_middle();
				break;
			case 4:
				//delete_at_begin();
			    break;
			case 5:
				//delete_at_end();
			    break;
			case 6:	
			    //delete_middle();
				break;
			case 7:
			    print();
				break;
			case 8:
			    //get_size();
				break;
			case 9:
			    //is_empty();
				break;
			case 10:
				break;
			default:
				break;
		}
	} while(action_key <= 10);
	

	
	getch();
}

int create(){
    list temp = NULL;
	int how_many_numbers = 0, counter = 0, data_number = 0;
	printf("\nEnter the doubly linked list initial size: \n");
	scanf("%d", &how_many_numbers);
	for(counter = 0; counter < how_many_numbers; counter++)
	{
		printf("\nEnter a number: \n");
		temp = (list) malloc(sizeof(node));
		scanf("%d", &data_number);
		temp->data = data_number;
		temp->next = NULL;
		temp->prev = prev_node;
		if(head == NULL)
		{
			head = temp;
			current = temp;
		}
		else
		{
			current->next = temp;
			current = current->next;
		}
		prev_node = temp;
	}
	print();
	//print_reverse();
	return 0;
}

int insert_at_begin(){
    int data_number = 0;
	list temp;
	printf("\nEnter a number: \n");
	temp = (list) malloc(sizeof(node));
	scanf("%d", &data_number);
	temp->data = data_number;
	temp->next = head;
	temp->prev = NULL;
	head->prev = temp;
	head = temp;	
	print();
	//print_reverse();
	return 0;
}

int insert_at_end(){
	int data_number = 0;
	list temp;
	printf("\nEnter a number: \n");
	temp = (list) malloc(sizeof(node));
	scanf("%d", &data_number);
	temp->data = data_number;
	temp->next = NULL;
	temp->prev = current;
	current->next = temp;
    current = temp;	
	print();
	print_reverse();
	return 0;
}

int print(){
	list iterator = NULL;
	iterator = head;
	if (iterator == NULL)
    {
        printf("\nThe doubly linked list is empty\n");
        return 0;
    }
    printf("\nThe doubly linked list is: \n");
    while (iterator != NULL)
    {
        printf("%d \n", iterator->data);
        iterator = iterator->next;
    } 
	return 0;	
}

int print_reverse(){
	list iterator = NULL;
	iterator = current;
	if (iterator == NULL)
    {
        printf("\nThe doubly linked list is empty\n");
        return 0;
    }
    printf("\nThe reversed doubly linked list is: \n");
    while (iterator != NULL)
    {
        printf("%d \n", iterator->data);
        iterator = iterator->prev;
    } 
	return 0;
}


