#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class World
{
public:
    vector <string> values;
public:
    World() {}
    ~World() {}
    virtual void print() 
    {   
        for (auto d : values)
        {
            printf("%s\n", d.c_str());
        }
    }
};

class Country : public World
{
    //�Ӽ� / Attribute / Property
public:
    //string Code, Name, Continent, Region, SurfaceArea;
    //string IndepYear, Population, LifeExpectancy, GNP, GNPOld;
    //string LocalName, GovernmentForm, HeadOfState, Capital, Code2;

    //�Լ� / Function / Method
public:  //�ۺ� ������ ����Ʈ�� private
    Country()
    {
        /*Code = Name = Continent = Region = SurfaceArea = "";
        IndepYear = Population = LifeExpectancy = GNP = GNPOld = "";
        LocalName = GovernmentForm = HeadOfState = Capital = Code2 = "";*/
    } //������
    ~Country() {} //�Ҹ���
};

class City : public World
{
    //�Ӽ� / Attribute / Property
public:
    //string ID, Name, CountryCode, District, Population;


    //�Լ� / Function / Method
public:  //�ۺ� ������ ����Ʈ�� private
    City(){} //������
    ~City() {} //�Ҹ���
};

class CountryLang : public World
{
    //�Ӽ� / Attribute / Property
public:
    //string CountryCode, Language, IsOfficial, Percentage;


    //�Լ� / Function / Method
public:  //�ۺ� ������ ����Ʈ�� private
    CountryLang()
    {
        //CountryCode = Language = IsOfficial = Percentage = "";

    } //������
    ~CountryLang() {} //�Ҹ���
};

