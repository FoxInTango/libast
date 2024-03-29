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

// block -- block pair
// numbers texts
// function
// class

#ifndef _AST_ELEMENT_H_
#define _AST_ELEMENT_H_
#include "ASTDebug.h"
#include "ASTDefines.h"
#include <libstring/libstring.h>
#include <libcpp/libcpp.h>
/**
 *
 */
EXTERN_C_BEGIN
namespaceBegin(foxintango)

typedef unsigned int ASTElementType;

const ASTElementType ASTElementType_Element    = 0;
const ASTElementType ASTElementType_Operator   = 1;
const ASTElementType ASTElementType_Scope      = 2;
const ASTElementType ASTElementType_Expression = 3;
const ASTElementType ASTElementType_Function   = 4;
const ASTElementType ASTElementType_Class      = 5;
const ASTElementType ASTElementType_MAX        = 1024;

/** TODO
 * ASTDefaultClasses 
 * ASTDefaultOperators
 * ASTDefaultFunctions
 * ASTDefaultVars
 */

/**
 * 元素识别 : language :: namespace :: name 
 */
class foxintangoAPI ASTElement {
public:
    friend class ASTContext;
public:
    //enum TYPE{};
public:
/*
    union {
        ASTDebug debug;
    } debug;
*/

//ASTDebug debug;
protected:
    /** Debug Infomation
     */
    Member<String> ns;
    Member<String> name;
    Member<String> language;
    Member<ASTElementType> type;
    //Map<String,ASTElement*> members;
    //template <class String> ASTElement* member();
public:
    ASTElement();
    virtual ~ASTElement();
public:
public:
    virtual Size appendSubelement(ASTElement* element);
    virtual Size removeSubelement(ASTElement* element);
    virtual Size removeSubelement(const Index& index);

    virtual Error insertMember(ASTElement* element,const String& name);
    virtual Error removeMember(const String& name);
protected:
    //Error executeInternal(const ASTContext* context, const ASTElement* caller);
public:
    /** must be called by subclasses
     *  return error  -- perfermence : ASTContext.errorStack;
     */
    virtual Error execute(const ASTContext* context,const ASTElement* caller);
    //virtual void execute(const ASTContext* context, const ASTElement* caller);
};

/** TODO begin:
 *  move to ast_standard_module
 */
class ASTBool   :public ASTElement{};
class ASTString :public ASTElement{};
class ASTNumber :public ASTElement{};
class ASTArray  :public ASTElement{};

class ASTOperator :public ASTElement{};
class ASTOperatorUnary :public ASTElement{};
class ASTOperatorBinary :public ASTElement{};
class ASTOperatorTernary : public ASTOperator{};

class ASTAssign    :public ASTOperatorBinary {};
class ASTAddAssign :public ASTOperatorBinary {};
class ASTSubAssign :public ASTOperatorBinary {};
class ASTMulAssign :public ASTOperatorBinary {};
class ASTDivAssign :public ASTOperatorBinary {};
class ASTModAssign :public ASTOperatorBinary {};

class ASTAdd :public ASTOperatorBinary {};
class ASTSub :public ASTOperatorBinary {};
class ASTMul :public ASTOperatorBinary {};
class ASTDiv :public ASTOperatorBinary {};
class ASTMod :public ASTOperatorBinary {};

/** 参考 https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/operators/boolean-logical-operators
 */
// logic
class ASTLogicAnd :public ASTOperatorBinary {};
class ASTLogicNot :public ASTOperatorBinary {};
class ASTLogicOr  :public ASTOperatorBinary {};

// bits
class ASTBitAnd :public ASTOperatorBinary {};
class ASTBitNot :public ASTOperatorBinary {};
class ASTBitOr  :public ASTOperatorBinary {};
class ASTBitXor :public ASTOperatorBinary {};

class ASTBitShiftLeft  :public ASTOperatorUnary{};
class ASTBitShiftRight :public ASTOperatorUnary{};

class ASTNE :public ASTOperatorBinary {};// not equal
class ASTEQ :public ASTOperatorBinary {};// equal 
class ASTGT :public ASTOperatorBinary {};// greater
class ASTGE :public ASTOperatorBinary {};// greater or equal
class ASTST :public ASTOperatorBinary {};// smaller 
class ASTSE :public ASTOperatorBinary {};// smaller or equal

// 条件运算符
class ASTCondition :public ASTOperatorTernary{};

/** TODO end:
 *  move to ast_standard_module
 */

class ASTCallArgument{
public:
    /** 参数传递类型
     * PT_VAL 按值传递
     * PT_FEF 引用传递
     */
    enum PassType{PT_VAL,PT_REF};
protected:
    enum PassType passBy;
    /** 参数类型 -- 类型名
     * 
     */
    String type;
};
class ASTCallName;
class ASTCall :public ASTElement {
public:
    ASTElement* target;
    Array<ASTCallArgument> arguments;
public:
    ASTCall();
    ASTCall(const ASTCallName& name);
public:
    operator ASTCallName();
};

class ASTCallName :public ASTElement{
public:
    String target;
    Array<ASTCallArgument> arguments;
public:
    ASTCallName();
    ASTCallName(const ASTCall& call);
public:
    operator ASTCall();
};

class ASTReturn   :public ASTElement {
protected:
    ASTScope* scope;// return to this scope
};/** jump to higher level.function only.*/
class ASTBreak    :public ASTElement {};
class ASTContinue :public ASTElement {};

class ASTScope :public ASTElement {
public:
    ASTScope* super;
    //Array<ASTElement*> symbols;
    Map<String,ASTElement*> symbolMap;
    Array<ASTElement*> subelements;
public:
    ASTScope();
    virtual ~ASTScope();
public:
    /** must be called by subclasses
         */
    virtual Error execute(const ASTContext* context, const ASTElement* caller);
};/** () | {} */
class ASTExpression :public ASTScope {};

class ASTFunction :public ASTScope {};
class ASTSwitch :public ASTScope {};/** if | switch */
class ASTCase:public ASTScope {};
class ASTFor :public ASTScope {};
class ASTWhile :public ASTScope {};
class ASTDo :public ASTScope {};
class ASTIn :public ASTScope {};
class ASTTry :public ASTScope {};
class ASTCatch :public ASTScope {};

class ASTClass :public ASTScope {};// members / methods

class ASTNew :public ASTElement {};
class ASTDel :public ASTElement {};
class ASTMemberOf :public ASTElement {};

class ASTSizeOf :public ASTElement{};
class ASTTypeOf :public ASTElement{};

namespaceEnd
EXTERN_C_END
#endif