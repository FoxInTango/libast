#include "ASTContext.h"
using namespace foxintango;

ASTContext::ASTContext(){}
ASTContext::~ASTContext(){}

Error ASTContext::execute(){
    for(Index index = 0;index < subelements.size();index ++){
        if(subelements[index]) subelements[index]->execute(this,this);
    }

    return 0;
}

Error ASTContext::loadModule(const char* path){
    Module* module = new Module(path);

    if(module){
        ModuleInterface* interface = module->interface();
        if(interface){
            Array<ASTElementInterface*>* symbols = interface->exportVariable("AST_MODULE_SYMBOLS");

            if(symbols){
                /** insert symbols to context
                 */

                 for(Index i = 0;i < symbols->size();i ++){
                     ASTElementInterface* e = symbols->at(i);

                     if(e){
                     /** switch interface type
                      */
                     }
                 }
            }
        }
        
    }
return 1;
}