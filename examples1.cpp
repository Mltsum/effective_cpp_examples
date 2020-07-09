#include <iostream>
#include <array>
#include <memory>

/*
 *  知识点1 : 函数签名
 *  知识点2 : explicit的优点是可以避免不合时宜的类型变换.
 *      注意: 该意思并不是说不允许构造函数进行类型转换，如下例1
 *      effective c++ 不推荐这种隐式类型转换
 *
 */

#include <io.h>
#include <string>

/*
 * 函数签名
 */
std::size_t func(int var);

/*
 * 例1
 */
class B{
public:
    B(int x){

    }
};

class C{
public:
    explicit C(int x) {
        m_x = x;
    }

public:
    int m_x;
};

/*
 * 例2:
 * 隐式转换：可以用单个实参来调用的构造函数定义了从形参类型到该类类型的一个隐式转换。
 */
class things{
public:
    things(const std::string&name =""):m_name(name),height(0),weight(10){}
//    explicit things(const std::string&name =""):m_name(name),height(0),weight(10){}
    int CompareTo(const things & other);

    std::string m_name;
    int height;
    int weight;
};

int main(){
    int x = 5;
    float f = 5.1;
    B b_obj(x);
    C c_obj(f);     // 误解:其并不是说生命了explicit就不允许进行类型转换
    std::cout << c_obj.m_x << std::endl;

    // 隐式类型转换
    things a;
    std::string num = "book";
    /*
     * 一个string类型对象作为实参传给things的CompareTo函数。这个函数本来是需要一个tings对象作为实参。现在编译器使用string nm来构造并初始化一个
     * things对象，新生成的临时的things对象被传递给CompareTo函数，并在离开这段函数后被析构。
     */
    int result = a.CompareTo(num);

    /*
     * 如果不想这种隐式类型转换，就声明explicit
     */
//    int result = a.CompareTo(num);

}