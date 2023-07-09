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
#include <libmodule/libmodule.h>
#include <libstring/libstring.h>
#include <libcpp/libcpp.h>
EXTERN_C_BEGIN
namespaceBegin(foxintango)
class ASTElement;
class ASTContext;
enum ASTSymbolType{
    ASTSymbolType_VAR,
    ASTSymbolType_OPERATOR,
    ASTSymbolType_CLASS,
    ASTSymbolType_FUNCTION
};
class foxintangoAPI ASTElementInterface {
public:
    friend class ASTContext;
protected:
    ASTSymbolType type;
    String name;
    ASTContext* context;
public:
    ASTElementInterface();
    virtual ~ASTElementInterface();
public:
    virtual ASTElement* create();// TODO -- delete
};

class foxintangoAPI ASTElementInterface_operator : public ASTElementInterface {
public:
    friend class ASTContext;
protected:
    ASTSymbolType type;
    String name;
    ASTContext* context;
public:
    ASTElementInterface_operator();
    virtual ~ASTElementInterface_operator();
public:
    virtual ASTElement* create();
};

class foxintangoAPI ASTElementInterface_class : public ASTElementInterface {
public:
    friend class ASTContext;
protected:
    ASTSymbolType type;
    String name;
    ASTContext* context;
public:
    ASTElementInterface_class();
    virtual ~ASTElementInterface_class();
public:
    virtual ASTElement* create();
};

class foxintangoAPI ASTElementInterface_function : public ASTElementInterface {
public:
    friend class ASTContext;
protected:
    ASTSymbolType type;
    String name;
    ASTContext* context;
public:
    ASTElementInterface_function();
    virtual ~ASTElementInterface_function();
public:
    virtual ASTElement* create();
};

class foxintangoAPI ASTElementInterface_variable : public ASTElementInterface {
public:
    friend class ASTContext;
protected:
    ASTSymbolType type;
    String name;
    ASTContext* context;
public:
    ASTElementInterface_variable();
    virtual ~ASTElementInterface_variable();
public:
    virtual ASTElement* create();
};

/** TODO : 处理namespace问题
 */
#define AST_SYMBOL(x) class x:public ASTElement {public:x();~x();};\
                      class x##_interface:public ASTElementInterface{public:x##_interface(){} ~x##_interface(){} virtual x* create(){ return new x();} };
#define AST_FUNCTION
#define AST_CLASS(x) class x:public ASTElement {public:x();~x();};   \
                     class x##_interface:public ASTElementInterface{ \
                         public:x##_interface(){} ~x##_interface(){} \
                         public:Array<String> members;               \
                         public:virtual x* create(){ return new x();} };
#define AST_OPERATOR
#define AST_VAR


#define AST_EXPORT(x) AST_MODULE_SYMBOLS.append(new x##_interface());
namespaceEnd
EXTERN_C_END


#endif