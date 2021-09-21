#include <iostream>
using namespace std;

int getparent(int parent[], int x) {
	if (parent[x] == x) return x;
	return getparent(parent, parent[x]);
}

void unionparent(int parent[], int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findparent(int parent[], int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);
	if (a == b) return 1;
	else return 0;
}

int main() {
	int parent[9];
	for (int i = 0; i < 9; i++) parent[i] = i;
	
	unionparent(parent, 1, 2);
	unionparent(parent, 2, 3);
	unionparent(parent, 3, 4);
	unionparent(parent, 5, 6);
	unionparent(parent, 7, 8);

	cout << "1 and 5 : " << findparent(parent, 1, 5) << "\n";
	
	unionparent(parent, 2, 5);
	cout << "1 and 5 : " << findparent(parent, 1, 5) << "\n";

	return 0;
}