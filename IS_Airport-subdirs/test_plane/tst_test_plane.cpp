#include <QtTest>
#include "plane.h"

// add necessary includes here

class test_plane : public QObject
{
    Q_OBJECT

public:
    test_plane();
    ~test_plane();

private slots:
    void test_default_constructor();
    void test_init_constructor();
    void test_set_data();
    void test_get_set();
    void test_operator();
};

test_plane::test_plane()
{

}

test_plane::~test_plane()
{

}

void test_plane::test_default_constructor()
{
    Plane p;
    QCOMPARE(p.number(), "");
    QCOMPARE(p.departure(), "");
    QCOMPARE(p.arrival(), "");
    QCOMPARE(p.mark(), "");
    QCOMPARE(p.countSeats(), 0);
    QCOMPARE(p.countFreeSeats(), 0);
}
void test_plane::test_init_constructor()
{
    Plane p("test1", "test2", "test3", "test4", 1, 2, { });
    QCOMPARE(p.number(), "test1");
    QCOMPARE(p.departure(), "test2");
    QCOMPARE(p.arrival(), "test3");
    QCOMPARE(p.mark(), "test4");
    QCOMPARE(p.countSeats(), 1);
    QCOMPARE(p.countFreeSeats(), 2);
}
void test_plane::test_set_data()
{
    Plane p;
    p.setData("test1", "test2", "test3", "test4", 1, 2, { });
    QCOMPARE(p.number(), "test1");
    QCOMPARE(p.departure(), "test2");
    QCOMPARE(p.arrival(), "test3");
    QCOMPARE(p.mark(), "test4");
    QCOMPARE(p.countSeats(), 1);
    QCOMPARE(p.countFreeSeats(), 2);
}
void test_plane::test_get_set()
{
    Plane p;
    p.setNumber("test1");
    p.setDeparture("test2");
    p.setArrival("test3");
    p.setMark("test4");
    p.setCountSeats(1);
    p.setCountFreeSeats(2);
    QCOMPARE(p.number(), "test1");
    QCOMPARE(p.departure(), "test2");
    QCOMPARE(p.arrival(), "test3");
    QCOMPARE(p.mark(), "test4");
    QCOMPARE(p.countSeats(), 1);
    QCOMPARE(p.countFreeSeats(), 2);
}
void test_plane::test_operator()
{
    Plane p("test1", "test2", "test3", "test4", 1, 2, { });
    QString str;
    QTextStream stream(&str);
    stream << p;

    QString res(
        "______Начало САМОЛЕТА______"
        "Номер самолета: test1"
        "Пункт отправления: test2"
        "Пункт назначения: test3"
        "Количество мест: 1"
        "Количество свободных мест: 2"
        "\nКоличество пассажировs: 0\n"
        "______КОНЕЦ САМОЛЕТА______"
    );

    QCOMPARE(str, res);
}

QTEST_APPLESS_MAIN(test_plane)

#include "tst_test_plane.moc"
