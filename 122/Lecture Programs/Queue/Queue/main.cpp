#include "Queue.hpp"

int main() {
	Queue q;

	q.enqueue("Print job 1");
	if (!q.is_empty()) {
		q.dequeue();
	}

	return 0;
}