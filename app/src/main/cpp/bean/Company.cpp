//
// Created by michael$szm on 2017/9/11.
//

#include "Company.h"
#include <iostream>
#include <android/log.h>

using namespace std;

Company::Company() {
    this->name = "tz";
    this->age = 100;
}

Company::Company(char *name, int age) {
    this->name = name;
    this->age = age;
}


Company::~Company() {
    __android_log_print(ANDROID_LOG_INFO,"main","调用了析构函数");
}

//重写该方法之后，变为深拷贝
Company::Company(const Company &company) {
    this->name = company.name;
    this->age = company.age;
    __android_log_print(ANDROID_LOG_INFO,"main","调用了拷贝函数");
}

void Company::setAge(int age) {
    this->age = age;
}

int Company::getAge() {
    return this->age;
}


void Company::setName(char *name) {
    this->name = name;
}

char* Company::getName() {
    return this->name;
}

char* Company::toString() {
    return this->name += this->age;
}

void Company::workWithCompany(Company company) {
    __android_log_print(ANDROID_LOG_INFO,"main","%s和%s合作",this->name,company.name);
}