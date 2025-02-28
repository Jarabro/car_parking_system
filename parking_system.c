#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARKING_SPOTS 10
int parking_spot = 0;

typedef struct Node{
	char carnumber[10];
	struct Node* link;
} Node;

int addcar(Node ** head, char * str){
	Node * node = (Node*)malloc(sizeof(Node));
	strcpy(node->carnumber, str);

	if(*head == NULL){
		*head = node;
		node->link = NULL;
		parking_spot ++;
	}
	else{	
		if(parking_spot < MAX_PARKING_SPOTS){
			Node * current = *head;
			while(current->link!=NULL)
			{
				current = current->link;
			}
			current->link = node;
			node->link = NULL;
			parking_spot ++;	
		}
		else{printf("주차장 자리 없음!\n");}
	}
	return 0;
}
/*int removecar(Node ** head, char * str){ //head와 차량번호가 들어옴:

	if(*head == NULL){
		printf("주차된 차량 없음.");
		return -1;
	}
	Node * current = *head;
	Node * prev = NULL;
	if(!strcmp(str, current->carnumber)){
		*head = current->link;
		free(current);
		return 0;
	}
	return 0;
}*/

void printparkinglot(Node * head){
	Node * current = head;
	while(current!=NULL)
	{
		for(int i=0; i < parking_spot; i++){
			printf("%d.차량번호 : [%s] \n", i+1,current->carnumber);
			current = current->link;
		}
	}
	printf("\n");
	return;
}

int main()
{
	Node *head = NULL;
	int select = 0;
	char carnumber[10];

	
	while(1)
	{	
		printf("1.차량 입차 2.차량 출차 3.주차 현황 4.종료\n");
		printf("번호 선택: ");
		scanf("%d", &select);
		if(select == 1){
			printf("차량번호: ");
			scanf("%s", carnumber);
			system("clear");
			addcar(&head, carnumber);
		}
		else if(select == 2){
			printf("차량번호: ");
			scanf("%s", carnumber);
			printf("미구현");
//			system("clear");
//			removecar(&head, carnumber);
		}
		else if(select == 3){
			system("clear");
			printparkinglot(head);
		}
		else if(select == 4){
			system("clear");
			break;
		}
		else{
			system("clear");
			printf("잘못 선택하셨습니다.\n");
		}	
	}
	return 0;
}
