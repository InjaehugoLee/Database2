#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class World // 클래스 World 생성
{
public: // 클래스를 먼저 만들고 나서 public으로 만드는 이유 : 
    //생성자, 소멸자 디폴트
    World() {}
    ~World() {}
    
    // 가상함수 초기화 이유? 
    // 순수 가상 함수의 문법임 
    virtual void print() = 0;
    virtual void save(MYSQL_ROW& row) = 0;
};

class Country : public World // 클래스 Country를 만들고, 위에 클래스 World를 상속받음.
{   //속성 / Attribute / Property
public:

    // 문자열을 쓸 것이라고 선언
    string Code, Name, Continent, Region, SurfaceArea;
    string IndepYear, Population, LifeExpectancy, GNP, GNPOld;
    string LocalName, GovernmentForm, HeadOfState, Capital, Code2;

    //함수 / Function / Method
public:  //퍼블릭 없으면 디폴트가 private
    Country()
    {
        // 생성자에서 (위의 속성들) 초기화
        Code = Name = Continent = Region = SurfaceArea = "";
        IndepYear = Population = LifeExpectancy = GNP = GNPOld = "";
        LocalName = GovernmentForm = HeadOfState = Capital = Code2 = "";
    } 
    ~Country() {} //소멸자
    
    void print()
    {
        // Country 클래스의 필드(구조체 형식)을 사용 c_str으로 문자열 불러옴
        printf("%s\n", Code.c_str());
        printf("%s\n", Name.c_str());
        printf("%s\n", Continent.c_str());
        printf("%s\n", Region.c_str());
        printf("%s\n", SurfaceArea.c_str());
        printf("%s\n", IndepYear.c_str());
        printf("%s\n", Population.c_str());
        printf("%s\n", LifeExpectancy.c_str());
        printf("%s\n", GNP.c_str());
        printf("%s\n", GNPOld.c_str());
        printf("%s\n", LocalName.c_str());
        printf("%s\n", GovernmentForm.c_str());
        printf("%s\n", HeadOfState.c_str());
        printf("%s\n", Capital.c_str());
        printf("%s\n", Code2.c_str());
    }

    void save(MYSQL_ROW& row)
    {
        int idx = 0;
        if (row[idx])  Code = (row[idx]); idx++;
        if (row[idx])  Name = (row[idx]); idx++;
        if (row[idx])  Continent = (row[idx]); idx++;
        if (row[idx])  Region = (row[idx]); idx++;
        if (row[idx])  SurfaceArea = (row[idx]); idx++;
        if (row[idx])  IndepYear = (row[idx]); idx++;
        if (row[idx])  Population = (row[idx]); idx++;
        if (row[idx])  LifeExpectancy = (row[idx]); idx++;
        if (row[idx])  GNP = (row[idx]); idx++;
        if (row[idx])  GNPOld = (row[idx]); idx++;
        if (row[idx])  LocalName = (row[idx]); idx++;
        if (row[idx])  GovernmentForm = (row[idx]); idx++;
        if (row[idx])  HeadOfState = (row[idx]); idx++;
        if (row[idx])  Capital = (row[idx]); idx++;
        if (row[idx])  Code2 = (row[idx]); 
    }
};

class City : public World
{
    //속성 / Attribute / Property
public:
    string ID, Name, CountryCode, District, Population;

    //함수 / Function / Method
public:  //퍼블릭 없으면 디폴트가 private
    City()
    {
        ID = Name = CountryCode = District = Population = "";
    
    } //생성자
    ~City() {} //소멸자
    void print()
    {
        printf("%s\n", ID.c_str());
        printf("%s\n", Name.c_str());
        printf("%s\n", CountryCode.c_str());
        printf("%s\n", District.c_str());
        printf("%s\n", Population.c_str());
    }

    void save(MYSQL_ROW& row)
    {
        int idx = 0;
        // if (row[idx]  란 말이 if (row[idx] != NULL)   같은 말. NULL이 아니면, 왜냐하면 데이터베이스의 값이 NULL일 경우 에러가 남.
        if (row[idx])  ID = (row[idx]); idx++;
        if (row[idx])  Name = (row[idx]); idx++;
        if (row[idx])  CountryCode = (row[idx]); idx++;
        if (row[idx])  District = (row[idx]); idx++;
        if (row[idx])  Population = (row[idx]); 
    }
};

class CountryLang : public World
{
    //속성 / Attribute / Property
public:
    string CountryCode, Language, IsOfficial, Percentage;


    //함수 / Function / Method
public:  //퍼블릭 없으면 디폴트가 private
    CountryLang()
    {
        CountryCode = Language = IsOfficial = Percentage = "";

    } //생성자
    ~CountryLang() {} //소멸자

    void print()
    {
        printf("%s\n", CountryCode.c_str());
        printf("%s\n", Language.c_str());
        printf("%s\n", IsOfficial.c_str());
        printf("%s\n", Percentage.c_str());
    }
    void save(MYSQL_ROW& row)
    {
        int idx = 0;
        if (row[idx])  CountryCode = (row[idx]); idx++;
        if (row[idx])  Language = (row[idx]); idx++;
        if (row[idx])  IsOfficial = (row[idx]); idx++;
        if (row[idx])  Percentage = (row[idx]); idx++;

    }
};

class English_count : public World
{
    //속성 / Attribute / Property
public:
    string continent;
    int count;


    //함수 / Function / Method
public:  //퍼블릭 없으면 디폴트가 private
    English_count()
    {
        continent = "";
        count = 0;

    } //생성자
    ~English_count() {} //소멸자

    void print()
    {
        printf("%s\n", continent.c_str());
        printf("%d\n", count);
    }
    void save(MYSQL_ROW& row)
    {
 
        if (row[0])  continent = (row[0]); 
        count = atoi(row[1]); 
    }
};

