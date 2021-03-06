// lns.cpp - line number set implementation

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <iomanip>
#include <iostream>

#include "lns.h"

void lns::add(unsigned n) {
	if (last->number != n) {
		last->next = new list_node;
		last = last->next;
		last->number = n;
		last->next = NULL;
	}
}

void lns::init(unsigned n) {
	first = new list_node;
	last = first;
	last->number = n;
	last->next = NULL;
}

void lns::put() {
	using namespace std;
	list_node *p;
	for (p = first; p != NULL; p = p->next) {
		cout << ' ' << setw(7) << p->number;
	}
}

