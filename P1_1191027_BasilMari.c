// COMP2421 Project 1 by Basil Mari		Student ID: 1191027		Date: 5/5/2022		Section: 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define passenger linked list node data structure
struct Passenger {
	char pid[20];
	char date[20];
	char time[20];
	char origin[20];
	char destination[20];
	struct Passenger* next;
};

//Deletes passenger linked list L from memory
void DeleteListP(struct Passenger* L){
	struct Passenger* P;
	struct Passenger* temp;
	P = L;
	if (P == NULL) {
		//printf("List does not exist!\n");
		return;
	}
	while(P != NULL){
		temp = P->next;
		free(P);
		P = temp;
	}
}

//Finds the node previous to P in a passengers linked list with head L
struct Passenger* FindPreviousP(struct Passenger* L, struct Passenger* P) {
	struct Passenger* node;
	node = L;
	while (node != NULL && node->next != P)
		node = node->next;
	return node;

}

//Deletes node P in passengers linked list with head L
void DeletePassenger(struct Passenger* L, struct Passenger* P){
	struct Passenger* node;
	struct Passenger* previous;
	node = P;
	if (node == NULL) {
		printf("Passenger does not exist!\n");
		return;
	}
	previous = FindPreviousP(L, node);
	previous->next = node->next;
	free(node);
}

//Makes passengers linked list with head L empty
struct Passenger* MakeEmptyP(struct Passenger* L) {

	if (L != NULL)
		DeleteListP(L);

	L = (struct Passenger*) malloc(sizeof(struct Passenger));

	if (L == NULL) {
		printf("Not enough memory!\n");
		return NULL;
	}

	L->next = NULL;
	return L;
}

//Checks if passengers linked list L is empty
int IsEmptyP(struct Passenger* L) {
	return L->next == NULL;
}

//Checks if passenger node P is the last node in linked list L
int IsLastP(struct Passenger* L, struct Passenger* P) {
	return P->next == NULL;
}

//Inserts passenger with specified information in passenger linked list L
void InsertPassenger(char pid[20], char date[20], char time[20], char origin[20], char destination[20], struct Passenger* L, struct Passenger* P) {

	struct Passenger* temp;
	temp = (struct Passenger*) malloc(sizeof(struct Passenger));

	if (temp == NULL) {
		printf("Not enough memory!\n");
		return;
	}

	strncpy(temp->pid, pid, 20);
	strncpy(temp->date, date, 20);
	strncpy(temp->time, time, 20);
	strncpy(temp->origin, origin, 20);
	strncpy(temp->destination, destination, 20);
	temp->next = P->next;
	P->next = temp;
}

//Prints passengers in linked list L along with their information
void PrintPassengers(struct Passenger* L) {
	struct Passenger* P = L;
	if (IsEmptyP(L))
		printf("\tList is empty!\n");
	else
		do{
			P=P->next;
			printf("\tPassenger ID: %s, Trip Date: %s, Trip Time: %s, Origin: %s, Destination: %s\n", P->pid, P->date, P->time, P->origin, P->destination);
		} while (!IsLastP(L, P));
}

//Finds last node in passenger linked list L
struct Passenger* FindLastP(struct Passenger* L) {
	struct Passenger* P;
	P = L;
	while (!IsLastP(L,P)) {
		P = P->next;
	}
	return P;
}

//Find passenger with matching ID in passenger linked list L
struct Passenger* FindPassenger(char pid[20], struct Passenger* L) {
	struct Passenger* P;
	P = L->next;
	while (P != NULL && strcmp(pid, P->pid) != 0)
		P=P->next;
	return P;
}

//define bus linked list node data structure
struct Bus {
	char bid[20];
	char date[20];
	char time[20];
	char origin[20];
	char destination[20];
	int ticketprice;
	int capacity;
	struct Passenger* passengers;
	struct Bus* next;
};

//Finds the node previous to P in a Bus linked list with head L
struct Bus* FindPreviousB(struct Bus* L, struct Bus* P) {
	struct Bus* node;
	node = L;
	while (node != NULL && node->next != P)
		node = node->next;
	return node;

}

//Deletes Bus linked list L from memory
void DeleteListB(struct Bus* L){
	struct Bus* P;
	struct Bus* temp;
	P = L;
	if (P == NULL) {
		//printf("List does not exist!\n");
		return;
	}
	while(P != NULL){
		temp = P->next;
		DeleteListP(P->passengers);
		free(P);
		P = temp;
	}
}

//Deletes node P in Bus linked list with head L
void DeleteBus(struct Bus* L, struct Bus* P){
	struct Bus* node;
	struct Bus* previous;
	node = P;
	if (node == NULL) {
		printf("Bus does not exist!\n");
		return;
	}
	previous = FindPreviousB(L, node);
	previous->next = node->next;
	DeleteListP(node->passengers);
	free(node);
}

//Makes passengers linked list with head L empty
struct Bus* MakeEmptyB(struct Bus* L) {

	if (L != NULL)
		DeleteListB(L);

	L = (struct Bus*) malloc(sizeof(struct Bus));

	if (L == NULL) {
		printf("Not enough memory!\n");
		return NULL;
	}

	L->next = NULL;
	L->passengers = NULL;
	return L;

}

//Checks if Bus linked list L is empty
int IsEmptyB(struct Bus* L) {
	return L->next == NULL;
}

//Checks if node P is the last node in Bus linked list L
int IsLastB(struct Bus* H, struct Bus* P) {
	return P->next == NULL;
}

//Inserts Bus with specified information in Bus linked list L
void InsertBus(char bid[20], char date[20], char time[20], char origin[20], char destination[20], int ticketprice, int capacity, struct Bus* L, struct Bus* P) {

	struct Bus* temp;
	temp = (struct Bus*) malloc(sizeof(struct Bus));

	if (temp == NULL) {
		printf("Not enough memory!\n");
		return;
	}

	strncpy(temp->bid, bid, 20);
	strncpy(temp->date, date, 20);
	strncpy(temp->time, time, 20);
	strncpy(temp->origin, origin, 20);
	strncpy(temp->destination, destination, 20);
	temp->ticketprice = ticketprice;
	temp->capacity = capacity;
	temp->next = P->next;
	temp->passengers = MakeEmptyP(NULL);
	P->next = temp;

}

//Prints Bus L from linked list along with its information
void PrintBus(struct Bus* L) {
	struct Bus* P;
	P = L;
	if (P == NULL)
		printf("Bus does not exist!\n");
	else {
		printf("Bus ID: %s, Trip Date: %s, Trip Time: %s, Origin: %s, Destination: %s, Ticket Price: %d, Capacity: %d\nPassengers:\n", P->bid, P->date, P->time, P->origin, P->destination, P->ticketprice, P->capacity);
		PrintPassengers(P->passengers);
		printf("\n");
	}
}

//Prints all nodes in Bus linked list L along with their information
void PrintBuses(struct Bus* L) {
	struct Bus* P;
	P = L;
	if (IsEmptyB(L))
		printf("List is empty!\n");
	else
		do{
			P=P->next;
			printf("Bus ID: %s, Trip Date: %s, Trip Time: %s, Origin: %s, Destination: %s, Ticket Price: %d, Capacity: %d\n", P->bid, P->date, P->time, P->origin, P->destination, P->ticketprice, P->capacity);
		} while (!IsLastB(L, P));
}

//Prints all nodes in Bus linked list L along with their information and passengers
void PrintBusesPassengers(struct Bus* L) {
	struct Bus* P;
	P = L;
	if (IsEmptyB(L))
		printf("List is empty!\n");
	else
		do {
			P = P->next;
			printf("Bus ID: %s, Trip Date: %s, Trip Time: %s, Origin: %s, Destination: %s, Ticket Price: %d, Capacity: %d\nPassengers:\n", P->bid, P->date, P->time, P->origin, P->destination, P->ticketprice, P->capacity);
			PrintPassengers(P->passengers);
			printf("\n");
		} while (!IsLastB(L, P));
}

//Finds last node in Bus linked list L
struct Bus* FindLastB(struct Bus* L) {
	struct Bus* P;
	P = L;
	while (!IsLastB(L,P)) {
		P = P->next;
	}
	return P;
}

//Finds bus with matching ID in bus linked list L
struct Bus* FindBus(char bid[20], struct Bus* L) {
	struct Bus* P;
	P = L->next;
	while (P != NULL && strcmp(bid, P->bid) != 0)
		P=P->next;
	return P;
}

//Finds bus with matching date, origin, and destinatino in bus linked list L
struct Bus* MatchBus(char date[20], char origin[20], char destination[20], struct Bus* L) {
	struct Bus* P;
	P = L->next;
	while (P != NULL && (strcmp(date, P->date) != 0 || strcmp(origin, P->origin) != 0 || strcmp(destination, P->destination) != 0))
		P=P->next;
	return P;
}

void LoadBusFile(struct Bus*);	//Loads informatino in busses.txt into a bus linked list "busList"
void LoadPassengerFile(struct Passenger*);	//Loads informatino in passengers.txt into passengers linked list "passengerList"
void AssignPassengers(struct Bus*, struct Passenger*);	//Assigned passengers in passengerList to buses in busList

//Main body of program defines user inteface menu
int main() {
	int busesloaded = 0;
	int passengersloaded = 0;
	int passengersassigned = 0;
	int option;
	char id[20];
	char date[20];
	char time[20];
	char origin[20];
	char destination[20];
	struct Bus* busList;
	busList = MakeEmptyB(NULL);		//creating head of the buses linked list
	struct Passenger* passengerList;
	passengerList = MakeEmptyP(NULL);	//creating head of the students linked list

	printf("Enter a number to perform one of the following operations:\n1. Load bus information from busses.txt.\n2. Load passenger information from passengers.txt.\n3. Assign passengers and print assignment information of all buses.\n4. Print the information for a specific bus along with its passengers.\n5. Print unmatched passengers.\n6. Add new passenger.\n7. Delete passenger.\n8. Delete bus.\n9. Exit Program.\n");
	do {
		printf("Option: ");		//Printing prompt and reading user input
		scanf("%d", &option);
		switch (option) {

			case (1):			//Option 1: Load bus information from busses.txt
				LoadBusFile(busList);
				busesloaded = 1;
				break;

			case (2):			//Option 2: Load passenger information from passengers.txt
				LoadPassengerFile(passengerList);
				passengersloaded = 1;
				break;

			case (3):			//Option 3: Assign loaded passengers to loaded buses and print assignment information
				if (busesloaded == 1 && passengersloaded == 1) {
					AssignPassengers(busList, passengerList);
					passengersassigned = 1;
					printf("\n");
					PrintBusesPassengers(busList);
				}
				else if (busesloaded != 1 && passengersloaded == 1)
					printf("Buses are not loaded! Load buses from busses.txt with option 1 and try again.\n");
				else if (busesloaded == 1 && passengersloaded != 1)
					printf("Passengers are not loaded! Load passengers from passengers.txt with option 2 and try again.\n");
				else
					printf("Passengers and buses are not loaded! Load passengers and buses from passengers.txt and busses.txt with options 1 and 2, and try again.\n");
				break;

			case (4):			//Option 4: Print information of specified bus along with its passengers
				if (passengersassigned != 1)
					printf("Most recent passenger list hasn't been assigned to buses. You may want to assign passengers with option 3 before printing the passengers assigned to this bus.\n");
				printf("Enter the bus ID of the bus you wish to print the information of: ");
				scanf("%19s", id);
				PrintBus(FindBus(id, busList));
				break;

			case (5):			// Option 5: Print unmatched passengers and their information
				PrintBus(FindLastB(busList));
				break;

			case (6):			// Option 6: Add passenger to passengerList
				printf("Enter the information of the passenger to be added.\nPassenger ID: ");
				scanf("%19s", id);
				printf("Trip date: ");
				scanf("%19s", date);
				printf("Trip time (HH:MM): ");
				scanf("%19s", time);
				printf("Trip origin: ");
				scanf("%19s", origin);
				printf("Trip destination: ");
				scanf("%19s", destination);
				InsertPassenger(id, date, time, origin, destination, passengerList, passengerList);
				passengersassigned = 0;
				busList = MakeEmptyB(busList);
				LoadBusFile(busList);
				break;

			case (7):			// Option 7: Delete passenger from passengerList
				printf("Enter the ID of the passenger to be deleted: ");
				scanf("%19s", id);
				DeletePassenger(passengerList, FindPassenger(id, passengerList));
				passengersassigned = 0;
				busList = MakeEmptyB(busList);
				LoadBusFile(busList);
				break;

			case (8):			// Option 8: Delete bus from busList
				printf("Enter the ID of the bus to be deleted: ");
				scanf("%19s", id);
				passengersassigned = 0;
				busList = MakeEmptyB(busList);
				LoadBusFile(busList);
				DeleteBus(busList, FindBus(id, busList));
				break;

			case (9):			// Option 9: Exit program
				printf("Exiting program...\n");
				break;

			default:			// Default option: print error message and prompt user for valid input
				printf("Option invalid. Please enter a valid option.\n");
				break;
		}
	} while(option != 9);

	DeleteListP(passengerList);		// Free passenger linked list
	DeleteListB(busList);			// Free bus linked list
}

// Load buses from busses.txt into busList
void LoadBusFile(struct Bus* busList) {
	FILE* input;
	input=fopen("busses.txt", "r");
	if(input==NULL) {
		printf("busses.txt not found!\n");
		exit(-1);
	}

	const char EOL = '\n';//end of line reading
	char character;
	int lines = 0;
	while((character = fgetc(input)) !=EOF){
		if(character==EOL)
			lines+=1;
	}
	fclose(input);//closing file to reopen it so that it resets the scanner

	FILE *inputB=fopen("busses.txt", "r");//opening file
	if(inputB==NULL){
		printf("busses.txt not found!\n");
		exit(-1);
	}
	char id[20];
	char date[20];
	char time[20];
	char origin[20];
	char destination[20];
	int ticketprice;
	int capacity;

	char s[20];
	memset(s, 0, sizeof(s));	//resetting the string
	int i=0;
	char temp=fgetc(inputB);

	//reading from file
	for (int j = 0; j < lines; j++) {
		while (temp != '#' && temp != EOF && i < 19) {		//1: Bus ID
			if (temp == '\n')
				temp = fgetc(inputB);
			s[i] = temp;
			i++;
			temp = fgetc(inputB);
		}
		temp = fgetc(inputB);
		i = 0;
		strncpy(id, s, 20);
		memset(s, 0, strlen(s));

		while (temp != '#' && temp != EOF && i < 19) {		//2: Trip date
			if (temp == '\n')
				temp = fgetc(inputB);
			s[i] = temp;
			//printf("%c", temp);
			i++;
			temp = fgetc(inputB);
		}
		temp = fgetc(inputB);
		i = 0;
		strncpy(date, s, 20);
		//printf("\t%s\t", s);
		//printf("%s\t", date);
		memset(s, 0, strlen(s));

		while (temp != '#' && temp != EOF && i < 19) {		//3: Trip time
			if (temp == '\n')
				temp = fgetc(inputB);
			s[i] = temp;
			i++;
			temp = fgetc(inputB);
		}
		temp = fgetc(inputB);
		i = 0;
		strncpy(time, s, 20);
		//printf("%s\t", time);
		memset(s, 0, strlen(s));

		while (temp != '#' && temp != EOF && i < 19) {	//4: Trip origin
			if (temp == '\n')
				temp = fgetc(inputB);
			s[i] = temp;
			i++;
			temp = fgetc(inputB);
		}
		temp = fgetc(inputB);
		i = 0;
		strncpy(origin, s, 20);
		//printf("%s\t", origin);
		memset(s, 0, strlen(s));

		while (temp != '#' && temp != EOF && i < 19) {	//5: Trip destrination
			if (temp == '\n')
				temp = fgetc(inputB);
			s[i] = temp;
			i++;
			temp = fgetc(inputB);
		}
		temp = fgetc(inputB);
		i = 0;
		strncpy(destination, s, 20);
		//printf("%s\t", destination);
		memset(s, 0, strlen(s));

		while (temp != '#' && temp != EOF && i < 19) {	//6: Ticket price
			if (temp == '\n')
				temp = fgetc(inputB);
			s[i] = temp;
			i++;
			temp = fgetc(inputB);
		}
		temp = fgetc(inputB);
		i = 0;
		ticketprice = atoi(s);
		//printf("%d\t", ticketprice);
		memset(s, 0, strlen(s));

		while (temp != '\n' && temp != EOF && i < 19) {	//7: Max capacity
			s[i] = temp;
			i++;
			temp = fgetc(inputB);
		}
		if(temp=='\n')
			temp = fgetc(inputB);
		i = 0;
		capacity = atoi(s);
		//printf("%d\n", capacity);
		memset(s, 0, strlen(s));

		InsertBus(id, date, time, origin, destination, ticketprice, capacity, busList, FindLastB(busList)); //inserting bus node into linked list
	}
	InsertBus("No match\0\0\0\0\0\0\0\0\0\0\0", "n/a\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", "n/a\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", "n/a\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", "n/a\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 0, 0, busList, FindLastB(busList));	//inserting bus node for unmatched passengers into linked list
	fclose(inputB);	// close busses.txt
}

// Load passengers from passengers.txt into passengerList
void LoadPassengerFile(struct Passenger* passengerList) {
	//reading from passenger file
	//counting number of lines in file
	FILE* input2;
	input2=fopen("passengers.txt", "r");
	if(input2==NULL) {
		printf("passengers.txt not found!\n");
		exit(-1);
	}

	char character2;
	int lines2=0;
	const char EOL = '\n';
	while((character2 = fgetc(input2)) != EOF){
		if(character2==EOL)
			lines2+=1;
	}
	fclose(input2);//closing file to reopen it so that it resets the scanner

	FILE *inputs=fopen("passengers.txt", "r");//opening file
	if(inputs==NULL){
		printf("passengers.txt not found!\n");
		exit(-1);
	}

	char s[20];
	memset(s, 0, sizeof(s));//resetting the string
	int i=0;
	int c=0;
	char temps=fgetc(inputs);
	char id[20];
	char date[20];
	char time[20];
	char origin[20];
	char destination[20];

	//reading from file
	for (int j=0; j<lines2; j++) {
		c=0;
		while (temps != '#' && temps != EOF && i < 19) {	//1: student name
			if (temps == '\n')
				temps = fgetc(inputs);
			s[i] = temps;
			//printf("%c\t", temps);
			i++;
			temps = fgetc(inputs);
		}
		temps = fgetc(inputs);
		i = 0;
		strncpy(id, s, 20);
		//printf("%s\t", id);
		memset(s, 0, strlen(s));

		while (temps != '#' && temps != EOF && i < 19) {	//2: trip date
			if (temps == '\n')
				temps = fgetc(inputs);
			s[i] = temps;
			i++;
			temps = fgetc(inputs);
		}
		temps = fgetc(inputs);
		i = 0;
		strncpy(date, s, 20);
		memset(s, 0, strlen(s));

		while (temps != '#' && temps != EOF && i < 19) {	//3: trip time
			if (temps == '\n')
				temps = fgetc(inputs);
			s[i] = temps;
			i++;
			temps = fgetc(inputs);
		}
		temps = fgetc(inputs);
		i = 0;
		strncpy(time, s, 20);
		memset(s, 0, strlen(s));

		while (temps != '#' && temps != EOF && i < 19) {	//4: trip origin
			if (temps == '\n')
				temps = fgetc(inputs);
			s[i] = temps;
			i++;
			temps = fgetc(inputs);
		}
		temps = fgetc(inputs);
		i = 0;
		strncpy(origin, s, 20);
		memset(s, 0, strlen(s));

		do {												//5: trip destinationn
			while (temps != '#' && temps!='\n' && temps != EOF && i < 19) {
				s[i] = temps;
				i++;
				temps = fgetc(inputs);
			}
			if(temps!='\n')
				temps = fgetc(inputs);
		i = 0;
		strncpy(destination, s, 20);
		memset(s, 0, strlen(s));
		c++;
		}while(temps!='\n' && temps != EOF);

			InsertPassenger(id, date, time, origin, destination, passengerList, FindLastP(passengerList));	// Insert passenger into passengerList
			memset(s, 0, strlen(s));

	}
	fclose(inputs);		// Close passengers.txt
}

// Assign passengers in passengerList to buses in busList
void AssignPassengers(struct Bus* busList, struct Passenger* passengerList) {
	struct Passenger* currentPassenger = passengerList->next;
	struct Bus* currentBus = busList->next;
	char time[20];
	memset(time, 0, sizeof(time));
	int hour;
	int minute;
	int passengertime;
	int bustime;
	char delimitor[2] = ":";
	while (currentPassenger != NULL) {		//Iterating through passengerList
		strncpy(time, currentPassenger->time, 19);	// Extracting trip time from passenger node
		hour = atoi(strtok(time, delimitor));
		minute = atoi(strtok(NULL, delimitor));
		passengertime = minute + hour * 60;			// Converting time string to integer in minutes
		memset(time, 0, sizeof(time));
		if ((currentBus = MatchBus(currentPassenger->date, currentPassenger->origin, currentPassenger->destination, busList)) != NULL) {	// trying to find bus matching current passenger date, origin, and destrination
			strncpy(time, currentBus->time, 19);	// Extracing time from bus node
			hour = atoi(strtok(time, delimitor));
			minute = atoi(strtok(NULL, delimitor));
			bustime = minute + hour * 60;			// Converting time strong to  integer in minutes
			memset(time, 0, sizeof(time));
			if (bustime >= passengertime && bustime <= (passengertime + 60) && currentBus->capacity != 0) {		// If bus trip time is after passenger trip time by less than one hour, assigns passenger to bus
				InsertPassenger(currentPassenger->pid, currentPassenger->date, currentPassenger->time, currentPassenger->origin, currentPassenger->destination, currentBus->passengers, FindLastP(currentBus->passengers));
				currentBus->capacity--;
			}
			else {		// If no match found, add passenger to no match node
				InsertPassenger(currentPassenger->pid, currentPassenger->date, currentPassenger->time, currentPassenger->origin, currentPassenger->destination, FindLastB(busList)->passengers, FindLastP(FindLastB(busList)->passengers));
			}
		}
		else {			// If no match found, add passenger to no match node
			InsertPassenger(currentPassenger->pid, currentPassenger->date, currentPassenger->time, currentPassenger->origin, currentPassenger->destination, FindLastB(busList)->passengers, FindLastP(FindLastB(busList)->passengers));
		}
		currentPassenger = currentPassenger->next;	// iterate current passenger

	}
}
