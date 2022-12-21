// The code below doesn't yet have bfs implemented. It simply creates two lists. Domjudge is a great versioning system. (I love wasting CPU cycles)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TODO: find a way to pass different structs into the scan_stdin function. -> Done
// TODO: Make wall && path global

struct Node {
	char data;
	int visited;
	struct Node *next;
};

struct Coordinates {
	char data;
	struct Node *next;
};

struct Queue {
	struct Node *head;
	struct Node *tail;
};

void bfs(struct Node *);

int check_around(struct Node *, struct Node *);

void print_queue(struct Queue *);

struct Queue* create_queue();

void enqueue(struct Queue*, struct Node*);

void dequeue(struct Queue*);

int scan_stdin(char, char, void *);

void push_into_list(struct Node *, char);

void print_list(struct Node *, int);

void show_runtime(clock_t);

int main() {
	clock_t begin = clock(); // better be small!!

	// LOAD THE MAZE AND PATHS

	struct Node *head = (struct Node *) malloc(sizeof(struct Node));
	struct Coordinates *coordinates_head = (struct Coordinates *) malloc(sizeof(struct Coordinates));
	int row_width = scan_stdin('#', '.', head);
	char scanNewLine;
	scanf("%c", &scanNewLine);
	int coordinates_width = scan_stdin('1', '2', coordinates_head);
	if (coordinates_width != row_width) {
		printf("Widths do not match. Returning.");
		show_runtime(begin);
		return 0;
	}
	if (head->next == NULL) {
		printf("List is empty\n");
		show_runtime(begin);
		return 0;
	}
	print_list(head->next, row_width);
	printf("\nrow width: %d\n", row_width);
	// BFS (maybe)

	bfs(head);

	show_runtime(begin);
	return 0;
}

// the parameters are: start node, end node -> TODO I am guessing that this will be the coordinates of the point I am starting in and the finish
void bfs(struct Node *list) {
	struct Queue* q = create_queue();
	list->visited = 1;
	enqueue(q, list);

	// gets to the end of the queue
	if (list->next != NULL) {
		if (list->data == '.') {
			printf("road ");
		}
		bfs(list->next);
	}

	int left = check_around(list, list);
	int right;
	if (list->next != NULL) {
		right = check_around(list, list->next->next);
	}

	printf("%d %d", left, right);

	// prints the queue from tail till head
	// print_queue(q);

	// So I will start the bfs starting at the start node

	// CYCLE until
	//	start point -> check surrounding points

	// I'll return the reconstructed path from start to finish
}

// prints the queue from head to tail
void print_queue(struct Queue *queue) {
	struct Node *current = queue->head;

	while (current != NULL) {
		printf("%c", current->data);
		current = current->next;
	}
	printf("\n");
}

struct Queue *create_queue() {
	struct Queue* q = malloc(sizeof (struct Queue));
	q->head = NULL;
	q->tail = NULL;
}

int check_around(struct Node *node, struct Node* direction) {
	struct Node *temp = node;
	while (temp != direction) {
		if (temp->next != NULL) {
			temp = temp->next;
		}
	}

	if (temp != NULL) {
		return  1;
	}
}

int list_right(struct Node *node) {
	struct Node *temp = node;
	while (temp->next != node) {
		temp = temp->next;
	}

	if (temp != NULL) {
		return  1;
	}
}
//int check_around(struct Node *node) {
//	if (node->data != '#') {
//		return 0;
//	}
//
//	struct Node *left = node;
//	while (left->next != node) {
//		left = left->next;
//	}
//
//	struct Node *right = node;
//	if (node->next->next == NULL) {
//		return "";
//	}
//	while (node->next->next != right) {
//		right = right->next;
//	}
//
//
//}

void enqueue(struct Queue *queue, struct Node *node) {
	if (queue->tail == NULL) {
		queue->tail = queue->head = node;
		return;
	}


	queue->tail->next = node;
	queue->tail = node;

	if (node->next != NULL) {
		enqueue(queue, node->next);
	}
}

void dequeue(struct Queue *queue) {
	if (queue->head == NULL) {
		return;
	}

	struct Node *temp = queue->head;

	queue->head = queue->head->next;

	if (queue->head == NULL) {
		queue->tail = NULL;
	}

	free(temp);

}

int scan_stdin(char wall, char path, void *head) {
	int rowWidth = 0;
	int iteratedOverColumn = 0;
	int count = 0;
	char tmp;
	char *format = "%c";
	while (scanf(format, &tmp) != EOF) {
		if (iteratedOverColumn == 0) {
			if (tmp == wall || tmp == path) {
				count = count + 1;
			}
			if (tmp == '\n') {
				rowWidth = count;
				iteratedOverColumn = 1;
				format = " %c";
			}
		}

		if (tmp == '-') {
			break;
		}
		if (tmp == wall || tmp == path) {
			push_into_list(head, tmp);
		}
	}
	return rowWidth;
}

//	Formát lze popsat takto: <index řádku startovnáho bodu> <index
//	sloupce startovního bodu> <index řádku koncového bodu> <index
//	sloupce koncového bodu>

void show_runtime(clock_t begin) {
	clock_t end = clock();
	double time_spent = (double) (end - begin);
	printf("\n\nruntime: %fs\n", time_spent / CLOCKS_PER_SEC);
}

void push_into_list(struct Node *node, char data) {
	while (node->next != NULL) {
		node = node->next;
	}

	node->next = (struct Node *) malloc(sizeof(struct Node));
	node->next->data = data;
	node->next->next = NULL;
}

void print_list(struct Node *node, int rowWidth) {
	int count = 1;
	while (node != NULL) {
		printf("%c", node->data);
		if (count % rowWidth == 0) {
			printf("\n");
		}
		node = node->next;
		count = count + 1;
	}
}
