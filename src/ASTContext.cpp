#include "ASTContext.h"
using namespace foxintango;

/**
 * Errors
 *   code :
 *   desc :
 */

ASTContext::ASTContext(){}
ASTContext::~ASTContext(){}

Error ASTContext::execute(){
    /** 全域
     */
    return this->symbolMap[this->entry] ? this->symbolMap[this->entry]->execute(this, this) : 1;
    return 0;
}

Error ASTContext::execute(const ASTContext* context,const ASTElement* caller){
    return 0;
}

Error ASTContext::loadModule(const char* path){
    Module* module = new Module(path);

    if(module){
        ModuleInterface* interface = module->interface();
        if(interface){
            std::vector<ASTElementInterface*>* symbols = static_cast<std::vector<ASTElementInterface*>*>(interface->exportVariable("AST_MODULE_SYMBOLS"));

            if(symbols){
                /** insert symbols to context
                 */

                 for(Index i = 0;i < symbols->size();i ++){
                     ASTElementInterface* e = symbols->at(i);

                     if(e){
                     e->context = this;
                     /** switch interface type
                      */
                     }
                 }
            }
        }
        
    }
return 1;
}
