
#include <malloc.h>
#include <stdio.h>
#include "LinkList.h"

//��ʼ˫������
DLinkList InitDLinkList() {
    DLinkList dLinkList;
    dLinkList = (DLinkList) malloc(sizeof(DBnode));
    dLinkList->data = 0;
    dLinkList->next = dLinkList;
    dLinkList->prior = dLinkList;
    return dLinkList;
}

//�������
DBnode *createdbnode(int data) {
    DBnode *dBnode;
    dBnode = malloc(sizeof(DBnode));
    dBnode->data = data;
    dBnode->next = dBnode;
    dBnode->prior = dBnode;
    return dBnode;
}

//��ӽ��
void AddForRearDLinkList(DLinkList dLinkList, int data) {
    DBnode *p = dLinkList;
    while (1) {
        if (p->next == dLinkList) {
            DBnode *node = createdbnode(data);

            node->next = p->next;
            node ->prior = p;
            p->next = node;
            break;
        }
        p = p->next;
    }
}
//��ȡ����
int GetLength(DLinkList dLinkList) {
    DBnode *node = dLinkList;
    int count = 0;
    while (node->next != dLinkList) {
        count++;
        node = node->next;
    }
    return count;
}

DBnode* GetNode(DLinkList dbLinkList,int i){
    DBnode *p = dbLinkList;
    int cout = 0;
    while(p->next!=dbLinkList){
        cout++;
        if(cout == i){
            return p->next;
        }
        p = p->next;
    }
    return NULL;
}

void DeleteNode(DLinkList dbLinkList,int i){
    DBnode *p = GetNode(dbLinkList,i);
    DBnode *prior = p->prior;
    DBnode *next = p->next;
    p->prior->next = p->next;
    p->next->prior =  p->prior;
    free(p);
}

void printDbLinkList(DLinkList dbLinkList) {
    DBnode *node = dbLinkList;
    do {
        node = node->next;
        printf("%d \n", node->data);
    } while (node->next != dbLinkList);
}

int main() {

    DLinkList dbLinkList = InitDLinkList();
    AddForRearDLinkList(dbLinkList, 1);
    AddForRearDLinkList(dbLinkList, 2);
 //   DeleteNode(dbLinkList,2);
    printDbLinkList(dbLinkList);

    int count = GetLength(dbLinkList);
    printf("DLinkList �����ǣ�%d \n", count);
    return 0;
}