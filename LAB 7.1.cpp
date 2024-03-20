#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

class LinkedList {
    // properties
protected:
    struct studentNode *start, **now;

    // methods
public:
    LinkedList();
    ~LinkedList();
    void InsNode(char n[], int a, char s, float g);
    void DelNode();
    void GoNext();
    virtual void ShowNode();
}; // end class

LinkedList::LinkedList() {
    this->start = NULL;
    this->now = &start;
   
}

LinkedList::~LinkedList() {
    struct studentNode *current = start;
    struct studentNode *next;

    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }

}

void LinkedList::InsNode(char n[], int a, char s, float g) {
    if (start == NULL) {
        start = new struct studentNode;
        strcpy(start->name, n);
        start->age = a;
        start->sex = s;
        start->gpa = g;
        start->next = NULL;
        start->back = NULL;
        *now = start;
    } else {
        (*now)->next = new struct studentNode;
        (*now)->next->back = *now;
        *now = (*now)->next;
        strcpy((*now)->name, n);
        (*now)->age = a;
        (*now)->sex = s;
        (*now)->gpa = g;
        (*now)->next = NULL;
    }

   
}

void LinkedList::DelNode() {
    struct studentNode *temp = NULL;

    if ((*now)->next != NULL) {
        (*now)->next->back = (*now)->back;
        temp = (*now)->next;
    } else {
        temp = (*now)->back;
    }

    delete *now;
    *now = temp;
    if (*now != NULL) {
        (*now)->next = NULL;
    }

    //printf("Delete Complete\n");
}

void LinkedList::GoNext() {
    if ((*now)->next != NULL) {
        *now = (*now)->next;
    }

  
}

void LinkedList::ShowNode() {
    printf("%s ", (*now)->name);
    printf("%d ", (*now)->age);
    printf("%c ", (*now)->sex);
    printf("%f ", (*now)->gpa);
    printf("\n");
 
}

class NewList : public LinkedList {
    // methods
public:
    void GoFirst();
    virtual void ShowNode();
}; // end class

void NewList::ShowNode() {
    printf("%s ", (*now)->name);
    printf("%d ", (*now)->age);
    printf("%c ", (*now)->sex);
    printf("%f ", (*now)->gpa);
    printf("\n");
    
}

void NewList::GoFirst() {
    *now = start;
    
}

int main() {
    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);
    listA.GoNext();
    listA.ShowNode();

    listB.InsNode("four", 4, 'D', 4.4);
    listB.InsNode("five", 5, 'E', 5.5);
    listB.InsNode("six", 6, 'F', 6.6);
    listB.GoNext();
    listB.DelNode();
    listB.ShowNode();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    NewList *newListC = &listB;
    newListC->GoFirst(); 
    newListC->ShowNode();

    return 0;
} // end function
