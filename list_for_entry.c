#include <stdio.h>
#include "list.h"


typedef struct usrList
{ 
    int index;
    int data; 
    struct list_head list; 
}USR_LIST_TYPE; 

int main(int argc, char *argv[]) 
{ 
    USR_LIST_TYPE msg, *pmsg; 
    LIST_HEAD(msg_head);
    int *ptr = &msg.data;
    int i; /* insert the 10 msgs */ 
    for(i = 0; i < 10; i++)
    { 
        pmsg = (USR_LIST_TYPE *)malloc(sizeof(USR_LIST_TYPE)); 
        pmsg->index = i + 1; 
        pmsg->data = (i + 1)*10; 
        list_add_tail(&pmsg->list, &msg_head); 
    } 

    /* 根据list 遍历 整个链表，并打印信息 */ 
    list_for_each_entry(pmsg, &msg_head, list)
    { 
        printf("msg index:%d data:%d\n", pmsg->index, pmsg->data); 
    } 
    
    return 0;
}

