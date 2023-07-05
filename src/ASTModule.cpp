#include "ASTModule.h"
using namespace foxintango;

ASTElementInterface::ASTElementInterface(){}
ASTElementInterface::~ASTElementInterface(){}
ASTElement* ASTElementInterface::create() { return 0; }