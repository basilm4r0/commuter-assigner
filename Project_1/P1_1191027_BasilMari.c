#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h>
#pragma clang diagnostic ignored "-Wformat-security"

//define passenger linked list node data structure
struct Passenger {
	char pid[20];
	char date[20];
	char time[20];
	char origin[20];
	char destination[20];
	struct Passenger* next;
};

void DeleteListP(struct Passenger* L){
	struct Passenger* P;
	struct Passenger* temp;
	P = L->next;
	L->next = NULL;
	while(P != NULL){
		temp = P->next;
		free(P);
		P = temp;
	}
}

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

int IsEmptyP(struct Passenger* L) {
	return L->next == NULL;
}

int IsLastP(struct Passenger* L, struct Passenger* P) {
	return P->next == NULL;
}

void InsertPassenger(char pid[20], char date[20], char time[20], char origin[20], char destination[20], struct Passenger* L, struct Passenger* P) {

	struct Passenger* temp;
	temp = (struct Passenger*) malloc(sizeof(struct Passenger));

	if (temp == NULL) {
		printf("Not enough memory!\n");
		return;
	}

	strlcpy(temp->pid, pid, 20);
	strlcpy(temp->date, date, 20);
	strlcpy(temp->time, time, 20);
	strlcpy(temp->origin, origin, 20);
	strlcpy(temp->destination, destination, 20);
	temp->next = P->next;
	P->next = temp;
}

void PrintPassengers(struct Passenger* L) {
	struct Passenger* P = L;
	if (IsEmptyP(L))
		printf("List is empty!");
	else
		do{
			P=P->next;
			printf("Passenger ID: %s, Trip Date: %s, Trip Time: %s, Origin: %s, Destination: %s\n", P->pid, P->date, P->time, P->origin, P->destination);
		} while (!IsLastP(L, P));
}

struct Passenger* FindLastP(struct Passenger* L) {
	struct Passenger* P;
	P = L;
	while (!IsLastP(L,P)) {
		P = P->next;
	}
	return P;
}

void SwapPassengers(struct Passenger* L, struct Passenger* P) {
	struct Passenger* T = MakeEmptyP(NULL);
	if (T == NULL)
		return;
	strlcpy(T->pid, L->pid, 20);
	strlcpy(T->date, L->date, 20);
	strlcpy(T->time, L->time, 20);
	strlcpy(T->origin, L->origin, 20);
	strlcpy(T->destination, L->destination, 20);

	strlcpy(L->pid, P->pid, 20);
	strlcpy(L->date, P->date, 20);
	strlcpy(L->time, P->time, 20);
	strlcpy(L->origin, P->origin, 20);
	strlcpy(L->destination, P->destination, 20);

	strlcpy(P->pid, T->pid, 20);
	strlcpy(P->date, T->date, 20);
	strlcpy(P->time, T->time, 20);
	strlcpy(P->origin, T->origin, 20);
	strlcpy(P->destination, T->destination, 20);

	free(T);
}

struct Passenger* FindPassenger(char pid[20], struct Passenger* L) {
	struct Passenger* P;
	P = L->next;
	while (P != NULL && strcmp(pid, P->pid) != 0)
		P=P->next;
	return P;
}

struct Bus {
	char bid[20];
	char date[20];
	char time[20];
	char origin[20];
	char destination[20];
	int ticketprice;
	int capacity;
	struct Passenger* Passengers;
	struct Bus* next;
};

void DeleteListB(struct Bus* L){
	struct Bus* P;
	struct Bus* temp;
	P = L->next;
	L->next = NULL;
	while(P != NULL){
		temp = P->next;
		free(P);
		P = temp;
	}
}

struct Bus* MakeEmptyB(struct Bus* L) {

	if (L != NULL)
		MakeEmptyB(L);

	L = (struct Bus*) malloc(sizeof(struct Bus));

	if (L == NULL) {
		printf("Not enough memory!\n");
		return NULL;
	}

	L->next = NULL;
	return L;

}

int IsEmptyB(struct Bus* L) {
	return L->next == NULL;
}

int IsLastB(struct Bus* H, struct Bus* P) {
	return P->next == NULL;
}

void InsertBus(char bid[20], char date[20], char time[20], char origin[20], char destination[20], int ticketprice, int capacity, struct Bus* L, struct Bus* P) {

	struct Bus* temp;
	temp = (struct Bus*) malloc(sizeof(struct Bus));

	if (temp == NULL) {
		printf("Not enough memory!\n");
		return;
	}

	strlcpy(temp->bid, bid, 20);
	strlcpy(temp->date, date, 20);
	strlcpy(temp->time, time, 20);
	strlcpy(temp->origin, origin, 20);
	strlcpy(temp->destination, destination, 20);
	temp->ticketprice = ticketprice;
	temp->capacity = capacity;
	temp->next = P->next;
	P->next = temp;

}

void PrintBusses(struct Bus* L) {
	struct Bus* P;
	P = L;
	if (IsEmptyB(L))
		printf("List is empty!\n");
	else
		do{
			P=P->next;
			printf("Bus ID: %s, Trip Date: %s, Trip Time: %s, Origin: %s, Destination: %s\n, Ticket Price: %d, Capacity: %d\n", P->bid, P->date, P->time, P->origin, P->destination, P->ticketprice, P->capacity);
		} while (!IsLastB(L, P));
}

struct Bus* FindLastB(struct Bus* L) {
	struct Bus* P;
	P = L;
	while (!IsLastB(L,P)) {
		P = P->next;
	}
	return P;
}

struct Bus* FindBus(char bid[20], struct Bus* L) {
	struct Bus* P;
	P = L->next;
	while (P != NULL && strcmp(bid, P->bid) != 0)
		P=P->next;
	return P;

}

void SwapBuses(struct Bus* L, struct Bus* P) {
	struct Bus* T = MakeEmptyB(NULL);
	if (T == NULL)
		return;
	strlcpy(T->bid, L->bid, 20);
	strlcpy(T->date, L->date, 20);
	strlcpy(T->time, L->time, 20);
	strlcpy(T->origin, L->origin, 20);
	strlcpy(T->destination, L->destination, 20);
	T->ticketprice = L->ticketprice;
	T->capacity = L->capacity;

	strlcpy(L->bid, P->bid, 20);
	strlcpy(L->date, P->date, 20);
	strlcpy(L->time, P->time, 20);
	strlcpy(L->origin, P->origin, 20);
	strlcpy(L->destination, P->destination, 20);
	L->ticketprice = P->ticketprice;
	L->capacity = P->capacity;


	strlcpy(P->bid, T->bid, 20);
	strlcpy(P->date, T->date, 20);
	strlcpy(P->time, T->time, 20);
	strlcpy(P->origin, T->origin, 20);
	strlcpy(P->destination, T->destination, 20);
	P->ticketprice = T->ticketprice;
	P->capacity = T->capacity;

	free(T);
}

int main() {
	FILE* input;
	input=fopen("Buses.txt", "r");
	if(input==NULL) {
		printf("Buses.txt not found!\n");
		exit(-1);
	}

	const char EOL = '\n';//end of line reading
	char character;
	int lines = 1;
	while((character = fgetc(input)) !=EOF){
		if(character==EOL)
			lines+=1;
	}
	fclose(input);//closing file to reopen it so that it resets the scanner

	FILE *inputB=fopen("Buses.txt", "r");//opening file
	if(inputB==NULL){
		printf("Busses.txt not found!\n");
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
	memset(s, 0, strlen(s));//resetting the string: solved the problem of printing strange symbols after reading
	int i=0;
	char temp=fgetc(inputB);

	struct Bus* busList;
	busList = MakeEmptyB(NULL);//creating head of the buses linked list

	//reading from file
	for (int j = 0; j < lines; j++) {
		while (temp != '#') {		//1: Bus ID
			if (temp == '\n')
				temp = fgetc(inputB);
			s[i] = temp;
			i++;
			temp = fgetc(inputB);
		}
		temp = fgetc(inputB);
		i = 0;
		strlcpy(id, s, 20);
		memset(s, 0, strlen(s));

		while (temp != '#') {		//2: Trip date
			if (temp == '\n')
				temp = fgetc(inputB);
			s[i] = temp;
			i++;
			temp = fgetc(inputB);
		}
		temp = fgetc(inputB);
		i = 0;
		strlcpy(date, s, 20);
		memset(s, 0, strlen(s));

		while (temp != '#') {		//3: Trip time
			if (temp == '\n')
				temp = fgetc(inputB);
			s[i] = temp;
			i++;
			temp = fgetc(inputB);
		}
		temp = fgetc(inputB);
		i = 0;
		strlcpy(time, s, 20);
		memset(s, 0, strlen(s));

		while (temp != '#') {	//4: Trip origin
			if (temp == '\n')
				temp = fgetc(inputB);
			s[i] = temp;
			i++;
			temp = fgetc(inputB);
		}
		temp = fgetc(inputB);
		i = 0;
		strlcpy(origin, s, 20);
		memset(s, 0, strlen(s));

		while (temp != '#') {	//5: Trip destrination
			if (temp == '\n')
				temp = fgetc(inputB);
			s[i] = temp;
			i++;
			temp = fgetc(inputB);
		}
		temp = fgetc(inputB);
		i = 0;
		strlcpy(destination, s, 20);
		memset(s, 0, strlen(s));

		while (temp != '#') {	//5: Trip destrination
			if (temp == '\n')
				temp = fgetc(inputB);
			s[i] = temp;
			i++;
			temp = fgetc(inputB);
		}
		temp = fgetc(inputB);
		i = 0;
		ticketprice = atoi(s);
		memset(s, 0, strlen(s));

		while (temp != '\n' && temp != -1) {//4: max students
			s[i] = temp;
			i++;
			temp = fgetc(inputB);
		}
		if(temp=='\n')
			temp = fgetc(inputB);
		i = 0;
		capacity = atoi(s);
		memset(s, 0, strlen(s));

		InsertBus(id, date, time, origin, destination, ticketprice, capacity, FindLastB(busList), busList);//inserting bus node into linked list
	}

	fclose(inputB);

	//reading from passenger file
	//counting number of lines in file
	FILE* input2;
	input2=fopen("Passengers.txt", "r");
	if(input2==NULL) {
		printf("Passengers.txt not found!\n");
		exit(-1);
	}

	char character2;
	int lines2=1;
	while((character2 = fgetc(input)) != EOF){
		if(character2==EOL)
			lines2+=1;
	}
	fclose(input2);//closing file to reopen it so that it resets the scanner

	FILE *inputs=fopen("Students.txt", "r");//opening file
	if(inputs==NULL){
		printf("Passengers.txt not found!\n");
		exit(-1);
	}


	memset(s, 0, strlen(s));//resetting the string array because random symbols are printed otherwise

	memset(s, 0, strlen(s));//resetting the string: solved the problem of printing strange symbols after reading
	i=0;
	int c=0;
	char temps=fgetc(inputs);

	struct Passenger* passengerList;
	passengerList = MakeEmptyP(NULL);//creating head of the students linked list

	//reading from file
	for (int j=0; j<lines2; j++) {
		c=0;
		while (temps != '#') {//1: student name
			if (temps == '\n')
				temps = fgetc(inputs);
			s[i] = temps;
			i++;
			temps = fgetc(inputs);
		}
		temps = fgetc(inputs);
		i = 0;
		strlcpy(id, s, 20);
		memset(s, 0, strlen(s));

		while (temps != '#') {//2: trip date
			if (temps == '\n')
				temps = fgetc(inputs);
			s[i] = temps;
			i++;
			temps = fgetc(inputs);
		}
		temps = fgetc(inputs);
		i = 0;
		strlcpy(date, s, 20);
		memset(s, 0, strlen(s));

		while (temps != '#') {//3: trip time
			if (temps == '\n')
				temps = fgetc(inputs);
			s[i] = temps;
			i++;
			temps = fgetc(inputs);
		}
		temps = fgetc(inputs);
		i = 0;
		strlcpy(time, s, 20);
		memset(s, 0, strlen(s));

		while (temps != '#') {//4: trip origin
			if (temps == '\n')
				temps = fgetc(inputs);
			s[i] = temps;
			i++;
			temps = fgetc(inputs);
		}
		temps = fgetc(inputs);
		i = 0;
		strlcpy(origin, s, 20);
		memset(s, 0, strlen(s));

		do {//5: trip destinationn
			while (temps != '#' && temps!='\n' && temps!=-1) {
				s[i] = temps;
				i++;
				temps = fgetc(inputs);
			}
			if(temps!='\n')
				temps = fgetc(inputs);
		i = 0;
		strlcpy(destination, s, 20);
		memset(s, 0, strlen(s));
		c++;
		}while(temps!=-1 && temps!='\n');

			InsertPassenger(id, date, time, origin, destination, FindLastP(passengerList), passengerList);
			memset(s, 0, strlen(s));

	}
	fclose(inputs);


}
