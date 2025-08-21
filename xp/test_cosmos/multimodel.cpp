#include "EventsQueue.hpp"
#include "markingImpl.hpp"
#include "stateImpl.hpp"
#include "MultiModel.hpp"
namespace hybridVar {
}
template<typename EQT, typename M1, typename M2>
void MultiModel<EQT,M1,M2>::synchronize_fire(size_t t){
{
}

}

template<typename EQT, typename M1, typename M2>
void MultiModel<EQT,M1,M2>::synchronize_update(double ctime, size_t tr, const abstractBinding& b, EQT &EQ, timeGen &TG){
{
	m1.fire(-1992156640,b,ctime);
	m1.update(ctime, -1992156640,b,EQ,TG);
}

}

template class MultiModel<EventsQueue,SPN_orig<EventsQueue>,SKModel<EventsQueue>>;
