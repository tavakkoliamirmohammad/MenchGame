#ifndef MENSCH_COMMAND_H
#define MENSCH_COMMAND_H

class Command {
public:
    virtual ~Command() = 0;

    virtual void execute() = 0;

    virtual void undo() = 0;
};

#endif //MENSCH_COMMAND_H
