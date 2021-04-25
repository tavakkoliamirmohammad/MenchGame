#ifndef MENSCH_COMMANDSTREAM_H
#define MENSCH_COMMANDSTREAM_H

#include <queue>
#include "Command.h"

using namespace std;

class CommandStream {
public:
    void push(Command *command);

    Command *pop();

private:
    queue<Command *> commands_;
};

#endif //MENSCH_COMMANDSTREAM_H
