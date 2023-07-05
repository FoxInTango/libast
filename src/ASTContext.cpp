#include "ASTContext.h"
using namespace foxintango;

ASTContext::ASTContext(){}
ASTContext::~ASTContext(){}

Error ASTContext::execute(){
    return this->entry ? this->entry->execute(this,this) : Error(1,"No Entry.");
}

Error ASTContext::loadModule(const char* path){
    Module* module = new Module(path);

    if(module){
        ModuleInterface* interface = module->interface();
        if(interface){
            Array<ASTElementInterface*>* symbols = static_cast<Array<ASTElementInterface*>*>(interface->exportVariable("AST_MODULE_SYMBOLS"));

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