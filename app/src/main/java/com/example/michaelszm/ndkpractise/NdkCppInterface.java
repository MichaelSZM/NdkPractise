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


}
