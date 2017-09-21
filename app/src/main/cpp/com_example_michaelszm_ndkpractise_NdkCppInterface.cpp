//
// Created by michael$szm on 17/9/9.
//
#include <iostream>
#include <malloc.h>
#include "android/log.h"
#include "com_example_michaelszm_ndkpractise_NdkCppInterface.h"

using namespace std;


JNIEXPORT void JNICALL Java_com_example_michaelszm_ndkpractise_NdkCppInterface_TestConst
(JNIEnv * env, jobject  obj){

    const int a = 100;
    int  * p = (int *) &a;
    *p = 200;
    __android_log_print(ANDROID_LOG_INFO,"main","修改后的值 %d",a);
}


struct User{
    char * name;
    int age;
};

void update_user(User ** pUser){
    User *user = (User *) malloc(sizeof(User));
    user ->name = "MichaelSZM";
    user ->age = 23;
    *pUser = user;
}

void update_user(User * &pUser){
    User *user = (User *) malloc(sizeof(User));
    user ->name = "Michael";
    user ->age = 23;
    pUser = user;
}


JNIEXPORT void JNICALL Java_com_example_michaelszm_ndkpractise_NdkCppInterface_testPointer
        (JNIEnv * env, jobject jobj){
    User * user = NULL;
    update_user(&user);
    __android_log_print(ANDROID_LOG_INFO,"main","--C++中指针测试结果 %s",user->name);
    update_user(&user);
    __android_log_print(ANDROID_LOG_INFO,"main","--C++中指针测试结果 %s",user->name);
}



void const_init(){
    int a = 100;
    int b = 200;
    //常引用写法   const int &c
    //引用写法   &c
    const int &c = a;
    __android_log_print(ANDROID_LOG_INFO,"main","变量a的值 %d",a);
}


struct Company1{
    char * name;
    char * address;
    int age;
} company;



void const_func_params(const Company1 &cp){
    //不能修改,只能读取
//    cp .name = "jjj";
    __android_log_print(ANDROID_LOG_INFO,"main","公司名字 %s",cp.name);
}


JNIEXPORT void JNICALL Java_com_example_michaelszm_ndkpractise_NdkCppInterface_testConstReference
        (JNIEnv * env, jobject jobj){
    const_init();
    company.name = "小时代xxx";
    company.address ="xxxx省";
    const_func_params(company);
}



#define GET_RESULT(A) A*A

void printf_result(int a){
    int  b = GET_RESULT(a);
    __android_log_print(ANDROID_LOG_INFO,"main","宏结果:%d",b);
}

//内联函数(inline),执行效率比一般函数高
//程序编译的时候,编译器将函数调用处的代码替换成函数体
//宏定义:预编译
__inline int get_result(int a){
    return a * a;
}


//c++中的可变参数
void func_params(int a , ...){
    __android_log_print(ANDROID_LOG_INFO,"main","宏结果:%d",a);
    //获取可变参数
    //定义可变参数指针
    va_list args_p;
    //首先要指定可变参数开始的位置
    va_start(args_p,a);
    //中间按照顺序,拿去对应类型的数据
//    int arg_int = va_arg(args_p, int);
    //结束
    va_end(args_p);
}


//函数预留参数
void func_params(int a , int){

}

JNIEXPORT void JNICALL Java_com_example_michaelszm_ndkpractise_NdkCppInterface_inlineFuncTest
        (JNIEnv * env, jobject  jobj){
    int  a =2 ;
    printf_result(a++);
    int  b = get_result(a++);
    __android_log_print(ANDROID_LOG_INFO,"main","内联结果:%d",b);
    func_params(10,2);
    func_params(12);
    func_params(12,10);
}

int getMin(int a, int b){
    return a < b ? a: b;
}


//函数指针别名
typedef int(*GET_MIN_P)(int, int);

JNIEXPORT void JNICALL Java_com_example_michaelszm_ndkpractise_NdkCppInterface_funcPointerTest
        (JNIEnv *env, jobject jobj){
    //函数指针
    int (*get_min_p)(int, int) = getMin;
    int  c = get_min_p(2,3);
    __android_log_print(ANDROID_LOG_INFO,"main","最小值:%d",c);


    GET_MIN_P p  = getMin;
    int result = p(3,4);
    __android_log_print(ANDROID_LOG_INFO,"main","最小值:%d",result);
}



//c++中的类的定义
#include "ComPuter.h"

JNIEXPORT void JNICALL Java_com_example_michaelszm_ndkpractise_NdkCppInterface_cppClassTest
        (JNIEnv * env, jobject jobj){
    ComPuter cOmputer ;
    cOmputer.setCpu("inter");
    cOmputer.setName("海尔");
    __android_log_print(ANDROID_LOG_INFO,"main","name:%s,cpu:%s",cOmputer.getName(),cOmputer.getCpu());

    ComPuter * cOmputer_p = new ComPuter();
    cOmputer_p->setName("华硕");
    cOmputer_p->setCpu("inter");
    __android_log_print(ANDROID_LOG_INFO,"main","name:%s,cpu:%s",cOmputer_p->getName(),cOmputer_p->getCpu());
}


#include "bean/Company.h"

/**
 * 构造方法练习
 */
JNIEXPORT void JNICALL Java_com_example_michaelszm_ndkpractise_NdkCppInterface_testConstructor
        (JNIEnv * env, jobject jobj){

    Company company1;
    __android_log_print(ANDROID_LOG_INFO,"main","结果：%s",company1.toString());

    Company company2("黄埔军校",50);
    __android_log_print(ANDROID_LOG_INFO,"main","结果：%s",company2.toString());

    Company company3 = Company("耶鲁大学",60);
    __android_log_print(ANDROID_LOG_INFO,"main","结果：%s",company3.toString());

}


/**
 * 析构函数练习
 * 对象释放的时候触发
 */
JNIEXPORT void JNICALL Java_com_example_michaelszm_ndkpractise_NdkCppInterface_testDestruct
        (JNIEnv * env, jobject jobj){
    Company company1("tz",100);
    __android_log_print(ANDROID_LOG_INFO,"main","结果：%s",company1.toString());

    //new关键字创建的对象，需要手动调用析构函数
    Company * company2 = new Company("xxxx",80);
    company2->~Company();
    __android_log_print(ANDROID_LOG_INFO,"main","结果：%s",company2->toString());
}


/**
 * 拷贝函数练习
 */
JNIEXPORT void JNICALL Java_com_example_michaelszm_ndkpractise_NdkCppInterface_testCopyFunc
        (JNIEnv * env, jobject jobj){
    Company company1("tz",100);
    Company company2 = company1;

    Company company3("yyyy",20);
    Company company4("mmmmm",30);
    company4 = company3;
}



JNIEXPORT void JNICALL Java_com_example_michaelszm_ndkpractise_NdkCppInterface_testCopyFuncScence
        (JNIEnv * env, jobject jobject1){

    //1
    Company company1("tz",100);
    Company company2 = company1;

    //2
    Company company3("科大讯飞",80);
    company3.workWithCompany(company1);

    //3
    Company company4(company1);

}





