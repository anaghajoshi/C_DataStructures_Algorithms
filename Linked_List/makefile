OBS = Insert Insert_n Delete_n Reverse Reverse_Recusrsion Doubly_LinkedList
CC = gcc

all: Insert Insert_n Delete_n Reverse Reverse_Recusrsion

Insert:
	$(CC) -Wall Insert_node_at_start.c -o Insert
Insert_n:
	$(CC) -Wall Insert_node_at_nth_position.c -o Insert_n
Delete_n:
	$(CC) -Wall Delete_node_at_nth_position.c -o Delete_n	
Reverse:
	$(CC) -Wall Reverse_LinkedList.c -o Reverse
Reverse_Recusrsion:
	$(CC) -Wall Recursive_reverse_LinkedList.c -o Reverse_Recusrsion
Doubly_LinkedList:
	$(CC) -Wall Doubly_Linked_List.c -o Doubly_Linked_List
clean:
	rm-rf $(OBS)

