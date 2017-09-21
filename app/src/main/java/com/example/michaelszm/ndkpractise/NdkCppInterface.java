package com.example.michaelszm.ndkpractise;

/**
 * Created by michaelszm on 17/9/9.
 */

public class NdkCppInterface {


    /**
     * 测试常量是否可以修改
     */
    public native void TestConst();


    public native void testPointer();

    public native void testConstReference();


    /**
     * 内联函数测试
     */
    public native void inlineFuncTest();

    /**
     * 函数指针
     */
    public native void funcPointerTest();

    public native void cppClassTest();

    /**
     * 构造函数测试
     */
    public native void testConstructor();

    /**
     * 析构函数的练习
     */
    public native void testDestruct();

    /**
     * 函数的拷贝和赋值运算
     */
    public native void testCopyFunc();

    /**
     * c++中拷贝函数调用场景
     */
    public native void testCopyFuncScence();


}
