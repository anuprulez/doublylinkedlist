// Doubly linked list Abstract Data Type
// 

#include <stdio.h>
#include <stdlib.h> 

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
	    printf("\n0: Create \n1: InsertAtBegin\n2: InsertAtEnd\n3: InsertMiddle\n4: DeleteAtBegin\n5: DeleteAtEnd\n6: DeleteMiddle\n7: Print\n8: Size\n9: Is Empty\n10: Exit \n");
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
				insert_middle();
				break;
			case 4:
				delete_at_begin();
			    break;
			case 5:
				delete_at_end();
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
			default:
				break;
		}
	} while(action_key <= 9);
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
		temp = (list) calloc(1, sizeof(node));
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
	temp = (list) calloc(1, sizeof(node));
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
	temp = (list) calloc(1, sizeof(node));
	scanf("%d", &data_number);
	temp->data = data_number;
	temp->next = NULL;
	temp->prev = current;
	current->next = temp;
    current = temp;	
	print();
	//print_reverse();
	return 0;
}

int insert_middle(){
	int number = 0, counter = 0, position = 0;
	list iterator = NULL, temp = NULL, previous_node = NULL;
	iterator = head;
	previous_node = head;
	printf("\nEnter position: \n");
	scanf("%d", &position);
	printf("\nEnter number to be inserted:\n");
	scanf("%d", &number);
	
	while(iterator != NULL){
		if(counter == position){
		    temp = (list) calloc(1, sizeof(node));
			temp->data = number;
			previous_node->next = temp;
			iterator->prev = temp;
			temp->prev = previous_node;
			temp->next = iterator;
			break;
		}
		previous_node = iterator;
		iterator = iterator->next;
		counter++;
	}
	print();
	print_reverse();
	return 0;
}

int delete_at_begin(){
	list temp_node = NULL;
	temp_node = head->next;
	head = NULL;
	head = temp_node;
	head->prev = NULL;
	print();
	print_reverse();
	return 0;
}

int delete_at_end(){
	list temp_node = NULL;
	temp_node = current->prev;
	current = NULL;
	current = temp_node;
	current->next = NULL;
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


