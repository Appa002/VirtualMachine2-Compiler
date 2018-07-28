//
// Created by a_mod on 29.07.2018.
//

#ifndef VM2_0_COMPILER_PIPES_H
#define VM2_0_COMPILER_PIPES_H

namespace compiler::utils{
    template<class F>
    struct pipe_closure : F {
        template<class... Xs>
        pipe_closure(Xs&&... xs) : F(std::forward<Xs>(xs)...)
        {}
    };
}

template <class T, class F>
decltype(auto) operator| (T&& x, const compiler::utils::pipe_closure<F>& p){
    return p(std::forward<T>(x));
};

#endif //VM2_0_COMPILER_PIPES_H
