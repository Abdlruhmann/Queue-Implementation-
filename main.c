#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

struct student {
    int id ;
    char name[30];
    int grade;
};
struct student fill_student() {


    struct student std1 ;
    printf("Enter id of the student: \n");
    scanf("%d", &std1.id);

    printf("Enter name of the student: \n");
    scanf("%s",std1.name);

    printf("Enter the grade of the student: \n");
    scanf("%d",&std1.grade);

    return std1;
}
void print_student(struct student std) {
    printf("Student id : %d\n", std.id);
    printf("Student name : %s\n", std.name);
    printf("Student grade : %d\n",std.grade);
}

struct student Queue [MAXSIZE];
int top;

int EnQueue(struct student std) {

    int retval=0;

    if(top < MAXSIZE) {
        Queue[top] = std;
        top++;
        retval=1;
    }
    return retval;
}

struct student DeQueue(void) {

    struct student std;
    int i;

    if(top > 0) {
        std=Queue[0];
    for(int i = 0 ; i < top; i++) {
        Queue[i]=Queue[i+1];
        top--;
        }
    }else {
        std.id=-1;
    }
    return std;
};

void print_queue(void) {
    for(int i = 0 ; i < top ; i++) {
        printf("Student ID: %d\n", Queue[i].id);
        printf("----------------------\n");
    }
}

void Menu(void) {
printf("\n------ Menu ------\n");
printf("1. EnQueue.\n");
printf("2. DeQueue.\n");
printf("3. Print\n");
printf("3. Exit.\n");
printf("----------------------\n");
}

int main () {
    int running = 1;
    int choice;

    do {

        Menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                {
                    // EnQueue
                    struct student std = fill_student();
                    int res = EnQueue(std);
                    if(res) {
                        printf("_____OUTPUT_____\n");
                        printf("Student %s Added Successfully to the queue!\n", std.name);
                        printf("________________\n");
                    }else {
                        printf("_____OUTPUT_____\n");
                        printf("Error While Adding new student!\n");
                        printf("________________\n");
                    }
                    break;
                }

            case 2:
                {
                    //DeQueue
                    struct student std ;
                    std = DeQueue();

                    if(std.id != -1) {
                        printf("_____OUTPUT_____\n");
                        printf("Student %s is Dequeued Successfully from the queue!\n", std.name);
                        printf("________________\n");
                    }else {
                        printf("_____OUTPUT_____\n");
                        printf("Error While Dequeuing!\n");
                        printf("________________\n");
                    }
                    break;
                }

            case 3: {
                    //PRINT
                    if(top==0) {
                        printf("_____OUTPUT_____\n");
                        printf("Queue Is Empty\n");
                        printf("________________\n");
                    }else {
                        printf("_____OUTPUT_____\n");
                        print_queue();
                        printf("________________\n");
                    }
                    break;
            }
            case 4 : {
                printf("Existing the program..");
                running = 0 ;
                break;
            }

            default: {
                printf("Invalid choice!");
                running=0;
            }

        }

    }while(running);

}
