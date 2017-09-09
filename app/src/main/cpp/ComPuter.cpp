//
// Created by michael$szm on 17/9/9.
//
#include <iostream>
#include "ComPuter.h"

void ComPuter::setCpu(char * cpu){
    this ->cpu = cpu;
}

char * ComPuter::getCpu(){
    return this ->cpu;
}

void ComPuter::setName(char * name){
    this ->name = name;
}

char * ComPuter::getName(){
    return this ->name;
}