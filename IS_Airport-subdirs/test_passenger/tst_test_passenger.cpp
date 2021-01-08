#include <QtTest>
#include "passenger.h"

// add necessary includes here

class test_passenger : public QObject
{
    Q_OBJECT

public:
    test_passenger();
    ~test_passenger();

private slots:
    void test_default_constructor();
    void test_init_constructor();
    void test_get_set();
    void test_buy_ticket();
    void test_hand_over_one_ticket();
};

test_passenger::test_passenger()
{

}

test_passenger::~test_passenger()
{

}

void test_passenger::test_default_constructor()
{
    Passenger p;
    QCOMPARE(p.firstName(), "");
    QCOMPARE(p.secondName(), "");
    QCOMPARE(p.middleName(), "");
    QCOMPARE(p.passport(), "");
    QCOMPARE(p.flight(), "");
}
void test_passenger::test_init_constructor()
{
    Passenger p("test1", "test2", "test3", "test4", "test5");
    QCOMPARE(p.firstName(), "test1");
    QCOMPARE(p.secondName(), "test2");
    QCOMPARE(p.middleName(), "test3");
    QCOMPARE(p.passport(), "test4");
    QCOMPARE(p.flight(), "test5");
}
void test_passenger::test_get_set()
{
    Passenger p;
    p.setFirstName("test1");
    p.setSecondName("test2");
    p.setMiddleName("test3");
    p.setPassport("test4");
    p.setFlight("test5");
    QCOMPARE(p.firstName(), "test1");
    QCOMPARE(p.secondName(), "test2");
    QCOMPARE(p.middleName(), "test3");
    QCOMPARE(p.passport(), "test4");
    QCOMPARE(p.flight(), "test5");
}
void test_passenger::test_buy_ticket()
{
    Passenger p;
    Ticket t;
    t.setId("test1");
    p.buyOneTicket(t);
    QCOMPARE(p.countBuyPlace(), 1);
    t.setId("test2");
    p.buyOneTicket(t);
    QCOMPARE(p.countBuyPlace(), 2);
}
void test_passenger::test_hand_over_one_ticket()
{
    Passenger p;
    Ticket t;
    t.setId("test1");
    p.buyOneTicket(t);
    t.setId("test2");
    p.buyOneTicket(t);
    p.handOverOneTicket("test2");
    p.handOverOneTicket("test");
    QCOMPARE(p.countBuyPlace(), 1);
}


QTEST_APPLESS_MAIN(test_passenger)

#include "tst_test_passenger.moc"
