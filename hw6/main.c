#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next_node;
};
typedef struct node node_t;

node_t* rec(node_t* head, int n) {
    if(n) {
    return rec(head->next_node, n-1);
    } else {
        return head;
    }
}

node_t* allocate_node(int data) {
    node_t* p = (node_t*)calloc(1, sizeof(node_t));
    p->data = data;
    p->next_node = NULL;
    return p;
}

void show_list(node_t* head) {
    while (head) {
        printf("[%d]->", head->data);
        head = head->next_node;
    }
    printf("null\n");
}

node_t* append_node(node_t* head, int new_data) {
    node_t* new_node = allocate_node(new_data);

    if (head) {
        node_t* p = head;
        while (p->next_node) {
            p = p->next_node;
        }
        p->next_node = new_node;
    } else {
        head = new_node;
    }
    return head;
}

void free_all_node(node_t* head) {
    node_t* p = NULL;
    while (head) {
        p = head;
        head = head->next_node;
        printf("free([%d])->", p->data);
        free(p);
    }
    printf("null\n");
}

node_t* add_node(node_t* head, int new_data) {
    node_t* p = (node_t*)calloc(1, sizeof(node_t));
    p->next_node = head;
    p->data = new_data;
    return p;
}

node_t* del_node(node_t* head, int n) {
    if(n) {
        (rec(head, n-1))->next_node = (rec(head, n))->next_node;
    } else {
        int temp = head->data;
        head->data = (head->next_node)->data;
        (head->next_node)->data = temp;
        return del_node(head, 1);
    }
}

int main() {
    node_t* head = NULL;
    head = append_node(head, 0);
    show_list(head);
    head = append_node(head, 1);
    show_list(head);
    head = add_node(head, -1);
    show_list(head);
    del_node(head, 1);
    show_list(head);
    free_all_node(head);
    return 0;
}