#include "Queue.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
using namespace std;
struct Queue
{
    //Front:  das vordere Element aus der Queue abzuholen
    //Rear: das letzte Element aus der Queue abzuholen
    //enQueue(value) Diese Funktion fugt ein Element in der Queue
    //deQueue() Diese Funktion loscht ein Element aus der Queue

    int rear, front;// front und rear zu initialisieren

    // zirkulares Queue
    int size;
    int* arr;

    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void enQueue(int value);
    int deQueue();
    void displayQueue();
};

// eine Funktion,um ein zirkulares Queue zu erhalten
void Queue::enQueue(int value)
{
    if ((front == 0 && rear == size - 1) ||
        (rear == (front - 1) % (size - 1)))
    {
        printf("\nQueue ist foll");
        return;
    }

    else if (front == -1) //ein erstes Element inserieren
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}
//  eine Funktion,welche Elemente des zirkulares Queue anzeigt
void Queue::displayQueue()
{
    if (front == -1)
    {
        printf("\nQueue ist leer");
        return;
    }
    printf("\nElemente im zirkulares Queue sind: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", arr[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", arr[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
}
// Function,welche Elemente aus den zirkularen Queue loscht
int Queue::deQueue()
{
    if (front == -1)
    {
        printf("\nQueue ist leer");
        return INT_MIN;
    }

    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front++;

    return data;
}


//Funtion des Programmes
int main()
{
    Queue q(5);

    // Einfugen von Elemente zirkulares Queue
    q.enQueue(4);
    q.enQueue(21);
    q.enQueue(12);
    q.enQueue(-3);

    //  Funktion,welche Elemente des zirkulares Queue anzeigt
    q.displayQueue();

    // Loschen der Elemente aus den zirkulares Queue
    printf("\nLoschung einer Variable = %d", q.deQueue());
    printf("\nLoschung einer Variable = %d", q.deQueue());

    q.displayQueue();

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(4);

    q.displayQueue();

    q.enQueue(10);
    return 0;
}
// Was habe Ich gemacht:
    //Uberprufung, ob der Queue voll ist - Uberprufung  (hinten == grosse-1 && vorne == 0) || (hinten == vorne-1).

    //Wenn es voll ist, ist der Queue voll. Wenn der Queue nicht voll ist, prufen wir,
    // ob (hinten == grosse - 1 && vorne! = 0), ob dies zutrifft, setzen  hinten = 0 und fugen  das Element ein.

    //Prufen, ob der Queue leer ist, bedeutet prufen (front == - 1).

    //Wenn es leer ist, ist der Queue leer. Wenn der Queue nicht leer ist,dann:
            //Uberprufung, ob vorne == hinten, wenn es wahr ist, dann setzen  vorne = hinten = -1,
            //sonst prufen, ob vorne == grosse-1, wenn es wahr ist, setzen  vorne = 0 und geben  das Element zuruck.

// Zeitliche Komplexitat:es gibt kein loop in der Operationen.
