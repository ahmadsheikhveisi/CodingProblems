
#include <iostream>

#include "SimpleSM.hpp"

struct  OpenEvent {
};

struct CloseEvent {
};

struct ClosedState;
struct OpenState;

struct ClosedState{
    TransitionTo<OpenState> handle(const OpenEvent&) const {
        std::cout << "Opening the door.\n";
        return {};
    }
    Nothing handle(const CloseEvent&) const {
        std::cout << "Cannot close. The door is already closed.\n";
        return {};
    }
};

struct OpenState {
    Nothing handle(const OpenEvent&) const {
        std::cout << "Cannot open. The door is already open!\n";
        return {};
    }
    TransitionTo<ClosedState> handle(const CloseEvent&) const {
        std::cout << "Closing the door.\n";
        return {};
    }
};


using Door = StateMachine<ClosedState, OpenState>;

int main() {
    Door door;
    door.handle(OpenEvent{});
    door.handle(CloseEvent{});
    door.handle(CloseEvent{});
    door.handle(OpenEvent{});
    door.handle(OpenEvent{});

    return 0;
}