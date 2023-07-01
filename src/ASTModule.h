/** MIT License

Copyright(c) 2022 FoxInTango <foxintango@yeah.net>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this softwareand associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef _AST_MODULE_H_
#define _AST_MODULE_H_
#include "ASTElement.h"
#include <libmodule/libmodule.h>
EXTERN_C_BEGIN
namespaceBegin(foxintango)
class foxintangoAPI ASTModuleInterface :public ModuleInterface {
public:
    ASTModuleInterface();
    virtual ~ASTModuleInterface();
public:
    virtual bool  containClass(const char* name);
    virtual void* createObject(const char* name, const Model& model = Model());

    virtual bool  containFunction(const char* name);
    virtual void* exportFunction(const char* name);

    virtual bool containVariable(const char* name);
    virtual void* exportVariable(const char* name);
public:
    Error insertSymbol(ASTElement* element,const String& name);
    Error removeSymbol(const String& name);
    ASTElement* sysmbolWithName(const String& name);

};
#define AST_SYMBOL_EXPORT(x) class x:public ASTElement {public:x();~x();};\
                             class x##_interface{public:x##_interface();~x##_interface();x* create(){ return new x();} };\
                             extern ASTModuleInterface MODULE_INTERFACE_INSTANCE;\
                             MODULE_INTERFACE_INSTANCE.insertSymbol(new x_interface(),"");

namespaceEnd
EXTERN_C_END
#endif