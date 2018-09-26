/* problem : printf("%c",*(joe->name))*/
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
/* structures in C, cannot have functions, they can have pointers to functions*/
struct PERSON{
	char *name;
	int    age;
	int   height;
	int   weight;
	void (*print)(struct PERSON *self);
	void(*destroy)(struct PERSON *self);

};


typedef struct PERSON person;
/**
 * C programming allows passing a pointer to a function. To do so, simply declare
 * the function parameter as a pointer type.
 **/
void person_print(person* who)
{
	printf("Name: %p\n", who->name);
	printf("Age: %d\n", who->age);
	printf("Height: %d\n", who->height);
	printf("Weight: %d\n", who->weight);
}

void person_destroy(person *who)
{
	assert(who != NULL);
	free(who->name);
	//	free(who->age);
	free(who);
	}

person *person_create(char *name, int age, int height, int weight)
{
  person *who = malloc(sizeof(person));
	assert(who != NULL);
  /* who->name is the short version of (*who).name */
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight=weight;
	who->print=&person_print;
	who->destroy=&person_destroy;

	return who;
	}


int main(int argc, char *argv[])
{
	person *joe = person_create("Joe Alex", 32, 64, 140);
	printf("Accessing the information of the object directly\n");
	printf("joe->name : %p\n",*(joe->name));
	printf("joe->age : %d\n",joe->age);
	printf("joe->height : %d\n",joe->height);
	printf("joe->weight : %d\n",joe->weight);
	printf("Accessing the information of the object through method\n");
	person_print(joe);                /*calling the print function directly */

	/*Declaration is void (*print)(struct PERSON *self);. Type is void (*)(struct PERSON*). It expects a pointer to struct PERSON*/
  joe->print(joe);
	joe->destroy(joe);
  joe->print(joe);

	return 0;
}
