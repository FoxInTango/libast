#ifndef _AST_MATCH_H_
#define _AST_MATCH_H_

/** ASTMatch ASTToken ASTBlock
 *              type     type
 *              name     name
 * 
 *  功能:
 *  一，匹配:校验目标序列是否符合指定规则
 *  二，查找:于目标序列中查找符合指定规则的子序列
 * 
 *  概念:
 *  元素与序列：元素是一个泛型概念，它指同类型事物所构成的集合中的单一个体。元素序列是指由该事物所构成的集合的数组型排列。
 *  元素分为位置元素和模式元素。
 *  位置元素:是指在某一个序列中位置的序号，由数值或由指代位置数值的符号和表达式构成。
 *  模式元素:是指由该类型事物的单体、复合体，或经表达式描述所构成的复合体。
 *  变量:变量代表了单个元素或者元素序列，变量之间支持相应的序列运算。
 * 
 *  序列特征--如何描述:
 *  基本特征：
 *      一，长度特征
 *      二，含有特征
 *             序列某位置
 *                 含有某元素集合中的N个元素
 *                     有且有其N:
 *                         有且有其N以上
 *                         有且仅有N以下
 *                         有A则在某范围无 ... 斥关系
 *                         有A则在某范围有 ... 友关系
 *                         无A则在某范围无 ...
 *                         无A则在某范围有 ...
 *                 含有特征重复次数 0 1 2  ...
 *       三，顺序特征
 *               符合特征A的部分处，符合特征B的部分必相对偏移[向前偏移|向后偏移]
 *                   特殊:符合特征A,B,C的排序必为 A B C
 *               
 *  复合特征:
 *      指定范围内，于符合特征的位置的某一相对位置符合另一特征
 * 
 *  模式元素
 *      自然元素
 *      根据描述定义元素
 * 
 *  位置元素
 *      自然元素
 *      根据描述定义元素
 * 
 *  序列定义与序列运算
 *      自然序列
 *      自定序列
 *  序列通过[]包含,例如 -- 位置元素序列:[0,1,2,3] ，模式元素序列:[x,y,z]
 *  序列与序列之间可以通过运算生成新序列，序列运算包括: 并集运算、交集运算、补集运算。运算符: 
 * 
 *  模式与模式匹配
 * 
 *  变量
 * 
 *  行为:匹配,查找,追加,插入,删除,分割
 * 
 *  1,字母 : [a - z]
 *           [A - Z]
 *  2,数字 : [0 - 9]
 *  3,符号 : [ ~ ` ! @ # $ % ^ & * ( ) - = _ + , . ; : ' " [ ] { } < > ? / | \ ]
 *  4,制表符
 *  5,控制符
 *  内置序列:https://baike.baidu.com/item/ASCII/309296
 *     位置序列  : int     [-∞ -- +∞]
 *     符号序列  : char    [' ' - '/'] [':' - '@'] ['[' - '`'] ['{' - '~']
 *     字母序列  : char    ['A' - 'Z'] ['a' - 'z']
 *     数符序列  : char    ['0' - '9']
 *     字符序列[待定] : wchar_t [0 - 2^32]
 *     
 * 
 *  location=@[2323,3223,[2,3,4,5]]
 *  location=
 *  index=[a-b,c-w,0-9]
 *  @+2022:
 *  @-2022:
 *  @|+2022:
 *  @|-2022:
 *  @|1/3-2022:
 *  @>=2022:
 *  @<=2022:
 *  @[0-2 | -2,3-7,8-]:
 *                                                           
 *  @*:[ 20 : a - z / h - w >= 2,a == 3,b < 5] & [0 - 5 < 2] & [xy,ab,cd,xy*,*xy,xy[a,b,c,index]] < 5 | index > 2;
 *  20@*:[ a - z / h - w >= 2 ,a == 3,b < 5] & [0 - 5 < 2] & [xy,ab,cd,xy*,*xy,xy[a,b,c,index]] < 5 | index > 2;
 *
 */

/** ASTMatchVar
 * 
 */

/** ASTMatchMode
 * 
 */

/** ASTMatchOperator 
 *  序列结合运算符： 
 *  并集:|
 *  交集:&
 *  差集:/
 * 
 *  匹配条件运算符：
 *  ==
 *  !=
 *  >=
 *  <=
 *  >
 *  <
 * 
 *  模式结合运算符
 *  & 并且
 *  | 或者
 *  / 
 */

// ASTMatchRange 

typedef struct _AST_MATCH_ERROR{
    typedef enum _ast_match_error_type{}ast_match_error_type;
    ast_match_error_type type;
    char* error;
}AST_MATCH_ERROR;

class ASTMatchElementImplement;

class ASTMatchElement {
protected:
    ASTMatchElement* m_super;
public:
    typedef enum _AST_MATCH_ELEMENT_TYPE {
        AST_MATCH_ELEMENT_TYPE_sequence
    }AST_MATCH_ELEMENT_TYPE;
    typedef enum _AST_MATCH_LOAD_STATUS {
        AST_MATCH_LOAD_STATUS_BAD_ELEMENT = -1,
        AST_MATCH_LOAD_STATUS_UNSURE,
        AST_MATCH_LOAD_STATUS_OK
    }AST_MATCH_LOAD_STATUS;
public:
    AST_MATCH_ELEMENT_TYPE type;
public:
    ASTMatchElementImplement* implement;
public:
    ASTMatchElement();
   ~ASTMatchElement();
public:
    ASTMatchElement* super();
public:
    bool eol(const wchar_t& value);
    bool letter(const wchar_t& value);
    bool arabic(const wchar_t& value);
public:
    virtual int loadMode(const wchar_t* mode, unsigned int& index, const unsigned int& size);
    virtual int pushError(const AST_MATCH_ERROR& error);
};

class ASTMatchSequence;
class ASTMatchOperator;
class ASTMatchRange;
class ASTMatchMode;
class ASTMatchCondition;

class ASTMatch :public ASTMatchElement {
public:
    ASTMatch();
    ~ASTMatch();
public:
    bool match(const char* target, const unsigned int& size, const char* mode = 0) {
        return 0;
    }

    int lookup() { return 0; }
    int append() { return 0; }
    int split()  { return 0; }
    int remove() { return 0; }
    int replace(){ return 0; }
public:
    int makeMode(const char* mode, unsigned int& index, const unsigned int& size);
public:
    virtual int loadMode(const wchar_t* mode, unsigned int& index,const unsigned int& size);
    virtual int pushError(const AST_MATCH_ERROR& error);
};
#endif