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
    //속성 / Attribute / Property
public:
    //string Code, Name, Continent, Region, SurfaceArea;
    //string IndepYear, Population, LifeExpectancy, GNP, GNPOld;
    //string LocalName, GovernmentForm, HeadOfState, Capital, Code2;

    //함수 / Function / Method
public:  //퍼블릭 없으면 디폴트가 private
    Country()
    {
        /*Code = Name = Continent = Region = SurfaceArea = "";
        IndepYear = Population = LifeExpectancy = GNP = GNPOld = "";
        LocalName = GovernmentForm = HeadOfState = Capital = Code2 = "";*/
    } //생성자
    ~Country() {} //소멸자
};

class City : public World
{
    //속성 / Attribute / Property
public:
    //string ID, Name, CountryCode, District, Population;


    //함수 / Function / Method
public:  //퍼블릭 없으면 디폴트가 private
    City(){} //생성자
    ~City() {} //소멸자
};

class CountryLang : public World
{
    //속성 / Attribute / Property
public:
    //string CountryCode, Language, IsOfficial, Percentage;


    //함수 / Function / Method
public:  //퍼블릭 없으면 디폴트가 private
    CountryLang()
    {
        //CountryCode = Language = IsOfficial = Percentage = "";

    } //생성자
    ~CountryLang() {} //소멸자
};

