OBS = Insert Insert_n Delete_n Reverse Reverse_Recusrsion
CC = gcc

all: Insert Insert_n Delete_n Reverse Reverse_Recusrsion

Insert:
	$(CC) -Wall -g Insert_node_at_start.c -o Insert
Insert_n:
	$(CC) -Wall -g Insert_node_at_nth_position.c -o Insert_n
Delete_n:
	$(CC) -Wall -g Delete_node_at_nth_position.c -o Delete_n	
Reverse:
	$(CC) -Wall -g Reverse_LinkedList.c -o Reverse
Reverse_Recusrsion:
	$(CC) -Wall -g Recursive_reverse_LinkedList.c -o Reverse_Recusrsion
clean:
	rm-rf $(OBS)

