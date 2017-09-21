//
// Created by michael$szm on 2017/9/11.
//

#ifndef NDKPRACTISE_COMPANY_H
#define NDKPRACTISE_COMPANY_H


class Company {
private:
    int age;
    char * name;
public:
    Company();
    Company(char * name, int age);

    ~Company();

    Company(const Company & company);//拷贝函数

    void setAge(int age);
    int  getAge();

    void setName(char * name);
    char * getName();

    void workWithCompany(Company company);

    char * toString();

};


#endif //NDKPRACTISE_COMPANY_H
