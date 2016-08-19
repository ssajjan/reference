// lns.h - line number set interface

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#ifndef LNS_H_INCLUDED
#define LNS_H_INCLUDED

struct list_node {
	unsigned number;
	list_node *next;
};

class lns {
public:
	lns(unsigned n);
	void add(unsigned n);
	void put();
private:
	list_node *first, *last;
};

#endif

