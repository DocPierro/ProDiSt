#include "spn.hpp"
#include <iomanip>
using namespace std;
#define PL_p0_LP 0
#define PL_p1_LP 1
#define PL_p2_LP 2
#define PL_p3_LP 3
#define PL_end_LP 4
#define PL_p5_LP 5
#define PL_start_LP 6
#define PL_p7_LP 7
#define PL_p8_LP 8
#define PL_p9_LP 9
#define PL_p10_LP 10
#define PL_p11_LP 11
#define PL_p12_LP 12
#define PL_p13_LP 13
#define PL_p14_LP 14
#define PL_p15_LP 15
#define TR_t0_RT 0
#define TR_t1_RT 1
#define TR_t2_RT 2
#define TR_t3_RT 3
#define TR_t4_RT 4
#define TR_t5_RT 5
#define TR_t6_RT 6
#define TR_t7_RT 7
#define TR_t8_RT 8
#define TR_t9_RT 9
#define TR_t10_RT 10
#define TR_t11_RT 11
#define TR_t12_RT 12
#define TR_t13_RT 13
#define TR_t14_RT 14
#define TR_t15_RT 15
#define TR_t16_RT 16
#define TR_t17_RT 17
#define TR_t18_RT 18
#define TR_t19_RT 19

double w_t0=1;
double w_t1=1;
double w_t10=1;
double w_t11=1;
double w_t12=1;
double w_t13=1;
double w_t14=1;
double w_t15=1;
double w_t16=1;
double w_t17=1;
double w_t18=1;
double w_t19=1;
double w_t2=1;
double w_t3=1;
double w_t4=1;
double w_t5=1;
double w_t6=1;
double w_t7=1;
double w_t8=1;
double w_t9=1;
const int _nb_Place_p0=0;
const int _nb_Place_p1=1;
const int _nb_Place_p2=2;
const int _nb_Place_p3=3;
const int _nb_Place_end=4;
const int _nb_Place_p5=5;
const int _nb_Place_start=6;
const int _nb_Place_p7=7;
const int _nb_Place_p8=8;
const int _nb_Place_p9=9;
const int _nb_Place_p10=10;
const int _nb_Place_p11=11;
const int _nb_Place_p12=12;
const int _nb_Place_p13=13;
const int _nb_Place_p14=14;
const int _nb_Place_p15=15;
namespace hybridVar {
}
void REHandling::print_state(const vector<int> &vect){}
void REHandling::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool REHandling::precondition(const abstractMarking &M){return true;}
double REHandling::direct_computation(abstractMarking const&){return -1.0;}
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_p0 = 0;
	P->_PL_p0 +=0 ;
	P->_PL_p1 = 0;
	P->_PL_p1 +=0 ;
	P->_PL_p2 = 0;
	P->_PL_p2 +=0 ;
	P->_PL_p3 = 0;
	P->_PL_p3 +=0 ;
	P->_PL_end = 0;
	P->_PL_end +=0 ;
	P->_PL_p5 = 0;
	P->_PL_p5 +=0 ;
	P->_PL_start = 0;
	P->_PL_start +=1 ;
	P->_PL_p7 = 0;
	P->_PL_p7 +=0 ;
	P->_PL_p8 = 0;
	P->_PL_p8 +=0 ;
	P->_PL_p9 = 0;
	P->_PL_p9 +=0 ;
	P->_PL_p10 = 0;
	P->_PL_p10 +=0 ;
	P->_PL_p11 = 0;
	P->_PL_p11 +=0 ;
	P->_PL_p12 = 0;
	P->_PL_p12 +=0 ;
	P->_PL_p13 = 0;
	P->_PL_p13 +=0 ;
	P->_PL_p14 = 0;
	P->_PL_p14 +=0 ;
	P->_PL_p15 = 0;
	P->_PL_p15 +=0 ;
}


abstractMarking::abstractMarking() {
	P= new abstractMarkingImpl;
	resetToInitMarking();
}

abstractMarking::abstractMarking(const std::vector<int>& m) {
	P = new abstractMarkingImpl;
	setVector(m);
}
abstractMarking::abstractMarking(const abstractMarking& m) {
	P= new abstractMarkingImpl;
	*this = m;
};

abstractMarking& abstractMarking::operator = (const abstractMarking& m) {
	*P = *(m.P);
	return *this;
}

abstractMarking::~abstractMarking() {
	delete(P);
}


void abstractMarking::swap(abstractMarking& m) {
	abstractMarkingImpl* tmp = m.P;
	m.P = P;
	P = tmp;
}
void abstractMarking::printHeader(ostream &s)const{
}

void abstractMarking::print(ostream &s,double eTime)const{
}
void abstractMarking::printSedCmd(ostream &s)const{
}

int abstractMarking::getNbOfTokens(int p)const {
	switch (p) {
		case 0: return P->_PL_p0;
		case 1: return P->_PL_p1;
		case 2: return P->_PL_p2;
		case 3: return P->_PL_p3;
		case 4: return P->_PL_end;
		case 5: return P->_PL_p5;
		case 6: return P->_PL_start;
		case 7: return P->_PL_p7;
		case 8: return P->_PL_p8;
		case 9: return P->_PL_p9;
		case 10: return P->_PL_p10;
		case 11: return P->_PL_p11;
		case 12: return P->_PL_p12;
		case 13: return P->_PL_p13;
		case 14: return P->_PL_p14;
		case 15: return P->_PL_p15;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(16);
	v.reserve(17);
	size_t i = 0;
	v[i++]= P->_PL_p0;
	v[i++]= P->_PL_p1;
	v[i++]= P->_PL_p2;
	v[i++]= P->_PL_p3;
	v[i++]= P->_PL_end;
	v[i++]= P->_PL_p5;
	v[i++]= P->_PL_start;
	v[i++]= P->_PL_p7;
	v[i++]= P->_PL_p8;
	v[i++]= P->_PL_p9;
	v[i++]= P->_PL_p10;
	v[i++]= P->_PL_p11;
	v[i++]= P->_PL_p12;
	v[i++]= P->_PL_p13;
	v[i++]= P->_PL_p14;
	v[i++]= P->_PL_p15;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	size_t i = 0;
	P->_PL_p0 = v[i++];
	P->_PL_p1 = v[i++];
	P->_PL_p2 = v[i++];
	P->_PL_p3 = v[i++];
	P->_PL_end = v[i++];
	P->_PL_p5 = v[i++];
	P->_PL_start = v[i++];
	P->_PL_p7 = v[i++];
	P->_PL_p8 = v[i++];
	P->_PL_p9 = v[i++];
	P->_PL_p10 = v[i++];
	P->_PL_p11 = v[i++];
	P->_PL_p12 = v[i++];
	P->_PL_p13 = v[i++];
	P->_PL_p14 = v[i++];
	P->_PL_p15 = v[i++];
};

void abstractMarking::Symmetrize(){
}bool abstractBinding::next() {
	idcount++;
	return false;
};
abstractBinding::abstractBinding() {
       idcount=0;
}
abstractBinding::abstractBinding(const abstractBinding& m) {
	idcount = m.idcount;
}
abstractBinding::~abstractBinding() {
}
abstractBinding& abstractBinding::operator = (const abstractBinding& m) {
	idcount = m.idcount;
       return *this;
}
void abstractBinding::print()const{
}
size_t abstractBinding::id()const{
	return idcount;
}
size_t abstractBinding::idTotal()const{
	 return 0;
}

void abstractBindingIterator::reset(size_t t,const abstractMarking& m) {
	P->reset(t,*(m.P));
};
bool abstractBindingIterator::isValid()const {
	return P->isValid;
};
abstractBindingIterator::abstractBindingIterator(const abstractMarking& m) {
	P = new abstractBindingIteratorImpl;
	//reset(m);
};
void abstractBindingIterator::next(size_t& t,const abstractMarking& m) {
	P->next(t,*(m.P));
};
abstractBindingIterator::~abstractBindingIterator() {
	delete(P);
};
size_t abstractBindingIterator::getIndex() {
	return P->getIndex();
};
abstractBinding abstractBindingIterator::getBinding() {
	return P->getBinding();
};
static const int EMPTY_array[1]={-1};
static const int PE_PossiblyEnabled_0[5]= {TR_t1_RT, TR_t10_RT, TR_t15_RT, TR_t16_RT, -1 }; /* t0*/
static const int PE_PossiblyEnabled_1[2]= {TR_t11_RT, -1 }; /* t1*/
static const int PE_PossiblyEnabled_2[2]= {TR_t11_RT, -1 }; /* t2*/
static const int PE_PossiblyEnabled_4[2]= {TR_t3_RT, -1 }; /* t4*/
static const int PE_PossiblyEnabled_5[2]= {TR_t3_RT, -1 }; /* t5*/
static const int PE_PossiblyEnabled_6[3]= {TR_t9_RT, TR_t19_RT, -1 }; /* t6*/
static const int PE_PossiblyEnabled_7[5]= {TR_t0_RT, TR_t4_RT, TR_t13_RT, TR_t14_RT, -1 }; /* t7*/
static const int PE_PossiblyEnabled_8[2]= {TR_t3_RT, -1 }; /* t8*/
static const int PE_PossiblyEnabled_9[2]= {TR_t8_RT, -1 }; /* t9*/
static const int PE_PossiblyEnabled_10[2]= {TR_t8_RT, -1 }; /* t10*/
static const int PE_PossiblyEnabled_11[3]= {TR_t2_RT, TR_t17_RT, -1 }; /* t11*/
static const int PE_PossiblyEnabled_12[2]= {TR_t18_RT, -1 }; /* t12*/
static const int PE_PossiblyEnabled_13[2]= {TR_t18_RT, -1 }; /* t13*/
static const int PE_PossiblyEnabled_14[2]= {TR_t3_RT, -1 }; /* t14*/
static const int PE_PossiblyEnabled_15[2]= {TR_t8_RT, -1 }; /* t15*/
static const int PE_PossiblyEnabled_16[2]= {TR_t6_RT, -1 }; /* t16*/
static const int PE_PossiblyEnabled_17[2]= {TR_t8_RT, -1 }; /* t17*/
static const int PE_PossiblyEnabled_18[3]= {TR_t5_RT, TR_t12_RT, -1 }; /* t18*/
static const int PE_PossiblyEnabled_19[2]= {TR_t6_RT, -1 }; /* t19*/
const int* SPN::PossiblyEnabled[] = {PE_PossiblyEnabled_0, PE_PossiblyEnabled_1, PE_PossiblyEnabled_2, EMPTY_array, PE_PossiblyEnabled_4, PE_PossiblyEnabled_5, PE_PossiblyEnabled_6, PE_PossiblyEnabled_7, PE_PossiblyEnabled_8, PE_PossiblyEnabled_9, PE_PossiblyEnabled_10, PE_PossiblyEnabled_11, PE_PossiblyEnabled_12, PE_PossiblyEnabled_13, PE_PossiblyEnabled_14, PE_PossiblyEnabled_15, PE_PossiblyEnabled_16, PE_PossiblyEnabled_17, PE_PossiblyEnabled_18, PE_PossiblyEnabled_19};

static const int PE_PossiblyDisabled_0[2]= {TR_t14_RT, -1 }; /* t0*/
static const int PE_PossiblyDisabled_1[2]= {TR_t10_RT, -1 }; /* t1*/
static const int PE_PossiblyDisabled_2[2]= {TR_t17_RT, -1 }; /* t2*/
static const int PE_PossiblyDisabled_4[2]= {TR_t13_RT, -1 }; /* t4*/
static const int PE_PossiblyDisabled_5[2]= {TR_t12_RT, -1 }; /* t5*/
static const int PE_PossiblyDisabled_9[2]= {TR_t19_RT, -1 }; /* t9*/
static const int PE_PossiblyDisabled_10[2]= {TR_t1_RT, -1 }; /* t10*/
static const int PE_PossiblyDisabled_12[2]= {TR_t5_RT, -1 }; /* t12*/
static const int PE_PossiblyDisabled_13[2]= {TR_t4_RT, -1 }; /* t13*/
static const int PE_PossiblyDisabled_14[2]= {TR_t0_RT, -1 }; /* t14*/
static const int PE_PossiblyDisabled_15[2]= {TR_t16_RT, -1 }; /* t15*/
static const int PE_PossiblyDisabled_16[2]= {TR_t15_RT, -1 }; /* t16*/
static const int PE_PossiblyDisabled_17[2]= {TR_t2_RT, -1 }; /* t17*/
static const int PE_PossiblyDisabled_19[2]= {TR_t9_RT, -1 }; /* t19*/
const int* SPN::PossiblyDisabled[] = {PE_PossiblyDisabled_0, PE_PossiblyDisabled_1, PE_PossiblyDisabled_2, EMPTY_array, PE_PossiblyDisabled_4, PE_PossiblyDisabled_5, EMPTY_array, EMPTY_array, EMPTY_array, PE_PossiblyDisabled_9, PE_PossiblyDisabled_10, EMPTY_array, PE_PossiblyDisabled_12, PE_PossiblyDisabled_13, PE_PossiblyDisabled_14, PE_PossiblyDisabled_15, PE_PossiblyDisabled_16, PE_PossiblyDisabled_17, EMPTY_array, PE_PossiblyDisabled_19};

const int* SPN::FreeMarkDepT[] = {EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array};

static spn_trans TransArray[20] = { _trans(0,EXPONENTIAL,0,1, 0), _trans(1,EXPONENTIAL,0,1, 0), _trans(2,EXPONENTIAL,0,1, 0), _trans(3,EXPONENTIAL,0,1, 0), _trans(4,EXPONENTIAL,0,1, 0), _trans(5,EXPONENTIAL,0,1, 0), _trans(6,EXPONENTIAL,0,1, 0), _trans(7,EXPONENTIAL,0,1, 0), _trans(8,EXPONENTIAL,0,1, 0), _trans(9,EXPONENTIAL,0,1, 0), _trans(10,EXPONENTIAL,0,1, 0), _trans(11,EXPONENTIAL,0,1, 0), _trans(12,EXPONENTIAL,0,1, 0), _trans(13,EXPONENTIAL,0,1, 0), _trans(14,EXPONENTIAL,0,1, 0), _trans(15,EXPONENTIAL,0,1, 0), _trans(16,EXPONENTIAL,0,1, 0), _trans(17,EXPONENTIAL,0,1, 0), _trans(18,EXPONENTIAL,0,1, 0), _trans(19,EXPONENTIAL,0,1, 0),  }; 
SPN::SPN():
customDistr(*(new CustomDistr())),pl(16), tr(20) ,Transition(TransArray,TransArray +20),Place(16),ParamDistr(),TransitionConditions(20,0){
    Path ="xp/test_sbib/gspn1.gspn";
	{ //t0
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[0].bindingList.size());
	Transition[0].bindingList.push_back( bl );
	}
	{ //t1
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[1].bindingList.size());
	Transition[1].bindingList.push_back( bl );
	}
	{ //t2
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[2].bindingList.size());
	Transition[2].bindingList.push_back( bl );
	}
	{ //t3
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[3].bindingList.size());
	Transition[3].bindingList.push_back( bl );
	}
	{ //t4
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[4].bindingList.size());
	Transition[4].bindingList.push_back( bl );
	}
	{ //t5
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[5].bindingList.size());
	Transition[5].bindingList.push_back( bl );
	}
	{ //t6
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[6].bindingList.size());
	Transition[6].bindingList.push_back( bl );
	}
	{ //t7
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[7].bindingList.size());
	Transition[7].bindingList.push_back( bl );
	}
	{ //t8
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[8].bindingList.size());
	Transition[8].bindingList.push_back( bl );
	}
	{ //t9
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[9].bindingList.size());
	Transition[9].bindingList.push_back( bl );
	}
	{ //t10
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[10].bindingList.size());
	Transition[10].bindingList.push_back( bl );
	}
	{ //t11
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[11].bindingList.size());
	Transition[11].bindingList.push_back( bl );
	}
	{ //t12
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[12].bindingList.size());
	Transition[12].bindingList.push_back( bl );
	}
	{ //t13
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[13].bindingList.size());
	Transition[13].bindingList.push_back( bl );
	}
	{ //t14
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[14].bindingList.size());
	Transition[14].bindingList.push_back( bl );
	}
	{ //t15
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[15].bindingList.size());
	Transition[15].bindingList.push_back( bl );
	}
	{ //t16
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[16].bindingList.size());
	Transition[16].bindingList.push_back( bl );
	}
	{ //t17
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[17].bindingList.size());
	Transition[17].bindingList.push_back( bl );
	}
	{ //t18
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[18].bindingList.size());
	Transition[18].bindingList.push_back( bl );
	}
	{ //t19
	abstractBinding bl;
	bl.idcount = static_cast<int>(Transition[19].bindingList.size());
	Transition[19].bindingList.push_back( bl );
	}
}

bool SPN::IsEnabled(TR_PL_ID t, const abstractBinding &b)const{

	switch (t){
		case 18:	//t18

			if (!(contains(Marking.P->_PL_p0 , 1 ))) return false;
		return true;
		break;
		case 4:	//t4
		case 13:	//t13

			if (!(contains(Marking.P->_PL_p10 , 1 ))) return false;
		return true;
		break;
		case 3:	//t3

			if (!(contains(Marking.P->_PL_p11 , 1 ))) return false;
			if (!(contains(Marking.P->_PL_p14 , 1 ))) return false;
		return true;
		break;
		case 5:	//t5
		case 12:	//t12

			if (!(contains(Marking.P->_PL_p12 , 1 ))) return false;
		return true;
		break;
		case 9:	//t9
		case 19:	//t19

			if (!(contains(Marking.P->_PL_p13 , 1 ))) return false;
		return true;
		break;
		case 6:	//t6

			if (!(contains(Marking.P->_PL_p2 , 1 ))) return false;
		return true;
		break;
		case 2:	//t2
		case 17:	//t17

			if (!(contains(Marking.P->_PL_p3 , 1 ))) return false;
		return true;
		break;
		case 11:	//t11

			if (!(contains(Marking.P->_PL_p5 , 1 ))) return false;
		return true;
		break;
		case 15:	//t15
		case 16:	//t16

			if (!(contains(Marking.P->_PL_p7 , 1 ))) return false;
		return true;
		break;
		case 1:	//t1
		case 10:	//t10

			if (!(contains(Marking.P->_PL_p8 , 1 ))) return false;
		return true;
		break;
		case 8:	//t8

			if (!(contains(Marking.P->_PL_p9 , 1 ))) return false;
			if (!(contains(Marking.P->_PL_p15 , 1 ))) return false;
		return true;
		break;
		case 7:	//t7

			if (!(contains(Marking.P->_PL_start , 1 ))) return false;
		return true;
		break;
		default:	//t0,t14,

			if (!(contains(Marking.P->_PL_p1 , 1 ))) return false;
		return true;
		break;
	}
}

void SPN::fire(TR_PL_ID t, const abstractBinding &b,REAL_TYPE time){
	lastTransition = t;

	switch (t){
		case 3:	//t3
{
			int tmpMark_end = Marking.P->_PL_end;
			int tmpMark_p11 = Marking.P->_PL_p11;
			int tmpMark_p14 = Marking.P->_PL_p14;
			Marking.P->_PL_end += 1 ;
			Marking.P->_PL_p11 -= 1 ;
			Marking.P->_PL_p14 -= 1 ;
	}
		break;
		case 13:	//t13
{
			int tmpMark_p0 = Marking.P->_PL_p0;
			int tmpMark_p10 = Marking.P->_PL_p10;
			Marking.P->_PL_p0 += 1 ;
			Marking.P->_PL_p10 -= 1 ;
	}
		break;
		case 12:	//t12
{
			int tmpMark_p0 = Marking.P->_PL_p0;
			int tmpMark_p12 = Marking.P->_PL_p12;
			Marking.P->_PL_p0 += 1 ;
			Marking.P->_PL_p12 -= 1 ;
	}
		break;
		case 18:	//t18
{
			int tmpMark_p0 = Marking.P->_PL_p0;
			int tmpMark_p12 = Marking.P->_PL_p12;
			Marking.P->_PL_p0 -= 1 ;
			Marking.P->_PL_p12 += 1 ;
	}
		break;
		case 14:	//t14
{
			int tmpMark_p1 = Marking.P->_PL_p1;
			int tmpMark_p14 = Marking.P->_PL_p14;
			Marking.P->_PL_p1 -= 1 ;
			Marking.P->_PL_p14 += 1 ;
	}
		break;
		case 0:	//t0
{
			int tmpMark_p1 = Marking.P->_PL_p1;
			int tmpMark_p7 = Marking.P->_PL_p7;
			int tmpMark_p8 = Marking.P->_PL_p8;
			Marking.P->_PL_p1 -= 1 ;
			Marking.P->_PL_p7 += 1 ;
			Marking.P->_PL_p8 += 1 ;
	}
		break;
		case 7:	//t7
{
			int tmpMark_p1 = Marking.P->_PL_p1;
			int tmpMark_start = Marking.P->_PL_start;
			int tmpMark_p10 = Marking.P->_PL_p10;
			Marking.P->_PL_p1 += 1 ;
			Marking.P->_PL_start -= 1 ;
			Marking.P->_PL_p10 += 1 ;
	}
		break;
		case 4:	//t4
{
			int tmpMark_p10 = Marking.P->_PL_p10;
			int tmpMark_p11 = Marking.P->_PL_p11;
			Marking.P->_PL_p10 -= 1 ;
			Marking.P->_PL_p11 += 1 ;
	}
		break;
		case 5:	//t5
{
			int tmpMark_p11 = Marking.P->_PL_p11;
			int tmpMark_p12 = Marking.P->_PL_p12;
			Marking.P->_PL_p11 += 1 ;
			Marking.P->_PL_p12 -= 1 ;
	}
		break;
		case 9:	//t9
{
			int tmpMark_p13 = Marking.P->_PL_p13;
			int tmpMark_p15 = Marking.P->_PL_p15;
			Marking.P->_PL_p13 -= 1 ;
			Marking.P->_PL_p15 += 1 ;
	}
		break;
		case 19:	//t19
{
			int tmpMark_p2 = Marking.P->_PL_p2;
			int tmpMark_p13 = Marking.P->_PL_p13;
			Marking.P->_PL_p2 += 1 ;
			Marking.P->_PL_p13 -= 1 ;
	}
		break;
		case 6:	//t6
{
			int tmpMark_p2 = Marking.P->_PL_p2;
			int tmpMark_p13 = Marking.P->_PL_p13;
			Marking.P->_PL_p2 -= 1 ;
			Marking.P->_PL_p13 += 1 ;
	}
		break;
		case 16:	//t16
{
			int tmpMark_p2 = Marking.P->_PL_p2;
			int tmpMark_p7 = Marking.P->_PL_p7;
			Marking.P->_PL_p2 += 1 ;
			Marking.P->_PL_p7 -= 1 ;
	}
		break;
		case 11:	//t11
{
			int tmpMark_p3 = Marking.P->_PL_p3;
			int tmpMark_p5 = Marking.P->_PL_p5;
			Marking.P->_PL_p3 += 1 ;
			Marking.P->_PL_p5 -= 1 ;
	}
		break;
		case 2:	//t2
{
			int tmpMark_p3 = Marking.P->_PL_p3;
			int tmpMark_p5 = Marking.P->_PL_p5;
			Marking.P->_PL_p3 -= 1 ;
			Marking.P->_PL_p5 += 1 ;
	}
		break;
		case 17:	//t17
{
			int tmpMark_p3 = Marking.P->_PL_p3;
			int tmpMark_p9 = Marking.P->_PL_p9;
			Marking.P->_PL_p3 -= 1 ;
			Marking.P->_PL_p9 += 1 ;
	}
		break;
		case 1:	//t1
{
			int tmpMark_p5 = Marking.P->_PL_p5;
			int tmpMark_p8 = Marking.P->_PL_p8;
			Marking.P->_PL_p5 += 1 ;
			Marking.P->_PL_p8 -= 1 ;
	}
		break;
		case 15:	//t15
{
			int tmpMark_p7 = Marking.P->_PL_p7;
			int tmpMark_p15 = Marking.P->_PL_p15;
			Marking.P->_PL_p7 -= 1 ;
			Marking.P->_PL_p15 += 1 ;
	}
		break;
		case 10:	//t10
{
			int tmpMark_p8 = Marking.P->_PL_p8;
			int tmpMark_p9 = Marking.P->_PL_p9;
			Marking.P->_PL_p8 -= 1 ;
			Marking.P->_PL_p9 += 1 ;
	}
		break;
		case 8:	//t8
{
			int tmpMark_p9 = Marking.P->_PL_p9;
			int tmpMark_p14 = Marking.P->_PL_p14;
			int tmpMark_p15 = Marking.P->_PL_p15;
			Marking.P->_PL_p9 -= 1 ;
			Marking.P->_PL_p14 += 1 ;
			Marking.P->_PL_p15 -= 1 ;
	}
		break;
	}
}

void SPN::unfire(TR_PL_ID t, const abstractBinding &b){


}

const abstractBinding* SPN::nextPossiblyEnabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {
	switch(lastTransition*(tr+1) + targettr){
	default:
		if(*bindingNum==Transition[targettr].bindingList.size())return NULL;
		*bindingNum = *bindingNum +1;
		return &(Transition[targettr].bindingList[*bindingNum-1]);
}}
const abstractBinding* SPN::nextPossiblyDisabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {
	switch(lastTransition*(tr+1) + targettr){
	default:
		if(*bindingNum==Transition[targettr].bindingList.size())return NULL;
		*bindingNum = *bindingNum +1;
		return &(Transition[targettr].bindingList[*bindingNum-1]);
}}
void SPN::setConditionsVector(){
}
void SPN::GetDistParameters(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

	switch (t){
		case 0:	//t0
	{
		ParamDistr[0]= ( double ) w_t0 ;
	}

		break;
		case 1:	//t1
	{
		ParamDistr[0]= ( double ) w_t1 ;
	}

		break;
		case 10:	//t10
	{
		ParamDistr[0]= ( double ) w_t10 ;
	}

		break;
		case 11:	//t11
	{
		ParamDistr[0]= ( double ) w_t11 ;
	}

		break;
		case 12:	//t12
	{
		ParamDistr[0]= ( double ) w_t12 ;
	}

		break;
		case 13:	//t13
	{
		ParamDistr[0]= ( double ) w_t13 ;
	}

		break;
		case 14:	//t14
	{
		ParamDistr[0]= ( double ) w_t14 ;
	}

		break;
		case 15:	//t15
	{
		ParamDistr[0]= ( double ) w_t15 ;
	}

		break;
		case 16:	//t16
	{
		ParamDistr[0]= ( double ) w_t16 ;
	}

		break;
		case 17:	//t17
	{
		ParamDistr[0]= ( double ) w_t17 ;
	}

		break;
		case 18:	//t18
	{
		ParamDistr[0]= ( double ) w_t18 ;
	}

		break;
		case 19:	//t19
	{
		ParamDistr[0]= ( double ) w_t19 ;
	}

		break;
		case 2:	//t2
	{
		ParamDistr[0]= ( double ) w_t2 ;
	}

		break;
		case 3:	//t3
	{
		ParamDistr[0]= ( double ) w_t3 ;
	}

		break;
		case 4:	//t4
	{
		ParamDistr[0]= ( double ) w_t4 ;
	}

		break;
		case 5:	//t5
	{
		ParamDistr[0]= ( double ) w_t5 ;
	}

		break;
		case 6:	//t6
	{
		ParamDistr[0]= ( double ) w_t6 ;
	}

		break;
		case 7:	//t7
	{
		ParamDistr[0]= ( double ) w_t7 ;
	}

		break;
		case 8:	//t8
	{
		ParamDistr[0]= ( double ) w_t8 ;
	}

		break;
		case 9:	//t9
	{
		ParamDistr[0]= ( double ) w_t9 ;
	}

		break;
	}
}

REAL_TYPE SPN::GetPriority(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

		return (double)1 ;
}

REAL_TYPE SPN::GetWeight(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

		return (double)1 ;
}

void SPN::overrideParameter(string &p, double val)const{
	if(p=="w_t0")w_t0=val;
	if(p=="w_t1")w_t1=val;
	if(p=="w_t10")w_t10=val;
	if(p=="w_t11")w_t11=val;
	if(p=="w_t12")w_t12=val;
	if(p=="w_t13")w_t13=val;
	if(p=="w_t14")w_t14=val;
	if(p=="w_t15")w_t15=val;
	if(p=="w_t16")w_t16=val;
	if(p=="w_t17")w_t17=val;
	if(p=="w_t18")w_t18=val;
	if(p=="w_t19")w_t19=val;
	if(p=="w_t2")w_t2=val;
	if(p=="w_t3")w_t3=val;
	if(p=="w_t4")w_t4=val;
	if(p=="w_t5")w_t5=val;
	if(p=="w_t6")w_t6=val;
	if(p=="w_t7")w_t7=val;
	if(p=="w_t8")w_t8=val;
	if(p=="w_t9")w_t9=val;
}
void SPN::Msimple(){
	vector<int> tab;
	Msimpletab = tab;
}
void SPN::reset() {
	lastTransitionTime = 0;
	Marking.resetToInitMarking();
}

