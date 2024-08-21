/*
 ============================================================================
 Name        : c-ptoject.c
 Author      : HAZEM _A_SHAMROUKH
 Description : STUDENT_DATA
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{   int id;
char name[50];
int age;
float gpa;
};

struct node
{
	struct student data;
	struct node *next;
};

struct node *head=NULL;
void Add_Student(void);
void Display_Student(void);
void search_by_id(int id_user);
void update_by_id(int id_user);
void Delete_by_id(int id_user);
float  Average_Gpa(void);
void Student_Highest_Gpa(void);

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);//to avoid write fflush(stdout); before any scanf or gets .. etc
	setvbuf(stderr, NULL, _IONBF, 0);


int choice,id;

	do{
		printf("-------------------------------------------------------------\n");
		printf(" 1 . Add Student \n");
		printf(" 2 . Display Students \n");
		printf(" 3 . Search Student by ID \n");
		printf(" 4 . Update Student Information \n");
		printf(" 5 . Delete Student \n");
		printf(" 6 . Calculate Average GPA \n");
		printf(" 7 . Search Student With Highest GPA \n");
		printf(" 8 . Exit \n");
		printf(" Enter choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:Add_Student();break;
		case 2:Display_Student();break;
		case 3:printf(" Enter the Student ID to search : ");scanf("%d",&id);search_by_id(id);break;
		case 4:printf(" Enter the Student ID to update it's information : ");scanf("%d",&id);update_by_id( id);break;
		case 5:printf(" Enter the Student ID to Delete it's Data : ");scanf("%d",&id);Delete_by_id( id);break;
		case 6: printf(" average GPA = %f \n",Average_Gpa());break;
		case 7:Student_Highest_Gpa();break;
		case 8:printf(" Exiting.......\n");return 0;
		default:printf("-------------------------------------------------------------\n");
		printf(" please enter a correct choice of a list \n");
		}

	}while(1);// to make the condition always true


	// Eng : Hazem_A_ shamroukh
}

//-------------------------------------------------------------------

void Add_Student(void)//to add student from last
{
	struct node *adder=(struct node*)malloc(sizeof(struct node));//reserved a location
	struct node *current=head,*check=head;//to move in list with out lost the head

	if(adder==NULL)// condition to check if memory reserved or not
	{
		printf("there is no available memory location \n");
		return;
	}

	adder->next=NULL;//to make the last pointer point to nothing
	//to assign the data element
	printf("-------------------------------------------------------------");
	printf("\n Enter Student ID : ");
	scanf("%d",&adder->data.id);
	printf(" Enter Student Name : ");
	scanf("%s",adder->data.name);
	printf(" Enter Student Age : ");
	scanf("%d",&adder->data.age);
	printf(" Enter Student GPA : ");
	scanf("%f",&adder->data.gpa);

	while(check!=NULL)//loop to check if id is exist or not
	{
		if(adder->data.id==check->data.id)//the condition for  check if id is exist or not
		{

			printf("\n-------------------------------------------------------------\n");
			printf("this ID is already reserved \n");
			free(adder);
			return;

		}
		check=check->next;
	}


	if(head==NULL)//to check if this node is a first node
	{
		head=adder;
		return;
	}

	while(current->next!=NULL)//to find the latest node
	{
		current=current->next;
	}
	current->next=adder; //to weld the new node by the latest
}

//-------------------------------------------------------------------

void Display_Student(void)
{
	struct node *printer=head;//to move in list with out lost the head
	printf("-------------------------------------------------------------\n");

	if(printer==NULL)
	{
		printf(" the list is empty ( there is no students ) \n");
		return;
	}

	while(printer!= NULL)
	{
		printf("[ ");
		printf(" ID : %d ,",printer->data.id);
		printf(" Name : %s ,",printer->data.name);
		printf(" Age : %d ,",printer->data.age);
		printf(" GPA : %.2f ",printer->data.gpa);
		printf(" ]\n");
		printer=printer->next;
	}

}

//-------------------------------------------------------------------

void search_by_id(int id_user)
{
	struct node *searcher=head;//to move in list with out lost the head


	if(head==NULL)//if the list is empty
	{
		printf("-------------------------------------------------------------\n");
		printf(" the list is empty ( there is no students for searching )\n ");
		return;
	}


	while(searcher!=NULL)
	{
		if(searcher->data.id==id_user)
		{
			printf("-------------------------------------------------------------\n");
			printf(" student is founded :\n");
			printf(" Name : %s ,",searcher->data.name);
			printf(" ID : %d ,",searcher->data.id);
			printf(" Age : %d ,",searcher->data.age);
			printf(" GPA : %.2f \n",searcher->data.gpa);

			return;
		}
		searcher=searcher->next;
	}

	printf("-------------------------------------------------------------");
	printf("\n the student with ID %d not founded\n ",id_user);

}

//-------------------------------------------------------------------

void update_by_id(int id_user)
{
	struct node *searcher=head;//to move in list with out lost the head

	if(head==NULL)//if the list is empty
	{
		printf("-------------------------------------------------------------\n");
		printf(" the list is empty ( there is no students for updating ) \n");
		return;
	}

	while(searcher!=NULL)
	{
		if(searcher->data.id==id_user)
		{
			printf("-------------------------------------------------------------\n");
			printf(" Enter the new data for student with ID %d \n",id_user);

			printf(" Enter New Name : ");
			scanf("%s",searcher->data.name);
			printf(" Enter New Age : ");
			scanf("%d",&searcher->data.age);
			printf(" Enter New GPA : ");
			scanf("%f",&searcher->data.gpa);
			printf(" Student details updated successfully. \n ");
			return;
		}
		searcher=searcher->next;
	}

	printf("-------------------------------------------------------------");
	printf("\n the student with ID %d not founded\n ",id_user);

}

//-------------------------------------------------------------------

void Delete_by_id(int id_user)
{
	struct node *searcher=NULL,*previous=head;//to move in list with out lost the head


	if(head==NULL) //if the list is empty
	{
		printf("-------------------------------------------------------------\n");
		printf(" the list is empty ( there is no students for Deleting) \n");
		return;
	}

	if(previous->data.id==id_user)// if a list consist form one node
	{
		head=NULL;
		printf("-------------------------------------------------------------\n");
		printf(" the student with id %d deleted successfully. \n",id_user);
		free(previous);
		return;
	}

	searcher=head->next;//to begin check from second nod

	while(searcher!=NULL)//loop to find the student
	{
		if(searcher->data.id==id_user)
		{
			previous->next=searcher->next;//to weld the next node to previous nod from deleted node
			printf("-------------------------------------------------------------");
			printf("\n the student with id %d deleted successfully. \n",id_user);
			free(searcher);
			return;
		}
		searcher=searcher->next;
		previous=previous->next;
	}

	printf("-------------------------------------------------------------");
	printf("\n the student with id %d not founded \n",id_user);

}

//-------------------------------------------------------------------

float  Average_Gpa(void)
{
	struct node *mover=head;//to move in list with out lost the head
	float average=0.0,sum=0,counter_student=0; //to find the sum of GPA then average

	if(mover==NULL)//to check if list is empty or not
	{

		return average;

	}

	while(mover!=NULL)//to find the sum of GPA and number of students
	{
		sum+=mover->data.gpa;
		counter_student++;
		mover=mover->next;
	}

	average+=sum/counter_student;
	return average;
}

//-------------------------------------------------------------------

void Student_Highest_Gpa(void)
{
	struct node *mover=head;//to move in list with out lost the head

	printf("-------------------------------------------------------------\n");

	if(mover==NULL)
	{
		printf(" the list is empty ( there is no students )\n");

		return;
	}

	float max=mover->data.gpa; //used to compare the GPA
	struct node *position=head;//used to find position of highest GPA

	while(mover!=NULL)//loop to compare the student's GPA
	{
		if(max<mover->data.gpa)
		{
			position=position->next;
			max=mover->data.gpa;
		}
		mover=mover->next;
	}

	printf(" the student with the highest GPA : \n");
	printf("[ ");
	printf(" ID : %d ,",position->data.id);
	printf("  Name : %s ,",position->data.name);
	printf("  Age : %d  ,",position->data.age);
	printf("  GPA : %f ",position->data.gpa);
	printf(" ]\n");
}
