#include <utility>

#include "../commands/CommandContainer.h"
#include "Request.h"

using namespace std;

class Controller {
public:
    explicit Controller(Context context) {
        container = new CommandContainer(context);
    }

    string executeCommand(string req) {
        Request request = Request(req);
        Command *command = container->getCommand(request);
        return command->execute(request);
    }

private:
    CommandContainer *container;
};

