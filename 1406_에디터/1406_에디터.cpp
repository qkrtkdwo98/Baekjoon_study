#include <iostream>
#include <string>

using namespace std;

struct node {
    char s;
    node *prev, *next;
};

node newnode[600100];
int cnt;
node* head;
node* tail;
node* point;

node* getNode(char s) {
    newnode[cnt].s = s;
    newnode[cnt].prev = nullptr;
    newnode[cnt].next = nullptr;
    return &newnode[cnt++];
}

void init() {
    head = getNode(NULL);
    tail = getNode(NULL);
    head->next = tail;
    tail->prev = head;
    point = tail;
}

void addBack(char s) {
    node* temp = getNode(s);

    point->prev->next = temp;
    temp->prev = point->prev;

    temp->next = point;
    point->prev = temp;


}

void moveLeft() {
    node* temp = point;
    if (temp->prev == head) {
        return;
    }
    point = temp->prev;
}

void moveRight() {
    node* temp = point;
    if ( temp->next == nullptr)
        return;
    point = temp->next;
}

void delLeft() {
    node* temp = point->prev;
    if (point->prev == head)
        return;

    temp->prev->next = point;
    point->prev = temp->prev;
}

void addLeft(char s) {
    node* temp = getNode(s);

    temp->prev = point->prev;
    point->prev->next = temp;

    temp->next = point;
    point->prev = temp;
}

void printNode() {
    node* temp = head->next;
    while (1) {
        cout << temp->s;
        if (temp->next == tail)
            break;
        else {
            node* temp1 = temp;
            temp = temp1->next;
        }  
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        addBack(str[i]);
    }
    int M = 0;
    cin >> M;
    for (int j = 0; j < M; j++) {
        char N = 0;
        char n = 0;
        cin >> N;
        if (N == 'L') {
            moveLeft();
        }
        else if (N == 'D') {
            moveRight();
        }
        else if (N == 'B') {
            delLeft();
        }
        else {
            cin >> n;
            addLeft(n);
        }
        
    }
    printNode();

    return 0;
}