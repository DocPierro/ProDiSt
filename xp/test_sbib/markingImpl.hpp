#ifndef _MarkingImpl_HPP
#define    _MarkingImpl_HPP
using namespace std;
#include <string.h>
#include "marking.hpp"
#include "markingTemplate.hpp"
#ifndef ABSTRACT_BINDING_h
#define ABSTRACT_BINDING_h
class abstractBindingImpl {
public:
};
#endif
class abstractMarkingImpl {
public:
	int _PL_p0;
	int _PL_p1;
	int _PL_p2;
	int _PL_p3;
	int _PL_end;
	int _PL_p5;
	int _PL_start;
	int _PL_p7;
	int _PL_p8;
	int _PL_p9;
	int _PL_p10;
	int _PL_p11;
	int _PL_p12;
	int _PL_p13;
	int _PL_p14;
	int _PL_p15;
};

class abstractBindingIteratorImpl {
public:
	const static bool isValid =false;
	void reset(size_t,const abstractMarkingImpl& m){};
	void next(size_t& t,const abstractMarkingImpl& m){};
	size_t getIndex(){return 0;};
	abstractBinding getBinding(){return abstractBinding();};
};
#endif
