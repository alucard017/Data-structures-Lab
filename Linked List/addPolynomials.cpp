#include <iostream>
using namespace std;

struct Node
{
    int coefficient, exponent;
    Node *next;
    Node(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

Node *addPolynomials(Node *p1, Node *p2)
{
    Node *head = new Node(0, 0);
    Node *curr = head;
    while (p1 && p2)
    {
        if (p1->exponent > p2->exponent)
        {
            curr->next = new Node(p1->coefficient, p1->exponent);
            p1 = p1->next;
        }
        else if (p1->exponent < p2->exponent)
        {
            curr->next = new Node(p2->coefficient, p2->exponent);
            p2 = p2->next;
        }
        else
        {
            int sum = p1->coefficient + p2->coefficient;
            if (sum != 0)
                curr->next = new Node(sum, p1->exponent);
            p1 = p1->next;
            p2 = p2->next;
        }
        curr = curr->next;
    }
    curr->next = p1 ? p1 : p2;
    return head->next;
}

void display(Node *poly)
{
    if (!poly)
    {
        cout << "0";
        return;
    }
    while (poly)
    {
        if (poly->coefficient != 0)
        {
            if (poly->coefficient > 0)
                cout << "+ ";
            cout << poly->coefficient;
            if (poly->exponent != 0)
                cout << "x^" << poly->exponent << " ";
        }
        poly = poly->next;
    }
}

void clear(Node *poly)
{
    while (poly)
    {
        Node *temp = poly;
        poly = poly->next;
        delete temp;
    }
}

int main()
{
    Node *poly1 = new Node(4, 3);
    poly1->next = new Node(3, 2);
    poly1->next->next = new Node(5, 1);

    Node *poly2 = new Node(3, 3);
    poly2->next = new Node(2, 2);
    poly2->next->next = new Node(1, 0);

    cout << "First polynomial: ";
    display(poly1);
    cout << endl;

    cout << "Second polynomial: ";
    display(poly2);
    cout << endl;

    Node *result = addPolynomials(poly1, poly2);

    cout << "Result of addition: ";
    display(result);
    cout << endl;

    clear(poly1);
    clear(poly2);
    clear(result);

    return 0;
}
