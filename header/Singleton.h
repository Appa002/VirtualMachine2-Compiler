//
// Created by a_mod on 25.07.2018.
//

#ifndef VM2_0_COMPILER_SINGLETON_H
#define VM2_0_COMPILER_SINGLETON_H

#include "ErrorFlags.h"

namespace compiler::utils{

    template <class T>
    class Singleton {
    public:
        Singleton() = default;

    private:
        static T* instance;

    public:
        static T& get(){
            if(instance == nullptr)
                instance = new T();
            return *instance;
        }

        static void del(){
            if(instance == nullptr)
                delete instance;
        }
    };
}

template <class T> T* compiler::utils::Singleton<T>::instance = nullptr;



#endif //VM2_0_COMPILER_SINGLETON_H
