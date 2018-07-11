#ifndef _RAGEL_LIB_H_
#define _RAGEL_LIB_H_

#ifndef _RAGEL_DLL_H_
#ifdef RAGELDLL_API
#undef RAGELDLL_API
#endif
#define RAGELDLL_API
#endif

#ifdef WIN32
#pragma comment(lib, "psapi.lib")
#endif

#include <iostream>

using namespace std;

class DFA
{
public:
    class State
    {
    public:
        State()
        {
            isStart = false;
            isEntry = false;
            isFinal = false;
            isDead  = true;
            memset(next, -1, sizeof(next));
            
            data = NULL;
        }
        
        ~State()
        {
        }
        
        bool isStart;
        bool isEntry;
        bool isFinal;
        bool isDead;
        int next[256];
        
        void * data;
    };
    
    DFA()
    {
        stateNum = 0;
        startState = 0;
        state = NULL;
    }
    
    ~DFA()
    {
        if(state != NULL)
        {
            delete []state;
        }
    }
    
    int stateNum;
    int startState;
    State * state;
};

/*
DFA�������ַ�Ϊ8λ�޷���������256������״̬���Ϊ32λ�з������������д��ڻ����0��ʾ��Ч״̬��С��0��ʾ��Ч״̬��
�������dfaָ������ݽṹ��ʹ����֮����Ҫ���û���delete������ͷš�
����ֵ���ڻ����0��ʾִ�гɹ���С��0��ʾִ��ʧ�ܡ�
*/
RAGELDLL_API int generateDfa(const char * cmd, istream & in, ostream & out, DFA * dfa);

RAGELDLL_API ostream & operator<<(ostream & out, const DFA & dfa);

#endif
