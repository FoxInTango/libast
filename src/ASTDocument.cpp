#include "ASTDocument.h"
#include <libstream/libstream.h>
using namespace foxintango;

ASTDocument::ASTDocument(const ASTContext* context){ this->context = context; }
ASTDocument::ASTDocument(const ASTContext* context, const URL& url){ this->context = context; }
ASTDocument::~ASTDocument() {}