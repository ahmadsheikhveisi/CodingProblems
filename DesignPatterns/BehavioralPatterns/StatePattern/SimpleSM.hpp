
#ifndef DESIGNPATTERNS_BEHAVIORALPATTERNS_STATEPATTERN_SIMPLESM_HPP_
#define DESIGNPATTERNS_BEHAVIORALPATTERNS_STATEPATTERN_SIMPLESM_HPP_

#include <tuple>
#include <variant>

template<typename... States>
class StateMachine {
 public:
    template<typename State>
    void transitionTo() {
        currentState = &std::get<State>(states);
    }

    template<typename Event>
    void handle(const Event& event) {
        auto passEventToState = [this, &event](auto statePtr){
            statePtr->handle(event).execute(*this);
        };
        std::visit(passEventToState, currentState);
    }
 private:
    std::tuple<States...> states;
    std::variant<States*...> currentState{&std::get<0>(states)};
};

template<typename State>
struct TransitionTo{
    template<typename Machine>
    void execute(Machine& machine) {
        machine.template transitionTo<State>();
    }
};

struct Nothing {
    template<typename Machine>
    void execute(Machine&){
        std::cout << "No state!\n";
    }
};

#endif  // DESIGNPATTERNS_BEHAVIORALPATTERNS_STATEPATTERN_SIMPLESM_HPP_
