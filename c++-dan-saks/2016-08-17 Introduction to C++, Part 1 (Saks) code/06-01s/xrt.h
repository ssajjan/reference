// xrt.h - cross-reference table interface

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <cstddef>      // for size_t

#include "lns.h"

struct entry {
	char *word;
	lns lines;
};

std::size_t const MAX_ENTRIES = 1024;

class xrt {
public:
	void add(char *w, unsigned n);
	void init();
	void put();
private:
	void sort();
	entry *xa[MAX_ENTRIES];
	std::size_t xm;
};

