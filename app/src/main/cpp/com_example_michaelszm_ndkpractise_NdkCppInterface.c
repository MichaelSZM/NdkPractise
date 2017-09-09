//
// Created by michael$szm on 17/9/9.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <android/log.h>
#include "com_example_michaelszm_ndkpractise_NdkCppInterface.h"


JNIEXPORT void JNICALL Java_com_example_michaelszm_ndkpractise_NdkCppInterface_TestConst
(JNIEnv *, jobject){

    const int  a= 100;
    int  * p = &a;
    *p =200;
    __android_log_print(ANDROID_LOG_INFO,"main","c中修改后的值 %d",a);

}
