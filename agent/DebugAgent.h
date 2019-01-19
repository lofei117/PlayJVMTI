#include "jvmti.h"

class AgentException 
{
 public:
	AgentException(jvmtiError err) {
		m_error = err;
	}

	char* what() const throw() { 
		return "AgentException"; 
	}

	jvmtiError ErrCode() const throw() {
		return m_error;
	}

 private:
	jvmtiError m_error;
};


class DebugAgent
{
 public:

	DebugAgent() throw(AgentException){}

	~DebugAgent() throw(AgentException);

	void Init(JavaVM *vm) const throw(AgentException);

	void ParseOptions(const char* str) const throw(AgentException);
        
	void AddCapability() const throw(AgentException);
        
	void RegisterEvent() const throw(AgentException);

//	void SetBreakpoint(JavaVM *vm, const char* str) const throw(AgentException);
    
	static void JNICALL HandleMethodEntry(jvmtiEnv* jvmti, JNIEnv* jni, jthread thread, jmethodID method);

	static void JNICALL HandleDebugMethodEntry(jvmtiEnv* jvmti, JNIEnv* jni, jthread thread, jmethodID method, jlocation location);

 private:
	static void CheckException(jvmtiError error) throw(AgentException)
	{
		// 可以根据错误类型扩展对应的异常，这里只做简单处理
		if (error != JVMTI_ERROR_NONE) {
			throw AgentException(error);
		}
	}

	static jvmtiEnv * m_jvmti;
	static char* m_filter;
};
