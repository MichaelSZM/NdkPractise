//
// Created by michael$szm on 17/9/9.
//

#ifndef NDKPRACTISE_COMPUTER_H
#define NDKPRACTISE_COMPUTER_H


class ComPuter {

private:
    char * cpu;
    char * display;
    char * name;
    int age;

public:
    void setCpu(char * cpu);

    char * getCpu();

    void setName(char * name);

    char * getName();


    void setCPU();
};


#endif //NDKPRACTISE_COMPUTER_H
