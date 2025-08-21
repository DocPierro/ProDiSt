#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
    const double n=3;
    const double w_t0=1;
    const double w_t1=1;
    const double w_t10=1;
    const double w_t11=1;
    const double w_t12=1;
    const double w_t13=1;
    const double w_t14=1;
    const double w_t15=1;
    const double w_t16=1;
    const double w_t17=1;
    const double w_t18=1;
    const double w_t19=1;
    const double w_t2=1;
    const double w_t3=1;
    const double w_t4=1;
    const double w_t5=1;
    const double w_t6=1;
    const double w_t7=1;
    const double w_t8=1;
    const double w_t9=1;
namespace hybridVar {
};
struct Variables {
	double id;
	double word;
	double cpt;
	double c;
	double c_t9;
	double c_t14;
	double c_t19;
};
bool varOrder(const Variables &v1,const Variables &v2){
	if(v1.id<v2.id)return true;
	if(v1.word<v2.word)return true;
	if(v1.cpt<v2.cpt)return true;
	if(v1.c<v2.c)return true;
	if(v1.c_t9<v2.c_t9)return true;
	if(v1.c_t14<v2.c_t14)return true;
	if(v1.c_t19<v2.c_t19)return true;
	return false;
};
template<class DEDState>
void LHA<DEDState>::resetVariables(){
	Vars->id= 0;
	Vars->word= 0;
	Vars->cpt= 0;
	Vars->c= 0;
	Vars->c_t9= 0;
	Vars->c_t14= 0;
	Vars->c_t19= 0;
};
template<class DEDState>
void LHA<DEDState>::printHeader(ostream &s)const{
	s << "	Location\t";
};
template<class DEDState>
void LHA<DEDState>::printState(ostream &s){
	s << "\t" << LocLabel[CurrentLocation] << "\t";
};
template<class DEDState>
const int LHA<DEDState>::ActionEdgesAr[] = {
	1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
	3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,0 ,3 ,3 ,3 ,3 ,1 ,3 ,3 ,3 ,3 ,2 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};
template<class DEDState>
 LHA<DEDState>::LHA():NbLoc(3),NbTrans(20),NbVar(7),FinalLoc( 3,false){
    InitLoc.insert(0);
    FinalLoc[1]=true;
    Edge= vector<LhaEdge>(116);
    Edge[0] = LhaEdge(0, 0, 0,Synch);
    Edge[1] = LhaEdge(1, 0, 0,Synch);
    Edge[2] = LhaEdge(2, 0, 0,Synch);
    Edge[3] = LhaEdge(3, 0, 0,Synch);
    Edge[4] = LhaEdge(4, 0, 1,Auto);
    Edge[5] = LhaEdge(5, 0, 1,Auto);
    Edge[6] = LhaEdge(6, 0, 1,Auto);
    Edge[7] = LhaEdge(7, 0, 1,Auto);
    Edge[8] = LhaEdge(8, 0, 1,Auto);
    Edge[9] = LhaEdge(9, 0, 1,Auto);
    Edge[10] = LhaEdge(10, 0, 1,Auto);
    Edge[11] = LhaEdge(11, 0, 1,Auto);
    Edge[12] = LhaEdge(12, 0, 1,Auto);
    Edge[13] = LhaEdge(13, 0, 1,Auto);
    Edge[14] = LhaEdge(14, 0, 1,Auto);
    Edge[15] = LhaEdge(15, 0, 1,Auto);
    Edge[16] = LhaEdge(16, 0, 1,Auto);
    Edge[17] = LhaEdge(17, 0, 1,Auto);
    Edge[18] = LhaEdge(18, 0, 1,Auto);
    Edge[19] = LhaEdge(19, 0, 1,Auto);
    Edge[20] = LhaEdge(20, 0, 1,Auto);
    Edge[21] = LhaEdge(21, 0, 1,Auto);
    Edge[22] = LhaEdge(22, 0, 1,Auto);
    Edge[23] = LhaEdge(23, 0, 1,Auto);
    Edge[24] = LhaEdge(24, 0, 1,Auto);
    Edge[25] = LhaEdge(25, 0, 1,Auto);
    Edge[26] = LhaEdge(26, 0, 1,Auto);
    Edge[27] = LhaEdge(27, 0, 1,Auto);
    Edge[28] = LhaEdge(28, 0, 1,Auto);
    Edge[29] = LhaEdge(29, 0, 1,Auto);
    Edge[30] = LhaEdge(30, 0, 1,Auto);
    Edge[31] = LhaEdge(31, 0, 1,Auto);
    Edge[32] = LhaEdge(32, 0, 1,Auto);
    Edge[33] = LhaEdge(33, 0, 1,Auto);
    Edge[34] = LhaEdge(34, 0, 1,Auto);
    Edge[35] = LhaEdge(35, 0, 1,Auto);
    Edge[36] = LhaEdge(36, 0, 1,Auto);
    Edge[37] = LhaEdge(37, 0, 1,Auto);
    Edge[38] = LhaEdge(38, 0, 1,Auto);
    Edge[39] = LhaEdge(39, 0, 1,Auto);
    Edge[40] = LhaEdge(40, 0, 1,Auto);
    Edge[41] = LhaEdge(41, 0, 1,Auto);
    Edge[42] = LhaEdge(42, 0, 1,Auto);
    Edge[43] = LhaEdge(43, 0, 1,Auto);
    Edge[44] = LhaEdge(44, 0, 1,Auto);
    Edge[45] = LhaEdge(45, 0, 1,Auto);
    Edge[46] = LhaEdge(46, 0, 1,Auto);
    Edge[47] = LhaEdge(47, 0, 1,Auto);
    Edge[48] = LhaEdge(48, 0, 1,Auto);
    Edge[49] = LhaEdge(49, 0, 1,Auto);
    Edge[50] = LhaEdge(50, 0, 1,Auto);
    Edge[51] = LhaEdge(51, 0, 1,Auto);
    Edge[52] = LhaEdge(52, 0, 1,Auto);
    Edge[53] = LhaEdge(53, 0, 1,Auto);
    Edge[54] = LhaEdge(54, 0, 1,Auto);
    Edge[55] = LhaEdge(55, 0, 1,Auto);
    Edge[56] = LhaEdge(56, 0, 1,Auto);
    Edge[57] = LhaEdge(57, 0, 1,Auto);
    Edge[58] = LhaEdge(58, 0, 1,Auto);
    Edge[59] = LhaEdge(59, 0, 1,Auto);
    Edge[60] = LhaEdge(60, 0, 1,Auto);
    Edge[61] = LhaEdge(61, 0, 1,Auto);
    Edge[62] = LhaEdge(62, 0, 1,Auto);
    Edge[63] = LhaEdge(63, 0, 1,Auto);
    Edge[64] = LhaEdge(64, 0, 1,Auto);
    Edge[65] = LhaEdge(65, 0, 1,Auto);
    Edge[66] = LhaEdge(66, 0, 1,Auto);
    Edge[67] = LhaEdge(67, 0, 1,Auto);
    Edge[68] = LhaEdge(68, 0, 1,Auto);
    Edge[69] = LhaEdge(69, 0, 1,Auto);
    Edge[70] = LhaEdge(70, 0, 1,Auto);
    Edge[71] = LhaEdge(71, 0, 1,Auto);
    Edge[72] = LhaEdge(72, 0, 1,Auto);
    Edge[73] = LhaEdge(73, 0, 1,Auto);
    Edge[74] = LhaEdge(74, 0, 1,Auto);
    Edge[75] = LhaEdge(75, 0, 1,Auto);
    Edge[76] = LhaEdge(76, 0, 1,Auto);
    Edge[77] = LhaEdge(77, 0, 1,Auto);
    Edge[78] = LhaEdge(78, 0, 1,Auto);
    Edge[79] = LhaEdge(79, 0, 1,Auto);
    Edge[80] = LhaEdge(80, 0, 1,Auto);
    Edge[81] = LhaEdge(81, 0, 1,Auto);
    Edge[82] = LhaEdge(82, 0, 1,Auto);
    Edge[83] = LhaEdge(83, 0, 1,Auto);
    Edge[84] = LhaEdge(84, 0, 1,Auto);
    Edge[85] = LhaEdge(85, 0, 1,Auto);
    Edge[86] = LhaEdge(86, 0, 1,Auto);
    Edge[87] = LhaEdge(87, 0, 1,Auto);
    Edge[88] = LhaEdge(88, 0, 1,Auto);
    Edge[89] = LhaEdge(89, 0, 1,Auto);
    Edge[90] = LhaEdge(90, 0, 1,Auto);
    Edge[91] = LhaEdge(91, 0, 1,Auto);
    Edge[92] = LhaEdge(92, 0, 1,Auto);
    Edge[93] = LhaEdge(93, 0, 1,Auto);
    Edge[94] = LhaEdge(94, 0, 1,Auto);
    Edge[95] = LhaEdge(95, 0, 1,Auto);
    Edge[96] = LhaEdge(96, 0, 1,Auto);
    Edge[97] = LhaEdge(97, 0, 1,Auto);
    Edge[98] = LhaEdge(98, 0, 1,Auto);
    Edge[99] = LhaEdge(99, 0, 1,Auto);
    Edge[100] = LhaEdge(100, 0, 1,Auto);
    Edge[101] = LhaEdge(101, 0, 1,Auto);
    Edge[102] = LhaEdge(102, 0, 1,Auto);
    Edge[103] = LhaEdge(103, 0, 1,Auto);
    Edge[104] = LhaEdge(104, 0, 1,Auto);
    Edge[105] = LhaEdge(105, 0, 1,Auto);
    Edge[106] = LhaEdge(106, 0, 1,Auto);
    Edge[107] = LhaEdge(107, 0, 1,Auto);
    Edge[108] = LhaEdge(108, 0, 1,Auto);
    Edge[109] = LhaEdge(109, 0, 1,Auto);
    Edge[110] = LhaEdge(110, 0, 1,Auto);
    Edge[111] = LhaEdge(111, 0, 1,Auto);
    Edge[112] = LhaEdge(112, 0, 2,Auto);
    Edge[113] = LhaEdge(113, 0, 2,Auto);
    Edge[114] = LhaEdge(114, 0, 2,Auto);
    Edge[115] = LhaEdge(115, 0, 2,Auto);
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    Out_A_Edges =vector< set < int > >(NbLoc);
    Out_A_Edges[0].insert(4);
    Out_A_Edges[0].insert(5);
    Out_A_Edges[0].insert(6);
    Out_A_Edges[0].insert(7);
    Out_A_Edges[0].insert(8);
    Out_A_Edges[0].insert(9);
    Out_A_Edges[0].insert(10);
    Out_A_Edges[0].insert(11);
    Out_A_Edges[0].insert(12);
    Out_A_Edges[0].insert(13);
    Out_A_Edges[0].insert(14);
    Out_A_Edges[0].insert(15);
    Out_A_Edges[0].insert(16);
    Out_A_Edges[0].insert(17);
    Out_A_Edges[0].insert(18);
    Out_A_Edges[0].insert(19);
    Out_A_Edges[0].insert(20);
    Out_A_Edges[0].insert(21);
    Out_A_Edges[0].insert(22);
    Out_A_Edges[0].insert(23);
    Out_A_Edges[0].insert(24);
    Out_A_Edges[0].insert(25);
    Out_A_Edges[0].insert(26);
    Out_A_Edges[0].insert(27);
    Out_A_Edges[0].insert(28);
    Out_A_Edges[0].insert(29);
    Out_A_Edges[0].insert(30);
    Out_A_Edges[0].insert(31);
    Out_A_Edges[0].insert(32);
    Out_A_Edges[0].insert(33);
    Out_A_Edges[0].insert(34);
    Out_A_Edges[0].insert(35);
    Out_A_Edges[0].insert(36);
    Out_A_Edges[0].insert(37);
    Out_A_Edges[0].insert(38);
    Out_A_Edges[0].insert(39);
    Out_A_Edges[0].insert(40);
    Out_A_Edges[0].insert(41);
    Out_A_Edges[0].insert(42);
    Out_A_Edges[0].insert(43);
    Out_A_Edges[0].insert(44);
    Out_A_Edges[0].insert(45);
    Out_A_Edges[0].insert(46);
    Out_A_Edges[0].insert(47);
    Out_A_Edges[0].insert(48);
    Out_A_Edges[0].insert(49);
    Out_A_Edges[0].insert(50);
    Out_A_Edges[0].insert(51);
    Out_A_Edges[0].insert(52);
    Out_A_Edges[0].insert(53);
    Out_A_Edges[0].insert(54);
    Out_A_Edges[0].insert(55);
    Out_A_Edges[0].insert(56);
    Out_A_Edges[0].insert(57);
    Out_A_Edges[0].insert(58);
    Out_A_Edges[0].insert(59);
    Out_A_Edges[0].insert(60);
    Out_A_Edges[0].insert(61);
    Out_A_Edges[0].insert(62);
    Out_A_Edges[0].insert(63);
    Out_A_Edges[0].insert(64);
    Out_A_Edges[0].insert(65);
    Out_A_Edges[0].insert(66);
    Out_A_Edges[0].insert(67);
    Out_A_Edges[0].insert(68);
    Out_A_Edges[0].insert(69);
    Out_A_Edges[0].insert(70);
    Out_A_Edges[0].insert(71);
    Out_A_Edges[0].insert(72);
    Out_A_Edges[0].insert(73);
    Out_A_Edges[0].insert(74);
    Out_A_Edges[0].insert(75);
    Out_A_Edges[0].insert(76);
    Out_A_Edges[0].insert(77);
    Out_A_Edges[0].insert(78);
    Out_A_Edges[0].insert(79);
    Out_A_Edges[0].insert(80);
    Out_A_Edges[0].insert(81);
    Out_A_Edges[0].insert(82);
    Out_A_Edges[0].insert(83);
    Out_A_Edges[0].insert(84);
    Out_A_Edges[0].insert(85);
    Out_A_Edges[0].insert(86);
    Out_A_Edges[0].insert(87);
    Out_A_Edges[0].insert(88);
    Out_A_Edges[0].insert(89);
    Out_A_Edges[0].insert(90);
    Out_A_Edges[0].insert(91);
    Out_A_Edges[0].insert(92);
    Out_A_Edges[0].insert(93);
    Out_A_Edges[0].insert(94);
    Out_A_Edges[0].insert(95);
    Out_A_Edges[0].insert(96);
    Out_A_Edges[0].insert(97);
    Out_A_Edges[0].insert(98);
    Out_A_Edges[0].insert(99);
    Out_A_Edges[0].insert(100);
    Out_A_Edges[0].insert(101);
    Out_A_Edges[0].insert(102);
    Out_A_Edges[0].insert(103);
    Out_A_Edges[0].insert(104);
    Out_A_Edges[0].insert(105);
    Out_A_Edges[0].insert(106);
    Out_A_Edges[0].insert(107);
    Out_A_Edges[0].insert(108);
    Out_A_Edges[0].insert(109);
    Out_A_Edges[0].insert(110);
    Out_A_Edges[0].insert(111);
    Out_A_Edges[0].insert(112);
    Out_A_Edges[0].insert(113);
    Out_A_Edges[0].insert(114);
    Out_A_Edges[0].insert(115);
    LinForm= vector<double>(1,0.0);
    OldLinForm=vector<double>(1,0.0);
    LhaFunc=vector<double>(1,0.0);
    LhaFuncDefaults=vector<double>(1,0.0);
    FormulaVal = vector<double>(108,0.0);
    FormulaValQual = vector<bool>(0,false);
}

template<class DEDState>
void LHA<DEDState>::DoElapsedTimeUpdate(double DeltaT,const DEDState& Marking) {
	Vars->id += GetFlow(0, Marking) * DeltaT;
	Vars->word += GetFlow(1, Marking) * DeltaT;
	Vars->cpt += GetFlow(2, Marking) * DeltaT;
	Vars->c += GetFlow(3, Marking) * DeltaT;
	Vars->c_t9 += GetFlow(4, Marking) * DeltaT;
	Vars->c_t14 += GetFlow(5, Marking) * DeltaT;
	Vars->c_t19 += GetFlow(6, Marking) * DeltaT;
}
template<class DEDState>
double LHA<DEDState>::GetFlow(int v, const DEDState& Marking)const{
		return 0.0;


}

template<class DEDState>
bool LHA<DEDState>::CheckLocation(int loc,const DEDState& Marking)const{
	switch (loc){
		case 1:	//lfa
         return (  Marking.P->_PL_end  == 1 );

		break;
		default:	//li,lfr,
         return true;

		break;
	}
}

template<class DEDState>
bool LHA<DEDState>::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const DEDState& Marking)const{
	return true;

}

template<class DEDState>
t_interval LHA<DEDState>::GetEdgeEnablingTime(int ed,const DEDState& Marking)const{
	switch (ed){
		case 47:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 20:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==10))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(10-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 46:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==100))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(100-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 58:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1012171477))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1012171477-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 26:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1093))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1093-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 64:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1111))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1111-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 60:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==112))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(112-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 92:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==11472))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(11472-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 97:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==11481))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(11481-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 75:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==118))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(118-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 66:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==12))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(12-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 7:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==121))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(121-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 94:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==127))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(127-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 40:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==12736))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(12736-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 106:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==129457))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(129457-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 5:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==13))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(13-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 74:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==13064716))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(13064716-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 99:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1315))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1315-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 24:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1327))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1327-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 76:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==149314))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(149314-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 62:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==15))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(15-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 87:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==156151))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(156151-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 85:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==16))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(16-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 111:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1639))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1639-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 36:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==16402))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(16402-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 70:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==16462))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(16462-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 73:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==16584))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(16584-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 72:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==16948))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(16948-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 68:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==17161))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(17161-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 55:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==17215))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(17215-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 78:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==17221))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(17221-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 82:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==18046))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(18046-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 39:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==181))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(181-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 52:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1815))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1815-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 56:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1822))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1822-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 6:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1840))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1840-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 81:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1842))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1842-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 53:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1855))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1855-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 67:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1882))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1882-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 35:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==19))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(19-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 71:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1900))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1900-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 27:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1902))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1902-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 19:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==1984))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(1984-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 90:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==2))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(2-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 31:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==2002))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(2002-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 25:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==202))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(202-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 57:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==2038))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(2038-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 63:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==204))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(204-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 37:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==2062))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(2062-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 51:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==208))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(208-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 110:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==21))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(21-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 33:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==210))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(210-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 69:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==211))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(211-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 42:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==213))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(213-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 17:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==22))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(22-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 44:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==226))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(226-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 65:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==228))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(228-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 96:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==23509))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(23509-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 32:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==24))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(24-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 102:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==24643))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(24643-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 105:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==2611))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(2611-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 49:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==286))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(286-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 107:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==289))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(289-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 21:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==3))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(3-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 80:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==301))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(301-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 98:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==307))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(307-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 29:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==31))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(31-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 95:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==33))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(33-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 109:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==343))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(343-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 11:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==3460))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(3460-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 108:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==366))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(366-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 38:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==37))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(37-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 10:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==4))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(4-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 4:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==40))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(40-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 12:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==42))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(42-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 100:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==420))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(420-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 86:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==424))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(424-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 16:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==46))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(46-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 101:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==4744))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(4744-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 77:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==4906))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(4906-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 91:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==4920))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(4920-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 104:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==532))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(532-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 22:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==5467))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(5467-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 15:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==5469))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(5469-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 59:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==5632))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(5632-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 14:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==58))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(58-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 30:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==6))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(6-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 28:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==607))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(607-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 8:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==613))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(613-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 23:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==625))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(625-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 41:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==631))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(631-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 50:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==637))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(637-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 54:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==64))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(64-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 13:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==67))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(67-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 9:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==7))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(7-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 48:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==70))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(70-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 45:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==70570))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(70570-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 43:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==73))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(73-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 88:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==74904))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(74904-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 34:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==7678))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(7678-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 84:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==7834))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(7834-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 79:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==8218))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(8218-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 89:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==850))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(850-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 93:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==928))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(928-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 83:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==930975792))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(930975792-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 18:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==94))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(94-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 103:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==96))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(96-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 61:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(1, Marking);
             SumAX=+(1)*Vars->word;

             if(SumAF==0){
                  if(!(SumAX==97))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(97-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		case 112:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(2, Marking);
             SumAX=+(1)*Vars->cpt;

             if(SumAF==0){
                  if(!(SumAX>=22))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(22-SumAX)/(double)SumAF;
                  if(SumAF>0){
                     if(EnablingT.first<t) EnablingT.first=t;
                     if(EnablingT.second<EnablingT.first) return EmptyInterval;
                      }
                  else{
                     if(EnablingT.second>t) EnablingT.second=t;
                     if(EnablingT.second<EnablingT.first) return EmptyInterval;
                      }
             }
             return EnablingT;
         }

		break;
		case 113:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(4, Marking);
             SumAX=+(1)*Vars->c_t9;

             if(SumAF==0){
                  if(!(SumAX>=15))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(15-SumAX)/(double)SumAF;
                  if(SumAF>0){
                     if(EnablingT.first<t) EnablingT.first=t;
                     if(EnablingT.second<EnablingT.first) return EmptyInterval;
                      }
                  else{
                     if(EnablingT.second>t) EnablingT.second=t;
                     if(EnablingT.second<EnablingT.first) return EmptyInterval;
                      }
             }
             return EnablingT;
         }

		break;
		case 114:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(5, Marking);
             SumAX=+(1)*Vars->c_t14;

             if(SumAF==0){
                  if(!(SumAX>=5))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(5-SumAX)/(double)SumAF;
                  if(SumAF>0){
                     if(EnablingT.first<t) EnablingT.first=t;
                     if(EnablingT.second<EnablingT.first) return EmptyInterval;
                      }
                  else{
                     if(EnablingT.second>t) EnablingT.second=t;
                     if(EnablingT.second<EnablingT.first) return EmptyInterval;
                      }
             }
             return EnablingT;
         }

		break;
		case 115:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(6, Marking);
             SumAX=+(1)*Vars->c_t19;

             if(SumAF==0){
                  if(!(SumAX>=9))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(9-SumAX)/(double)SumAF;
                  if(SumAF>0){
                     if(EnablingT.first<t) EnablingT.first=t;
                     if(EnablingT.second<EnablingT.first) return EmptyInterval;
                      }
                  else{
                     if(EnablingT.second>t) EnablingT.second=t;
                     if(EnablingT.second<EnablingT.first) return EmptyInterval;
                      }
             }
             return EnablingT;
         }

		break;
		default:	//,,,,
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             return EnablingT;
         }

		break;
	}
}

template<class DEDState>
void LHA<DEDState>::DoEdgeUpdates(int ed,const DEDState& Marking, const abstractBinding& b){
	switch (ed){
		case 4:	//
         {
		Vars->id=0;
         }

		break;
		case 104:	//
         {
		Vars->id=100;
         }

		break;
		case 105:	//
         {
		Vars->id=101;
         }

		break;
		case 106:	//
         {
		Vars->id=102;
         }

		break;
		case 107:	//
         {
		Vars->id=103;
         }

		break;
		case 108:	//
         {
		Vars->id=104;
         }

		break;
		case 109:	//
         {
		Vars->id=105;
         }

		break;
		case 110:	//
         {
		Vars->id=106;
         }

		break;
		case 111:	//
         {
		Vars->id=107;
         }

		break;
		case 14:	//
         {
		Vars->id=10;
         }

		break;
		case 15:	//
         {
		Vars->id=11;
         }

		break;
		case 16:	//
         {
		Vars->id=12;
         }

		break;
		case 17:	//
         {
		Vars->id=13;
         }

		break;
		case 18:	//
         {
		Vars->id=14;
         }

		break;
		case 19:	//
         {
		Vars->id=15;
         }

		break;
		case 20:	//
         {
		Vars->id=16;
         }

		break;
		case 21:	//
         {
		Vars->id=17;
         }

		break;
		case 22:	//
         {
		Vars->id=18;
         }

		break;
		case 23:	//
         {
		Vars->id=19;
         }

		break;
		case 5:	//
         {
		Vars->id=1;
         }

		break;
		case 24:	//
         {
		Vars->id=20;
         }

		break;
		case 25:	//
         {
		Vars->id=21;
         }

		break;
		case 26:	//
         {
		Vars->id=22;
         }

		break;
		case 27:	//
         {
		Vars->id=23;
         }

		break;
		case 28:	//
         {
		Vars->id=24;
         }

		break;
		case 29:	//
         {
		Vars->id=25;
         }

		break;
		case 30:	//
         {
		Vars->id=26;
         }

		break;
		case 31:	//
         {
		Vars->id=27;
         }

		break;
		case 32:	//
         {
		Vars->id=28;
         }

		break;
		case 33:	//
         {
		Vars->id=29;
         }

		break;
		case 6:	//
         {
		Vars->id=2;
         }

		break;
		case 34:	//
         {
		Vars->id=30;
         }

		break;
		case 35:	//
         {
		Vars->id=31;
         }

		break;
		case 36:	//
         {
		Vars->id=32;
         }

		break;
		case 37:	//
         {
		Vars->id=33;
         }

		break;
		case 38:	//
         {
		Vars->id=34;
         }

		break;
		case 39:	//
         {
		Vars->id=35;
         }

		break;
		case 40:	//
         {
		Vars->id=36;
         }

		break;
		case 41:	//
         {
		Vars->id=37;
         }

		break;
		case 42:	//
         {
		Vars->id=38;
         }

		break;
		case 43:	//
         {
		Vars->id=39;
         }

		break;
		case 7:	//
         {
		Vars->id=3;
         }

		break;
		case 44:	//
         {
		Vars->id=40;
         }

		break;
		case 45:	//
         {
		Vars->id=41;
         }

		break;
		case 46:	//
         {
		Vars->id=42;
         }

		break;
		case 47:	//
         {
		Vars->id=43;
         }

		break;
		case 48:	//
         {
		Vars->id=44;
         }

		break;
		case 49:	//
         {
		Vars->id=45;
         }

		break;
		case 50:	//
         {
		Vars->id=46;
         }

		break;
		case 51:	//
         {
		Vars->id=47;
         }

		break;
		case 52:	//
         {
		Vars->id=48;
         }

		break;
		case 53:	//
         {
		Vars->id=49;
         }

		break;
		case 8:	//
         {
		Vars->id=4;
         }

		break;
		case 54:	//
         {
		Vars->id=50;
         }

		break;
		case 55:	//
         {
		Vars->id=51;
         }

		break;
		case 56:	//
         {
		Vars->id=52;
         }

		break;
		case 57:	//
         {
		Vars->id=53;
         }

		break;
		case 58:	//
         {
		Vars->id=54;
         }

		break;
		case 59:	//
         {
		Vars->id=55;
         }

		break;
		case 60:	//
         {
		Vars->id=56;
         }

		break;
		case 61:	//
         {
		Vars->id=57;
         }

		break;
		case 62:	//
         {
		Vars->id=58;
         }

		break;
		case 63:	//
         {
		Vars->id=59;
         }

		break;
		case 9:	//
         {
		Vars->id=5;
         }

		break;
		case 64:	//
         {
		Vars->id=60;
         }

		break;
		case 65:	//
         {
		Vars->id=61;
         }

		break;
		case 66:	//
         {
		Vars->id=62;
         }

		break;
		case 67:	//
         {
		Vars->id=63;
         }

		break;
		case 68:	//
         {
		Vars->id=64;
         }

		break;
		case 69:	//
         {
		Vars->id=65;
         }

		break;
		case 70:	//
         {
		Vars->id=66;
         }

		break;
		case 71:	//
         {
		Vars->id=67;
         }

		break;
		case 72:	//
         {
		Vars->id=68;
         }

		break;
		case 73:	//
         {
		Vars->id=69;
         }

		break;
		case 10:	//
         {
		Vars->id=6;
         }

		break;
		case 74:	//
         {
		Vars->id=70;
         }

		break;
		case 75:	//
         {
		Vars->id=71;
         }

		break;
		case 76:	//
         {
		Vars->id=72;
         }

		break;
		case 77:	//
         {
		Vars->id=73;
         }

		break;
		case 78:	//
         {
		Vars->id=74;
         }

		break;
		case 79:	//
         {
		Vars->id=75;
         }

		break;
		case 80:	//
         {
		Vars->id=76;
         }

		break;
		case 81:	//
         {
		Vars->id=77;
         }

		break;
		case 82:	//
         {
		Vars->id=78;
         }

		break;
		case 83:	//
         {
		Vars->id=79;
         }

		break;
		case 11:	//
         {
		Vars->id=7;
         }

		break;
		case 84:	//
         {
		Vars->id=80;
         }

		break;
		case 85:	//
         {
		Vars->id=81;
         }

		break;
		case 86:	//
         {
		Vars->id=82;
         }

		break;
		case 87:	//
         {
		Vars->id=83;
         }

		break;
		case 88:	//
         {
		Vars->id=84;
         }

		break;
		case 89:	//
         {
		Vars->id=85;
         }

		break;
		case 90:	//
         {
		Vars->id=86;
         }

		break;
		case 91:	//
         {
		Vars->id=87;
         }

		break;
		case 92:	//
         {
		Vars->id=88;
         }

		break;
		case 93:	//
         {
		Vars->id=89;
         }

		break;
		case 12:	//
         {
		Vars->id=8;
         }

		break;
		case 94:	//
         {
		Vars->id=90;
         }

		break;
		case 95:	//
         {
		Vars->id=91;
         }

		break;
		case 96:	//
         {
		Vars->id=92;
         }

		break;
		case 97:	//
         {
		Vars->id=93;
         }

		break;
		case 98:	//
         {
		Vars->id=94;
         }

		break;
		case 99:	//
         {
		Vars->id=95;
         }

		break;
		case 100:	//
         {
		Vars->id=96;
         }

		break;
		case 101:	//
         {
		Vars->id=97;
         }

		break;
		case 102:	//
         {
		Vars->id=98;
         }

		break;
		case 103:	//
         {
		Vars->id=99;
         }

		break;
		case 13:	//
         {
		Vars->id=9;
         }

		break;
		case 0:	//
         {
		tempVars->word=Vars->word + 1 * ( pow(3 , Vars->c) );
		tempVars->c=Vars->c + 1;
		tempVars->c_t9=Vars->c_t9 + 1;
		Vars->word = tempVars->word;
		Vars->c = tempVars->c;
		Vars->c_t9 = tempVars->c_t9;
         }

		break;
		case 1:	//
         {
		tempVars->word=Vars->word + 2 * ( pow(3 , Vars->c) );
		tempVars->c=Vars->c + 1;
		tempVars->c_t14=Vars->c_t14 + 1;
		Vars->word = tempVars->word;
		Vars->c = tempVars->c;
		Vars->c_t14 = tempVars->c_t14;
         }

		break;
		case 2:	//
         {
		tempVars->word=Vars->word + 3 * ( pow(3 , Vars->c) );
		tempVars->c=Vars->c + 1;
		tempVars->c_t19=Vars->c_t19 + 1;
		Vars->word = tempVars->word;
		Vars->c = tempVars->c;
		Vars->c_t19 = tempVars->c_t19;
         }

		break;
	}
}

template<class DEDState>
void LHA<DEDState>::UpdateLinForm(const DEDState& Marking){
    }

template<class DEDState>
void LHA<DEDState>::UpdateLhaFunc(double& Delta ){

    }

template<class DEDState>
void LHA<DEDState>::UpdateFormulaVal(const DEDState& Marking){

    LhaFunc[0]= Vars->id;
    FormulaVal[0]=((LhaFunc[0] >= 0&& LhaFunc[0]<1) ? 1:0);
    FormulaVal[1]=((LhaFunc[0] >= 1&& LhaFunc[0]<2) ? 1:0);
    FormulaVal[2]=((LhaFunc[0] >= 2&& LhaFunc[0]<3) ? 1:0);
    FormulaVal[3]=((LhaFunc[0] >= 3&& LhaFunc[0]<4) ? 1:0);
    FormulaVal[4]=((LhaFunc[0] >= 4&& LhaFunc[0]<5) ? 1:0);
    FormulaVal[5]=((LhaFunc[0] >= 5&& LhaFunc[0]<6) ? 1:0);
    FormulaVal[6]=((LhaFunc[0] >= 6&& LhaFunc[0]<7) ? 1:0);
    FormulaVal[7]=((LhaFunc[0] >= 7&& LhaFunc[0]<8) ? 1:0);
    FormulaVal[8]=((LhaFunc[0] >= 8&& LhaFunc[0]<9) ? 1:0);
    FormulaVal[9]=((LhaFunc[0] >= 9&& LhaFunc[0]<10) ? 1:0);
    FormulaVal[10]=((LhaFunc[0] >= 10&& LhaFunc[0]<11) ? 1:0);
    FormulaVal[11]=((LhaFunc[0] >= 11&& LhaFunc[0]<12) ? 1:0);
    FormulaVal[12]=((LhaFunc[0] >= 12&& LhaFunc[0]<13) ? 1:0);
    FormulaVal[13]=((LhaFunc[0] >= 13&& LhaFunc[0]<14) ? 1:0);
    FormulaVal[14]=((LhaFunc[0] >= 14&& LhaFunc[0]<15) ? 1:0);
    FormulaVal[15]=((LhaFunc[0] >= 15&& LhaFunc[0]<16) ? 1:0);
    FormulaVal[16]=((LhaFunc[0] >= 16&& LhaFunc[0]<17) ? 1:0);
    FormulaVal[17]=((LhaFunc[0] >= 17&& LhaFunc[0]<18) ? 1:0);
    FormulaVal[18]=((LhaFunc[0] >= 18&& LhaFunc[0]<19) ? 1:0);
    FormulaVal[19]=((LhaFunc[0] >= 19&& LhaFunc[0]<20) ? 1:0);
    FormulaVal[20]=((LhaFunc[0] >= 20&& LhaFunc[0]<21) ? 1:0);
    FormulaVal[21]=((LhaFunc[0] >= 21&& LhaFunc[0]<22) ? 1:0);
    FormulaVal[22]=((LhaFunc[0] >= 22&& LhaFunc[0]<23) ? 1:0);
    FormulaVal[23]=((LhaFunc[0] >= 23&& LhaFunc[0]<24) ? 1:0);
    FormulaVal[24]=((LhaFunc[0] >= 24&& LhaFunc[0]<25) ? 1:0);
    FormulaVal[25]=((LhaFunc[0] >= 25&& LhaFunc[0]<26) ? 1:0);
    FormulaVal[26]=((LhaFunc[0] >= 26&& LhaFunc[0]<27) ? 1:0);
    FormulaVal[27]=((LhaFunc[0] >= 27&& LhaFunc[0]<28) ? 1:0);
    FormulaVal[28]=((LhaFunc[0] >= 28&& LhaFunc[0]<29) ? 1:0);
    FormulaVal[29]=((LhaFunc[0] >= 29&& LhaFunc[0]<30) ? 1:0);
    FormulaVal[30]=((LhaFunc[0] >= 30&& LhaFunc[0]<31) ? 1:0);
    FormulaVal[31]=((LhaFunc[0] >= 31&& LhaFunc[0]<32) ? 1:0);
    FormulaVal[32]=((LhaFunc[0] >= 32&& LhaFunc[0]<33) ? 1:0);
    FormulaVal[33]=((LhaFunc[0] >= 33&& LhaFunc[0]<34) ? 1:0);
    FormulaVal[34]=((LhaFunc[0] >= 34&& LhaFunc[0]<35) ? 1:0);
    FormulaVal[35]=((LhaFunc[0] >= 35&& LhaFunc[0]<36) ? 1:0);
    FormulaVal[36]=((LhaFunc[0] >= 36&& LhaFunc[0]<37) ? 1:0);
    FormulaVal[37]=((LhaFunc[0] >= 37&& LhaFunc[0]<38) ? 1:0);
    FormulaVal[38]=((LhaFunc[0] >= 38&& LhaFunc[0]<39) ? 1:0);
    FormulaVal[39]=((LhaFunc[0] >= 39&& LhaFunc[0]<40) ? 1:0);
    FormulaVal[40]=((LhaFunc[0] >= 40&& LhaFunc[0]<41) ? 1:0);
    FormulaVal[41]=((LhaFunc[0] >= 41&& LhaFunc[0]<42) ? 1:0);
    FormulaVal[42]=((LhaFunc[0] >= 42&& LhaFunc[0]<43) ? 1:0);
    FormulaVal[43]=((LhaFunc[0] >= 43&& LhaFunc[0]<44) ? 1:0);
    FormulaVal[44]=((LhaFunc[0] >= 44&& LhaFunc[0]<45) ? 1:0);
    FormulaVal[45]=((LhaFunc[0] >= 45&& LhaFunc[0]<46) ? 1:0);
    FormulaVal[46]=((LhaFunc[0] >= 46&& LhaFunc[0]<47) ? 1:0);
    FormulaVal[47]=((LhaFunc[0] >= 47&& LhaFunc[0]<48) ? 1:0);
    FormulaVal[48]=((LhaFunc[0] >= 48&& LhaFunc[0]<49) ? 1:0);
    FormulaVal[49]=((LhaFunc[0] >= 49&& LhaFunc[0]<50) ? 1:0);
    FormulaVal[50]=((LhaFunc[0] >= 50&& LhaFunc[0]<51) ? 1:0);
    FormulaVal[51]=((LhaFunc[0] >= 51&& LhaFunc[0]<52) ? 1:0);
    FormulaVal[52]=((LhaFunc[0] >= 52&& LhaFunc[0]<53) ? 1:0);
    FormulaVal[53]=((LhaFunc[0] >= 53&& LhaFunc[0]<54) ? 1:0);
    FormulaVal[54]=((LhaFunc[0] >= 54&& LhaFunc[0]<55) ? 1:0);
    FormulaVal[55]=((LhaFunc[0] >= 55&& LhaFunc[0]<56) ? 1:0);
    FormulaVal[56]=((LhaFunc[0] >= 56&& LhaFunc[0]<57) ? 1:0);
    FormulaVal[57]=((LhaFunc[0] >= 57&& LhaFunc[0]<58) ? 1:0);
    FormulaVal[58]=((LhaFunc[0] >= 58&& LhaFunc[0]<59) ? 1:0);
    FormulaVal[59]=((LhaFunc[0] >= 59&& LhaFunc[0]<60) ? 1:0);
    FormulaVal[60]=((LhaFunc[0] >= 60&& LhaFunc[0]<61) ? 1:0);
    FormulaVal[61]=((LhaFunc[0] >= 61&& LhaFunc[0]<62) ? 1:0);
    FormulaVal[62]=((LhaFunc[0] >= 62&& LhaFunc[0]<63) ? 1:0);
    FormulaVal[63]=((LhaFunc[0] >= 63&& LhaFunc[0]<64) ? 1:0);
    FormulaVal[64]=((LhaFunc[0] >= 64&& LhaFunc[0]<65) ? 1:0);
    FormulaVal[65]=((LhaFunc[0] >= 65&& LhaFunc[0]<66) ? 1:0);
    FormulaVal[66]=((LhaFunc[0] >= 66&& LhaFunc[0]<67) ? 1:0);
    FormulaVal[67]=((LhaFunc[0] >= 67&& LhaFunc[0]<68) ? 1:0);
    FormulaVal[68]=((LhaFunc[0] >= 68&& LhaFunc[0]<69) ? 1:0);
    FormulaVal[69]=((LhaFunc[0] >= 69&& LhaFunc[0]<70) ? 1:0);
    FormulaVal[70]=((LhaFunc[0] >= 70&& LhaFunc[0]<71) ? 1:0);
    FormulaVal[71]=((LhaFunc[0] >= 71&& LhaFunc[0]<72) ? 1:0);
    FormulaVal[72]=((LhaFunc[0] >= 72&& LhaFunc[0]<73) ? 1:0);
    FormulaVal[73]=((LhaFunc[0] >= 73&& LhaFunc[0]<74) ? 1:0);
    FormulaVal[74]=((LhaFunc[0] >= 74&& LhaFunc[0]<75) ? 1:0);
    FormulaVal[75]=((LhaFunc[0] >= 75&& LhaFunc[0]<76) ? 1:0);
    FormulaVal[76]=((LhaFunc[0] >= 76&& LhaFunc[0]<77) ? 1:0);
    FormulaVal[77]=((LhaFunc[0] >= 77&& LhaFunc[0]<78) ? 1:0);
    FormulaVal[78]=((LhaFunc[0] >= 78&& LhaFunc[0]<79) ? 1:0);
    FormulaVal[79]=((LhaFunc[0] >= 79&& LhaFunc[0]<80) ? 1:0);
    FormulaVal[80]=((LhaFunc[0] >= 80&& LhaFunc[0]<81) ? 1:0);
    FormulaVal[81]=((LhaFunc[0] >= 81&& LhaFunc[0]<82) ? 1:0);
    FormulaVal[82]=((LhaFunc[0] >= 82&& LhaFunc[0]<83) ? 1:0);
    FormulaVal[83]=((LhaFunc[0] >= 83&& LhaFunc[0]<84) ? 1:0);
    FormulaVal[84]=((LhaFunc[0] >= 84&& LhaFunc[0]<85) ? 1:0);
    FormulaVal[85]=((LhaFunc[0] >= 85&& LhaFunc[0]<86) ? 1:0);
    FormulaVal[86]=((LhaFunc[0] >= 86&& LhaFunc[0]<87) ? 1:0);
    FormulaVal[87]=((LhaFunc[0] >= 87&& LhaFunc[0]<88) ? 1:0);
    FormulaVal[88]=((LhaFunc[0] >= 88&& LhaFunc[0]<89) ? 1:0);
    FormulaVal[89]=((LhaFunc[0] >= 89&& LhaFunc[0]<90) ? 1:0);
    FormulaVal[90]=((LhaFunc[0] >= 90&& LhaFunc[0]<91) ? 1:0);
    FormulaVal[91]=((LhaFunc[0] >= 91&& LhaFunc[0]<92) ? 1:0);
    FormulaVal[92]=((LhaFunc[0] >= 92&& LhaFunc[0]<93) ? 1:0);
    FormulaVal[93]=((LhaFunc[0] >= 93&& LhaFunc[0]<94) ? 1:0);
    FormulaVal[94]=((LhaFunc[0] >= 94&& LhaFunc[0]<95) ? 1:0);
    FormulaVal[95]=((LhaFunc[0] >= 95&& LhaFunc[0]<96) ? 1:0);
    FormulaVal[96]=((LhaFunc[0] >= 96&& LhaFunc[0]<97) ? 1:0);
    FormulaVal[97]=((LhaFunc[0] >= 97&& LhaFunc[0]<98) ? 1:0);
    FormulaVal[98]=((LhaFunc[0] >= 98&& LhaFunc[0]<99) ? 1:0);
    FormulaVal[99]=((LhaFunc[0] >= 99&& LhaFunc[0]<100) ? 1:0);
    FormulaVal[100]=((LhaFunc[0] >= 100&& LhaFunc[0]<101) ? 1:0);
    FormulaVal[101]=((LhaFunc[0] >= 101&& LhaFunc[0]<102) ? 1:0);
    FormulaVal[102]=((LhaFunc[0] >= 102&& LhaFunc[0]<103) ? 1:0);
    FormulaVal[103]=((LhaFunc[0] >= 103&& LhaFunc[0]<104) ? 1:0);
    FormulaVal[104]=((LhaFunc[0] >= 104&& LhaFunc[0]<105) ? 1:0);
    FormulaVal[105]=((LhaFunc[0] >= 105&& LhaFunc[0]<106) ? 1:0);
    FormulaVal[106]=((LhaFunc[0] >= 106&& LhaFunc[0]<107) ? 1:0);
    FormulaVal[107]=((LhaFunc[0] >= 107&& LhaFunc[0]<108) ? 1:0);
}

bool IsLHADeterministic = 1;
fullState::fullState():loc(0){
	var= new Variables;
}

fullState::fullState(int l,const Variables &v):loc(l){
	var= new Variables(v);
}

fullState::fullState(const fullState &fs):loc(fs.loc){
	var= new Variables(*(fs.var));
}

fullState::~fullState(){delete var;}

template class LHA<abstractMarking>;
