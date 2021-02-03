#include <stdio.h>
#include <stdlib.h>

typedef struct value {
	int v;
	struct value *next;
} LinkList;

LinkList *create(int n) {
	LinkList *head, *node, *end;
	head = (LinkList*)malloc(sizeof(LinkList));
	end = head;
	for (int i = 0; i < n; i++) {
		node = (LinkList*)malloc(sizeof(LinkList));
		scanf("%d", &node->v);
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}

void change(LinkList *list, int n) {
	LinkList *t = list;
	int i = 0;
	while(i < n && t != NULL) {
		t = t->next;
		i++;
	}
	if (t != NULL) {
		puts("输入要修改的值");
		scanf("%d", &t->v);
	} else {
		puts("结点不存在");
	}
}

void delete(LinkList *list, int n) {
	LinkList *t = list, *in;
	int i = 0;
	while(i < n && t != NULL) {
		in = t;
		t = t->next;
		i++;
	}
	if (t != NULL) {
		in->next = t ->next;
		free(t);
	} else {
		puts("结点不存在");
	}
}

void insert(LinkList *list, int n, int value) {
	LinkList *t = list, *in;
	int i = 0;
	while (i < n && t != NULL) {
		t = t->next;
		i++;
	} if (t != NULL) {
		in = (LinkList*)malloc(sizeof(LinkList));
		in->v = value;
		in->next = t->next;
		t->next = in;
	} else {
		puts("结点不存在");
	}
}

void show(LinkList *h) {
	while(h->next != NULL) {
		h = h->next;
		printf("%d\n", h->v);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	LinkList *h = create(n);
	show(h);
	insert(h, 3, 9);
	show(h);
	return 0;
}
