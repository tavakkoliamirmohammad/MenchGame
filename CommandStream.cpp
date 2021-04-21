#include "CommandStream.h"

void CommandStream::push(Command *command) {
    commands_.push(command);
}

Command *CommandStream::pop() {
    if (commands_.empty()) return nullptr;

    auto command = commands_.front();
    commands_.pop();

    return command;
}

