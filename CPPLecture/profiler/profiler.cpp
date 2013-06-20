#include "profiler.hpp"
#include <iostream>

namespace Prof {

	const double CLOCK_TICKTIME = std::chrono::high_resolution_clock::period::num/double(std::chrono::high_resolution_clock::period::den);
	

	// ********************************************************************* //
	// ProfileStack
	// ********************************************************************* //

	void ProfileStack::push()
	{
		m_TimeStack.push(Ticks());
	}

	Ticks ProfileStack::pop( const Ticks& functionTime )
	{
		if(m_TimeStack.empty())
			return functionTime;
		Ticks tmp = m_TimeStack.top();
		m_TimeStack.pop();
		if(m_TimeStack.empty())
			return tmp;
		Ticks t2 = m_TimeStack.top();
		t2 = functionTime - t2;

		m_TimeStack.pop();
		m_TimeStack.push(t2);

		// TODO: return the time occupied in subfunctions and update the
		// parent function's counter on the stack.
		return t2;
	}
		
	ProfileStack* ProfileStack::instance = 0;

	ProfileStack& ProfileStack::getInstance() {
		if (instance == 0)
			instance = new ProfileStack();
		return *instance;
	}


	
	// ********************************************************************* //
	// ProfileCollector
	// ********************************************************************* //
	ProfileCollector::~ProfileCollector()
	{
		std::chrono::high_resolution_clock::now();
		std::cerr << "Consumed time in    " << m_function << "()   [" << m_file << "] :\n    ";
		std::cerr << (m_collectetedTime*CLOCK_TICKTIME*1000.0) << " ms    [";
		std::cerr << (m_collectetedTimeExclusive*CLOCK_TICKTIME*1000.0) << " ms]\n";
	}



	// ********************************************************************* //
	// ScopeProfiler
	// ********************************************************************* //
	ScopeProfiler::ScopeProfiler( ProfileCollector& collector ) :
			m_collector( collector )
	{
		ProfileStack& stack = ProfileStack::getInstance();
		stack.push();
	}

	ScopeProfiler::~ScopeProfiler()
	{
		
		ProfileStack& stack = ProfileStack::getInstance();
		Ticks timeSpan = (std::chrono::high_resolution_clock::now()-m_startPoint).count();
		timeSpan = stack.pop(timeSpan);
		m_collector.addTime( timeSpan, timeSpan);
	}

};