// dbstudy.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//
#include <iostream>
#include <vector>

#include "mysql.h"
#include "World2.h"


using namespace std;
#define FIELDS_COUNTRY "Code, Name, Continent,Region, SurfaceArea, IndepYear, Population, LifeExpectancy, GNP, GNPOld, LocalName, GovernmentForm, HeadOfState, Capital, Code2"
#define FIELDS_CITY "ID, Name, CountryCode, District, Population"
#define FIELDS_COUNTRYLANGUAGE "CountryCode, Language, IsOfficial, Percentage"
vector <World*> vec;

void printData(const vector <World*>& vec)
{
    for (auto pc : vec)
    {
        pc->print();
        printf("===============================\n");
    }
}

int main()
{
    // mysql db�� ����ϱ� ���� ���� ����
    MYSQL mysql;

    // ���� �ʱ�ȭ
    if (mysql_init(&mysql) == NULL)
    {
        printf("Fail to initialize mysql\n");
        return 1;
    }

    // �����ͺ��̽� ����
    if (mysql_real_connect(&mysql, "localhost", "scott", "tiger", "world", 0, 0, 0) == NULL)
    {
        printf("%s\n", mysql_error(&mysql));
        return 1;
    }

    
    // ���� ����
    char sql[9999];

    //==========================================================
    //    Country
    //==========================================================
    sprintf_s(sql, "select %s from country", FIELDS_COUNTRY);
    if (mysql_query(&mysql, sql) != 0)
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }

    // ���� ��� ����
    MYSQL_RES* res = mysql_store_result(&mysql); //������ �޸� res ��� ������ �־����Ƿ� ���� �߻��� ���� ����� ���� �ڵ��ؾ� ��.
    if (res == NULL) // if(!res) ���� ǥ��
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }

    // ���� ��� �ʵ� ��
    int fieldCount = mysql_num_fields(res);

    // ���� ������� ���ڵ�(row)���� �ϳ��� ���� ����
    MYSQL_ROW row;

    // ��� ���ڵ带 �� ���� ������ �ݺ� ����
    while (row = mysql_fetch_row(res))
    {
        Country* pc = new Country;
        pc->save(row);
        //vec.push_back(pc);
    }
    // ���� ��� �޸� ����
    mysql_free_result(res);

    //==========================================================
    //    City
    //==========================================================
    sprintf_s(sql, "select %s from city", FIELDS_CITY);
    if (mysql_query(&mysql, sql) != 0)
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }

    // ���� ��� ����
    res = mysql_store_result(&mysql); //������ �޸� res ��� ������ �־����Ƿ� ���� �߻��� ���� ����� ���� �ڵ��ؾ� ��.
    if (res == NULL) // if(!res) ���� ǥ��
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }

    // ���� ��� �ʵ� ��
    fieldCount = mysql_num_fields(res);

    while (row = mysql_fetch_row(res))
    {
        City* pc = new City;
        pc->save(row);
        //vec.push_back(pc);
    }

    // ���� ��� �޸� ����
    mysql_free_result(res);

    //==========================================================
    //    CountryLanguage
    //==========================================================
    sprintf_s(sql, "select %s from countrylanguage", FIELDS_COUNTRYLANGUAGE);
    if (mysql_query(&mysql, sql) != 0)
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }

    // ���� ��� ����
    res = mysql_store_result(&mysql); //������ �޸� res ��� ������ �־����Ƿ� ���� �߻��� ���� ����� ���� �ڵ��ؾ� ��.
    if (res == NULL) // if(!res) ���� ǥ��
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }

    // ���� ��� �ʵ� ��
    fieldCount = mysql_num_fields(res);

    while (row = mysql_fetch_row(res))
    {
        CountryLang* pc = new CountryLang;
        pc->save(row);
        //vec.push_back(pc);
    }
    // ���� ��� �޸� ����
    mysql_free_result(res);

    //==========================================================
    //    English_count
    //==========================================================
    sprintf_s(sql, "SELECT continent, count(*) FROM country WHERE EXISTS(SELECT * FROM countrylanguage WHERE country.code = countrylanguage.CountryCode AND Language = 'English') GROUP BY continent ORDER BY continent");
    if (mysql_query(&mysql, sql) != 0)
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }

    // ���� ��� ����
    res = mysql_store_result(&mysql); //������ �޸� res ��� ������ �־����Ƿ� ���� �߻��� ���� ����� ���� �ڵ��ؾ� ��.
    if (res == NULL) // if(!res) ���� ǥ��
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }

    // ���� ��� �ʵ� ��
    fieldCount = mysql_num_fields(res);

    while (row = mysql_fetch_row(res))
    {
        English_count* pc = new English_count;
        pc->save(row);
        vec.push_back(pc);
    }
    // ���� ��� �޸� ����
    mysql_free_result(res);

    // �����ͺ��̽� �ݱ�
    mysql_close(&mysql);

    // ��ü�� ����Ѵ�
    printData(vec);

    // ��ü���� �޸𸮿��� �����Ѵ�
    // ���ο� ����
    for (auto pc : vec)
        delete pc;

    // ���� ����
    //for (int i = 0; i < vec.size(); i++)
    //    delete vec[i];

    vec.clear();
}