#include <utility>

#include "map"
#include "Command.h"
#include "../core/Context.h"
#include "AllProducts.h"
#include "AddItemCommand.h"
#include "SaveStateCommand.h"
#include "DeleteItemCommand.h"
#include "UpdateItemCommand.h"
#include "InvalidCommand.h"
#include "SaveProductIntoBucket.h"
#include "ShowBucketCommand.h"
#include "BuyProductsCommand.h"
#include "AllOrdersCommand.h"


class CommandContainer {
public:
    explicit CommandContainer(const Context &context) {
        initCommands(context);
        invCommand = new InvalidCommand(printAllCommands());
    }

    Command *getCommand(Request request) {
        if (commands.count(request.getCommand()) < 1) {
            return invCommand;
        }
        return (*commands.find(request.getCommand())).second;
    }

private:
    Command *invCommand;
    map<string, Command *> commands;

    void initAdminStrategy(Context context) {
        string allProducts = "--all";
        string addProduct = "--add";
        string saveState = "--state";
        string deleteProduct = "--delete";
        string updateProduct = "--update";
        Command *allProductsCommand = new AllProducts(context);
        Command *addProductCommand = new AddItemCommand(context);
        Command *saveStateCommand = new SaveStateCommand(context);
        Command *deleteProductCommand = new DeleteItemCommand(context);
        Command *updateProductCommand = new UpdateItemCommand(context);
        commands.insert(pair<string, Command *>(allProducts, allProductsCommand));
        commands.insert(pair<string, Command *>(addProduct, addProductCommand));
        commands.insert(pair<string, Command *>(saveState, saveStateCommand));
        commands.insert(pair<string, Command *>(deleteProduct, deleteProductCommand));
        commands.insert(pair<string, Command *>(updateProduct, updateProductCommand));
        string orders = "--orders";
        Command *allOrdersCommand = new AllOrdersCommand(context);
        commands.insert(pair<string, Command *>(orders, allOrdersCommand));
    }

    void initUserStrategy(Context context) {
        string allProducts = "--all";
        string saveState = "--state";
        string saveToBucket = "--saveItem";
        string showBucket = "--bucket";
        string buyAll = "--buy";
        Command *saveStateCommand = new SaveStateCommand(context);
        Command *allProductsCommand = new AllProducts(context);
        Command *saveToBucketCommand = new SaveProductIntoBucket(context);
        Command *showBucketCommand = new ShowBucketCommand(context);
        Command *buyAllCommand = new BuyProductsCommand(context);
        commands.insert(pair<string, Command *>(allProducts, allProductsCommand));
        commands.insert(pair<string, Command *>(saveState, saveStateCommand));
        commands.insert(pair<string, Command *>(saveToBucket, saveToBucketCommand));
        commands.insert(pair<string, Command *>(showBucket, showBucketCommand));
        commands.insert(pair<string, Command *>(buyAll, buyAllCommand));

    }

    void initCommands(const Context &context) {
        string strategy;
        while (true) {
            cout
                    << "Input strategy of using app.(Client or Admin. If you choose admin you have to write password, and you have only 3 attempts)"
                    << endl;
            cin >> strategy;
            if (strategy == "admin") {
                int count = 0;
                while (count < 3) {
                    string password;
                    std::cout << "Enter password" << endl;
                    std::cin >> password;
                    if (password == "root") {
                        std::cout << "You sign in like a admin!" << endl;
                        initAdminStrategy(context);
                        return;
                    } else {
                        count++;
                        std::cout << "Осталось " << 3 - count << endl;
                    }
                }
            } else if (strategy == "client") {
                std::cout << "You entered like a user!" << endl;
                initUserStrategy(context);
                return;
            }
            cout << "Invalid input" << endl;
        }
    }

    string printAllCommands() {
        string allCommands;
        for (auto &it:commands) {
            allCommands += it.second->toString();
            allCommands += "\n";
        }
        return allCommands;
    }

};


