#include <iostream>

#include "DebugAgent.h"
#include "jvmti.h"

using namespace std;

JNIEXPORT jint JNICALL Agent_OnLoad(JavaVM *vm, char *options, void *reserved)
{
    cout << "Agent_OnLoad(" << vm << ")" << endl;
    try{
        
        DebugAgent* agent = new DebugAgent();
		agent->Init(vm);
		agent->ParseOptions(options);
        agent->AddCapability();
        agent->RegisterEvent();

    } catch (AgentException& e) {
        cout << "Error when enter HandleMethodEntry: " << e.what() << " [" << e.ErrCode() << "]" << endl;
		return JNI_ERR;
	}
    
	return JNI_OK;
}

JNIEXPORT void JNICALL Agent_OnUnload(JavaVM *vm)
{
    cout << "Agent_OnUnload(" << vm << ")" << endl;
}



JNIEXPORT jint JNICALL Agent_OnAttach(JavaVM *vm, char *options,
    void *reserved) 
{
    cout << "Agent_OnAttach(" << vm << ")" << endl;

	try{

	    DebugAgent* agent = new DebugAgent();
		agent->Init(vm);
//	    agent->SetBreakpoint(vm, options);

	} catch (AgentException& e) {
	    cout << "Error when enter HandleMethodEntry: " << e.what() << " [" << e.ErrCode() << "]" << endl;
		return JNI_ERR;
	}

    return JNI_OK;

}