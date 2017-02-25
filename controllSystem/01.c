//
//  main.c
//  homework01
//
//  Created by panis on 2017/2/25.
//  Copyright © 2017年 panis. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stuNode{
    int sno;
    char sname[20];
    int sage;
    char sclass[20];
    struct stuNode *next;
};



int display(struct stuNode * head) {
    struct stuNode *cur;
    cur=head->next;
    
    while(cur!=NULL) {
        printf("%5d\t%20s\t%d\t%20s\n",cur->sno,cur->sname,cur->sage,cur->sclass);
        cur=cur->next;
    }
    
    return 0;
}

struct stuNode * search(struct stuNode * head,int sno) {
    struct stuNode *cur;
    cur=head->next;
    
    while(cur!=NULL&&cur->sno!=sno){
        cur=cur->next;
    }
    if (cur != NULL) {
        printf("%5d\t%20s\t%d\t%20s\n",cur->sno,cur->sname,cur->sage,cur->sclass);
    } else {
        printf("no such student\n");
    }
    return cur;
}

void delete(struct stuNode * head, int sno) {
    struct stuNode *cur,*temp;
    cur=head;
    
    if(head->sno==sno) {
        head=head->next;
    }
    else{
        while(cur->next!=NULL && cur->next->sno!=sno) {
            cur=cur->next;
        }
        if(cur->next!=NULL) {
            temp=cur->next;
            cur->next=temp->next;
            free(temp);
        }
    }
    
}

int insert(struct stuNode * head) {
    struct stuNode *cur,*temp;
    
    cur=head;
    while(cur->next!=NULL) {
        cur=cur->next;
    }
    temp=(struct stuNode *)malloc(sizeof(struct stuNode));
    if(temp!=NULL) {
        printf("input the sno:");
        scanf("%d",&temp->sno);
        
        printf("input the sname:");
        char sname[20];
        scanf("%s",sname);
        strcpy(temp->sname, sname);

        printf("input the sage:");
        scanf("%d",&temp->sage);
        
        printf("input the sclass");
        char sclass[20];
        scanf("%s",sclass);
        strcpy(temp->sclass, sclass);
        
        temp->next=NULL;
        
        cur->next=temp;
    }
    
    return 0;
}

int update(struct stuNode * head, int sno) {
    struct stuNode *cur;
    
    cur=head;

    
    while(cur!=NULL && cur->sno!=sno) {
        cur=cur->next;
    }
    if(cur!=NULL) {
        printf("input the sname of the student:");
        char sname[20];
        scanf("%s",sname);
        strcpy(cur->sname, sname);
        
        printf("input the sage of the student:");
        scanf("%d",&cur->sage);
        
        printf("input the class of the student:");
        char sclass[20];
        scanf("%s",sclass);
        strcpy(cur->sclass, sclass);
    }
    
    return 0;
}

int main()
{
    struct stuNode *head = (struct stuNode *)malloc(sizeof(struct stuNode));
    head->next = NULL;

    
    while(1) {
        printf("1.新增\n2.查询(根据学号)\n3.打印全部\n");
        int state = 0;
        scanf("%d",&state);
        switch (state) {
            case 1:
                insert(head);
                break;
            case 2:{
                int sno;
                printf("input the sno of student:");
                scanf("%d",&sno);
                if(search(head, sno) == NULL) {
                    break;
                }
                printf("选择操作:\n");
                printf("1.修改\n2.删除\n3.编辑其他学生\n");
                scanf("%d",&state);
                switch(state) {
                    case 1:
                        update(head, sno);
                        break;
                    case 2:
                        printf("确认删除？Y/n\n");
                        char temp = 'n';
                        getchar();
                        scanf("%c",&temp);
                        printf("%c",temp);
                        if (temp == 'Y') {
                            delete(head, sno);
                        }
                        break;
                    case 3:
                        break;
                }
            }
            break;

            case 3:
                display(head);
                break;
        }
        
        
    }
    return 0;
}